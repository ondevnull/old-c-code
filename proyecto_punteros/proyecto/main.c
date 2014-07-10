/* 
 * File:   main.c
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on March 26, 2008, 11:14 PM
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * Name: eval
 * Description: Evaluates the value of the point
 * Args: 
 *      + `*m' is the array where all the values are given.
 *      + `x' and `y' is the point to be analyzed.
 *      + `maxx' and `maxy' are the limits of the array.
 * Input: Args
 * Output: Salida.txt
 */
void eval(float *m[][500], int x, int y, int maxy, int maxx) {
    
    FILE *z;
    float q, diff;
    char pto[30];
    int t; // With `t' we check how much values have been plus.
    // Let's check if it is in some of the corners.
    if ((x==0)&&(y==0))
    {
        // Then it's in the left-up corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x + 1][y + 1];
        else
            q = *m[x][y];
        t = 1;
    } else if ((x==maxx)&&(y==maxy)) {
        // Then it's in the right-down corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x - 1][y - 1];
        else
            q = *m[x][y];
        t = 1;
    } else if ((x==maxx)&&(y==0)) {
        // Then it's in the right-up corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x - 1][y + 1];
        else
            q = *m[x][y];
        t = 1;
    } else if ((x==0)&&(y==maxy)) {
        // Then it's in the left-down corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x + 1][y - 1];
        else
            q = *m[x][y];
        t = 1;
    } else if ((x==0)&&((y!=maxy)&&(y!=0))) {
        // Then it's in the right side but not in a corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x + 1][y + 1] + *m[x + 1][y - 1];
        else
            q = *m[x][y];
        t = 2;
    } else if ((y==0)&&((x!=maxx)&&(x!=0))) {
        // Then it's in the left side but not in a corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x - 1][y - 1] + *m[x - 1][y + 1];
        else
            q = *m[x][y];
        t = 2;
    } else if ((x==maxx)&&((y!=0)&&(y!=maxy))) {
        // Then it's in the bottom side but not in a corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x - 1][y - 1] + *m[x + 1][y - 1];
        else
            q = *m[x][y];
        t = 2;
    } else if ((y==maxy)&&((x!=0)&&(x!=maxx))) {
        // Then it's in the top side but not in a corner
        if ((maxx>1)&&(maxy>1))
            q = *m[x - 1][y + 1] + *m[x + 1][y - 1];
        else
            q = *m[x][y];
        t = 2;
    } else {
        // Then obviously is in some place in the center!!
        q = *m[x - 1][y - 1] + *m[x - 1][y + 1] + *m[x + 1][y + 1] + *m[x + 1][y - 1];
        t = 4;
    }
    
    // Now calculates the difference between the sumatory 
    msdiff = (q/(float)t) - *m[x][y];
    
    // Weak point or strong?
    if (diff>30)
    {
        strcpy(pto, "weak point");
    } else {
        strcpy(pto, "strong point");
    }
    // Opening `Salida.txt'
    z = fopen ("Salida.txt", "w");
    // Writing data in `*z'
    if (q==*m[x][y])
        fprintf (z, "The array is too little to make it work");
    else
        fprintf (z, "%d-%d-%f-%s", x, y, diff, pto);
    // Closing `*z'
    fclose(z);
    
}

/*
 * Name: load
 * Description: Loads data from Entrada.txt
 * Args:
 * Input:
 * Output:
 */

void load() {
    FILE *z;
    char q[1000];
    int qq, a = 0;
    // Opening `Entrada.txt'
    z = fopen ("Entrada.txt", "r");
    
    // While there's something in `z*'
    while (!(feof(z)))
    {
         
        // If a is zero then must be the first line that contains in an integer
        // how many arrays there'll be in the source.
        if (a==0)
        {
            fscanf (z, "%d", &qq);
            a = 1;
        } else {
            
        }
        fscanf(z, "%s", &q);
    }
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main() {
    
    return (0);
}
