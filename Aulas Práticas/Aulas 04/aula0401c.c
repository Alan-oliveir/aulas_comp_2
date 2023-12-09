/*************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao da funcao Calcular Exponencial utilizando o laco de repeticao for.  
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 01:26:15 $
 * $Log: aula0401c.c,v $
 * Revision 1.2  2022/08/01 01:26:15  alan.goncalves
 * Computacao II - aulas praticas - aula04
 * Correcao na funcao CalcularExponencial usando for.
 *
 * Revision 1.1  2022/08/01 01:21:36  alan.goncalves
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
	
	/* teste valorExpoente < 0 */
	if (valorExpoente < 0)
		expoenteAuxiliar = valorExpoente * -1;
	else
		expoenteAuxiliar = valorExpoente;

	for (resultado = 1; expoenteAuxiliar > 0; expoenteAuxiliar--)
		resultado *= valorBase;

	if (valorExpoente < 0)
		resultado = (1.0/resultado);

	return resultado;

} /* CalcularExponencial */

/* $RCSfile: aula0401c.c,v $ */
