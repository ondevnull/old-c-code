/* 
 * File: tree-avl.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 18, 2008, 11:37
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

#ifndef _TREE-AVL_H
#define _TREE-AVL_H

#include "tree.h"

/**
 * It's a better aproach for trees
 *
 * It adds nodes in a way that the tree remains equilibrated. It's a child
 * of Tree.
 */
template <class T>
class TreeAVL : public Tree<T> {
public:
	TreeAVL();
	virtual ~TreeAVL();
private:
	struct node {
		T info;
		node * chl, chr; /** < Child left and child right respectively. */
		int hf; /** < Hierarchy factor. */
	}*root;
};




#endif // _TREE-AVL_H
