/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Prototipo da funcao CodificarBase16.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/

#ifndef _AULA0801_
#define _AULA0801_                      "@(#)aula0801.h $Revision$"


#define EOS	            				'\0'
#define TAMANHO_ALFABETO_BASE16			15
#define PULA_LINHA						'\n'
#define PADDING							'='
#define FORA_BASE_64					100


typedef unsigned char byte;

typedef enum 
{
	ok,
	argumentoNulo,
	argumentoInvalido,
	foraDosLimites,
	baseInvalida
} 
tipoErros;

typedef enum 
{
	basico, 
	estendido
} 
tipoAlfabetoBase32;

typedef enum 
{
	desabilitado, 
	habilitado
} 
tipoFinalLinha;


tipoErros
CodificarBase16 (byte * /* (E) */, unsigned long long /* (E) */, char * /* (S) */);


tipoErros
DecodificarBase16 (char * /* (E) */, byte * /* (S) */, unsigned long long * /*  (S) */);


tipoErros
CodificarBase32 (byte * /* (E) */, unsigned long long /*  (E) */, tipoAlfabetoBase32 /* (E) */, char * /* (S) */);


tipoErros
DecodificarBase32 (char * /* (E) */, tipoAlfabetoBase32 /* (E) */, byte * /* (S) */, unsigned long long * /* (S) */);


tipoErros
CodificarBase64 (byte * /* (E) */, unsigned long long /*  (E) */, tipoFinalLinha /* (E) */, char * /* (S) */);


tipoErros
DecodificarBase64 (char * /* (E) */, tipoFinalLinha /* (E) */, byte * /* (S) */, unsigned long long * /* (S) */);

#endif

/* $RCSfile$ */ 