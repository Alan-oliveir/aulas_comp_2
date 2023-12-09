/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao MultiplicarMatrizes
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/17 16:03:45 $
 * $Log: aula0602.c,v $
 * Revision 1.3  2022/08/17 16:03:45  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Correcao de erros na funcao MultiplicarMatrizes.
 *
 * Revision 1.2  2022/08/17 03:42:41  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Correcao no programa de testes da funcao MultiplicarMatrizes.
 *
 * Revision 1.1  2022/08/17 02:22:16  alan.goncalves
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

#define NUMERO_ARGUMENTOS_DIMENSAO_MATRIZES       4 /* numero de argumentos necessarios p/ defineir as dimensoes das matrizes */

#define EOS				          '\0' /* igual ao byte 0 */

int 
main (int argc, char **argv) 
{
	char *verificacao;
	unsigned long numeroAuxiliar;
	
	unsigned short numeroLinhasA;
	unsigned short numeroColunasA;
	unsigned short numeroLinhasB;
	unsigned short numeroColunasB;
	
	tipoErros codigoRetorno;

	/* Verifica o numero de argumentos referentes as dimensoes das matrizes A e B */
	if(argc <  NUMERO_ARGUMENTOS_DIMENSAO_MATRIZES + 1)
	{
		printf ("Uso: %s <numero-linhas-A> <numero-colunas-A> <numero-linhas-B> <numero-colunas-B> <a11> <a12> ... <amn> <b11> <b12> ... <bnm>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* inicio dos testes dos numero de linhas da matriz A */
	if (argv [1][0] == '-')
	{
		printf ("Este programa espera o numero de linhas ou colunas das matrizes positivo.\n");
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
	
	numeroLinhasA = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de linhas da matrizA */	
	
	/* inicio dos testes dos numero de colunas da matriz A */
	if (argv [2][0] == '-')
	{
		printf ("Este programa espera o numero de linhas ou colunas das matrizes positivo.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroAuxiliar = strtoul (argv [2], &verificacao, 10);
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
	
	numeroColunasA = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de colunas da matrizA */	
	
	/* inicio dos testes dos numero de linhas da matrizB */
	if (argv [3][0] == '-')
	{
		printf ("Este programa espera o numero de linhas ou colunas das matrizes positivo.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroAuxiliar = strtoul (argv [3], &verificacao, 10);
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
	
	numeroLinhasB = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de linhas da matrizB */
	
	/* inicio dos testes dos numero de colunas da matrizB */	
	if (argv [4][0] == '-')
	{
		printf ("Este programa espera o numero de linhas ou colunas das matrizes positivo.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroAuxiliar = strtoul (argv [4], &verificacao, 10);
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
	
	numeroColunasB = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de colunas da matrizB */

	#ifdef DEPURACAO
	printf("\nNumero de linhas da Matriz A: #%hu\n", numeroLinhasA);
	printf("Numero de colunas da Matriz A: #%hu\n", numeroColunasA);
	printf("Numero de linhas da Matriz B: #%hu\n", numeroLinhasB);
	printf("Numero de colunas da Matriz B: #%hu\n\n", numeroLinhasB);
	#endif

	if(argc != ((numeroLinhasA * numeroColunasA) + (numeroLinhasB * numeroColunasB) + 5))
	{
		printf ("\nUso: %s <numero-linhas-A> <numero-colunas-A> <numero-linhas-B> <numero-colunas-B> <a11> <a12> ... <amn> <b11> <b12> ... <bnm>\n", argv[0]);
		printf ("Numero de argumentos recebidos: #%i\n", argc);
		printf ("Numero de argumentos necessarios: #%i\n\n", ((numeroLinhasA * numeroColunasA) + (numeroLinhasB * numeroColunasB) + 5));
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
		
	double matrizA [numeroLinhasA][numeroColunasA];
	double matrizB [numeroLinhasB][numeroColunasB];
	double matrizProduto [numeroLinhasA][numeroColunasB];
	
	unsigned indiceLinha;
	unsigned indiceColuna;
	unsigned indiceAuxiliar = 5;
	
	/* matrizA */ 
	for (indiceLinha = 0; indiceLinha < numeroLinhasA; indiceLinha++) 
		for (indiceColuna = 0; indiceColuna < numeroColunasA; indiceColuna++) 
		{
         	matrizA[indiceLinha][indiceColuna] = strtod(argv[indiceAuxiliar], &verificacao);
							
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
		
	/* matrizB */ 
	for (indiceLinha = 0; indiceLinha < numeroLinhasB; indiceLinha++) 
		for (indiceColuna = 0; indiceColuna < numeroColunasB; indiceColuna++) 
		{
         	matrizB[indiceLinha][indiceColuna] = strtod(argv[indiceAuxiliar], &verificacao);
							
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
		
	codigoRetorno = MultiplicarMatrizes(numeroLinhasA, numeroColunasA, numeroLinhasB, numeroColunasB, matrizA, matrizB, matrizProduto);

	if (codigoRetorno != ok)
	{
		printf ("\nErro executando a funcao. Erro numero: #%u\n\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}
	
	system("clear");

	/* Exibe a matrizA */
	printf ("\nA Matriz A eh: \n\n");
	for (indiceLinha = 0; indiceLinha < numeroLinhasA; indiceLinha++)
	{
        	for (indiceColuna = 0; indiceColuna < numeroColunasA; indiceColuna++)
                	printf ("%.5f\t", matrizA [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}

	/* Exibe a matrizB */
	printf ("\nA Matriz B eh: \n\n");
	for (indiceLinha = 0; indiceLinha < numeroLinhasB; indiceLinha++)
	{
        	for (indiceColuna = 0; indiceColuna < numeroColunasB; indiceColuna++)
                	printf ("%.5f\t", matrizB [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}

	/* Exibe o produto das matrizes A e B */
	printf ("\nO produto das matrizes A e B eh:\n\n");
	for (indiceLinha = 0; indiceLinha < numeroLinhasA; indiceLinha++)
	{
        	for (indiceColuna = 0; indiceColuna < numeroColunasB; indiceColuna++)
                	printf ("%.5f\t", matrizProduto [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}

	return OK;

} /* main */

/* $RCSfile: aula0602.c,v $ */	
