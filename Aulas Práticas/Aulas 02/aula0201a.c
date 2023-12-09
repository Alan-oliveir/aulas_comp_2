/********************************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao da funcao CalcularTermoSerieFibonacci utilizando recursividade.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:19:18 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2022/07/31 21:19:18  alan.goncalves
 * Initial revision
 *
 * 
 ********************************************************************************************/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us numeroTermoDesejado)
{
	ull valorTermoSerieFibonacci;

	if (numeroTermoDesejado == 0)
		return 0;

	if (numeroTermoDesejado == 1 || numeroTermoDesejado == 2)
		return 1;

	valorTermoSerieFibonacci = (CalcularTermoSerieFibonacci (numeroTermoDesejado - 1) + CalcularTermoSerieFibonacci (numeroTermoDesejado - 2));

	return valorTermoSerieFibonacci;
}

/* $RCSfile: aula0201a.c,v $ */
