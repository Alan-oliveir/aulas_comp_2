/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CodificarBase16.
 *
 * $Author$
 * $Date$
 * $Log$
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

#include "aula0801.h"

#define OK                           	    0
#define NUMERO_ARGUMENTOS_INVALIDO	        1
#define ARGUMENTO_INVALIDO           	    2
#define ACIMA_DO_LIMITE_BYTE 		        3
#define ARGUMENTO_NULO		                4

#define NUMERO_MINIMO_ARGUMENTOS            2

#define MAXIMO_BYTES                        2000
#define EOS                                '\0'

int 
main (int argc, char **argv)
{
    
    unsigned indice;
    unsigned long long numeroBytes, numeroRecebido;

    char stringResultado [MAXIMO_BYTES];
	
	char *verificacao;

    byte conjuntoBytes [MAXIMO_BYTES];

    tipoErros codigoRetorno;

    if (argc < NUMERO_MINIMO_ARGUMENTOS)
    {
        printf ("Uso: %s <numero-de-bytes> <byte> <byte> ... <byte>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    numeroBytes = strtoull (argv [1], &verificacao, 10);

    if (*verificacao != EOS)
    {
        printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
        exit (ARGUMENTO_INVALIDO);
    }
    
    if (argc != numeroBytes + 2)
    {
        printf ("Uso: %s <numero-de-bytes> <byte> <byte> ... <byte>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    for (indice = 2; indice < numeroBytes + 2; indice++)
    {
        numeroRecebido = strtoull (argv [indice], &verificacao, 10);

        if (*verificacao != EOS)
        {
            printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
            exit (ARGUMENTO_INVALIDO);
        }

	    if (numeroRecebido > 255)
        {
            printf ("O numero recebido por argumento deve ser maior que 0 e menor que 255.\n\n");
            exit (ACIMA_DO_LIMITE_BYTE);
        }

	    conjuntoBytes [indice - 2] = (byte) numeroRecebido;
    } 

    codigoRetorno = CodificarBase16 (conjuntoBytes, numeroBytes, stringResultado);

    if (codigoRetorno == argumentoNulo)
    {
        printf ("Quantidade de bytes de entrada nula\n\n");
	    exit (ARGUMENTO_NULO);
    }

    printf ("\nResultado codificado em Base 16: %s\n\n", stringResultado);

    return OK;
	
} /* main */

/* $RCSfile$ */ 