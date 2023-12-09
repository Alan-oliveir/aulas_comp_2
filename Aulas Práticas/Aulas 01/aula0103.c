/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Programa que exibe o tamanho das combinacoes validas entre tipos basicos, modificadores de sinal e de largura.
 *
 * $Author: alan.goncalves $
 * $Date: 2022/05/21 09:58:08 $
 * $Log: aula0103.c,v $
 * Revision 1.1  2022/05/21 09:58:08  alan.goncalves
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO                         0
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

	/* Exibicao dos tamanhos dos modificadores de sinal combinados com modificadores de largura */ 
	printf ("Tamanho dos Modificadores de Sinal combinados com Modificadores de Largura\n\n");

	printf ("unsigned long:");	
	for (contador = 14; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned long), (sizeof(unsigned long) == 1? "byte":"bytes"));

	printf ("unsigned long long:");
	for (contador = 19; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned long long), (sizeof(unsigned long long) == 1? "byte":"bytes"));

	printf ("unsigned short:");
	for (contador = 15; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned short), (sizeof(unsigned short) == 1? "byte":"bytes"));
	
	printf ("signed long:");
	for (contador = 12; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed long), (sizeof(signed long) == 1? "byte":"bytes"));

	printf ("signed long long:");
	for (contador = 17; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed long long), (sizeof(signed long long) == 1? "byte":"bytes"));

	printf ("signed short:");
	for (contador = 13; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(signed short), (sizeof(signed short) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	/* Exibicao dos tamanhos dos modificadores de sinal combinados com Tipos Basicos */ 
	printf ("Tamanho dos Tipos Basicos combinados com  Modificadores de Sinal\n\n");

	printf ("signed int:");
	for (contador = 11; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed int), (sizeof(signed int) == 1? "byte":"bytes"));

	printf ("unsigned int:");
	for (contador = 13; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned int), (sizeof(unsigned int) == 1? "byte":"bytes"));

	printf ("signed char:");
	for (contador = 12; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed char), (sizeof(signed char) == 1? "byte":"bytes"));

	printf ("unsigned char:");
	for (contador = 14; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(unsigned char), (sizeof(unsigned char) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	/* Exibicao dos tamanhos dos modificadores de largura combinados com tipos basicos */ 
	printf ("Tamanho dos Tipos Basicos combinados com Modificadores de Largura\n\n");

	printf ("short int:");
	for (contador = 10; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(short int), (sizeof(short int) == 1? "byte":"bytes"));

	printf ("long int:");
	for (contador = 9; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(long int), (sizeof(long int) == 1? "byte":"bytes"));

	printf ("long long int:");
	for (contador = 14; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(long long int), (sizeof(long long int) == 1? "byte":"bytes"));

	printf ("long double:");
	for (contador = 12; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(long double), (sizeof(long double) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	/* Exibicao dos tamanhos dos tipos basicos combinados com modificadores de sinal e de largura */ 
	printf ("Tamanho dos Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura\n\n");

	printf ("unsigned long int:");	
	for (contador = 18; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned long int), (sizeof(unsigned long int) == 1? "byte":"bytes"));

	printf ("unsigned long long int:");
	for (contador = 23; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned long long int), (sizeof(unsigned long long int) == 1? "byte":"bytes"));

	printf ("unsigned short int:");
	for (contador = 19; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(unsigned short int), (sizeof(unsigned short int) == 1? "byte":"bytes"));
	
	printf ("signed long int:");
	for (contador = 16; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed long int), (sizeof(signed long int) == 1? "byte":"bytes"));

	printf ("signed long long int:");
	for (contador = 21; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n", sizeof(signed long long int), (sizeof(signed long long int) == 1? "byte":"bytes"));

	printf ("signed short int:");
	for (contador = 17; contador <= COLUNA_INICIAL_TAMANHO; contador++)
		printf (" ");
	printf ("%ld %s\n\n", sizeof(signed short int), (sizeof(signed short int) == 1? "byte":"bytes"));

	/* Laco de repeticao que gera os 100 hifens exibidos no terminal */
	for (contador = 0; contador < NUMERO_HIFENS_TERMINAL; contador++)
		printf ("-");

	printf ("\n\n");

	return SUCESSO;
}

/* $RCSfile: aula0103.c,v $ */
