/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao DecodificarBase64.
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

#define OK                     	            0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_INVALIDO           	    2

#define MAXIMO_BYTES                        2000
#define NUMERO_ARGUMENTOS                   3
#define EOS                                 '\0'

int 
main (int argc, char *argv[])
{
    
    unsigned indice = 0;
             
    unsigned long long numeroBytes;

    char *verificacao;

    byte conjuntoBytes [MAXIMO_BYTES];

    tipoFinalLinha indicadorFinalLinha;

    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <indicadorFinalLinha> <String-Base64>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    indicadorFinalLinha = (unsigned int) strtoul (argv [1], &verificacao, 10);

    if (*verificacao != EOS)
    {
        printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
        exit (ARGUMENTO_INVALIDO);
    }

    if (indicadorFinalLinha != 0 && indicadorFinalLinha != 1)
    {
	    printf ("Indicador Final de Linha invalido - A entrada deve ser: \n0 - Desabilitado\n1 - Habilitado.\n\n");
	    exit (ARGUMENTO_INVALIDO);
    }

    codigoRetorno = DecodificarBase64 (argv[2], indicadorFinalLinha, conjuntoBytes, &numeroBytes);

    if (codigoRetorno != ok)
    {
        printf ("String invalida.\n\n");
	    exit (ARGUMENTO_INVALIDO);
	}    

    printf ("\nResultado decodificado: ");

    while (conjuntoBytes [indice] != EOS)
    {		
		printf ("%X ", conjuntoBytes [indice]);
		indice++;
	}

    printf ("\n\n");

    return OK;
	
} /* main */

/* $RCSfile$ */ 