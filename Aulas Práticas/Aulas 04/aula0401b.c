/*******************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao da funcao Calcular Exponencial utilizando o laco de repeticao do .. while.  
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 00:55:30 $
 * $Log: aula0401b.c,v $
 * Revision 1.2  2022/08/01 00:55:30  alan.goncalves
 * Computacao II - Aulas Praticas - Aula04
 * Correcao na funcao CalcularExponencial usando do .. while.
 *
 * Revision 1.1  2022/08/01 00:51:20  alan.goncalves
 * Initial revision
 *
 *
 ********************************************************************************************************/

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
	
	/* Testa se expoente eh negativo */
	if (valorExpoente < 0)
		expoenteAuxiliar = valorExpoente * -1;
	else
		expoenteAuxiliar = valorExpoente;

	do
	{
		resultado = resultado * valorBase;
		expoenteAuxiliar--;
	} 
	while (expoenteAuxiliar > 0);

	if (valorExpoente < 0)
		resultado = (1.0/resultado);

	return resultado;

} /* CalcularExponencial */

/* $RCSfile: aula0401b.c,v $ */
