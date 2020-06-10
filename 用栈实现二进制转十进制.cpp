/*
	用栈实现二进制转十进制
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Stark_Init_Size 100//栈的初始大小
#define StarkIncrement  10//当栈空间不足时每次追加的大小

typedef char ElemType;//栈元素类型名

typedef struct {
	ElemType* top;
	ElemType* base;
	int StarkSize;
}SqStark;

/* ↓构造一个空栈↓ */
void InitStark(SqStark* S) {
	S->base = (ElemType*)malloc(Stark_Init_Size * sizeof(ElemType));
	if (!S->base) exit(0);//分配空间失败，退出
	S->top = S->base;
	S->StarkSize = Stark_Init_Size;
}


/* ↓插入元素e为新的栈顶元素↓ */
void Push(SqStark* S, ElemType e) {
	if (S->top - S->base >= S->StarkSize) {//栈空间不足，追加空间
		S->base = (ElemType*)realloc(S->base, (S->StarkSize + StarkIncrement) * sizeof(ElemType));
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
void ClearStark(SqStark* S) {
	S->top = S->base;
}

/* ↓计算当前栈的容量↓ */
int StarkLen(SqStark S) {
	return S.top - S.base;
}


int main() {
	ElemType c;
	SqStark S;
	int len, i, sum = 0;

	InitStark(&S);
	printf("请输入二进制数，输入#符号结束！\n");
	scanf_s("%c", &c);
	while (c != '#') {
		Push(&S, c);
		scanf_s("%c", &c);
	}

	getchar();

	len = StarkLen(S);
	printf("栈的当前容量是：%d\n", len);

	for (i = 0; i < len; i++) {
		c = Pop(&S);
		sum = sum + (c - 48) * pow(2, i);
	}

	printf("转化为十进制数为：%d", sum);

	return 0;
}
