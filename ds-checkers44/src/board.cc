/* 
 * File: board.cc
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

#include "board.h"
#include <iostream>

/**
 * Creates the Tables.
 *
 * Creates the Tables, the EventBoxes and fill them with white Images.
 */
Board::Board() : board( 15, 15, true)
{
	
};

Board::~Board() {};
/**
 * Fills the board with pieces.
 *
 * This method should be called at the beginning of the game or while
 * restarting, just put the pieces at the starting point.
 *
 * @return Returns 0 if succesful, 1 if there's any error related to.
 */
int Board::FillBoard()
{
	return (0);
};
