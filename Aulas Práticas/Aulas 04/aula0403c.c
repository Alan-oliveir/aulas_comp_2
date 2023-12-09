/********************************************************************************************** 
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implemnetacao da funcao CalcularSerieHarmonicaAlternada usando for
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 22:22:20 $
 * $Log: aula0403c.c,v $
 * Revision 1.1  2022/08/01 22:22:20  alan.goncalves
 * Initial revision
 *
 * 
**********************************************************************************************/

#include "aula0401.h"

float CalcularSerieHarmonicaAlternada (unsigned short numero)
{
	float termoAtual;
	float resultadoSerie = 0;

	unsigned verificacaoSerie;

	if (numero == 0)
		return 0;
	
	for (verificacaoSerie = 1; verificacaoSerie <= numero; verificacaoSerie++)
	{
		termoAtual = CalcularExponencial ((1.0/verificacaoSerie), verificacaoSerie);
		
		if (verificacaoSerie % 2 == 0) 
			resultadoSerie -= termoAtual;						
		else
			resultadoSerie += termoAtual;
	}
	
	return resultadoSerie;
	
} /* CalcularSerieHarmonicaAlternada */

/* $RCSfile: aula0403c.c,v $ */	
