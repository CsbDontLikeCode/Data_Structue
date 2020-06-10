/*
	��ջʵ�ֶ�����תʮ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Stark_Init_Size 100//ջ�ĳ�ʼ��С
#define StarkIncrement  10//��ջ�ռ䲻��ʱÿ��׷�ӵĴ�С

typedef char ElemType;//ջԪ��������

typedef struct {
	ElemType* top;
	ElemType* base;
	int StarkSize;
}SqStark;

/* ������һ����ջ�� */
void InitStark(SqStark* S) {
	S->base = (ElemType*)malloc(Stark_Init_Size * sizeof(ElemType));
	if (!S->base) exit(0);//����ռ�ʧ�ܣ��˳�
	S->top = S->base;
	S->StarkSize = Stark_Init_Size;
}


/* ������Ԫ��eΪ�µ�ջ��Ԫ�ء� */
void Push(SqStark* S, ElemType e) {
	if (S->top - S->base >= S->StarkSize) {//ջ�ռ䲻�㣬׷�ӿռ�
		S->base = (ElemType*)realloc(S->base, (S->StarkSize + StarkIncrement) * sizeof(ElemType));
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
void ClearStark(SqStark* S) {
	S->top = S->base;
}

/* �����㵱ǰջ�������� */
int StarkLen(SqStark S) {
	return S.top - S.base;
}


int main() {
	ElemType c;
	SqStark S;
	int len, i, sum = 0;

	InitStark(&S);
	printf("�������������������#���Ž�����\n");
	scanf_s("%c", &c);
	while (c != '#') {
		Push(&S, c);
		scanf_s("%c", &c);
	}

	getchar();

	len = StarkLen(S);
	printf("ջ�ĵ�ǰ�����ǣ�%d\n", len);

	for (i = 0; i < len; i++) {
		c = Pop(&S);
		sum = sum + (c - 48) * pow(2, i);
	}

	printf("ת��Ϊʮ������Ϊ��%d", sum);

	return 0;
}