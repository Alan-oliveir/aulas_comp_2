/****************************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci implementada utilizando a estrutura do...while 
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:26:41 $
 * $Logs$
 * 
 ****************************************************************************************************************/

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

	do
	{
		valorTermoAnterior = valorTermoAuxiliar;
		valorTermoAuxiliar = valorTermoSerieFibonacci;
		valorTermoSerieFibonacci = valorTermoAuxiliar + valorTermoAnterior;

		contador++;
	} while (contador <= numeroTermoDesejado);
	
	return valorTermoSerieFibonacci;
}

/* $RCSfile: aula0201b.c,v $ */
