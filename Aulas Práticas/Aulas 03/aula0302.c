/*************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CalcularMaximoDivisorComum
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/31 21:51:42 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2022/07/31 21:51:42  alan.goncalves
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
#include <limits.h>
#include <errno.h>
#include <math.h>

#include "aula0301.h"

#define OK                                             0
#define NUMERO_ARGUMENTOS_INVALIDO                     1 
#define ARGUMENTO_INVALIDO                             2
#define ARGUMENTO_NEGATIVO                             3
#define BASE_INVALIDA                                  4
#define CARACTERE_INVALIDO                             5
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO       6

#define NUMERO_ARGUMENTOS                              3

#define END_OF_STRING                                  '\0' /* igual ao byte 0 */

int
main (int argc, char *argv[])
{
	char *verificacao;

	ull numeroInteiroA, numeroInteiroB, maximoDivisorComum;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <inteiro-nao-negativo-longo-longo> <inteiro-nao-negativo-longo-longo>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1][0] == '-')
	{
		printf ("Argumento invalido. Primeiro caractere invalido: \'-\'\n" );
		exit (ARGUMENTO_NEGATIVO);
	}

	if (argv [2][0] == '-')
	{
		printf ("Argumento invalido. Primeiro caractere invalido: \'-\'\n" );
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroInteiroA = strtoull (argv [1], &verificacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("Base invalida\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned long long (%llu).\n", ULLONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	if (*verificacao != END_OF_STRING)
	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}

	numeroInteiroB = strtoull (argv [2], &verificacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("Base invalida\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned long long (%llu).\n", ULLONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	if (*verificacao != END_OF_STRING)

	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}
	
	/* Teste de erro numeroInteiroA == 0 e numeroInteiroB == 0 realizado no programa de testes */
	if ((numeroInteiroA == 0) && (numeroInteiroB == 0))
	{
		printf ("Argumento invalido. Ambos os inteiros nao podem ser iguais a 0. \n");
		exit (ARGUMENTO_INVALIDO);
	}

	maximoDivisorComum = CalcularMaximoDivisorComum (numeroInteiroA, numeroInteiroB);

	if (maximoDivisorComum == INFINITY)
	{
		printf ("Valor maximo do tipo unsigned long long (%llu) foi excedido para o valor do MDC entre: (%llu) e (%llu).\n", ULLONG_MAX, numeroInteiroA, numeroInteiroB);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	printf ("MDC entre %llu e %llu eh: %llu\n", numeroInteiroA, numeroInteiroB, maximoDivisorComum);

	return OK;
} /* main */

/* $RCSfile: aula0302.c,v $ */
