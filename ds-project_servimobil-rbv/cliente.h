/*
 * File:   cliente.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 14, 2008, 12:45 PM
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

#ifndef CLIENTE_H
#define	CLIENTE_H
#include <string>
#include <cstdio>
#include "estructuras.h"
/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */
class cliente {
private:
	FILE *f1; /* Lista de espera */
	FILE *f2; /* Personas activas en el plan */
public:
	cliente (FILE *archivo, FILE *archivo2) { f1 = archivo; f2 = archivo2; }
	int amortizacion (int ci);
	bool lista_query (int ci);
	bool activos_query (int ci)
	bool lista_add (std::string nom_cliente, int ci_cliente, int marca, int modelo, std::string estado);
	bool asignacion_auto (int ci);
	void swappr (r_clientese a, r_clientes &b);
	void reorganizr (FILE *f);
};

int cliente::amortizacion (int ci) {
	if (f2 == NULL)
		return (-1); /* No hay archivo */
	else {
		rewind(f2);
		r_clientes buf;
		while (!feof(f2)) {
			fread (buf, sizeof(buf), 1, f2);
			if (buf.ci_cliente == ci) {
				buf.credito = buf.credito - buf.cuota - (buf.credito * (((float)buf.tasa / (float)100) / 12 ) );
				return (0); /* Succesful */
			}
		}
	}
	return (-2); /* Si no encontró nada en el archivo */
}
/* Retorna true si el cliente está en lista o tiene un crédito activo */
bool cliente::lista_query (int ci) {
	if (f1==NULL)
		return (false);
	else {
		rewind (f1);
		r_clientese buf;
		while (!feof(f1)) {
			fread (buf, sizeof(buf), 1, f1);
			if (buf.ci_cliente == ci)
				return (true);
		}
	}
	if (f2 == NULL)
		return (false); /*Si no está en lista de espera y no hay nadie en el plan pues no puede estar */
	else {
		rewind (f2);
		r_clientes buf;
		while (!feof(f2)) {
			fread (buf, sizeof(buf), 1, f2);
			if (buf.ci_cliente == ci)
				return (true);
		}
	}
	return (false);	/* If everything else fails */
}

bool cliente::activos_query (int ci) {
	if (f2 == NULL)
		return (false); /*Si no está en lista de espera y no hay nadie en el plan pues no puede estar */
	else {
		rewind (f2);
		r_clientes buf;
		while (!feof(f2)) {
			fread (buf, sizeof(buf), 1, f2);
			if (buf.ci_cliente == ci)
				return (true);
		}
	}
	return (false);	/* If everything else fails */
}

bool cliente::lista_add (std::string nom_cliente, int ci_cliente, int marca, int modelo, std::string estado) {
	if ((!lista_query(ci_cliente))&&(f1 != NULL) {
		r_clientese buf;
		buf.nom_cliente = nom_cliente;
		buf.ci_cliente = ci_cliente;
		buf.codmarca = marca;
		buf.codmodelo = modelo;
		buf.estado = estado;
		fseek (f1, sizeof(buf), SEEK_END);
		fwrite (buf, sizeof(buf), 1, f1);
		return (true);
	} else
		return (false);
}

bool cliente::asignacion_auto (int ci, float precio, float inicial, char tipo) {
	if (f1==NULL)
		return (false);
	else {
		rewind (f1);
		r_clientese buf;
		int c1 = -1;
		while !(feof(f1)) {
			c1++;
			fread (buf, sizeof(buf), 1, f1);
			if (buf.ci_cliente == ci) {
				r_clientes buff;
				fseek (f2, sizeof(buff), SEEK_END);
				swapper (buf, buff);
				buff.montodecompra = precio;
				buff.credito = precio - inicial;
				buff.cuota = buff.credito / (float)60;
				if (tipo == 'C')
					buff.tasa = 16;
				else
					buff.tasa = 12;
				fwrite (buff, sizeof(buff), 1, f2); /* Escribiendo en los activos */
				r_clientese cleaner;
				fseek (f1, c1 * sizeof(buf), SEEK_SET);
				fwrite (cleaner, sizeof(cleaner), 1, f1); /* Dejando el espacio en blanco */
				reorganizr (f1); /* Reorganizando el archivo borrado */
				return (true);
			}
		}
	}
	return (false); /* If everything else fails */
}

void cliente::swappr (r_clientese a, r_clientes &b) {
	b.ci_cliente = a.ci_cliente;
	b.codmarca = a.codmarca;
	b.codmodelo = a.codmodelo;
	b.estado = a.estado;
	b.nom_cliente = a.nom_cliente;
}

void cliente::reorganizr (FILE *f) {
	FILE *tmp;
	tmp = tmpfile ();
	rewind (f);
	rewind (tmp);
	r_clientese buf;
	while (!feof(f)) {
		fread (buf, sizeof(buf), 1, f);
		if !(buf.estado.empty()) /* Re-escribiendo si es que estado no está vacío */
			fwrite (buf, sizeof(buf), 1, tmp);
	}
	fclose(f);
	f = fopen ("clienteslista.dat", "w+b");
	rewind (tmp);
	/* Ahora a pasar toda esa info a `*f' */
	while (!feof(tmp)) {
		fread (buf, sizeof(buf), 1, tmp);
		fwrite (buf, sizeof(buf), 1, f);
	}
}

#endif	/* CLIENTE_H */

