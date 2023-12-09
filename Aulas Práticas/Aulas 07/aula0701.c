/*****************************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao das funcoes MostrarMonitor e GerarDistribuicaoInicial
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ****************************************************************************************/

#include <stdio.h>
#include <math.h>

#include "aula0701.h"

#define	NUMERO_MINIMO_VERTICE			3

tipoErros
MostrarMonitor (__useconds_t tempoEspera,
		tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroMaximoLinhas,
		unsigned numeroMaximoColunas)
		
{
	unsigned indiceColuna;
	unsigned indiceLinha;

	system("clear");

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS )
		return dimensaoInvalida;
	
	PrintarHifens (numeroMaximoColunas);
	printf ("\n");

	for(indiceLinha = 1; indiceLinha < numeroMaximoLinhas + 3; indiceLinha++)
	{
		printf("|");
		printf(" ");
		
		for (indiceColuna = 2; indiceColuna < numeroMaximoColunas + 2; indiceColuna++)
		{
			if ( indiceLinha == 1)
				printf(" ");

			else
			{
				if (indiceLinha == numeroMaximoLinhas + 2)
					printf(" ");
				
				else
				{
					switch (monitor [indiceLinha - 2][indiceColuna - 2])
						{
							case defeituoso:
								printf("%c", DEFEITUOSO);
								break;

							case aceso:
								printf("%c", ACESO);
								break;

							case apagado:
								printf("%c", APAGADO);
								break;
						}
				}

			}
			
		}
		
		printf(" |\n");
	}

	PrintarHifens (numeroMaximoColunas);
	
	printf ("\n\n\n\n");

	usleep (tempoEspera);
	
	return ok;
	
} /* MostrarMonitor */

void
PrintarHifens ( unsigned coluna) /* funcao auxiliar para evitar repeticao de codigo */
{
	unsigned indiceColuna;
	
	printf(" ");
	
	for (indiceColuna = 1; indiceColuna < coluna + 3; indiceColuna++)
		printf("-");
	
	printf(" ");
	
} /* PrintarHifens */

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			  unsigned numeroMaximoLinhas,
			  unsigned numeroMaximoColunas,
			  float percentualDefeituosos,
			  float percentualApagados)
			  
{
	unsigned numeroDefeituosos, numeroApagados, numeroAcesos, semente, linha, coluna;
	unsigned acesos,defeitos, apagados;
	int valor;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS )
                return dimensaoInvalida;

	if ( percentualDefeituosos + percentualApagados > 100)
		return percentualInvalido;
		
	InicializarMatriz (monitor, aceso);	

	numeroDefeituosos = (unsigned) (percentualDefeituosos * numeroMaximoLinhas * numeroMaximoColunas / 100.0);
	numeroApagados = (unsigned) (percentualApagados * numeroMaximoLinhas * numeroMaximoColunas/100.0);
	numeroAcesos = (unsigned) (numeroMaximoColunas * numeroMaximoLinhas - numeroDefeituosos - numeroApagados);
	
	acesos = 0;
	defeitos = 0;
	apagados = 0;	
	
	semente = time (NULL);
	srand (semente);

	while ( defeitos < numeroDefeituosos || apagados < numeroApagados )
	{
		linha = rand() % numeroMaximoLinhas;
		coluna = rand() % numeroMaximoColunas;

		if (monitor [linha][coluna] == aceso)
		{
			valor = (rand() % 3) -1;

			while (valor == aceso)
				valor = (rand() % 3) -1;

			if (valor == apagado)
			{
				apagados++;
				monitor[linha][coluna] = apagado;				
			}

			else if ( valor == defeituoso )
			{
				defeitos++;
				monitor[linha][coluna] = defeituoso;
			}
		}		
		
	}
			
	return ok;
	
} /* GerarDistribuicaoInicial */

tipoErros
InicializarMatriz (tipoPixel matriz [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], tipoPixel valorInicial)
{
	unsigned  indiceLinha, indiceColuna;

	for (indiceLinha = 0; indiceLinha < NUMERO_MAXIMO_LINHAS; indiceLinha++)
			for(indiceColuna = 0; indiceColuna < NUMERO_MAXIMO_COLUNAS; indiceColuna++)
					matriz [indiceLinha][indiceColuna] = valorInicial;

	return ok;
	
} /* InicializarMatriz */

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
               unsigned numeroMaximoLinhas,
               unsigned numeroMaximoColunas)
			   
{
	unsigned indiceLinha, indiceColuna;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS )
                return dimensaoInvalida;

	for (indiceLinha = 0; indiceLinha < numeroMaximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < numeroMaximoColunas; indiceColuna++)
			if (monitor [indiceLinha][indiceColuna] == aceso)
				monitor [indiceLinha][indiceColuna] = apagado;
			
	return ok;
	
} /* LimparMonitor */

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
	      unsigned numeroMaximoLinhas,
	      unsigned numeroMaximoColunas,
	      unsigned linhaA,
	      unsigned colunaA,
	      unsigned linhaB,
	      unsigned colunaB)
		  
{
	float inclinacao, passo;
	float linhaAAuxiliar, linhaBAuxiliar, colunaAAuxiliar, colunaBAuxiliar;
	float linhaAuxiliar, colunaAuxiliar;
	
	unsigned linhaAtual,colunaAtual;

	linhaAAuxiliar = (float) linhaA;
	linhaBAuxiliar = (float) linhaB;
	colunaAAuxiliar = (float) colunaA;
	colunaBAuxiliar = (float) colunaB;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS )
		return dimensaoInvalida;

	if ( linhaA > numeroMaximoLinhas || linhaB > numeroMaximoLinhas || colunaA > numeroMaximoColunas || colunaB > numeroMaximoColunas)
		return PosicaoInvalida;	

	if ( linhaA == linhaB)
	{
		if (colunaA > colunaB)
			for (colunaAtual = colunaB - 1; colunaAtual < colunaA; colunaAtual++)
			{
				if(monitor [linhaA-1][colunaAtual] == defeituoso)
					return falha;

				else
					monitor [linhaA-1][colunaAtual] = aceso;
			}

		else
			for (colunaAtual = colunaA - 1; colunaAtual < colunaB; colunaAtual++)
			{
				if(monitor [linhaA-1][colunaAtual] == defeituoso)
					return falha;

				else
					monitor [linhaA-1][colunaAtual] = aceso;
			}
	}

	else
	{
		inclinacao = (colunaBAuxiliar - colunaAAuxiliar) / (linhaBAuxiliar-linhaAAuxiliar);
		passo = 0;

		if (inclinacao <= 1 && inclinacao >= - 1)
		{		
			if (linhaA < linhaB)
				for(linhaAtual = linhaA - 1; linhaAtual < linhaB; linhaAtual++)
				{
					colunaAuxiliar = (passo + colunaA - 1);
					colunaAtual = (unsigned) colunaAuxiliar;
					
					if (monitor [linhaAtual][colunaAtual] == defeituoso)
						return falha;

					else
					{
						monitor [linhaAtual][colunaAtual] = aceso;
						passo += inclinacao;
					}
				}


			else
				for(linhaAtual = linhaA - 1; linhaAtual > linhaB - 1; linhaAtual--)
				{
					colunaAuxiliar = ((-passo) + colunaA - 1);
					colunaAtual = (unsigned) colunaAuxiliar;
					
					if (monitor [linhaAtual][colunaAtual] == defeituoso)
						return falha;

					else
					{
						monitor[linhaAtual][colunaAtual] = aceso;
						passo += inclinacao;
					}
				}
		}
		
		else
		{
			inclinacao = (linhaBAuxiliar - linhaAAuxiliar) / (colunaBAuxiliar - colunaAAuxiliar);
			
			if ( colunaA < colunaB)
				for(colunaAtual = colunaA - 1; colunaAtual < colunaB; colunaAtual++)
				{
					linhaAuxiliar = (passo) + linhaA - 1;
					linhaAtual = (unsigned) linhaAuxiliar;

					if (monitor [linhaAtual][colunaAtual] == defeituoso)
						return falha;

					else
					{
						monitor [linhaAtual][colunaAtual] = aceso;
						passo += inclinacao;
					}
				}

			else
				for(colunaAtual = colunaA - 1; colunaAtual > colunaB - 1; colunaAtual--)
				{
					linhaAuxiliar = (-passo) + linhaA-1;
					linhaAtual = (unsigned)linhaAuxiliar;
					
					if (monitor [linhaAtual][colunaAtual] == defeituoso)
						return falha;

					else
					{
						monitor [linhaAtual][colunaAtual] = aceso;
						passo += inclinacao;
					}
				}			
		}		
		
	} /* else */

	if (monitor [linhaB - 1][colunaB - 1] == defeituoso)
		return falha;

	monitor [linhaB - 1][colunaB - 1] = aceso;	

	return ok;
	
} /* DesenharReta */

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
		  unsigned numeroMaximoLinhas, 
		  unsigned numeroMaximoColunas,
		  unsigned numeroVertices,
		  unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],
		  unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS])

{  	
	unsigned linhaAtual, colunaAtual, linhaProximaima, colunaProximaima;
	
	unsigned indice;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
	    return dimensaoInvalida;
	
	if (numeroVertices < NUMERO_MINIMO_VERTICE)
	    return poligonoInvalido;
	
	if (numeroVertices > NUMERO_MAXIMO_LINHAS || numeroVertices > NUMERO_MAXIMO_COLUNAS)
	    return poligonoInvalido;
	
	for (indice = 0; indice < numeroVertices; indice++)
	{
		linhaAtual = linhasVertices[indice];
		colunaAtual = colunasVertices[indice];

		if(indice == numeroVertices - 1)
		{
			linhaProximaima = linhasVertices [0];
			colunaProximaima = colunasVertices [0];	     
		}

		else
		{
			linhaProximaima = linhasVertices [indice + 1];
			colunaProximaima = colunasVertices [indice + 1];
		}

		if (linhaAtual > numeroMaximoLinhas || colunaAtual > numeroMaximoColunas || linhaProximaima > numeroMaximoLinhas || colunaProximaima > numeroMaximoColunas || !linhaAtual || !colunaAtual || !linhaProximaima || !colunaProximaima)
			return dimensaoInvalida;	  

		DesenharReta (monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaAtual, colunaAtual, linhaProximaima, colunaProximaima);	  
	}
	
	return ok;

} /* DesenharPoligono */

tipoErros
PreencherPoligono (useconds_t tempoEspera,
		    tipoPixel monitor[NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
		    unsigned numeroMaximoLinhas,
		    unsigned numeroMaximoColunas,
		    unsigned linha,
		    unsigned coluna)
			
{
    unsigned linhaAnterior, linhaProxima, colunaAnterior, colunaProxima;    

    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
	    return dimensaoInvalida;
    
    if (linha > NUMERO_MAXIMO_LINHAS || coluna > NUMERO_MAXIMO_COLUNAS || !linha || !coluna)
	    return dimensaoInvalida;
     
    if (linha > numeroMaximoLinhas || coluna > numeroMaximoColunas)
		return dimensaoInvalida;
	    
    if (monitor [linha - 1][coluna - 1] == defeituoso)
		return falha;

    if (monitor [linha - 1][coluna - 1] == apagado)
    {
	    monitor [linha - 1][coluna - 1] = aceso;
        linhaAnterior = linha - 1;
	    linhaProxima = linha + 1;
	    colunaAnterior = coluna - 1;
	    colunaProxima = coluna + 1;
        PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaAnterior, coluna);
	    PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaProxima, coluna);
	    PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, colunaAnterior);
	    PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, colunaProxima);
    }    
  
    return ok;

} /* PreencherPoligono */

/* $RCSfile$ */