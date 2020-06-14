#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
	char data;
	BiTNode* lchild, * rchild;
}BiTNode;

/* ��������������Ĭ����ǰ�����˳������� */
/* ������#Ĭ��Ϊ���ӽڵ�               �� */
void CreateBiTree(BiTNode* &T) {
	char c;
	scanf_s("%c", &c);

	if (c == '#') {
		T = NULL;
	}
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = c;
		T->lchild = NULL;
		T->rchild = NULL;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

/* ��ǰ������������� */
void PreOrderTraverse(BiTNode *T) {
	if (T == NULL) {
		return;
	}

	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* ����������������� */
void InOrderTraverse(BiTNode* T) {
	if (T == NULL) {
		return;
	}

	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

/* ����������������� */
void PostOrderTraverse(BiTNode *T) {
	if (T == NULL) {
		return;
	}

	InOrderTraverse(T->lchild);
	InOrderTraverse(T->rchild);
	printf("%c", T->data);
}

int main() {
	printf("����ǰ�����˳����������:");

	BiTNode *T = NULL;
	
	CreateBiTree(T);
	if (T == NULL) {
		printf("������Ϊ��");
	}

	printf("\nǰ��������Ϊ:");
	PreOrderTraverse(T);

	printf("\n����������Ϊ:");
	InOrderTraverse(T);

	printf("\n����������Ϊ:");
	PostOrderTraverse(T);

	return 0;
}