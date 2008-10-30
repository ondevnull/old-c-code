/* 
 * File: checkers.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 27, 2008, 19:08
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

#include "checkers.h"

/**
 * Constructor of the class.
 *
 * Here the board is built.
 *
 * @param width width of the table
 * @param height height of the table
 */
Checkers::Checkers (int width, int height) {
	/* Assigning memory from the heap to the table */
	board = new *Node[width];
	for (int i = 0; i < height; i++)
		board[i] = new Node[height];
	w = width;
	h = height;

	/* Building the table */
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if ((( i < (w/3))||(i >= (w/3)*2)) && ((j < (h/3)) || (j >= (h/3)*2)) ) {
				board[i][j].valid = false;
				board[i][j].color = 0;
			}
		}
	}
	cleanboard();
};

/**
 * prints the board to stdout.
 */
void Chechers::print() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++)
			std::cout << board[i][j];
		std::cout << std::endl;
	}
};

/**
 * Cleans the board.
 *
 * @return If doesn't return 0 then something, or everything, went wrong.
 */
int Checkers::cleanboard() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if ( ((i >= (w/3)) || (i < (w/3)*2) ) && ( (j >= (h/3)) || (j < (h/3)*2)) ) {
			board[i][j].used = false;
			board[i][j].color = 0;
			}
		}
	}
	return (0);
};

/**
 * Set up all the board for a new game.
 */
int Checkers::newgame() {
	cleanboard();
	for (int i = (w/3) - 1; i <= (w/3)*2; i++) {
		board[i][0].used = true;
		board[i][0].color = 1;
		board[i][h - 1].used = true;
		board[i][h - 1].color = -1;
	}
	return (0);
};

/**
 * Checks if it can be moved some chip over that position
 */
bool Checkers::checkmove(int x, int y) {
	if ((board[x][y].valid)&&(!board[x][y].used))
		return (true);
	return (false);
};

/**
 * Check if valid
 */
bool Checkers::checkvalid(int x, int y, int col) {
	if ((board[x + col][y + 1].valid) && (board[x + col][y - 1].valid))
		return (true);
	return (false);
};

/**
 * Moves a piece.
 *
 * @param xo initial height position.
 * @param yo initial width position.
 * @param xf final height position.
 * @param yf finail width position.
 * @param col color it should be 1 for down-side chips and -1 for up-side chips.
 *
 * @return -1 if is not a valid move because of the position, unable to move
 * from there, -2 if is not a valid move, please use checkpremove method,
 * zero - 0 if successful, -3 if is a bad color, 2 if can make a stairs movement.
 *
 */
int Checkers::move(int xo, int yo, int xf, int yf, int col) {
	/* Good color? */
	if ((col != -1)||(col != 1)) {
		std::cerr << "Bad color sent!" << std::endl;
		return (-3);
	}
	/* Checking if the move is valid */
	if ((!(xf - xo == col) && (!(yf - yo == -1) || !(yf - yo == 1))) || ( !(xf - xo == col*2) && (!(yf - yo == -2) || !(yf - yo == 2)) ) ) {
		std::cerr << "This is not a valid move, please use checkpremove method!" << std::endl;
		return (-1);
	}
	if (((xf - xo == col*2) && (yf - yo == -2) && !(checkmove (xo + 1, yo - 1))) || ((xf - xo == col*2) && (yf - yo == 2) && !(checkmove(xo + 1, yo + 1)))) {
		std::cerr << "This is not a valid move, please use checkpremove method!" << std::endl;
		return (-1);
	}
	if !(checkmove(int xf, int yf)) {
		std::cerr << "This is not a valid move, please use checkpremove method!" << std::endl;
		return (-2);
	}

	/* Passing data from initial position to final position */
	board[xf][yf].used = true;
	board[xf][yf].color = board[xo][yo].color;
	board[xo][yo].used = false;
	board[xo][yo].color = 0;
	/* Checking if it can make a "stairs move" */
	if (xf - xo == col*2) {
		if (checkmove(xf + (col*2), yf + 2) || checkmove (xf + (col*2), yf - 2))
			return (2);
	}
	return (0);
};

/**
 * Checks if at a position there's an enemy
 *
 * @param col friends color or himself color.
 * @param x height position to check.
 * @param y width position to check.
 *
 * @return true if there's a enemy, false otherwise.
 */
bool Checkers::checkenemy(int x, int y, int col) {
	if ((board[x][y].used) && (board[x][y].color != col))
		return (true);
	return (false);
};

/**
 * Check if a chip can be moved
 *
 * This is the method that should be use and just use checkmove and checkvalid
 * in an optional manner.
 *
 * @param x height position of the chip.
 * @param y width position of the chip.
 * @param col color of the chip
 *
 * @return -3 if is on a wall and can't move, then should be re-posisionated!
 */
int Checkers::checkpremove(int x, int y, int col) {
	int acum = 0;
	/* Can move to left */
	if (checkmove(x + col, y - 1))
		acum = acum + 1;
	/* Can move to right */
	if (checkmove(x + col, y + 1))
		acum = acum + 3;
	/* Can jump to left */
	if (checkmove(x + col*2, y - 2) && !checkmove(x + col, y - 1))
		if (checkenemy(x + col, y - 1))
			acum = acum + 11;
		else
			acum = acum + 9;
	/* Can jump to right */
	if (checkmove(x + col*2, y + 2) && !checkmove(x + col, y + 1))
		if (checkenemy(x + col, y + 1))
			acum = acum + 33;
		else
			acum = acum + 27;
	if (!checkvalid(x, y, col))
		return (-3);
	return acum;
};
