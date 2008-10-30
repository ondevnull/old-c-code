/* 
 * File: tree.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 17, 2008, 18:07
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

#ifndef _TREE_H
#define _TREE_H

template <class T>
class Tree {
public:
	Tree() { root = NULL; } /** < Constructor of the class, initializes root
				as being empty */
//	virtual ~Tree();
	bool isempty() { 
		return (root == NULL); }
	int push( T ele);
	void print( void (*PtrF)(T ele));
private:
	struct Node {
		T info;
		Node *chl, *chr; /** < Child left and child right respectively. */
	}*root;
	void tourer( void (*PtrF)(T ele), Node *p, int lev); /** PtrF means pointer of function */
};


/**
 * Creates a new Node in the tree.
 *
 * @param ele the element to add
 * @return 1 if the Node wasn't created succesfully, 2 if something weird
 * happened and 0 if successful.
 */
template <class T>
int Tree<T>::push (T ele) {
	Node *neo;
	neo = new Node; /* Created space in the heap */
	if (!neo)
		return (1); /* If wasn't created the Node in the heap of memory */
	neo->info = ele;
	neo->chr = neo->chl = NULL;
	if ( isempty()) {
		root = neo;
	} else {
		Node *p, *bef;
		p = root;
		bef = NULL;

		while (p != NULL) {
			if (ele < (p->info)) {
				bef = p;
				p = p->chl;
			} else {
				bef = p;
				p = p->chr;
			}
		}

		if (ele < bef->info)
			bef->chl = neo;
		else
			bef->chr = neo;
		return (0);
	}
	return (2);
};

/**
 * Arranges the order how it's going to be printed.
 *
 * @param PtrF A pointer to a function that will print the values.
 * @param p is a Node from where to start.
 * @param lev is how deep is printing, like level.
 */
template <class T>
void Tree<T>::tourer (void (*PtrF)(T ele), Node *p, int lev) {
	for (int i = 0; i < lev; i++)
		std::cout << "\t";
	PtrF( p->info);

	if (p->chl)
		tourer (PtrF, p->chl, lev + 1);
	if (p->chr)
		tourer (PtrF, p->chr, lev + 1);
};

/**
 * Function to be called when printing
 *
 * @param PtrF Pointer of function to print.
 */
template <class T>
void Tree<T>::print (void (*PtrF)(T ele)) {
	tourer (PtrF, root, 0);
};

#endif // _TREE_H
