/***********************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao ValidarRg.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0504.h"

#define NUMERO_ARGUMENTOS	                  COMPRIMENTO_RG + 1

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define COMPRIMENTO_ARGUMENTO_INVALIDO            2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO       3
#define ERRO_EXECUTANDO_FUNCAO                    4

int
main (int argc, char *argv [])
{
	unsigned indice;
	char digitosRg [COMPRIMENTO_RG]; 
	tipoErros codigoRetorno;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < argc; indice++)
	{
		if (strlen (argv [indice]) != 1)
		{
			printf ("Argumento #%u apresenta comprimento invalido\n", indice);
			exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
		}
		
		if (argv [indice][0] < '0' || argv [indice][0] > '9')
		{
			printf ("Argumento contem o caractere invalido: %c.\n", argv [indice] [0]);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}
	
		digitosRg [indice - 1] = argv [indice][0];	
	}

	digitosRg [indice] = EOS;

	codigoRetorno = ValidarRg (digitosRg);

	if (codigoRetorno == erroGerarDigitoVerificador)
	{
		printf ("Erro executando a funcao. Erro numero %u\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}

	printf ("Rg: %s", digitosRg);

	if (codigoRetorno == digitoVerificadorValido)
		printf (" - valido.\n\n");
	if (codigoRetorno == digitoVerificadorInvalido)
		printf (" - invalido.\n\n");
	
	return OK;
} 

/* $RCSfilemake$ */
