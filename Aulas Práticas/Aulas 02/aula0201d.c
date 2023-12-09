/***********************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao CalcularTermoSerieFibonacci utilizando a estrutura while 
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:34:43 $
 * $Logs$
 * 
 ***********************************************************************************************/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us numeroTermoDesejado)
{
	ull valorTermoSerieFibonacci;
	ull valorTermoAnterior;
	ull valorTermoAuxiliar;
	us contador;

	if (numeroTermoDesejado == 0)
		return 0;
	
	if (numeroTermoDesejado == 1)
		return 1;
	
	valorTermoSerieFibonacci = 1;
	valorTermoAuxiliar = 0;
	contador = 2;

	 while (contador <= numeroTermoDesejado)
	 {
		valorTermoAnterior = valorTermoAuxiliar;
		valorTermoAuxiliar = valorTermoSerieFibonacci;
		valorTermoSerieFibonacci = valorTermoAuxiliar + valorTermoAnterior;

		contador++;
	 }

	return valorTermoSerieFibonacci;
}

/* $RCSfile: aula0201d.c,v $ */
