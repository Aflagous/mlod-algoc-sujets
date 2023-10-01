#include "echangeContenu.c"

int main(void)
{
	int a=4;
	int b=14;

	printf ("a = %d\tb = %d\n", a, b);
	echangeContenu(&a, &b);
	printf ("a = %d\tb = %d\n", a, b);
	return 0;
}

