/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa que exibe o tamanho dos tipos basicos, modificadores de sinal e de largura.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/05/21 09:58:01 $
 * $Log: aula0102.c,v $
 * Revision 1.1  2022/05/21 09:58:01  alan.goncalves
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define OK                              0
#define NUMERO_ARGUMENTOS_INVALIDO      1

#define NUMERO_ARGUMENTOS               1

#define NUMERO_HIFENS_TERMINAL          100
#define COLUNA_INICIAL_TAMANHO          91

int
main (int argc, char *argv [])
{
	unsigned contador;

	/* Testa se o numero de argumento inseridos pelo usuario esta correto */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	contador = 0;

	printf ("\n");
	
	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");
	
	printf ("\n\n");

	/* Exibicao dos tamanhos dos tipos basicos na linguagem C */ 
	printf ("Tamanho dos Tipos Basicos\n\n");

	printf ("void:");	
	for (contador = 5; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(void), (sizeof(void) == 1? "byte":"bytes"));

	printf ("char:");
	for (contador = 5; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(char), (sizeof(char) == 1? "byte":"bytes"));

	printf ("int:");
	for (contador = 4; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(int), (sizeof(int) == 1? "byte":"bytes"));
	
	printf ("float:");
	for (contador = 6; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(float), (sizeof(float) == 1? "byte":"bytes"));

	printf ("double:");
	for (contador = 7; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(double), (sizeof(double) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	/* Exibicao dos tamanhos dos modificadores de sinal na linguagem C */ 
	printf ("Tamanho dos Modificadores de Sinal\n\n");

	printf ("signed:");
	for (contador = 7; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed), (sizeof(signed) == 1? "byte":"bytes"));

	printf ("unsigned:");
	for (contador = 9; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(unsigned), (sizeof(unsigned) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	/* Exibicao dos tamanhos dos modificadores de largura na linguagem C */ 
	printf ("Tamanho dos Modificadores de Largura\n\n");

	printf ("short:");
	for (contador = 6; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(short), (sizeof(short) == 1? "byte":"bytes"));

	printf ("long:");
	for (contador = 5; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(long), (sizeof(long) == 1? "byte":"bytes"));

	printf ("long long:");
	for (contador = 10; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(long long), (sizeof(long long) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	return OK;
} /* main */

/* $RCSfile: aula0102.c,v $ */
