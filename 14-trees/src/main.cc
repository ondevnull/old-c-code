#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "tree.h"

void mostrar(int buf)
{
	std::cout << buf << std::endl;
}

int main()
{
   char num[8];
   int numero;
   Tree<int> tree;
   FILE *f = fopen("claves.txt","r+");
   if(!f)
   {
      printf("error al abrir el archivo");
      fclose(f);
   }
   while(1)
   {
      fgets(num,8,f);
      if ( feof(f) ) 
	      break;
      numero = atoi(num);
      tree.push(numero);
   }
   tree.print(mostrar);

   return (0);
}
