template <class T>
class ListaDin
{
 private:
  int n;
  struct nodo
  {
   T inf;
   nodo *sig;
  } *cab, *pt;
 public:
  int num    ( ) { return n; }
  ListaDin  ( ) { cab=NULL; n=0;}
  int Vacia      ( ) { if (!cab) return 1; return 0; }
  T    Elemento ( ) { return pt->inf; }
  void Cabecera ( ) { pt=cab; }
  nodo *DirCabe ( ) { return cab; }
  void Siguient ( ) { pt=pt->sig; }
  int BuscaInserta (T &ele);
  int Buscar ( T &ele );
  int Modificar    (T &ele);
};

template <class T> 
int ListaDin<T>::Buscar (T &ele)
{
 nodo *p= cab;
 int enc=0;
 while ( !enc && p )
  if ( ele.clave== p->inf.clave )
  {
   enc=1;
   ele= p->inf;
  }
  else
   p  = p->sig;
 return enc;
}

template <class T>
int ListaDin<T>::BuscaInserta (T &ele)
{
 nodo *nue= new nodo, *p= cab, *ant=NULL;
 int enc=0;
 if ( !nue ) return -1;
 nue->inf= ele;
 while ( !enc && p )
  if ( ele.clave== p->inf.clave )
  {
   pt= p;
   delete nue;
   return 0;
  }
  else if ( ele.clave<p->inf.clave )
   enc=1;
  else
  {
   ant= p;
   p  = p->sig;
  }
 if ( !ant )
  cab= nue;
 else
  ant->sig= nue;
 nue->sig = p;
 n++;
 return 1;
}

template <class T>
int ListaDin<T>::Modificar( T &ele )
{
 nodo *p= cab;
 int enc=0;
 while (p && !enc)
  if (p->inf.clave==ele.clave)
   enc=1;
  else
   p= p->sig;
 if ( !enc ) return 0;
 p->inf= ele;
 return 1;
}
