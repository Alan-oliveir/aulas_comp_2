/**********************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao CalcularTermoSerieFibonacci utilizando a estrutura de controle for. 
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:30:24 $
 * $Logs$
 * 
 **********************************************************************************************************/

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

	for (contador = 2; contador <= numeroTermoDesejado; contador++)
	{
		valorTermoAnterior = valorTermoAuxiliar;
		valorTermoAuxiliar = valorTermoSerieFibonacci;
		valorTermoSerieFibonacci = valorTermoAuxiliar + valorTermoAnterior;
	}

	return valorTermoSerieFibonacci;
}

/* $RCSfile: aula0201c.c,v $ */
