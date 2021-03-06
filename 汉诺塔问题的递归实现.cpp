#include <stdio.h>


/*将n个盘子从x借助y移动到z*/
void move(int n, char x, char y, char z) {
	if (n == 1) {
		printf(" %c-->%c\n", x, z);
	}

	else {
		move(n - 1, x, z, y);//将n-1个盘子从x借助z移动到y上
		printf(" %c-->%c", x, z);//将第n个盘子从x移动到z上
		move(n - 1, y, x, z);//将n-1个盘子从y借助x移动到z上
	}
}

int main() {
	int n = 3;

	move(n, 'X', 'Y', 'Z');

	return 0;
}