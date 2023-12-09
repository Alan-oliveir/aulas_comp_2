/***********************************************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao GerarDigitosVerificadoresRg - versao com 1 argumento e strings.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0504.h"

#define NUMERO_ARGUMENTOS	                  2

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define COMPRIMENTO_ARGUMENTO_INVALIDO            2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO       3
#define ERRO_EXECUTANDO_FUNCAO                    4

int
main (int argc, char *argv [])
{
	unsigned contador;
	char digitosRg [COMPRIMENTO_RG];
	char digitoVerificadorRg;
	tipoErros codigoRetorno;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <XX.XXX.XXX>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (strlen (argv [1]) != COMPRIMENTO_RG + 1)
	{
		printf ("Argumento apresenta comprimento invalido\n");
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
	}
	
	digitosRg [0] =  argv [1][0];
	digitosRg [1] =  argv [1][1];
	digitosRg [2] =  argv [1][3];
        digitosRg [3] =  argv [1][4];
	digitosRg [4] =  argv [1][5];
	digitosRg [5] =  argv [1][7];
	digitosRg [6] =  argv [1][8];
	digitosRg [7] =  argv [1][9];
	
	for (contador = 0; contador < COMPRIMENTO_RG - 1; contador++)
		if (digitosRg [contador] < '0' || digitosRg [contador] > '9')
		{
			printf ("Argumento contem o caractere invalido: #%u na posicao #%u.\n", digitosRg [contador], contador);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);	
		}

	digitosRg [8] = EOS;
	
	codigoRetorno = GerarDigitosVerificadoresRg (digitosRg, &digitoVerificadorRg);

	if (codigoRetorno != ok)
	{
		printf ("Erro executando a funcao. Erro numero %u\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}
	
	printf ("RG: %s\n\n", digitosRg);

	return OK;
	
} /* main */

/* $RCSfile$ */
