/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Prototipo da funcao MultiplicarMatrizes
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/18 02:34:43 $
 * $Log: aula0601.h,v $
 * Revision 1.5  2022/08/18 02:34:43  alan.goncalves
 * Computacao II - Aulas Praticas - aula06.
 * Alteracao no tipoErros.
 *
 * Revision 1.4  2022/08/17 23:34:28  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Inclusao dos prototipos da funcao CalcularDeterminanteMatriz, CalcularMenorComplementar e CalcularComplementoAlgebrico.
 *
 * Revision 1.3  2022/08/17 20:37:16  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Inclusao do prototipo da funcao ObterMatrizTransposta.
 *
 * Revision 1.2  2022/08/17 03:40:18  alan.goncalves
 * Computacao II - aulas praticas - Aula 06
 * Correcao no prototipo da funcao MultiplicarMatrizes.
 *
 * Revision 1.1  2022/08/17 02:21:28  alan.goncalves
 * Initial revision
 *
 *
 ******************************************************************************/

#ifndef _AULA0601_
#define _AULA0601_                            "@(#)aula0601.h $Revisions$"

#define NUMERO_MAXIMO_LINHAS                  100
#define NUMERO_MAXIMO_COLUNAS                 100

#define ORDEM_MAXIMA_MATRIZ                   100

typedef enum
{
	ok,
	numeroElementosMatrizInvalido,
	numeroMaximoLinhasExcedido,
	numeroMaximoColunasExcedido,
	ordemMaximaMatrizExcedida,
	matrizNulaA,
	matrizNulaB,
	ordemMatrizInvalida
} tipoErros;

tipoErros
MultiplicarMatrizes (unsigned short, /* numero de linhas da matriz 1 (E) */
		     unsigned short, /* numero de colunas da matriz 1 (E) */
		     unsigned short, /* numero de linhas da matriz 2 (E) */
		     unsigned short, /* numero de colunas da matriz 2 (E) */
		     double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 1 (E) */ 
	     	     double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 2 (E) */ 
	     	     double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]); /* matriz produto (S) */ 

tipoErros 
ObterMatrizTransposta (unsigned short, /* numero de linhas da matriz original (E) */
		       unsigned short, /* numero de colunas da matriz original (E) */ 
		       double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz original (E) */
		       double [NUMERO_MAXIMO_COLUNAS][NUMERO_MAXIMO_LINHAS]); /* matriz transposta (S) */
				 
tipoErros
CalcularMenorComplementar (unsigned short, /* ordem da matriz (E) */
			   unsigned short, /* linha do elemento (E) */
			   unsigned short, /* coluna do elemento (E) */
			   double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz (E) */
			   double *); /* menor complementar (S) */


tipoErros 
CalcularComplementoAlgebrico (unsigned short, /* ordem da matriz (E) */
			      unsigned short, /* linha do elemento (E) */ 
			      unsigned short, /* coluna do elemento (E) */ 
			      double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],/* matriz (E) */  
			      double *); /* complemento algebrico / cofator (S) */

tipoErros 
CalcularDeterminanteMatriz (unsigned short, /* ordem da matriz (E) */
			    double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz (E) */
			    double *); /* determinante */

#endif

/* $RCSfile: aula0601.h,v $ */
