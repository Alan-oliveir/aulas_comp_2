/*******************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao ValidarRg - versao com 1 argumento.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ********************************************************************************************/

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
	unsigned indice; /* variavel da posicao do vetor digitosRg */
	char digitosRg [COMPRIMENTO_RG];
	tipoErros codigoRetorno;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <XX.XXX.XXX-X>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (strlen (argv [1]) != COMPRIMENTO_RG + 3)
	{
		printf ("Argumento apresenta comprimento invalido\n");
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
	}
	
	/* escrevendo os numeros no vetor digitosRg usados lacos de repeticao */ 
	for (indice = 0; indice < 2; indice++)
		digitosRg [indice] =  argv [1][indice];
	for (indice = 3; indice < 6; indice++)
		digitosRg [indice - 1] = argv [1][indice];
	for (indice = 7; indice < 10; indice++)
		digitosRg [indice - 2] = argv [1][indice];
	digitosRg [COMPRIMENTO_RG - 1] = argv [1][COMPRIMENTO_RG + 2];
	digitosRg [COMPRIMENTO_RG] = EOS;

	/* Teste se os digitos estao no intervalo 0 .. 9 */
	for (contador = 0; contador < COMPRIMENTO_RG - 1; contador++)
		if (digitosRg [contador] < '0' || digitosRg [contador] > '9')
		{
			printf ("Argumento contem o caractere invalido: #%u na posicao #%u.\n", digitosRg [contador], contador);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);	
		}

	codigoRetorno = ValidarRg (digitosRg);

	if (codigoRetorno == erroGerarDigitoVerificador)
	{
		printf ("Erro executando a funcao. Erro numero %u\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}
	
	printf ("RG: %s", digitosRg);
	if (codigoRetorno == digitoVerificadorInvalido)
		printf (" - invalido.\n\n");
	if (codigoRetorno == digitoVerificadorValido)
		printf (" - valido.\n\n");
	
	return OK;
	
} /* main */

/* $RCSfile$ */
