/***************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Prototipo da funcao CalcularExponencial
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 15:43:14 $
 * $Log: aula0403a.c,v $
 * Revision 1.1  2022/08/01 15:43:14  alan.goncalves
 * Initial revision
 *
 * 
 **************************************************************/

#ifdef DEPURACAO
#include <stdio.h>
#endif

#include "aula0401.h" 

float
CalcularSerieHarmonicaAlternada (unsigned short int numero)
{
	float termoAtual;

	if (numero == 0)
		return 0;
	else if (numero == 1)
		return 1;

	termoAtual = CalcularExponencial ((1.0/numero), numero);

	#ifdef DEPURACAO
	printf ("%hu: %g\n", numero, termoAtual);
	#endif

	if (numero % 2 == 0)
		return CalcularSerieHarmonicaAlternada (numero - 1) - termoAtual;

	return CalcularSerieHarmonicaAlternada (numero - 1) + termoAtual;

} /* CalcularSerieHarmonicaAlternada */

/* $RCSfile: aula0403a.c,v $ */
