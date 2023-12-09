/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CalcularDeterminanteMatriz
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/17 23:32:55 $
 * $Log: aula0604.c,v $
 * Revision 1.1  2022/08/17 23:32:55  alan.goncalves
 * Initial revision
 *
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "aula0601.h"

#define OK				          0
#define NUMERO_ARGUMENTOS_INVALIDO	          1
#define ARGUMENTO_NEGATIVO                        2
#define CARACTERE_INVALIDO                        3
#define BASE_INVALIDA                             4
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO       5
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO      6
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO              7
#define ERRO_EXECUTANDO_FUNCAO                    8

#define NUMERO_ARGUMENTO_MINIMO_ORDEM_MATRIZ      2 /* numero minimo de argumento p/ definir a ordem da matriz */

#define EOS				          '\0' /* igual ao byte 0 */

int 
main (int argc, char **argv) 
{
	char *verificacao;
	unsigned long numeroAuxiliar;
	
	unsigned short ordemMatriz;
	
	double valorDeterminante;
	double * determinante = &valorDeterminante;
	
	tipoErros codigoRetorno;

	system("clear");

	/* Verifica o numero de argumentos referentes ao nome do programa e ordem da matriz */
	if(argc < NUMERO_ARGUMENTO_MINIMO_ORDEM_MATRIZ)
	{
		printf ("\nUso: %s <ordem-matriz> <a11> <a12> ... <amn> \n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* inicio dos testes da ordem da matriz de entrada */
	if (argv [1][0] == '-')
	{
		printf ("Ordem da matriz nao pode ser negativa.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroAuxiliar = strtoul (argv [1], &verificacao, 10);
	if (errno == EINVAL)
	{
		printf ("Base invalida\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned long (%lu).\n", ULONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("Argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
		exit (CARACTERE_INVALIDO);
	}

	if (numeroAuxiliar > USHRT_MAX)
	{
		printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned short (%d).\n", USHRT_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}
	
	ordemMatriz = (unsigned short) numeroAuxiliar; /* Fim dos testes da ordem da matriz de entrada */
		
	if(argc != ((ordemMatriz * ordemMatriz) + 2))
	{
		printf ("\nUso: %s <ordem-matriz> <a11> <a12> ... <amn> \n", argv[0]);
		printf ("Numero de argumentos recebidos: #%i\n", argc);
		printf ("Numero de argumentos necessarios: #%i\n\n", ((ordemMatriz * ordemMatriz) + 2));
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
		
	double matriz [ordemMatriz][ordemMatriz];
	
	unsigned indiceLinha;
	unsigned indiceColuna;
	unsigned indiceAuxiliar = 2;
	
	/* matriz de entrada */ 
	for (indiceLinha = 0; indiceLinha < ordemMatriz; indiceLinha++) 
		for (indiceColuna = 0; indiceColuna < ordemMatriz; indiceColuna++) 
		{
         		matriz [indiceLinha][indiceColuna] = strtod(argv[indiceAuxiliar], &verificacao);
							
			if (errno == ERANGE)
			{
				printf ("Valor fornecido ultrapassa o valor maximo permitido para double (%.10e).\n", DBL_MAX);
				exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
			}

			if (*verificacao != EOS)
			{
				printf ("Argumento contem caractere invalido.\n");
				printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
				exit (CARACTERE_INVALIDO);
			}
			
			indiceAuxiliar++;	
		}
	
	codigoRetorno = CalcularDeterminanteMatriz(ordemMatriz, matriz, determinante);

	if (codigoRetorno != ok)
	{
		printf ("\nErro executando a funcao. Erro numero: #%u\n\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}
	
	/* Exibe a matriz de entrada */
	printf ("\nA Matriz de entrada eh: \n\n");
	for (indiceLinha = 0; indiceLinha < ordemMatriz; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < ordemMatriz; indiceColuna++)
			printf ("%.5f\t", matriz [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}
	
	/* Exibe o determinante da matriz */
	printf("\nO determinante da matriz eh: %.5f\n\n", *determinante);

	return 0;
	
} /* main */

/* $RCSfile: aula0604.c,v $ */	
