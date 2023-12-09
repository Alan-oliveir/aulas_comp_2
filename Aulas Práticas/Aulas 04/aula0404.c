/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CalcularSerieHarmonicaAlternada
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 21:58:04 $
 * $Log: aula0404.c,v $
 * Revision 1.4  2022/08/01 21:58:04  alan.goncalves
 * Computacao II - Aulas Praticas - Aula04
 * Modifificacao na exibicao do resultado da funcao CalcularserieHarmonicaAlternada.
 *
 * Revision 1.3  2022/08/01 21:44:56  alan.goncalves
 * Computacao II - Aulas Praticas - Aula04.
 * Correcao do programa de testes da funcao CalcularSerieHarmonicaAlternada.
 *
 * Revision 1.2  2022/08/01 15:44:36  alan.goncalves
 * *** empty log message ***
 *
 * Revision 1.1  2022/08/01 12:08:40  alan.goncalves
 * Initial revision
 *
 *
******************************************************************************/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

#include "aula0401.h"


#define NUMERO_ARGUMENTOS		        	2
#define EOS					        '\0'

#define OK				         	0
#define NUMERO_ARGUMENTOS_INVALIDO               	1
#define ARGUMENTO_INVALIDO	           		2	
#define VALOR_MAXIMO_FLOAT_EXCEDIDO                     3
#define PERCENTUAL_INVALIDO                             4

int 
main (int argc, char *argv[]) 
{

	float percentualSerie;
	float resultadoSerie;
	float resultadoAnterior;
	float diferencaSerie;
	char *verificacao;

	unsigned numero;

	system ("clear");

	printf ("\n\n");

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <numero-real-nao-negativo> \n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1][0] == '-') 
	{
		printf ("Uso: %s <numero-real-nao-negativo> \n", argv[0]);
		printf ("Argumento invalido. Caractere invalido: \'-\'\n");
		exit (ARGUMENTO_INVALIDO);
	}

	percentualSerie = strtof (argv[1], &verificacao);

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para float (%.10f).\n", FLT_MAX);
		exit (VALOR_MAXIMO_FLOAT_EXCEDIDO);
	}
	
	if (*verificacao != EOS) 
	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (percentualSerie == 0 && percentualSerie >= 1)
	{
		printf ("Percentual deve ser maior que 0 e menor que 1.\n");
		exit (PERCENTUAL_INVALIDO);
	}
	
	numero = 0;
	
	resultadoSerie = CalcularSerieHarmonicaAlternada (numero);
	printf ("S(%u) = %f\n\n" , numero, resultadoSerie);
	resultadoAnterior = 1;
	
	diferencaSerie = (resultadoSerie - resultadoAnterior);
	
	if (diferencaSerie < 0)
		diferencaSerie *= -1;
	
	while (diferencaSerie > percentualSerie)
	{
		numero++;
		resultadoAnterior = resultadoSerie;
		resultadoSerie = CalcularSerieHarmonicaAlternada (numero);
		diferencaSerie = (resultadoSerie - resultadoAnterior);
	
		if (diferencaSerie < 0)
			diferencaSerie *= -1;
		
		printf ("S(%u) = %f\n\n" , numero, resultadoSerie);
	}

	printf ("\n\n");
	
	return OK;

} /* main */

/* $RCSfile: aula0404.c,v $ */	
