/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Prototipo da funcao MostrarMonitor
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/

#ifndef _AULA0701_
#define _AULA0701_		            	"@(#)aula0701.h $Revision$"

#define NUMERO_MAXIMO_LINHAS			250
#define NUMERO_MAXIMO_COLUNAS			800
#define APAGADO				        	' '
#define ACESO					        '0'
#define DEFEITUOSO				        '.'

typedef enum
{	
	defeituoso = -1,
	apagado,
	aceso
} tipoPixel;

typedef enum
{
	ok,
	falha,
	dimensaoInvalida,
	percentualInvalido,
	posicaoInvalida,
	poligonoInvalido        
} tipoErros;

tipoErros
MostrarMonitor(useconds_t tempoEspera, /* E */
		tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
		unsigned numeroMaximoLinhas, /* E */
		unsigned numeroMaximoColunas /* E */);

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
			  unsigned numeroMaximoLinhas, /* E */
			  unsigned numeroMaximoColunas, /* E */
			  float percentualDefeituosos, /* E */
			  float percentualApagados /* E */);

void 
PrintarHifens (unsigned coluna); /* funcao auxilia usada durante a execucao da funcao MostrarMonitor. */

tipoErros
InicializarMatriz (tipoPixel [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz */
                   tipoPixel); /* valor para preencher. Normalmente usa 0 */
				   
tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
	       unsigned numeroMaximoLinhas, /* E */
	       unsigned numeroMaximoColunas);
		   
tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
	      unsigned numeroMaximoLinhas, /* E */
	      unsigned numeroMaximoColunas, /* E */
	      unsigned linhaA, /* E */
	      unsigned colunaA, /* E */
	      unsigned linhaB, /* E */
	      unsigned colunaB /* E */);
		  
tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
		  unsigned numeroMaximoLinhas, /* E */
		  unsigned numeroMaximoColunas, /* E */
		  unsigned numeroVertices, /* E */
		  unsigned linhasVertices [NUMERO_MAXIMO_LINHAS], /* E */
		  unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS] /* E */);

tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
		    tipoPixel monitor[NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],/* E/S */
		    unsigned numeroMaximoLinhas, /* E */
		    unsigned numeroMaximoColunas, /* E */
		    unsigned linha, /* E */
		    unsigned coluna /* E */); 
		  
#endif 

/* $RCSfile$ */
