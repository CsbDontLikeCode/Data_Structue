/*
	创建栈
*/

#include <stdio.h>
#include <stdlib.h>

#define Stark_Init_Size 100//栈的初始大小
#define StarkIncrement  10//当栈空间不足时每次追加的大小

typedef int ElemType;//栈元素类型名

typedef struct {
	ElemType* top;
	ElemType* base;
	int StarkSize;
}SqStark;

/* ↓构造一个空栈↓ */
int InitStark(SqStark* S) {
	S->base = (ElemType*)malloc(Stark_Init_Size * sizeof(ElemType));
	if (!S->base) return 1;//分配空间失败，返回1
	S->top = S->base;
	S->StarkSize = Stark_Init_Size;
	return 0;//构建空栈成功，返回0
}


/* ↓插入元素e为新的栈顶元素↓ */
void Push(SqStark *S,ElemType e) {
	if (S->top - S->base >= S->StarkSize) {//栈空间不足，追加空间
		S->base = (ElemType*)realloc(S->base,(S->StarkSize + StarkIncrement) * sizeof(ElemType));
		if (!S->base) exit(1);
		S->top = S->base + S->StarkSize;
		S->StarkSize += StarkIncrement;
	}
	*S->top++ = e;
}

/* ↓获取栈顶元素并打印↓ */
void GetTop(SqStark S) {
	if (S.top == S.base) {
		exit(1);
	}
	printf("\n栈顶元素为%d", *(--S.top));
}

/* ↓若栈不为空，则删除栈顶元素，并将删除的栈顶元素赋值给e↓ */
int Pop(SqStark* S) {
	if (S->top == S->base) {
		exit(1);
	}
	return *(--S->top);
}

/* ↓把栈设置为空栈↓ */
void ClearStark(SqStark *S){
	S->top = S->base;
}

int main() {
	SqStark S;
	InitStark(&S);
	for (int i = 0; i < 100; i++) {
		Push(&S, i);
	}
	GetTop(S);
	ElemType i;
	i = Pop(&S);
	printf("\n在Pop后，被删除的栈顶元素为：%d", i);
	GetTop(S);

	return 0;
}
