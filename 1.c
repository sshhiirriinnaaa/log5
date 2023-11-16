#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 

int randomEdge() {
	return rand() % 2;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n; 
	srand(time(NULL)); 

	printf("Введите размер матрицы (количество вершин): ");
	scanf("%d", &n);

	int** adjacencyMatrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		adjacencyMatrix[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				adjacencyMatrix[i][j] = 0;                                              
			}
			else {
				adjacencyMatrix[i][j] = randomEdge();
				adjacencyMatrix[j][i] = adjacencyMatrix[i][j]; 
			}
		}
	}

	printf("Матрица смежности для графа G:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", adjacencyMatrix[i][j]);
		}
		printf("\n");
	}


	int m = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				m++;
			}
		}
	}

	printf("Размер графа G =  %d\n", m);

	
	printf("Изолированные вершины:");
	for (int i = 0; i < n; i++) {
		int isolated = 1; 
		for (int j = 0; j < n; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				isolated = 0; 
				break;
			}
		}
		if (isolated) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	printf("Концевые вершины:");
	for (int i = 0; i < n; i++) {
		int degree = 0;
		for (int j = 0; j < n; j++) {
			degree += adjacencyMatrix[i][j];
		}
		if (degree == 1) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	printf("Доминирующие вершины:");
	for (int i = 0; i < n; i++) {
		int dominating = 1; 
		for (int j = 0; j < n; j++) {
			if (i != j && adjacencyMatrix[i][j] != 1) {
				dominating = 0; 
				break;
			}
		}
		if (dominating) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	int** incidenceMatrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		incidenceMatrix[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			incidenceMatrix[i][j] = 0;
		}
	}

	int edgeIndex = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				incidenceMatrix[i][edgeIndex] = 1;
				incidenceMatrix[j][edgeIndex] = 1;
				edgeIndex++;
			}
		}
	}

	printf("Матрица инцидентности для графа G:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", incidenceMatrix[i][j]);
		}
		printf("\n");
	}

	printf("Размер графа G =  %d\n", m);

	printf("Изолированные вершины:");
	for (int i = 0; i < n; i++) {
		int isolated = 1; 
		for (int j = 0; j < m; j++) {
			if (incidenceMatrix[i][j] == 1) {
				isolated = 0; 
				break;
			}
		}
		if (isolated) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	printf("Концевые вершины:");
	for (int i = 0; i < n; i++) {
		int degree = 0;
		for (int j = 0; j < m; j++) {
			if (incidenceMatrix[i][j] == 1) {
				degree++;
			}
		}
		if (degree == 1) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	printf("Доминирующие вершины:");
	for (int i = 0; i < n; i++) {
		int degree = 0; 
		for (int j = 0; j < m; j++) {
			if (incidenceMatrix[i][j] == 1) {
				degree++;
			}
		}

		if (degree == n - 1) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");


	for (int i = 0; i < n; i++) {
		free(adjacencyMatrix[i]);
	}
	free(adjacencyMatrix);

	for (int i = 0; i < n; i++) {
		free(incidenceMatrix[i]);
	}
	free(incidenceMatrix);

	return 0;
}
