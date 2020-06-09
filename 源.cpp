/*
	����ջ
*/

#include <stdio.h>
#include <stdlib.h>

#define Stark_Init_Size 100//ջ�ĳ�ʼ��С
#define StarkIncrement  10//��ջ�ռ䲻��ʱÿ��׷�ӵĴ�С

typedef int ElemType;//ջԪ��������

typedef struct {
	ElemType* top;
	ElemType* base;
	int StarkSize;
}SqStark;

/* ������һ����ջ�� */
int InitStark(SqStark* S) {
	S->base = (ElemType*)malloc(Stark_Init_Size * sizeof(ElemType));
	if (!S->base) return 1;//����ռ�ʧ�ܣ�����1
	S->top = S->base;
	S->StarkSize = Stark_Init_Size;
	return 0;//������ջ�ɹ�������0
}


/* ������Ԫ��eΪ�µ�ջ��Ԫ�ء� */
void Push(SqStark *S,ElemType e) {
	if (S->top - S->base >= S->StarkSize) {//ջ�ռ䲻�㣬׷�ӿռ�
		S->base = (ElemType*)realloc(S->base,(S->StarkSize + StarkIncrement) * sizeof(ElemType));
		if (!S->base) exit(1);
		S->top = S->base + S->StarkSize;
		S->StarkSize += StarkIncrement;
	}
	*S->top++ = e;
}

/* ����ȡջ��Ԫ�ز���ӡ�� */
void GetTop(SqStark S) {
	if (S.top == S.base) {
		exit(1);
	}
	printf("\nջ��Ԫ��Ϊ%d", *(--S.top));
}

/* ����ջ��Ϊ�գ���ɾ��ջ��Ԫ�أ�����ɾ����ջ��Ԫ�ظ�ֵ��e�� */
int Pop(SqStark* S) {
	if (S->top == S->base) {
		exit(1);
	}
	return *(--S->top);
}

/* ����ջ����Ϊ��ջ�� */
void ClearStark(SqStark *S){
	S->top = S->base;
}

/* ���ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ�����1�����򷵻�0��*/


int main() {
	SqStark S;
	InitStark(&S);
	for (int i = 0; i < 100; i++) {
		Push(&S, i);
	}
	GetTop(S);
	ElemType i;
	i = Pop(&S);
	printf("\n��Pop�󣬱�ɾ����ջ��Ԫ��Ϊ��%d", i);
	GetTop(S);

	return 0;
}