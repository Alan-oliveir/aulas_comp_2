/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CodificarBase64.
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
#define NUMERO_ARGUMENTOS_INVALIDO	        1
#define ARGUMENTO_INVALIDO           	    2
#define FORA_DO_LIMITE_BYTE                 3
#define ARGUMENTO_NULO		                4
#define FINAL_LINHA_INVALIDO 		        5

#define BASE_DECIMAL                        10
#define BASE_HEXADECIMAL                    16
#define MAXIMO_BYTES                        2000
#define NUMERO_MINIMO_ARGUMENTOS            3
#define EOS                                 '\0'

int 
main (int argc, char *argv[])
{    
    unsigned indice;
             
    unsigned long long numeroBytes;

    char stringResultado [MAXIMO_BYTES], *verificacao;

    byte conjuntoBytes [MAXIMO_BYTES], byteRecebido;

    tipoFinalLinha finalLinha;

    tipoErros codigoRetorno;

    if (argc < NUMERO_MINIMO_ARGUMENTOS)
    {
        printf ("Uso: %s <indicador-final-linha> <numero-bytes> <byte> <byte> ... <byte>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    finalLinha = (unsigned int) strtoul (argv[1], &verificacao, BASE_DECIMAL);

    if (*verificacao != EOS)
    {
        printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
        exit (ARGUMENTO_INVALIDO);
    }

    if (finalLinha != 0 && finalLinha != 1)
    {
	    printf ("Indicador de final de linha invalido - A entrada deve ser: \n0 - Desabilitado\n1 - Habilitado.\n\n");
	    exit (FINAL_LINHA_INVALIDO);
    }

    numeroBytes = strtoull (argv [2], &verificacao, BASE_DECIMAL);

    if (*verificacao != EOS)
    {
        printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
        exit (ARGUMENTO_INVALIDO);
    }

    if (argc != numeroBytes + 3)
    {
        printf ("Uso: %s <indicador-final-linha> <numero-bytes> <byte> <byte> ... <byte>\n\n", argv [0]);
	    exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    for (indice = 3; indice < numeroBytes + 3; indice++) 
	{
		if (argv[indice][1] != EOS && argv[indice][2] != EOS) 
		{
			printf ("Byte deve estar entre 00 ate FF.\n\n");
			exit (FORA_DO_LIMITE_BYTE); 
		}		

		byteRecebido = (byte) strtoul (argv[indice], &verificacao, BASE_HEXADECIMAL);
		
	    if (*verificacao != EOS) 
		{
			printf ("O Argumento contem um caractere invalido - Primeira ocorrencia: \"%c\"\n\n", *verificacao);
			exit (ARGUMENTO_INVALIDO);
		}

		conjuntoBytes [indice - 3] = byteRecebido;
	} 

    codigoRetorno = CodificarBase64(conjuntoBytes, numeroBytes, finalLinha, stringResultado);

	if (codigoRetorno == argumentoNulo) 
	{
		printf ("Quantidade de bytes de entrada nula\n\n");
		exit (ARGUMENTO_NULO);
	} 

    printf ("\nResultado codificado: %s\n\n", stringResultado);

    return OK;
	
} /* main */

/* $RCSfile$ */ 