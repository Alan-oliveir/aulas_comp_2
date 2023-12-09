/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao MostrarMonitor
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
#define NUMERO_ARGUMENTOS				        6

int 
main (int argc, char **argv) 
{
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	unsigned numeroMaximoLinhas, numeroMaximoColunas;
	unsigned argumentoAtual, numeroArgumentosCli [NUMERO_ARGUMENTOS - 1];
	unsigned indice;

	float percentualDefeituosos, percentualApagados;

	useconds_t tempoEspera;

	char *verificacao;

	tipoErros codigoRetorno;

	printf ("\n\n");

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < argc; indice++)
    {
		if (indice >= 4)
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

		numeroArgumentosCli [indice - 1] = argumentoAtual;
	} /* for */

    tempoEspera = numeroArgumentosCli [0];
	numeroMaximoLinhas = numeroArgumentosCli [1];
	numeroMaximoColunas = numeroArgumentosCli [2];
    percentualDefeituosos = numeroArgumentosCli [3];
    percentualApagados = numeroArgumentosCli [4];

    codigoRetorno = GerarDistribuicaoInicial(monitor, numeroMaximoLinhas, numeroMaximoColunas, percentualDefeituosos, percentualApagados);

    if (codigoRetorno == 1)
    {
        printf ("Erro (%u): Matriz monitor nula\n\n", MATRIZ_NULA);
        exit(MATRIZ_NULA);
    }

    if (codigoRetorno == 2)
    {
        printf ("Erro (%u): Quantidade de Linhas invalida\n\n", NUMERO_LINHAS_INVALIDO);
        exit(NUMERO_LINHAS_INVALIDO);
    }

    if (codigoRetorno == 3)
    {
        printf ("Erro (%u): Quantidade de Colunas invalida\n\n", NUMERO_COLUNAS_INVALIDO);
        exit(NUMERO_COLUNAS_INVALIDO);
    }

    if (codigoRetorno == 4)
    {
        printf ("Erro (%u): Tempo de espera invalido\n\n", TEMPO_ESPERA_INVALIDO);
        exit(TEMPO_ESPERA_INVALIDO);
    }

    if (codigoRetorno == 5)
    {
        printf ("Erro (%u): Percentual invalido\n\n", PERCENTUAL_INVALIDO);
        exit(PERCENTUAL_INVALIDO);
    }

    codigoRetorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);

    if (codigoRetorno == 1)
    {
        printf ("Erro (%u): Matriz monitor nula\n\n", MATRIZ_NULA);
        exit(MATRIZ_NULA);
    }

    if (codigoRetorno == 2)
    {
        printf ("Erro (%u): Quantidade de Linhas invalida\n\n", NUMERO_LINHAS_INVALIDO);
        exit(NUMERO_LINHAS_INVALIDO);
    }

    if (codigoRetorno == 3)
    {
        printf ("Erro (%u): Quantidade de Colunas invalida\n\n", NUMERO_COLUNAS_INVALIDO);
        exit(NUMERO_COLUNAS_INVALIDO);
    }

    if (codigoRetorno == 4)
    {
        printf ("Erro (%u): Tempo de espera invalido\n\n", TEMPO_ESPERA_INVALIDO);
        exit(TEMPO_ESPERA_INVALIDO);
    }

    if (codigoRetorno == 5)
    {
        printf ("Erro (%u): Percentual invalido\n\n", PERCENTUAL_INVALIDO);
        exit(PERCENTUAL_INVALIDO);
    }    
	
	return OK;
}

/* $RCSfile$ */ 