/* 
 * File: checkers.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 27, 2008, 19:07
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

#ifndef _CHECKERS_H
#define _CHECKERS_H

#include <iostream>

/**
 * Class Checkers.
 *
 * This is the API for the game of checkers44.
 *
 * For reference of readers, the blank nodes will always have as color the int
 * 0 - zero, so for real colors you should use -1 for color of down-side and 1
 * for color of up-side and for showing check that the node is valid, if's not
 * valid then that means should be a NULL block.
 */
class Checkers {
private:
	struct Node {
		bool used = false;
		int color;
		bool valid = true;
	};
	Node **board;
	int w, h; /**< width and height */
public:
	Checkers(int width, int height);
	virtual ~Checkers();
	void print();
	int cleanboard();
	int newgame();
	int checkpremove(int x, int y, int col);
	bool checkmove(int x, int y);
	bool checkvalid(int x, int y);
	int move (int xo, int yo, int xf, int yf, int col);
	bool checkenemy(int x, int y, int col);
};

#endif // _CHECKERS_H
