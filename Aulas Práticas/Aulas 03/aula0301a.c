/***********************************************************************
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao de funcao CalcularMaximoDivisorComum. 
 * Esta implementacao da funcao utiliza recursividade. 
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:50:20 $
 * $Logs$
 ***********************************************************************/

#include "aula0301.h" 

ull
CalcularMaximoDivisorComum (ull numeroInteiroA, ull numeroInteiroB)
{
	ull restoEntradas;
	
	if (numeroInteiroA == 0)
		return numeroInteiroB;

	if (numeroInteiroB == 0)
		return numeroInteiroA;
		
	restoEntradas = (numeroInteiroA % numeroInteiroB);

	if (restoEntradas != 0)
		return CalcularMaximoDivisorComum (numeroInteiroB, restoEntradas);

	return numeroInteiroB;

} /* CalcularMaximoDivisorComum */


/* $RCSfile: aula0301a.c,v $ */
