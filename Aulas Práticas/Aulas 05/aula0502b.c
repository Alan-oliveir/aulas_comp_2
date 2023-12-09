/*************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao GerarDigitosVerificadoresRg - versao com 1 argumento.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/14 01:45:58 $
 * $Log: aula0502b.c,v $
 * Revision 1.2  2022/08/14 01:45:58  alan.goncalves
 * Computacao II - Aulas Praticas - Aula05.
 * Correcao no programa de testes da funcao GerarDigitosVerificadoresRg.
 * Versao do programa com 1 argumento.
 *
 * Revision 1.1  2022/08/10 17:44:50  alan.goncalves
 * Initial revision
 *
 *
 *************************************************************************************************/

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
		printf ("Uso: %s <XX.XXX.XXX>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (strlen (argv [1]) != COMPRIMENTO_RG + 1)
	{
		printf ("Argumento apresenta comprimento invalido\n");
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
	}
	
	digitosRg [0] = (byte) argv [1][0] - '0';
	digitosRg [1] = (byte) argv [1][1] - '0';
	digitosRg [2] = (byte) argv [1][3] - '0';
        digitosRg [3] = (byte) argv [1][4] - '0';
	digitosRg [4] = (byte) argv [1][5] - '0';
	digitosRg [5] = (byte) argv [1][7] - '0';
	digitosRg [6] = (byte) argv [1][8] - '0';
	digitosRg [7] = (byte) argv [1][9] - '0';
	
	for (contador = 0; contador < COMPRIMENTO_RG - 1; contador++)
		if (digitosRg [contador] < 0 || digitosRg [contador] > 9)
		{
			printf ("Argumento contem o caractere invalido: #%u na posicao #%u.\n", digitosRg [contador], contador);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);	
		}

	codigoRetorno = GerarDigitosVerificadoresRg (digitosRg);

	if (codigoRetorno != ok)
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
	printf ("-%u\n\n", digitosRg [indice]);
	
	return OK;

} /* main */

/* $RCSfile: aula0502b.c,v $ */
