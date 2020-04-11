//c++数组，a指数组首地址，&a指整个数组地址
#include<stdio.h>
 
void main() {
	int a[10] = {};
	printf("%d\n", a);
	printf("%d\n", a+1);    //与前面一个相差4
	printf("%d\n", &a);
	printf("%d\n", &a + 1); //与前面一个相差40	
}