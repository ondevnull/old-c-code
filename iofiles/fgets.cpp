#include stdio
main()
{
	FILE *p;
	char x[100];
	p = fopen("archivo.txt", "r");

	while (!(feof(p)))
	{
		fgets(x, 100, p);
	}
	fclose(p);
	return 0;
}
