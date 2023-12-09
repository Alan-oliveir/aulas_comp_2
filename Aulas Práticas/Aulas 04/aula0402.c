/************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CalcularExponencial
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/01 00:01:16 $
 * $Log: aula0402.c,v $
 * Revision 1.2  2022/08/01 00:01:16  alan.goncalves
 * Computacao II - Aulas Praticas - aula04
 * Correcao no programa de testes da funcao CalcularExponencial.
 *
 * Revision 1.1  2022/07/31 23:28:53  alan.goncalves
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
#include <float.h>


#include "aula0401.h"

#define OK                                             0
#define NUMERO_ARGUMENTOS_INVALIDO                     1
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO                   2
#define CARACTERE_INVALIDO                             3
#define BASE_INVALIDA                                  4
#define VALOR_MAXIMO_INT_EXCEDIDO                      5
#define VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO              6

#define NUMERO_ARGUMENTOS                              3

#define EOS                                            '\0' /* igual ao byte 0 */

int
main (int argc, char **argv)
{
	char *verificacao;
	double base;
	int expoente;
	long double resultadoExponencial;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <numero-real> <numero-inteiro>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	base = strtod (argv [1], &verificacao);
	
	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para double (%.10e).\n", DBL_MAX);
		exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}

	expoente = strtol (argv [2], &verificacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("Base invalida.\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para int (%lu).\n", LONG_MAX);
		exit (VALOR_MAXIMO_INT_EXCEDIDO);
	}

	if (*verificacao != EOS)

	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}
	
	resultadoExponencial = CalcularExponencial (base, expoente);

	if (resultadoExponencial == HUGE_VAL)
	{
		printf ("Valor maximo do tipo long double (%.10Le) foi excedido.\n", LDBL_MAX);
		exit (VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO);
	}

	printf ("%g ^ %i: %Lg \n", base, expoente, resultadoExponencial);

	return OK;

} /* main */

/* $RCSfile: aula0402.c,v $ */
