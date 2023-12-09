/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao DecodificarBase16.
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

#define OK                     	    0
#define NUMERO_ARGUMENTOS_INVALIDO  1
#define ARGUMENTO_INVALIDO          2

#define NUMERO_ARGUMENTOS           2

#define MAXIMO_BYTES                2000
#define EOS                         '\0'

int 
main (int argc, char *argv[])
{
    
    unsigned indice, 
             comprimentoString = 0;
             
    unsigned long long numeroBytes [1];

    byte conjuntoBytes [MAXIMO_BYTES];
	
	tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <String-Base16>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    for (indice = 0; argv [1][indice] != EOS; indice++)
        comprimentoString++;
    
    if ( (comprimentoString % 2) != 0)
    {
       printf ("String invalida\n\n");
       exit (ARGUMENTO_INVALIDO);
    }

    codigoRetorno = DecodificarBase16 (argv [1], conjuntoBytes, numeroBytes);

    printf ("\nResultado decodificado: ");

    for (indice = 0; indice < numeroBytes [0]; indice++)
        printf ("%i ", conjuntoBytes [indice]);
    
    printf ("\n\n");

    return OK;
	
} /* main */

/* $RCSfile$ */ 