/********************************************************************************************** 
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implemnetacao da funcao CalcularSerieHarmonicaAlternada usando do .. while
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 18:04:22 $
 * $Log: aula0403b.c,v $
 * Revision 1.1  2022/08/01 18:04:22  alan.goncalves
 * Initial revision
 *
 * 
**********************************************************************************************/

#include "aula0401.h"

float CalcularSerieHarmonicaAlternada (unsigned short numero)
{
	float termoAtual;
	float resultadoSerie = 0;

	int verificacaoSerie = 1;

	if (numero == 0)
		return 0;
	
	do 
	{
		termoAtual = CalcularExponencial ((1.0/verificacaoSerie), verificacaoSerie);

		if (verificacaoSerie % 2 == 0) 
			resultadoSerie -= termoAtual;						
		else
			resultadoSerie += termoAtual;
		
		verificacaoSerie++;		
	} 
	while (verificacaoSerie <= numero);

	return resultadoSerie;
	
} /* CalcularSerieHarmonicaAlternada */

/* $RCSfile: aula0403b.c,v $ */	
