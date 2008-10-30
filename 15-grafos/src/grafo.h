# include "listadin.h"
#include <iostream>

template <class T>
class Grafo
{
 private:
  int n;
  float **m;
  T *vertice;
  struct nodoady
  {
   T   clave;
   float peso;
  };
  struct nododir
  {
   T    clave;
   ListaDin<nodoady> *ady;
  };
  ListaDin<nododir> *lista_ady;
 public:
  Grafo( int num, T a[], float mat[] );
  void muestra();
  void lista_adyacencia();
  void imprime();
};

template <class T> Grafo<T>::Grafo( int num, T a[], float mat[] )
{
 int i, j, k;
 n= num;
 m= new float*[n];
 vertice= new T[n];
 for (i=0; i<n; i++ )
 {
  vertice[i]= a[i];
  m[i]= new float[n];
 }
 for (i=0,k=0; i<n; i++)
  for (j=0; j<n; j++, k++)
   m[i][j]= mat[k];
 lista_ady= new ListaDin<nododir>;
}

template <class T> void Grafo<T>::muestra( )
{
 int i, j;
 for (i=0; i<n; i++)
  std::cout<< vertice[i] <<"  ";
 std::cout<< std::endl;
 for (i=0; i<n; i++)
 {
  for (j=0; j<n; j++)
   std::cout<< m[i][j]<<"  ";
  std::cout<<std::endl;
 }
}

template <class T> void Grafo<T>::lista_adyacencia()
{
 nododir buf1;
 nodoady buf2;
 int i,j;
 for (i=0; i<n; i++)
 {
  buf1.clave= vertice[i];
  buf1.ady  = new ListaDin<nodoady>;
  for (j=0; j<n; j++)
   if ( i!=j && m[i][j]!=0 )
   {
    buf2.peso = m[i][j];
    buf2.clave= vertice[j];
    buf1.ady->BuscaInserta(buf2);
   }
  lista_ady->BuscaInserta(buf1);
 }
}

template <class T> void Grafo<T>::imprime( )
{
 nododir buf1;
 nodoady buf2;
 int i,j;
 lista_ady->Cabecera();
 for (i=0; i<n; i++)
 {
  buf1= lista_ady->Elemento();
  std::cout<< "Nodo dir: "<< buf1.clave <<" Adyacentes: ";
  (buf1.ady)->Cabecera();
  for (j=0; j<buf1.ady->num(); j++)
  {
   buf2= buf1.ady->Elemento();
   std::cout<<"  "<< buf2.clave << "["<<buf2.peso<<"]";
   buf1.ady->Siguient();
  }
  std::cout<<std::endl;
  lista_ady->Siguient();
 }
}
