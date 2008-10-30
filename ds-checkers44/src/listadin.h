/* 
 * File: listadin.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 16, 2008, 18:43
 *
 * Copyright (c) 2008 Jose Luis Rivas <ghostbar38@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

template <class T>
class ListaDin
{
	private:
		int n;
		struct nodo {
			T inf;
			int x; /**< height value of the chip to move */
			int y; /**< width value of the chip to move */
			int level; /**< level of the multilist */
			nodo *sig;
		} *cab, *pt;
	public:
		int num () { return n; }
		ListaDin () { cab=NULL; n=0;}
		int Vacia() { if (!cab) return 1; return 0; }
		T Elemento () { return pt->inf; }
		void Cabecera () { pt=cab; }
		nodo *DirCabe () { return cab; }
		void Siguient () { pt=pt->sig; }
		int BuscaInserta (T &ele);
		int Buscar (T &ele);
		int Modificar (T &ele);
};

template <class T> 
int ListaDin<T>::Buscar (T &ele) {
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
};

template <class T>
int ListaDin<T>::BuscaInserta (T &ele) {
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
};

template <class T>
int ListaDin<T>::Modificar( T &ele ) {
	nodo *p= cab;
	int enc=0;
	while (p && !enc)
		if (p->inf.clave==ele.clave)
			enc=1;
		else
			p= p->sig;
	if ( !enc ) 
		return 0;
	p->inf= ele;
	return 1;
};
