#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
	char data;
	BiTNode* lchild, * rchild;
}BiTNode;

/* ↓创建二叉树，默认以前序遍历顺序输入↓ */
/* ↓输入#默认为无子节点               ↓ */
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

/* ↓前序遍历二叉树↓ */
void PreOrderTraverse(BiTNode *T) {
	if (T == NULL) {
		return;
	}

	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* ↓中序遍历二叉树↓ */
void InOrderTraverse(BiTNode* T) {
	if (T == NULL) {
		return;
	}

	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

/* ↓后序遍历二叉树↓ */
void PostOrderTraverse(BiTNode *T) {
	if (T == NULL) {
		return;
	}

	InOrderTraverse(T->lchild);
	InOrderTraverse(T->rchild);
	printf("%c", T->data);
}

int main() {
	printf("请以前序遍历顺序输入数据:");

	BiTNode *T = NULL;
	
	CreateBiTree(T);
	if (T == NULL) {
		printf("二叉树为空");
	}

	printf("\n前序遍历结果为:");
	PreOrderTraverse(T);

	printf("\n中序遍历结果为:");
	InOrderTraverse(T);

	printf("\n后序遍历结果为:");
	PostOrderTraverse(T);

	return 0;
}