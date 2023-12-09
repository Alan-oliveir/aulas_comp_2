/************************************************************************************
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
 **************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0501.h"

#define NUMERO_ARGUMENTOS	                  2

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define COMPRIMENTO_ARGUMENTO_INVALIDO            2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO       3
#define ERRO_EXECUTANDO_FUNCAO                    4

#define EOS                                       '\0'

int
main (int argc, char *argv [])
{
	unsigned contador;
	unsigned indice; /* variavel da posicao do vetor digitosRg */
	byte digitosRg [COMPRIMENTO_RG];
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
		digitosRg [indice] = (byte) argv [1][indice] - '0';
	for (indice = 3; indice < 6; indice++)
		digitosRg [indice - 1] = (byte) argv [1][indice] - '0';
	for (indice = 7; indice < 10; indice++)
		digitosRg [indice - 2] = (byte) argv [1][indice] - '0';
	digitosRg [COMPRIMENTO_RG - 1] = (byte) argv [1][COMPRIMENTO_RG + 2] - '0';

	/* Teste se os digitos estao no intervalo 0 .. 9 */
	for (contador = 0; contador < COMPRIMENTO_RG - 1; contador++)
		if (digitosRg [contador] < 0 || digitosRg [contador] > 9)
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
	
	/* codigo que exibe o RG completo no formato "XX.XXX.XXX-X" */
	printf ("RG: ");
	for (indice = 0; indice < 2; indice++)
		printf ("%u", digitosRg [indice]);	
	printf (".");
	for (; indice < 5; indice++)
		printf ("%u", digitosRg [indice]);	
	printf (".");
	for (; indice < 8; indice++)
		printf ("%u", digitosRg [indice]);	
	printf ("-%u", digitosRg [indice]);

	if (codigoRetorno == digitoVerificadorInvalido)
		printf (" - invalido.\n\n");
	if (codigoRetorno == digitoVerificadorValido)
		printf (" - valido.\n\n");
	
	return OK;
	
} /* main */

/* $RCSfile: aula0503b.c,v $ */
