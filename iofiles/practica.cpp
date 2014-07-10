#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *op;
	//, *ou;

	int in, a, ac;
	char cad[10];

	op = fopen("hola.txt", "r");
	//ou = fopen("chao.txt", "w");

	while (!feof(op))
	{
		fscanf(op, "%s", &cad);
		in = atoi(cad);
		ac = 1;
		for (a=0; a<in; a++)
		{
			ac=ac*(a+1);
		}
		printf ("%d %d\n", ac, in);
//		fprintf(ou, "%d\r\n", ac);
	}
	fclose(op);
	//fclose(ou);
	return 0;
}
