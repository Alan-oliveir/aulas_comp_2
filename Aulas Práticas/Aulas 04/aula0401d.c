/**************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao da funcao Calcular Exponencial utilizando o laco de repeticao while.  
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 01:39:15 $
 * $Log: aula0401d.c,v $
 * Revision 1.2  2022/08/01 01:39:15  alan.goncalves
 * Computacao II - Aulas Praticas - Aula 04.
 * correcao da funcao CalcularExponencial usando while.
 *
 * Revision 1.1  2022/08/01 01:38:14  alan.goncalves
 * Initial revision
 *
 *
 **************************************************************************************************/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double valorBase, int valorExpoente)
{
	long double resultado;
	int expoenteAuxiliar;

	if ((valorBase == 0) && (valorExpoente < 0))
		return HUGE_VAL;

	if ((valorBase == 0) && (valorExpoente == 0))
		return 1;

	if (valorBase == 0)
		return 0;

	if (valorExpoente == 0)
		return 1;

	resultado = 1;
	
	if (valorExpoente < 0)
		expoenteAuxiliar = valorExpoente * -1;
	else
		expoenteAuxiliar = valorExpoente;

	while (expoenteAuxiliar > 0)
	{
		resultado *= valorBase;
		expoenteAuxiliar--;
	}

	if (valorExpoente < 0)
		resultado = (1.0/resultado);

	return resultado;

} /* CalcularExponencial */

/* $RCSfile: aula0401d.c,v $ */
