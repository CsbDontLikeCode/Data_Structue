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
		printf("��������밴�淶���룡����");
		printf("\n��%d���%d֮���Ƿ����·��(����1Ϊ���ڣ�����0Ϊ������):");
		Ensure();
	}
}

void createGraph(Graph *G) {
	for (int i = 0; i < size; i++) {
		G->V[i] = i + 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			printf("��%d���%d֮���Ƿ����·��(����1Ϊ���ڣ�����0Ϊ������):",i+1,j+1);
			int i;
			i = Ensure();
			G->E[i][j] = G->E[j][i] = i;
		}
	}
}

void query(Graph *G) {//��ѯ����֮���Ƿ����·��
	int i, j;
	printf("��������Ҫ��ѯ�������㣺");
	scanf_s("%d %d", &i, &j);
	if (G->E[i+1][j+1] == 1) {
		printf("��%d���%d֮�����·��.",i,j);
	}
	else {
		printf("��%d���%d֮�䲻����·��.",i,j);
	}
}

int main() {
	Graph G;

	createGraph(&G);

	query(&G);

	return 0;
}