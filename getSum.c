#include <stdio.h>
//��ʹ�������+��-��������֮��
bool isPerfectSquare(int num) {

	int k = num + 1;
	int i = 0;
	for (i = 1; i <= num; i++)
	{
		k = num / i;
		if (!(k - i))
			return true;
		k = num + 1;
	}

	return false;
}
int main()
{
	int num = 5;
	isPerfectSquare(num);
}