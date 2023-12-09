/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao DesenharReta.
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

#define EOS              		                '\0'
#define NUMERO_ARGUMENTOS				        10

int
main (int argc, char *argv[]) 
{
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	unsigned numeroMaximoLinhas, numeroMaximoColunas;

	unsigned indice, indiceLinha, indiceColuna;
 
	unsigned argumentoAtual, numeroArgumentoCli [NUMERO_ARGUMENTOS - 1];
	
	tipoErros codigoRetorno;
	
    unsigned numeroVertices;
	
	unsigned linhasVertices [NUMERO_MAXIMO_LINHAS], colunasVertices [NUMERO_MAXIMO_LINHAS];
	
	unsigned linhaPonto, colunaPonto;

	float percentualDefeituosos, percentualApagados;

	useconds_t tempoEspera;

	char *verificacao;

	tipoErros verificaErros;

	system ("clear");

	for (indice = 1; indice < NUMERO_ARGUMENTOS; indice++)
    {
		if (indice == 4 || indice == 5) 
        {
            argumentoAtual = strtof (argv[indice], &verificacao);
        }

        else
        {
            argumentoAtual = strtoul (argv[indice], &verificacao, 10);
        }

		if (*verificacao != END_OF_STRING) 
        {
			printf ("Erro (%u): Caractere ('%c') Invalido!\n\n", ARGUMENTO_INVALIDO, *verificacao);

			exit (ARGUMENTO_INVALIDO);
		} 
        
        else if (argv[indice][0] == '-') 
        {
			printf ("Erro (%u): Argumentos negativos são invalidos!\n\n", ARGUMENTO_INVALIDO);

			exit (ARGUMENTO_INVALIDO);
		}

		numeroArgumentoCli [indice - 1] = argumentoAtual;
	}

    tempoEspera = numeroArgumentoCli [0];
	numeroMaximoLinhas = numeroArgumentoCli [1];
	numeroMaximoColunas = numeroArgumentoCli [2];
    percentualDefeituosos = numeroArgumentoCli [3];
    percentualApagados = numeroArgumentoCli [4];
    linhaPonto = numeroArgumentoCli [5];
    colunaPonto = numeroArgumentoCli [6];
    numeroVertices = numeroArgumentoCli [7];

    if (argc != NUMERO_ARGUMENTOS + 2 * numeroVertices) 
    {
		printf ("Erro (%u): Numero Argumentos Invalido! | Pedidos: %u | Fornecidos: %u\n\n",
		NUMERO_ARGUMENTOS_INVALIDO, NUMERO_ARGUMENTOS + 6, argc);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	indiceLinha = 0;
	indiceColuna = 0;
	
    for (indice = NUMERO_ARGUMENTOS; indice < NUMERO_ARGUMENTOS + numeroVertices * 2; indice++)
    {
        if (indice % 2 != 0)
        {
            linhasVertices [indiceAuxiliarLinha] = strtoul (argv [indice], &verificacao, BASE_DECIMAL);
            indiceLinha++;
        }        

        else
        {
            colunasVertices [indiceAuxiliarColuna] = strtoul (argv [indice], &verificacao, BASE_DECIMAL);
            indiceColuna++;
        }        

        if (*verificacao != END_OF_STRING)
        {
            printf ("Erro (%u): Entrada (%c) invalida!\n\n", ARGUMENTO_INVALIDO, *verificacao);
            exit (ARGUMENTO_INVALIDO);
        }        
    }

    codigoRetorno = GerarDistribuicaoInicial(monitor, numeroMaximoLinhas, numeroMaximoColunas, percentualDefeituosos, percentualApagados);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    
   codigoRetorno = LimparMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    
	codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVertices, linhasVertices, colunasVertices);
   
    if (codigoRetorno != 0)
        exit (codigoRetorno);     
	
	codigoRetorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    
    codigoRetorno = PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaPonto, colunaPonto);

    if (codigoRetorno != 0)
        exit (codigoRetorno);
    
	return OK;

} /* main */

/* $RCSfile$ */ 