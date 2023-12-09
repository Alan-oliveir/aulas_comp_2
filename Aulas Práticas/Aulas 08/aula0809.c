/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa de testes da funcao CodificarBase64.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

#define OK                          	    0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ERRO_ABERTURA_ARQUIVO               2
#define ERRO_FUNCAO                         3
#define ERRO_LEITURA                        4

#define MAXIMO_BYTES                        2000
#define NUMERO_ARGUMENTOS                   3
#define TAMANHO_MAXIMO_LINHA                76


int 
main (int argc, char *argv[])
{
    FILE *leitura, *escrita;
             
    unsigned numeroLinhas = 0;

    unsigned long long numeroBytes, 
                       numeroBytesLidos;

    char stringResultado [MAXIMO_BYTES];

    byte conjuntoBytes [MAXIMO_BYTES];

    tipoFinalLinha indicadorFinalLinha = 1;

    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\n\nUso: %s <arquivo-base> <arquivo-resultado>\n\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if ((leitura = fopen (argv[1], "r")) == NULL)
	{
		printf ("\nErro ao abrir o arquivo: \"%s\"\n", argv [1]);
		exit (ERRO_ABERTURA_ARQUIVO);
	}

	if ((escrita = fopen (argv [2], "w")) == NULL)
	{
		printf ("Erro ao abrir o arquivo: \"%s\"\n", argv [2]);
		fclose (leitura);
		exit (ERRO_ABERTURA_ARQUIVO);
	}

	numeroBytesLidos = fread((void *) stringResultado, 1, TAMANHO_MAXIMO_LINHA, leitura);

	printf ("Quantidade de bytes lidos: %llu\n\n", numeroBytesLidos);

	while (numeroBytesLidos > 0)
	{	
		printf ("Linha atual: %s\n\n", stringResultado);

		if (numeroBytesLidos != TAMANHO_MAXIMO_LINHA)
		{	
			fread((void *) stringResultado, numeroBytesLidos, 1, leitura);

			codigoRetorno = DecodificarBase64(stringResultado, indicadorFinalLinha, conjuntoBytes, &numeroBytes);

			if (codigoRetorno != ok)
			{	
                printf ("Retorno da funcao: %i\n", codigoRetorno);
				printf ("\nErro na funcao DecodificarBase64\n\n");
				exit (ERRO_FUNCAO);
			}

			fprintf (escrita,"%s", conjuntoBytes);
			fprintf (escrita,"%s", "\n");

			numeroLinhas++;
		}

		else
		{	
			codigoRetorno = DecodificarBase64(stringResultado, indicadorFinalLinha, conjuntoBytes, &numeroBytes);

			if (codigoRetorno != ok)
			{	
                printf ("Retorno da funcao: %i\n", codigoRetorno);
				printf ("\nErro na funcao DecodificarBase64\n\n");
				exit (ERRO_FUNCAO);
			}

			fprintf (escrita,"%s", conjuntoBytes);
			fprintf (escrita,"%s", "\n");

			numeroLinhas++;
		}
	}

	if (ferror (leitura))
	{
		printf ("\nErro na leitura do arquivo\n\n");		

		fclose (leitura);
		fclose (escrita);

		remove (argv[2]);

		exit (ERRO_LEITURA);
	}

	fclose (leitura);
	fclose (escrita);

	printf ("\nCodificacao do arquivo concluida\nO novo arquivo contem %u linhas\n\n", numeroLinhas);

	return OK;
	
} /* main */

/* $RCSfile$ */ 