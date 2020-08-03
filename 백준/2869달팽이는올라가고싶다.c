#include <stdio.h>
int main()
{
	double nat, bam, top;
	double a;
	scanf("%lf%lf%lf", &nat, &bam, &top);
	a = (top - nat) / (nat - bam);
	if (a == (int)a)
		printf("%d", (int)a + 1);
	else
		printf("%d", (int)a + 2);

	return 0;
}