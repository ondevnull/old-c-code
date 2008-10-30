/*
 * File:   writers.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 30, 2008, 6:44 PM
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

#ifndef _WRITERS_H
#define	_WRITERS_H

#include <iostream>
#include <structures.h>

/*
 * Name: which_lookr
 * Description: Checks which code is for a given carreer/class
 * Args: 
 *	+ a: which career/class
 *	+ what: "alumno" or "materia"
 *	+ where: path for the file to check
 * Input: args.
 * Output: returns the code of the career/class as an integer
 */
extern int which_lookr (string a, string what, string where){
//	Opening the file with data of the carreer codes
	FILE *f;
	f = fopen (where, "rb");
//	Creating an auxiliar structure type for reading file
	if (what=="carrera")
		REG_CARRERA t;
	else
		REG_MATERIA t;
	
//	Run trough all the file
	while (f!=NULL) {
		fread (t, sizeof(t), f);
//		If this is the _one_ then return the code
		if (t.des == a)
			return (t.cod);
	}
}

/*
 * Name: fill_data
 * Description: Fills archives with data
 * Args:
 *	+ f: a pointer FILE-type (to a file already opened)
 *	+ what: what's gonna be filled
 * Input:
 * Output:
 */
extern int fill_data (FILE *f, string what, REG_DATA data[])
{
//	Checking if file is open, if not then return a -3
	if (f==NULL)
		return (-3);
//	Setting f to the beggining
	rewind (f);
	char q = 's';
//	According to the kind of file the data will be filled.
	switch (what) {
		case "alumno":
			std::cout << "A continuación se le pedirá información para" << endl
				<< "llenar los campos del archivo para alumnos." << endl;
			REG_ALUMNO aux;
			string aucarr;
			while ((q=='s')||(q=='S')) {
				std::cout << "Ingrese la cédula (sólo números): ";
				std::cin >> aux.ced;
				std::cout << "Ingrese el nombre: ";
				std::cin >> aux.nom;
				std::cout << "Ingrese la carrera: ";
				std::cin >> aucarr;
//				Check `which_lookr()' to understand what's happening here
				aux.carr = which_lookr(aucarr, data[2].what, data[2].where);
				std::cout << "Indice Académico: ";
				std::cin >> aux.ind;
				fwrite (aux, sizeof(aux), 1, f);
				std::cout << "¿Desea agregar otro alumno? <s/n> ";
				std::cin >> q;
			}
			break;
		case "materias":
			std::cout << "A continuación se le pedirá información para" << endl
				<< "llenar los campos del archivo para materias." << endl;
			REG_MATERIA aux;
			while ((q=='s')||(q=='S')) {
				std::cout << "Ingrese el nombre de la materia: ";
				std::cin >> aux.des;
				std::cout << "Ingrese el código de la materia: ";
				std::cin >> aux.cod;
				fwrite (aux, sizeof(aux), 1, f);
				sdt::cout << "¿Desea agregar otra materia? <s/n> ";
				std::cin >> q;
			}
			break;
		case "carrera":
			std::cout << "A continuación se le pedirá información para" << endl
				<< "llenar los campos del archivo para carreras." << endl;
			REG_CARRERA aux;
			while ((q=='s')||(q=='S')) {
				std::cout << "Ingrese el nombre de la carrera: ";
				std::cin >> aux.des;
				std::cout << "Ingrese el código de la carrera: ";
				std::cin >> aux.cod;
				fwrite (aux, sizeof(aux), 1, f);
				std::cout << "¿Desea ingresar otra carrera? <s/n> ";
				std::cin >> q;
			}
			break;
		case "notas":
			std::cout << "A continuación se le pedirá información para" << endl
				<< "lenar los campos del archivo para notas." << endl;
			REG_NOTA aux;
			int auxcid;
			string auxmat;
			while ((q=='s')||(q=='S')) {
				std::cout << "Ingrese cédula: ";
				std::cin >> auxcid;
				std::cout << "Ingrese materia: ";
				std::cin >> auxmat;
				std::cout << "Ingrese período (sin guiones): ";
				std::cin >> aux.per;
				std::cout << "Ingrese la nota: ";
				std::cin >> aux.not;
//				Mixing ced and class code
				aux.ced = (auxcid*100) + which_lookr (auxmat, data[3].what, data[3].where);
				fwrite (aux, sizeof(aux), 1, f);
				std::cout << "¿Desea ingresar otra nota? <s/n> ";
				std::cin >> q;
			}
			break;
		default:
			return (-2); /* This error means the option wasn't valid */
	}
	return (0); /* This is returned when succesfull */
	
}

/*
 * Name: open_files
 * Description: Open needed files
 * Args:
 * Input:
 * Output:
 */
extern void open_files (FILE *falu, FILE *fnot, FILE *fcar, FILE *fmat, d[]) {
	char o;
	std::cout << "¿Los archivos están en los lugares estándar? <s/n>";
	std::cin >> o;
	if ((o=='S')||(o=='s')) {
		data[0].where = "ALUMNO.DAT";
		data[1].where = "NOTAS.DAT";
		data[2].where = "CARRERA.DAT";
		data[3].where = "MATERIA.DAT";
	} else {
		string aux;
		std::cout << "¿Donde quiere colocar los datos de los alumnos?";
		std::cin >> aux;
		data[0].where = aux;
		std::cout << "¿Donde quiere colocar los datos de las notas?";
		std::cin >> aux;
		data[1].where = aux;
		std::cout << "¿Donde quiere colocar los datos de las carreras?";
		std::cin >> aux;
		data[2].where = aux;
		std::cout << "¿Donde quiere colocar los datos de las materias?";
		std::cin >> aux;
		data[3].where = aux;
	}
	
	std::cout << "Abriendo los archivos..." << endl;
	*falu = fopen (data[0].where, "rb+");
	*fnot = fopen (data[1].where, "rb+");
	*fcar = fopen (data[2].where, "rb+");
	*fmat = fopen (data[3].where, "rb+");
	if ((*falu==NULL)||(*fnot==NULL)||(*fcar==NULL)||(*fmat==NULL)) {
		std::cout << "Parece que es la primera vez que usa la" << endl
			<< "aplicación o algunos archivos no existen, " << endl
			<< "crearemos los archivos de data que falten." << endl;
		if (*fcar==NULL) {
			std::cout << "Creando " << data[2].where << endl;
			*fcar = fopen (data[2].where, "wb+");
			fill_data (fcar, data[2].what, data);
		}
		if (*fmat==NULL) {
			std::cout << "Creando " << data[3].where << endl;
			*fmat = fopen (data[3].where, "wb+");
			fill_data (fmat, data[3].what, data);
		}
		if (*falu==NULL) {
			std::cout << "Creando " << data[0].where << endl;
			*falu = fopen (data[0].where, "wb+");
			fill_data (falu, data[0].what, data);
		}
		if (*fnot==NULL) {
			std::cout << "Creando " << data[1].where << endl;
			*fnot = fopen (data[1].where, "wb+");
			fill_data (fnot, data[1].what, data);
		}

	}
}



#endif	/* _WRITERS_H */

