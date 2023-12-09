/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao DesenharPoligono.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/
 
 #ifdef __linux__
#define _XOPEN_SOURCE			        		600
#include <unistd.h>
#undef _XOPEN_SOURCE
#endif

#ifdef __FreeBSD__
#include <unistd.h>
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
#include <limits.h>

#include "aula0701.h"

#define OK   						            0
#define NUMERO_ARGUMENTOS_INVALIDO		        1
#define CARACTERE_INVALIDO				        2
#define VALOR_MAXIMO_FLOAT_EXCEDIDO             3
#define BASE_INVALIDA                           4 
#define VALOR_MAXIMO_LONG_UNSIGNED_EXCEDIDO     5 
#define MATRIZ_NULA                             6
#define NUMERO_LINHAS_INVALIDO                  7
#define NUMERO_COLUNAS_INVALIDO                 8
#define TEMPO_ESPERA_INVALIDO                   9
#define PERCENTUAL_INVALIDO                     10

#define EOS              		                '\0'
#define NUMERO_ARGUMENTOS				        7

int
main (int argc, char *argv[]) 
{
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	unsigned numeroMaximoLinhas, numeroMaximoColunas;	
    unsigned indice;
	unsigned indiceLinha, indiceColuna;	
	unsigned argumentoAtual;	
	unsigned numeroArgumentoCli [NUMERO_ARGUMENTOS - 1];
	unsigned numeroVertices;             
	unsigned linhasVertices [NUMERO_MAXIMO_LINHAS];
    unsigned colunasVertices [NUMERO_MAXIMO_LINHAS];

	float percentualDefeituosos, percentualApagados;

	useconds_t tempoEspera;

	char *verificacao;

	tipoErros codigoRetorno;

	printf ("\n\n");
	
	for (indice = 1; indice < NUMERO_ARGUMENTOS; indice++)
    {
		if (indice == 4 || indice == 5) 
        {
            argumentoAtual = strtof (argv[indice], &verificacao);
			
			if (errno == ERANGE)
			{
				printf ("Valor fornecido ultrapassa o valor maximo permitido para float (%.10e).\n", FLT_MAX);
				exit (VALOR_MAXIMO_FLOAT_EXCEDIDO);
			}

			if (*verificacao != EOS)
			{
				printf ("Argumento contem caractere invalido.\n");
				printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
				exit (CARACTERE_INVALIDO);
			}
        }

        else
        {
            argumentoAtual = strtoul (argv[indice], &verificacao, 10);
			
			if (argv [indice][0] == '-') 
			{
				printf ("Erro: argumentos negativos nao sao permitidos.\n\n");
				exit (CARACTERE_INVALIDO);
			}
			
			if (errno == EINVAL)
			{
				printf ("Base invalida.\n");
				exit (BASE_INVALIDA);
			}

			if (errno == ERANGE)
			{
				printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned long int (%lu).\n", ULONG_MAX);
				exit (VALOR_MAXIMO_LONG_UNSIGNED_EXCEDIDO);
			}
			
			if (*verificacao != EOS)
			{
				printf ("Argumento contem caractere invalido.\n");
				printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
				exit (CARACTERE_INVALIDO);
			}
        }

		numeroArgumentoCli [indice - 1] = argumentoAtual;
	} /* for */
	
	tempoEspera = numeroArgumentoCli [0];
	numeroMaximoLinhas = numeroArgumentoCli [1];
	numeroMaximoColunas = numeroArgumentoCli [2];
    percentualDefeituosos = numeroArgumentoCli [3];
    percentualApagados = numeroArgumentoCli [4];
    numeroVertices = numeroArgumentoCli [5];
	
	if (argc != NUMERO_ARGUMENTOS + 2 * qtdVertices) 
    {
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <numero-vertices> <linha-1> <linha-2> ... <linha-N>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	indiceLinha = 0;
	indiceColuna = 0;
	
	for (indice = NUMERO_ARGUMENTOS; indice < NUMERO_ARGUMENTOS + numeroVertices * 2; indice++)
    {
        if (indice % 2 != 0)
        {
            linhasVertices [indiceLinha] = strtoul (argv [indice], &verificacao, 10);
            indiceLinha++;
        }        

        else
        {
            colunasVertices [indiceColuna] = strtoul (argv [indice], &verificacao, 10);
            indiceColuna++;
        }        

        if (*verificacao != EOS)
        {
            printf ("Argumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
			exit (CARACTERE_INVALIDO);
        }
	}
		
	codigoRetorno = GerarDistribuicaoInicial(monitor, numeroMaximoLinhas, numeroMaximoColunas, percentualDefeituosos, percentualApagados);

    if (codigoRetorno != 0)
		exit (codigoRetorno);
  
    codigoRetorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    
	codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVerticesVertices, linhasVertices, colunasVertices);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    	
    codigoRetorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
  
	return OK;
	
} /* main */

/* $RCSfile$ */