/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao DecodificarBase32.
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
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_INVALIDO           	    2

#define NUMERO_ARGUMENTOS                   3

#define MAXIMO_BYTES                        2000
#define EOS                                 '\0'

int 
main (int argc, char *argv[])
{
    
    unsigned indice,
             comprimentoString = 0;
             
    unsigned long long numeroBytes [1];

    char *verificacao;

    byte conjuntoBytes [MAXIMO_BYTES];

    tipoAlfabetoBase32 alfabeto;

    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <alfabeto-> <String-Base32>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    alfabeto = strtoull (argv [1], &verificacao, 10);

    if (*verificacao != EOS)
    {
        printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
        exit (ARGUMENTO_INVALIDO);
    }

    if (alfabeto != 0 && alfabeto != 1)
    {
	    printf ("Alfabeto invalido - A entrada deve ser: \n0 - Alfabeto basico\n1 - Alfabeto estendido.\n\n");
	    exit (ARGUMENTO_INVALIDO);
    }

    comprimentoString = 0;

    for (indice = 0; argv [2][indice] != EOS; indice++)
        comprimentoString++;
        
    if (comprimentoString % 8 != 0)
    {
       printf ("String invalida.\n\n");
       exit (ARGUMENTO_INVALIDO);
    }

    codigoRetorno = DecodificarBase32 (argv [2], alfabeto, conjuntoBytes, numeroBytes);

    if (codigoRetorno != ok)
    {
        printf ("String invalida.\n\n");
	    exit (ARGUMENTO_INVALIDO);
    }
    
    printf ("\nResultado decodificado: ");

    for (indice = 0; indice < numeroBytes [0]; indice++)
        printf ("%x ", conjuntoBytes [indice]);
    
    printf ("\n\n");

    return OK;
	
} /* main */

/* $RCSfile$ */ 