#include <stdio.h>
#include <stdlib.h>

#define size 5

typedef struct {
	int V[size];
	int E[size][size];
}Graph;

int Ensure() {
	int n;
	scanf_s("%d", &n);
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		printf("输入错误，请按规范输入！！！");
		printf("\n点%d与点%d之间是否存在路径(输入1为存在，输入0为不存在):");
		Ensure();
	}
}

void createGraph(Graph *G) {
	for (int i = 0; i < size; i++) {
		G->V[i] = i + 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			printf("点%d与点%d之间是否存在路径(输入1为存在，输入0为不存在):",i+1,j+1);
			int i;
			i = Ensure();
			G->E[i][j] = G->E[j][i] = i;
		}
	}
}

void query(Graph *G) {//查询两点之间是否存在路径
	int i, j;
	printf("请输入需要查询的两个点：");
	scanf_s("%d %d", &i, &j);
	if (G->E[i+1][j+1] == 1) {
		printf("点%d与点%d之间存在路径.",i,j);
	}
	else {
		printf("点%d与点%d之间不存在路径.",i,j);
	}
}

int main() {
	Graph G;

	createGraph(&G);

	query(&G);

	return 0;
}