//��ʹ�������+��-��������֮��
int getSum(int a, int b) {

	int t = 0;
	if (a<0 && b>0)
	{
		t = abs(a);
		while (t--)
		{
			b--;
		}
		return b;
	}
	else if ((a>0 && b<0) || (a<0 && b<0))
	{
		t = abs(b);
		while (t--)
		{
			a--;
		}
		return a;
	}
	else
	{

		while (a--)
			b++;
		return b;
	}
}
