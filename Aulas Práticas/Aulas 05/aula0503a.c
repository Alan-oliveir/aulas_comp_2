/*******************************************************************
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
 * $Author: alan.goncalves $
 * $Date: 2022/08/14 01:52:36 $
 * $Log: aula0503a.c,v $
 * Revision 1.1  2022/08/14 01:52:36  alan.goncalves
 * Initial revision
 *
 *
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0501.h"

#define NUMERO_ARGUMENTOS	                  COMPRIMENTO_RG + 1

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define COMPRIMENTO_ARGUMENTO_INVALIDO            2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO       3
#define ERRO_EXECUTANDO_FUNCAO                    4

#define EOS                                       '\0'

int
main (int argc, char *argv [])
{
	unsigned indice;
	byte digitosRg [COMPRIMENTO_RG]; 
	char *verificacao;
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
	
		digitosRg [indice - 1] = (byte) strtoul (argv [indice], &verificacao, 10);
		
		if (*verificacao != EOS )			
		{
			printf ("Argumento contem o caractere invalido: %c.\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}
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

	if (codigoRetorno == digitoVerificadorValido)
		printf (" - valido.\n\n");
	if (codigoRetorno == digitoVerificadorInvalido)
		printf (" - invalido.\n\n");
	
	return OK;

} /* main */

/* $RCSfile: aula0503a.c,v $ */
