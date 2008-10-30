//---------------------------------------------------------------------------

#include <iostream>
#include "grafo.h"

int main( )
{
 int   n;
 char  a[]= {'A', 'B', 'C'};
 float v[]= {12.3, 10.1, 20.5,
             52.2, 10.2, 34.2,
             13.1, 32.5, 16.9 };
 n= sizeof(a)/sizeof(a[0]);
 Grafo<char> G(n,a,v);
 G.muestra();
 G.lista_adyacencia();
 std::cout<<std::endl;
 G.imprime();
 return 0;
}
//---------------------------------------------------------------------------
 
