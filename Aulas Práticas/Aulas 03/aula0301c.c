/***********************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao CalcularMaximoDivisorComum.
 * Esta funcao foi implementada utilizando o laco de repeticao for. 
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 22:06:07 $
 * $Logs$
 * 
 ***********************************************************************/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull numeroInteiroA, ull numeroInteiroB)
{

	ull numeroAuxiliar;

	if (numeroInteiroA == 0)
		return numeroInteiroB;

	if (numeroInteiroB == 0)
		return numeroInteiroA;

	/* Inicializacao da variavel numeroAuxiliar para resolver warning gerado quando utilizado o compilador CLANG no sistema Linux */
	numeroAuxiliar = 1;
	
	for (; numeroAuxiliar != 0;)
	{
		numeroAuxiliar = numeroInteiroA % numeroInteiroB;
		numeroInteiroA = numeroInteiroB;
		numeroInteiroB = numeroAuxiliar;
	}

	return numeroInteiroA;

} /* CalcularMaximoDivisorComum */

/* $RCSfile: aula0301c.c,v $ */
