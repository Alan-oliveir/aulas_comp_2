/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CalcularMenorComplementar
 *
 * $Author$
 * $Date$
 * $Log$
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

#define NUMERO_ARGUMENTOS_DIMENSAO_MATRIZES       2 /* numero de argumentos necessarios p/ defineir a dimensao da matriz */

#define EOS				          '\0' /* igual ao byte 0 */

int 
main (int argc, char **argv) 
{
	char *verificacao;
	unsigned long numeroAuxiliar;
	
	unsigned short numeroLinhas;
	unsigned short numeroColunas;
	
	tipoErros codigoRetorno;

	system("clear");

	/* Verifica o numero de argumentos referentes as dimensoes e ordem da matriz */
	if(argc <  NUMERO_ARGUMENTOS_DIMENSAO_MATRIZES + 2)
	{
		printf ("\nUso: %s <ordem-matriz> <numero-linhas> <numero-colunas>  <a11> <a12> ... <amn> \n", argv[0]);
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

	/* inicio dos testes dos numero de linhas da matriz de entrada */
	if (argv [2][0] == '-')
	{
		printf ("Este programa espera o numero de linhas ou colunas da matriz positivo.\n");
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
	
	numeroLinhas = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de linhas da matriz de entrada */	
	
	/* inicio dos testes dos numero de colunas da matriz de entrada */
	if (argv [3][0] == '-')
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
	
	numeroColunas = (unsigned short) numeroAuxiliar; /* Fim dos testes do numero de colunas da matriz de entrada */	
	
	#ifdef DEPURACAO
	printf("\nOrdem da Matriz: #%hu\n", ordemMatriz);
	printf("\nNumero de linhas da Matriz: #%hu\n", numeroLinhas);
	printf("Numero de colunas da Matriz: #%hu\n", numeroColunas);
	#endif

	if(argc != ((numeroLinhas * numeroColunas) + 3))
	{
		printf ("\nUso: %s <numero-linhas> <numero-colunas> <a11> <a12> ... <amn> \n", argv[0]);
		printf ("Numero de argumentos recebidos: #%i\n", argc);
		printf ("Numero de argumentos necessarios: #%i\n\n", ((numeroLinhas * numeroColunas) + 3));
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
		
	double matriz [numeroLinhas][numeroColunas];
	double matrizTransposta [numeroColunas][numeroLinhas];
	
	unsigned indiceLinha;
	unsigned indiceColuna;
	unsigned indiceAuxiliar = 3;
	
	/* matriz de entrada */ 
	for (indiceLinha = 0; indiceLinha < numeroLinhas; indiceLinha++) 
		for (indiceColuna = 0; indiceColuna < numeroColunas; indiceColuna++) 
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
	
	codigoRetorno = ObterMatrizTransposta(numeroLinhas, numeroColunas, matriz, matrizTransposta);

	if (codigoRetorno != ok)
	{
		printf ("\nErro executando a funcao. Erro numero: #%u\n\n", codigoRetorno);
 		exit (ERRO_EXECUTANDO_FUNCAO);
	}
	
	#ifdef DEPURACAO
	/* Exibe a matriz de entrada */
	printf ("\nA Matriz de entrada eh: \n\n");
	for (indiceLinha = 0; indiceLinha < numeroLinhas; indiceLinha++)
	{
        	for (indiceColuna = 0; indiceColuna < numeroColunas; indiceColuna++)
           		printf ("%.5f\t", matriz [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}
	#endif

	/* Exibe a matriz transposta */
	printf ("\nA Matriz Transposta eh: \n\n");
	for (indiceLinha = 0; indiceLinha < numeroColunas; indiceLinha++)
	{
        	for (indiceColuna = 0; indiceColuna < numeroLinhas; indiceColuna++)
           		printf ("%.5f\t", matrizTransposta [indiceLinha][indiceColuna]);
		printf ("\n\n");
	}

	return OK;

} /* main */

/* $RCSfile: aula0603.c,v $ */	
