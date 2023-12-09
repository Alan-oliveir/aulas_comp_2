/*************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao CalcularExponencial utilizando recursividade.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 23:58:18 $
 * $Log: aula0401a.c,v $
 * Revision 1.1  2022/07/31 23:58:18  alan.goncalves
 * Initial revision
 *
 * 
 **************************************************************************************/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double valorBase, int valorExpoente)
{

	if ((valorBase == 0) && (valorExpoente < 0))
		return HUGE_VAL;

	if ((valorBase == 0) && (valorExpoente == 0))
		return 1;

	if (valorBase == 0)
		return 0;

	/* Condicao de parada expoente igual a 0 */
	if (valorExpoente == 0)
		return 1;	
	
	/* Condicao de parada expoente igual a 1 */
	if (valorExpoente == 1)
		return valorBase;

	if (valorExpoente < 0)
	{
		valorExpoente *= -1;
		valorBase = (1.0/valorBase);
	}

	return (valorBase * CalcularExponencial (valorBase, valorExpoente -1));

} /* CalcularExponencial */

/* $RCSfile: aula0401a.c,v $ */

