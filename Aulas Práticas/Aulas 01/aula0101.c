/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Computacao II - Aulas Praticas - Aula 01
 * Este programa exibe um nome recebido atraves da linha de comando
 *
 * $Author: alan.goncalves $
 * $Date: 2022/07/21 20:31:50 $
 * $Log: aula0101.c,v $
 * Revision 1.1  2022/07/21 20:31:50  alan.goncalves
 * Initial revision
 *
 * Revision 1.1  2022/05/21 09:57:50  alan.goncalves
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK                               0
#define NUMERO_ARGUMENTOS_INVALIDO       1
#define COMPRIMENTO_MAXIMO_NOME_EXCEDIDO 2

#define NUMERO_ARGUMENTOS                2

#define NUMERO_COLUNAS_TERMINAL          100
#define COMPRIMENTO_MAXIMO_NOME          64

int
main (int argc, char *argv [])
{
	unsigned contador;
	unsigned indiceDezena;
	unsigned indiceUnidade;

	char *nome;

	size_t comprimentoString;

	unsigned espacamento;

	/* Testa se o numero de argumento inseridos pelo usuario esta correto */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

   	contador = 0;
	indiceDezena = 0;
	indiceUnidade = 0;	

	printf ("\n");
	
	/* Primeiro bloco de lacos de repeticao - mostra as dezenas da numeracao de colunas */
	for (indiceDezena = 0; indiceDezena <= 9; indiceDezena++)
	{
		for (contador = 0; contador <= 9; contador++)
			printf ("%u", indiceDezena);
		
		contador = 0;
	}

	printf ("\n");

	/* Segundo bloco de lacos de repeticao - mostra as unidades da numeracao de colunas */
	for (contador = 0; contador <= 9; contador++)
		for (indiceUnidade = 0; indiceUnidade <= 9; indiceUnidade++)
			printf ("%u", indiceUnidade);
	
	printf ("\n\n");

	nome = argv [1];
	comprimentoString = strlen (nome);

	if (comprimentoString > COMPRIMENTO_MAXIMO_NOME)
	{
		printf ("Comprimento do nome maior que o permitido.\n");
		exit (COMPRIMENTO_MAXIMO_NOME_EXCEDIDO);
	}


	espacamento = ((NUMERO_COLUNAS_TERMINAL - comprimentoString) / 2);

	for (contador = 0; contador <= (espacamento - 1); contador++)
		printf (" ");

	printf ("\"%s\"\n\n", nome);
	
	/* Laco de repeticao que gera os 80 hifens exibidos */
	for (contador = 0; contador < NUMERO_COLUNAS_TERMINAL; contador++)
		printf ("-");
	
	printf ("\n\n");

	return OK;
} /* main */

/* $RCSfile: aula0101.c,v $ */
