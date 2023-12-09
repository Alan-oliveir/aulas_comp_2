/**************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao MultiplicarMatrizes
 *
 * $Author: alan.goncalves $
 * $Date: 2022/08/18 02:36:11 $
 * $Log: aula0601.c,v $
 * Revision 1.6  2022/08/18 02:36:11  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Implementacao da funcao CalcularMenorComplementar.
 *
 * Revision 1.5  2022/08/17 23:36:24  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Implemetacao da funcao CalcularDetrerminanteMatriz para matrizes ate terceira ordem.
 *
 * Revision 1.4  2022/08/17 20:38:23  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Inclusao da funcao ObterMatrizTransposta.
 *
 * Revision 1.3  2022/08/17 16:13:36  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Modificacao na funcao MultiplicarMatrizes.
 *
 * Revision 1.2  2022/08/17 03:41:36  alan.goncalves
 * Computacao II - Aulas Praticas - Aula06.
 * Correcao na funcao MultiplicarMatrizes.
 *
 * Revision 1.1  2022/08/17 02:21:58  alan.goncalves
 * Initial revision
 *
 *
 **************************************************************************/

#ifdef DEPURACAO
#include <stdio.h>
#endif

#include "aula0601.h"

tipoErros
MultiplicarMatrizes (unsigned short numeroLinhasA, /* numero de linhas da matriz A (E) */
		     unsigned short numeroColunasA, /* numero de colunas da matriz A (E) */
		     unsigned short numeroLinhasB, /* numero de linhas da matriz B (E) */
		     unsigned short numeroColunasB, /* numero de colunas da matriz B (E) */
		     double matrizA [numeroLinhasA][numeroColunasA], /* matriz A (E) */ 
	     	     double matrizB [numeroLinhasB][numeroColunasB], /* matriz B (E) */ 
	     	     double matrizProduto [numeroLinhasA][numeroColunasB]) /* matriz produto (S) */ 

{	
	unsigned linha, coluna, indiceAuxiliar;	
		
	/* Teste numero maximo de linhas e colunas das matrizes */
	if (numeroLinhasA > NUMERO_MAXIMO_LINHAS)
		return numeroMaximoLinhasExcedido;

	if (numeroColunasA > NUMERO_MAXIMO_COLUNAS)
		return numeroMaximoColunasExcedido;

	if (numeroLinhasB > NUMERO_MAXIMO_LINHAS)
		return numeroMaximoLinhasExcedido;

	if (numeroColunasB > NUMERO_MAXIMO_COLUNAS)
		return numeroMaximoColunasExcedido;
	
	/* Teste caso matriz__ == NULL */
	if (!matrizA) 
		return matrizNulaA;

	if (!matrizB) 
		return matrizNulaB;
	
	/* Teste se eh possivel realizar a multiplicacao entre as matrizes recebidas */
	if (numeroColunasA != numeroLinhasB) 
		return numeroElementosMatrizInvalido;
	
	/* Inicializacao da matrizProduto com todos os indices iguais a zero. */
	for (linha = 0; linha < numeroLinhasA; linha++) 
		for (coluna = 0; coluna < numeroColunasB; coluna++) 
	   	 	matrizProduto[linha][coluna] = 0;
    		
	for (linha = 0; linha < numeroLinhasA ; linha++) 
		for (coluna = 0; coluna < numeroColunasB; coluna++) 
			for (indiceAuxiliar = 0; indiceAuxiliar < numeroColunasA; indiceAuxiliar++)
			{
				#ifdef DEPURACAO
				printf ("Calcula o elemento [%u][%u] da matriz produto\n", linha, coluna);
				#endif

				matrizProduto [linha][coluna] = matrizProduto [linha][coluna] + matrizA[linha][coluna] * matrizB[linha][coluna]; 

				#ifdef DEPURACAO
				printf ("Resultado: %f\n\n", matrizProduto [linha][coluna] );
				#endif
			}

	return ok;
	
} /* MultiplicarMatrizes */

tipoErros 
ObterMatrizTransposta (unsigned short numeroLinhasMatriz, /* numero de linhas da matriz (E) */
		       unsigned short numeroColunasMatriz, /* numero de colunas da matriz (E) */ 
		       double matriz [numeroLinhasMatriz][numeroColunasMatriz], /* matriz (E) */
		       double matrizTransposta [numeroColunasMatriz][numeroLinhasMatriz]) /* matriz transposta (S) */

{
	unsigned short indiceLinhas;
	unsigned short indiceColunas;
	
	/* Teste numero maximo de linhas e colunas das matrizes */
	if (numeroLinhasMatriz > NUMERO_MAXIMO_LINHAS)
		return numeroMaximoLinhasExcedido;

	if (numeroColunasMatriz > NUMERO_MAXIMO_COLUNAS)
		return numeroMaximoColunasExcedido;

	/* Teste caso matriz == NULL */
	if (!matriz) 
		return matrizNulaA;

	for (indiceLinhas = 0; indiceLinhas < numeroLinhasMatriz; indiceLinhas++)
		for (indiceColunas = 0; indiceColunas < numeroColunasMatriz; indiceColunas++) 
			matrizTransposta[indiceColunas][indiceLinhas] = matriz[indiceLinhas][indiceColunas];
  		
	return ok;
	
} /* ObterMatrizTransposta */

tipoErros
CalcularMenorComplementar (unsigned short ordemMatriz, /* ordem da matriz (E) */
			   unsigned short linha, /* linha do elemento (E) */
			   unsigned short coluna, /* coluna do elemento (E) */
			   double matriz [ordemMatriz][ordemMatriz], /* matriz (E) */
			   double * menorComplementar) /* menor complementar (S) */

{
	unsigned short indiceLinhas;
	unsigned short indiceColunas;
	
	/* Teste numero maximo de linhas e colunas da matriz */
	if (ordemMatriz > ORDEM_MAXIMA_MATRIZ)
		return ordemMaximaMatrizExcedida;

	/* Teste caso matriz == NULL */
	if (!matriz) 
		return matrizNulaA;
	
	/* 
	 * Teste se ordem da matriz eh maior ou igual a 2. 
	 * Nao eh possivel calcular o menor complementar para matriz de ordem menor que 2. 
	 */	 
	if (ordemMatriz < 2)
		return ordemMatrizInvalida;
	
	/* Definacao da matriz alterada para calcular o menor complementar de cada termo da matriz de entrada */
	double matrizTransformada [ordemMatriz - 1][ordemMatriz - 1]; 

	for (indiceLinhas = 0; indiceLinhas < ordemMatriz; indiceLinhas++)
	{
		if(indiceLinhas < linha - 1)
			for (indiceColunas = 0; indiceColunas < ordemMatriz; indiceColunas++)
			{			
				if (indiceColunas < coluna - 1)
					matrizTransformada [indiceLinhas][indiceColunas] = matriz [indiceLinhas][indiceColunas];
							
				if (indiceColunas > coluna - 1)
					matrizTransformada [indiceLinhas][indiceColunas - 1] = matriz [indiceLinhas][indiceColunas];
			}

		if(indiceLinhas > linha - 1)
			for (indiceColunas = 0; indiceColunas < ordemMatriz; indiceColunas++)
			{
				if (indiceColunas < coluna - 1)
					matrizTransformada [indiceLinhas - 1][indiceColunas] = matriz [indiceLinhas][indiceColunas];
				
				if (indiceColunas > coluna - 1)
					matrizTransformada [indiceLinhas - 1][indiceColunas - 1] = matriz [indiceLinhas][indiceColunas];
			}
	}
	
	CalcularDeterminanteMatriz (ordemMatriz - 1, matrizTransformada, menorComplementar);
	
	return ok;

} /* CalcularMenorComplementar */

tipoErros 
CalcularComplementoAlgebrico (unsigned short ordemMatriz, /* ordem da matriz (E) */
			      unsigned short linha, /* linha do elemento (E) */ 
			      unsigned short coluna, /* coluna do elemento (E) */ 
			      double matriz [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],/* matriz (E) */  
			      double * cofator) /* complemento algebrico / cofator (S) */
		
{
	unsigned short somaIndiceTermo;
	
	/* Teste numero maximo de linhas e colunas da matriz */
	if (ordemMatriz > ORDEM_MAXIMA_MATRIZ)
		return ordemMaximaMatrizExcedida;

	/* Teste caso matriz == NULL */
	if (!matriz) 
		return matrizNulaA;
	
	/* 
	 * Teste se ordem da matriz eh maior ou igual a 2. 
	 * Nao eh possivel calcular o menor complementar para matriz de ordem menor que 2. 
	 */	 
	if (ordemMatriz < 2)
		return ordemMatrizInvalida;

	somaIndiceTermo = linha + coluna;

	CalcularMenorComplementar (ordemMatriz, linha, coluna, matriz, cofator);

	if (somaIndiceTermo % 2)
		*cofator = -1 * (*cofator);

	return ok;

} /* CalcularComplementoAlgebrico */

tipoErros 
CalcularDeterminanteMatriz (unsigned short ordemMatriz, /* ordem da matriz (E) */
			    double matriz [ordemMatriz][ordemMatriz], /* matriz (E) */			    
			    double * determinante) /* determinante */

{
	double primeiraDiagonalPrincipal, segundaDiagonalPrincipal, terceiraDiagonalPrincipal;
	double primeiraDiagonalSecundaria, segundaDiagonalSecundaria, terceiraDiagonalSecundaria;
	double somaDiagonaisPrincipais, somaDiagonaisSecundarias;
 	double produtoDiagonalPrincipal, produtoDiagonalSecundaria;
 
	/* Teste numero maximo de linhas e colunas da matriz */
	if (ordemMatriz > ORDEM_MAXIMA_MATRIZ)
		return ordemMaximaMatrizExcedida;

	/* Teste caso matriz == NULL */
	if (!matriz) 
		return matrizNulaA;
 
	/***************************************************************************************************************
	 * Esta funcao calcula o determinante de uma matriz.                                                           *
	 * Para ordem da matriz igual a 1, o determinante e o unico elemeto da matriz.                                 *
	 * Para ordem da matriz igual a 2, sera a diferenca entre os produtos das diagonais principal e secundaria.    *
	 * Para ordem da matriz igual a 3, o determinante eh calculado usando a regra de Sarrus.                       *
	 * Para ordem da matriz maior ou igual a 4, o determinante eh calculado usando o teorema de Laplace.           *
	 **************************************************************************************************************/
	     
	if (ordemMatriz == 1)
		* determinante = matriz [0][0];
  
 	if (ordemMatriz == 2)
 	{	
		produtoDiagonalPrincipal = matriz [0][0] * matriz [1][1];
		produtoDiagonalSecundaria = matriz [0][1] * matriz [1][0];

		* determinante = produtoDiagonalPrincipal - produtoDiagonalSecundaria;	
	}

	if (ordemMatriz == 3)
	{
		primeiraDiagonalPrincipal = matriz[0][0] * matriz[1][1] * matriz[2][2];
		segundaDiagonalPrincipal = matriz[0][1] * matriz[1][2] * matriz[2][0];
		terceiraDiagonalPrincipal = matriz[0][2] * matriz[1][0] * matriz[2][1];

		somaDiagonaisPrincipais = primeiraDiagonalPrincipal + segundaDiagonalPrincipal + terceiraDiagonalPrincipal;

		primeiraDiagonalSecundaria = matriz[0][2] * matriz[1][1] * matriz[2][0];
		segundaDiagonalSecundaria = matriz[0][0] * matriz[1][2] * matriz[2][1];
		terceiraDiagonalSecundaria = matriz[0][1] * matriz[1][0] * matriz[2][2];

		somaDiagonaisSecundarias = primeiraDiagonalSecundaria + segundaDiagonalSecundaria + terceiraDiagonalSecundaria;

		* determinante = somaDiagonaisPrincipais - somaDiagonaisSecundarias;
	}
	
	/* Calculo do determinante para matrizes de ordem 4 ou superior */
	unsigned indice;	
	double produto, termo;
	
	for(indice = 0; indice < ordemMatriz; indice++)
		if(matriz [indice][0])
			{
				CalcularComplementoAlgebrico(ordemMatriz, indice + 1, 1, matriz, determinante);	
				produto = matriz [indice][0] * (*determinante);
				termo = termo + produto;
			}
			
	* determinante = termo;
			
	return ok;
		
} /* CalcularDeterminanteMatriz */
	
/* $RCSfile: aula0601.c,v $ */
