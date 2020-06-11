#include <stdio.h>
#include <stdlib.h>

long int Fib(long int i) {
	if (i <= 2) {
		return i == 0 ? 0 : 1;
	}
	return Fib(i - 1) + Fib(i - 2);
}

int main(void) {
	long int loc,num;

	printf("输入数列序号：");
	scanf_s("%d", &loc);
	num = Fib(loc);
	printf("对应位置元素为%d", num);

	return 0;
}