/*************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Programa de testes da funcao CacularTermoSerieFibonacci.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:20:41 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2022/07/31 21:20:41  alan.goncalves
 * Initial revision
 *
 *
 *************************************************************************/

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
#include <limits.h>
#include <math.h>

#include "aula0201.h"

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define ARGUMENTO_NEGATIVO                        2
#define BASE_INVALIDA                             3
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO       4
#define CARACTERE_INVALIDO                        5
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO      6
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO  7

#define NUMERO_ARGUMENTOS                         2
#define EOS                                       '\0'

int
main (int argc, char *argv [])
{

	unsigned long numeroAuxiliar; /* Variavel auxiliar que recebe o valor da funcao strtoul */
	unsigned short numeroTermoFibonacci;
	unsigned short numeroTermoAuxiliar;
	unsigned long long valorTermoFibonacci;

	char *verificacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <inteiro-nao-negativo>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1] [0] == '-')
	{
		printf ("Este programa nao aceita numeros negativos.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroAuxiliar = strtoul (argv [1], &verificacao, 10);
	if (errno == EINVAL)
	{
		printf ("Base invalida\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned long (%lu).\n", ULONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}

	if (numeroAuxiliar > USHRT_MAX)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned short (%d).\n", USHRT_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

	numeroTermoFibonacci = (unsigned short) numeroAuxiliar;

	for (numeroTermoAuxiliar = 0; numeroTermoAuxiliar <= numeroTermoFibonacci; numeroTermoAuxiliar++)
	{
		valorTermoFibonacci = CalcularTermoSerieFibonacci (numeroTermoAuxiliar);
			
		if (valorTermoFibonacci == INFINITY)
		{
			printf ("Valor do termo da serie de Fibonacci eh superior ao maximo permitido para unsigned long long");
			exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
		}

		printf ("F (%hu) = %llu\n", numeroTermoAuxiliar, valorTermoFibonacci);
	}

	return OK;

}

/* $RCSfile: aula0202.c,v $ */
