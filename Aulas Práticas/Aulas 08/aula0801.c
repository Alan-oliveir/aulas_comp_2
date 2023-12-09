/*****************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliveira Goncalves
 * Descricao: Implementacao da funcao CodificarBase16.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

tipoErros
CodificarBase16 (byte *conjuntoBytes , unsigned long long numeroBytes, char *resultado)
{
    unsigned indice, indiceResultado;

    char *alfabetoHexa;

	byte nibblesResultado [2];

	if (numeroBytes == 0)
        return argumentoNulo;
   
    alfabetoHexa = "0123456789ABCDEF";

	indiceResultado = 0;

	for (indice = 0; indice < numeroBytes; indice++)
	{
		nibblesResultado [0] = (conjuntoBytes  [indice] >> 4) & 0x0F;
		resultado  [indiceResultado] = alfabetoHexa [nibblesResultado [0]];

		nibblesResultado [1] = conjuntoBytes  [indice] & 0x0F;
		resultado [indiceResultado + 1] = alfabetoHexa [nibblesResultado [1]];

		indiceResultado += 2;
	}

	return ok;
	
} /* CodificarBase16 */

tipoErros
DecodificarBase16 (char *resultado, byte *conjuntoBytes , unsigned long long *numeroBytes)
{
	unsigned indice, 
             indiceResultado = 0,
             numeroBytesDecodificados = 0, 
             indiceAlfabeto;

    char *alfabetoHexa;
    
	byte nibblesResultado [2];
	
	alfabetoHexa = "0123456789ABCDEF";

	for (indice = 0; resultado [indice] != EOS; indice += 2)
	{
		nibblesResultado [0] = '-';
		nibblesResultado [1] = '-';


		for (indiceAlfabeto = 0; indiceAlfabeto < TAMANHO_ALFABETO_BASE16; indiceAlfabeto++)
		{
			if (resultado [indice] == alfabetoHexa [indiceAlfabeto])
			{
				nibblesResultado [0] = indiceAlfabeto;
			}
		}


		for (indiceAlfabeto = 0; indiceAlfabeto < TAMANHO_ALFABETO_BASE16; indiceAlfabeto++)
		{
			if (resultado [indice + 1] == alfabetoHexa [indiceAlfabeto])
			{
				nibblesResultado [1] = indiceAlfabeto;
			}
		}


		conjuntoBytes   [indiceResultado] = ( ( (nibblesResultado [0] << 4) & 0xF0 ) | (nibblesResultado [1] & 0x0F) );

		numeroBytesDecodificados++;
		
	}

	*numeroBytes = numeroBytesDecodificados;

	return ok;
	
} /* DecodificarBase16 */

tipoErros
CodificarBase32 (byte *conjuntoBytes , unsigned long long numeroBytes, tipoAlfabetoBase32 alfabeto, char *resultado)
{
	char *alfabetoBase32, 
         *alfabetoEstendidoBase32;

  	unsigned long long indice = 0, 
                       indiceResultado = 0, 
                       indiceByte = 0;

 	unsigned numero5Bits,
             conjuntoMenor,
             conjunto5bits;

  	byte conjuntoResultado5bits [5],
         conjuntoByteResultado [8];


  	if (numeroBytes == 0)
    {
        return argumentoNulo;
    }


  	numero5Bits = numeroBytes / 5;
  	conjuntoMenor = numeroBytes % 5;

    alfabetoBase32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
  	alfabetoEstendidoBase32 = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";

	
  	if (alfabeto == 0)
	{
    	for (conjunto5bits = 1; conjunto5bits <= numero5Bits; conjunto5bits++)
		{
      		for (indice = 0; indice < 5; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
              

			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
     		resultado  [indiceResultado] = alfabetoBase32 [conjuntoByteResultado [0]];
      		

			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoBase32 [conjuntoByteResultado [1]];
      		

			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoBase32 [conjuntoByteResultado [2]];
      		

			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoBase32 [conjuntoByteResultado [3]];
      		

			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoBase32 [conjuntoByteResultado [4]];
      		

			conjuntoByteResultado [5] = (conjuntoResultado5bits [3] >> 2) & 0x1F;
      		resultado [indiceResultado + 5] = alfabetoBase32 [conjuntoByteResultado [5]];
      		

			conjuntoByteResultado [6] = ((conjuntoResultado5bits [3] << 3) & 0x18) | ((conjuntoResultado5bits [4] >> 5) & 0x07);
      		resultado [indiceResultado + 6] = alfabetoBase32 [conjuntoByteResultado [6]];
      		

			conjuntoByteResultado [7] = conjuntoResultado5bits [4] & 0x1F;
      		resultado [indiceResultado + 7] = alfabetoBase32 [conjuntoByteResultado [7]];
    

            indiceResultado += 8;
      		indice = 0;
		}
		
		if (conjuntoMenor == 4)
		{
      		for (indice = 0; indice < 4; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      			
			conjuntoResultado5bits [indice] = 0b00000000;
      		
      			
			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
     		resultado  [indiceResultado] = alfabetoBase32 [conjuntoByteResultado [0]];
      		

			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoBase32 [conjuntoByteResultado [1]];
      		

			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoBase32 [conjuntoByteResultado [2]];
      		

			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoBase32 [conjuntoByteResultado [3]];
      		

			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoBase32 [conjuntoByteResultado [4]];
      		

			conjuntoByteResultado [5] = (conjuntoResultado5bits [3] >> 2) & 0x1F;
      		resultado [indiceResultado + 5] = alfabetoBase32 [conjuntoByteResultado [5]];
      		

			conjuntoByteResultado [6] = ((conjuntoResultado5bits [3] << 3) & 0x18) | ((conjuntoResultado5bits [4] >> 5) & 0x07);
      		resultado [indiceResultado + 6] = alfabetoBase32 [conjuntoByteResultado [6]];
      	
      			
      		resultado [indiceResultado + 7] = alfabetoBase32 [32];


            indiceResultado += 8;
      		indice = 0;
		}

		else if (conjuntoMenor == 3)
		{
      		for (indice = 0; indice < 3; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      		

            while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }


			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
     		resultado  [indiceResultado] = alfabetoBase32 [conjuntoByteResultado [0]];
      		

			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoBase32 [conjuntoByteResultado [1]];
      		

			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoBase32 [conjuntoByteResultado [2]];
      		

			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoBase32 [conjuntoByteResultado [3]];
      		

			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoBase32 [conjuntoByteResultado [4]];


      		for (indiceResultado += 5; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoBase32 [32];
            }


            indiceResultado += 8;
      		indice = 0;
  	  	}

		else if (conjuntoMenor == 2)
		{
      		for (indice = 0; indice < 2; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      		
			while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
      		
			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
     		resultado  [indiceResultado] = alfabetoBase32 [conjuntoByteResultado [0]];
      		

			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoBase32 [conjuntoByteResultado [1]];
      		

			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoBase32 [conjuntoByteResultado [2]];
      		

			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoBase32 [conjuntoByteResultado [3]];
      		

      		for (indiceResultado += 4; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoBase32 [32];
            }


            indiceResultado += 8;
      		indice = 0;
		}

		else if (conjuntoMenor == 1)
		{
      		conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
            indice++;
      		indiceByte++;

            while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
              
      		
			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
     		resultado  [indiceResultado] = alfabetoBase32 [conjuntoByteResultado [0]];
      		

			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoBase32 [conjuntoByteResultado [1]];
      		

      		for (indiceResultado += 2; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoBase32 [32];
            }


            indiceResultado += 8;
      		indice = 0;
    	}
	}


	else
	{
    	for (conjunto5bits = 1; conjunto5bits <= numero5Bits; conjunto5bits++)
		{
     		for (indice = 0; indice < 5; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }


			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
      		resultado  [indiceResultado] = alfabetoEstendidoBase32 [conjuntoByteResultado [0]];

      			
			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoEstendidoBase32 [conjuntoByteResultado [1]];

      			
			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoEstendidoBase32 [conjuntoByteResultado [2]];
 
     			
			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoEstendidoBase32 [conjuntoByteResultado [3]];

      			
			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoEstendidoBase32 [conjuntoByteResultado [4]];

      			
			conjuntoByteResultado [5] = (conjuntoResultado5bits [3] >> 2) & 0x1F;
      		resultado [indiceResultado + 5] = alfabetoEstendidoBase32 [conjuntoByteResultado [5]];

      			
			conjuntoByteResultado [6] = ((conjuntoResultado5bits [3] << 3) & 0x18) | ((conjuntoResultado5bits [4] >> 5) & 0x07);
      		resultado [indiceResultado + 6] = alfabetoEstendidoBase32 [conjuntoByteResultado [6]];

      			
			conjuntoByteResultado [7] = conjuntoResultado5bits [4] & 0x1F;
      		resultado [indiceResultado + 7] = alfabetoEstendidoBase32 [conjuntoByteResultado [7]];


            indiceResultado += 8;
      		indice = 0;
		}


		if (conjuntoMenor == 4)
		{
      		for (indice = 0; indice < 4; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      		

			while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
      			
      			
			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
      		resultado  [indiceResultado] = alfabetoEstendidoBase32 [conjuntoByteResultado [0]];

      			
			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoEstendidoBase32 [conjuntoByteResultado [1]];

      			
			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoEstendidoBase32 [conjuntoByteResultado [2]];
 
     			
			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoEstendidoBase32 [conjuntoByteResultado [3]];

      			
			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoEstendidoBase32 [conjuntoByteResultado [4]];

      			
			conjuntoByteResultado [5] = (conjuntoResultado5bits [3] >> 2) & 0x1F;
      		resultado [indiceResultado + 5] = alfabetoEstendidoBase32 [conjuntoByteResultado [5]];

      			
			conjuntoByteResultado [6] = ((conjuntoResultado5bits [3] << 3) & 0x18) | ((conjuntoResultado5bits [4] >> 5) & 0x07);
      		resultado [indiceResultado + 6] = alfabetoEstendidoBase32 [conjuntoByteResultado [6]];
      	
      			
      		resultado [indiceResultado + 7] = alfabetoEstendidoBase32 [32];


            indiceResultado += 8;
      		indice = 0;
		}


		else if (conjuntoMenor == 3)
		{
      		for (indice = 0; indice < 3; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      		

			while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
      			

			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
      		resultado  [indiceResultado] = alfabetoEstendidoBase32 [conjuntoByteResultado [0]];

      			
			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoEstendidoBase32 [conjuntoByteResultado [1]];

      			
			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoEstendidoBase32 [conjuntoByteResultado [2]];
 
     			
			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoEstendidoBase32 [conjuntoByteResultado [3]];

      			
			conjuntoByteResultado [4] = ((conjuntoResultado5bits [2] << 1) & 0x1E) | ((conjuntoResultado5bits [3] >> 7) & 0x01);
      		resultado [indiceResultado + 4] = alfabetoEstendidoBase32 [conjuntoByteResultado [4]];

      		
            for (indiceResultado += 5; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoEstendidoBase32 [32];
            }


            indiceResultado += 8;
      		indice = 0;
		}


		else if (conjuntoMenor == 2)
		{
      		for (indice = 0; indice < 2; indice++)
            {
                conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
                indiceByte++;
            }
      		

			while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
      			

			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
      		resultado  [indiceResultado] = alfabetoEstendidoBase32 [conjuntoByteResultado [0]];

      			
			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoEstendidoBase32 [conjuntoByteResultado [1]];

      			
			conjuntoByteResultado [2] = (conjuntoResultado5bits [1] >> 1) & 0x1F;
      		resultado [indiceResultado + 2] = alfabetoEstendidoBase32 [conjuntoByteResultado [2]];
 
     			
			conjuntoByteResultado [3] = ((conjuntoResultado5bits [1] << 4) & 0x10) | ((conjuntoResultado5bits [2] >> 4) & 0x0F);
      		resultado [indiceResultado + 3] = alfabetoEstendidoBase32 [conjuntoByteResultado [3]];

      		
            for (indiceResultado += 4; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoEstendidoBase32 [32];
            }

            indiceResultado += 8;
      		indice = 0;
		}


		else if (conjuntoMenor == 1)
		{
      		conjuntoResultado5bits [indice] = conjuntoBytes  [indiceByte];
      		indice++;
      		indiceByte++;
      			
			while (indice < 5)
            {
                conjuntoResultado5bits [indice] = 0b00000000;
                indice++;
            }
      			
            
			conjuntoByteResultado [0] = (conjuntoResultado5bits [0] >> 3) & 0x1F;
      		resultado  [indiceResultado] = alfabetoEstendidoBase32 [conjuntoByteResultado [0]];

      			
			conjuntoByteResultado [1] = ((conjuntoResultado5bits [0] << 2) & 0x1C) | ((conjuntoResultado5bits [1] >> 6) & 0x03);
      		resultado [indiceResultado + 1] = alfabetoEstendidoBase32 [conjuntoByteResultado [1]];

      		
            for (indiceResultado += 2; indiceResultado < 7; indiceResultado++)
            {
                resultado  [indiceResultado] = alfabetoEstendidoBase32 [32];
            }


            indiceResultado += 8;
      		indice = 0;
    	}
  	}

	return ok;
	
} /* CodificarBase32 */

tipoErros
DecodificarBase32 (char *stringBase32, tipoAlfabetoBase32 alfabeto, byte *conjuntoBytes , unsigned long long *numeroBytes)
{
	char *alfabetoBase32, 
         *alfabetoEstendidoBase32;

  	unsigned indice = 0,
	  		 indiceAuxiliar = 0, 
             indiceResultado = 0,
             indiceAlfabeto,
             numeroBytesRecebida = 0;

  	byte conjuntoByteResultado [8];


	alfabetoBase32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
	alfabetoEstendidoBase32 = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";

	
	for (indice = 0; stringBase32 [indice] != '\0'; indice = indice + 8)
	{
		
		while (indiceAuxiliar < 8)
		{
			conjuntoByteResultado [indiceAuxiliar] = '-';

			indiceAuxiliar++;
		}
		
		indiceAuxiliar = 0;
		
		if (alfabeto == 0)
		{
			while (indiceAuxiliar < 8)
			{
				for (indiceAlfabeto = 0; indiceAlfabeto <= 32; indiceAlfabeto++)
				{
					if (alfabetoBase32 [indiceAlfabeto] == stringBase32 [indice + indiceAuxiliar] )
					{
						conjuntoByteResultado [indiceAuxiliar] = indiceAlfabeto;
					}
				}


				if (conjuntoByteResultado [indiceAuxiliar] == '-')
				{
					return argumentoInvalido;
				}


				indiceAuxiliar++;
			}

			indiceAuxiliar = 0;
		}


		else
		{
			while (indiceAuxiliar < 8)
			{
				for (indiceAlfabeto = 0; indiceAlfabeto <= 32; indiceAlfabeto++)
				{
					if (alfabetoEstendidoBase32 [indiceAlfabeto] == stringBase32 [indice + indiceAuxiliar] )
					{
						conjuntoByteResultado [indiceAuxiliar] = indiceAlfabeto;
					}
				}
			
				if (conjuntoByteResultado [indiceAuxiliar] == '-')
				{
					return argumentoInvalido;
				}


				indiceAuxiliar++;
			}
			
			indiceAuxiliar = 0;
    	}      
		

		if (conjuntoByteResultado [2] == 32)
		{
			conjuntoBytes  [indiceResultado] = ((conjuntoByteResultado [0] << 3) & 0xF8) | ((conjuntoByteResultado [1] >> 2) & 0x07);
			indiceResultado++;
			numeroBytesRecebida++;
		}


		else if (conjuntoByteResultado [4] == 32)
		{
			conjuntoBytes  [indiceResultado] = ((conjuntoByteResultado [0] << 3) & 0xF8) | ((conjuntoByteResultado [1] >> 2) & 0x07);

			conjuntoBytes  [indiceResultado + 1] = ((conjuntoByteResultado [1] << 6) & 0xC0) | ((conjuntoByteResultado [2] << 1) & 0x3E) | ((conjuntoByteResultado [3] >> 4) & 0x01);

			indiceResultado += 2;
			numeroBytesRecebida += 2;
		}

		else if (conjuntoByteResultado [5] == 32)
		{
			conjuntoBytes  [indiceResultado] = ((conjuntoByteResultado [0] << 3) & 0xF8) | ((conjuntoByteResultado [1] >> 2) & 0x07);
			
			conjuntoBytes  [indiceResultado + 1] = ((conjuntoByteResultado [1] << 6) & 0xC0) | ((conjuntoByteResultado [2] << 1) & 0x3E) | ((conjuntoByteResultado [3] >> 4) & 0x01);
			
			conjuntoBytes  [indiceResultado + 2] = ((conjuntoByteResultado [3] << 4) & 0xF0) | ((conjuntoByteResultado [4] >> 1) & 0x0F);

			indiceResultado += 3;
			numeroBytesRecebida += 3;
		}

		else if (conjuntoByteResultado [7] == 32)
		{
	      	conjuntoBytes  [indiceResultado] = ((conjuntoByteResultado [0] << 3) & 0xF8) | ((conjuntoByteResultado [1] >> 2) & 0x07);
		    
			conjuntoBytes  [indiceResultado + 1] = ((conjuntoByteResultado [1] << 6) & 0xC0) | ((conjuntoByteResultado [2] << 1) & 0x3E) | ((conjuntoByteResultado [3] >> 4) & 0x01);
			
			conjuntoBytes  [indiceResultado + 2] = ((conjuntoByteResultado [3] << 4) & 0xF0) | ((conjuntoByteResultado [4] >> 1) & 0x0F);
			
			conjuntoBytes  [indiceResultado + 3] = ((conjuntoByteResultado [4] << 7) & 0x80) | ((conjuntoByteResultado [5] << 2) & 0x7C) | ((conjuntoByteResultado [6] >> 3) & 0x03);
			

			indiceResultado += 4;
			numeroBytesRecebida += 4;
		}

		else
		{
			conjuntoBytes  [indiceResultado] = ((conjuntoByteResultado [0] << 3) & 0xF8) | ((conjuntoByteResultado [1] >> 2) & 0x07);
			
			conjuntoBytes  [indiceResultado + 1] = ((conjuntoByteResultado [1] << 6) & 0xC0) | ((conjuntoByteResultado [2] << 1) & 0x3E) | ((conjuntoByteResultado [3] >> 4) & 0x01);
			
			conjuntoBytes  [indiceResultado + 2] = ((conjuntoByteResultado [3] << 4) & 0xF0) | ((conjuntoByteResultado [4] >> 1) & 0x0F);
			
			conjuntoBytes  [indiceResultado + 3] = ((conjuntoByteResultado [4] << 7) & 0x80) | ((conjuntoByteResultado [5] << 2) & 0x7C) | ((conjuntoByteResultado [6] >> 3) & 0x03);
		
			conjuntoBytes  [indiceResultado + 4] = ((conjuntoByteResultado [6] << 5) & 0xE0) | (conjuntoByteResultado [7] & 0x1F);

			indiceResultado += 5;
			numeroBytesRecebida += 5;
		}
	  }


	*numeroBytes = numeroBytesRecebida;


	return ok;
	
} /* DecodificarBase32 */

tipoErros
CodificarBase64 (byte *conjuntoBytes , unsigned long long numeroBytes, tipoFinalLinha indicadorFinalLinha, char *resultado)
{
	unsigned indice, 
			 indiceConjuntoBits, 
			 bitsRestantes, 
			 numeroCaracteres = 0, 
			 numero3bits, 
			 numeroBitsConjunto, 
			 indiceString = 0,
			 indiceAuxiliar = 0,
			 indiceWhile = 0;

	byte conjuntoResultado3bits[3], 
		 indiceResultado [4];
	
	char *alfabetoBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


	if (numeroBytes == 0) 
	{
		return argumentoNulo;
	}
		

	numero3bits = numeroBytes/3;

	bitsRestantes = numeroBytes % 3;


	if (bitsRestantes != 0) 
	{
		numero3bits += 1;
	}

    else 
	{
		bitsRestantes = 3;
	}


		for (indiceConjuntoBits = 1; indiceConjuntoBits <= numero3bits; indiceConjuntoBits += 1) 
		{
			numeroBitsConjunto = 3;

			if (indiceConjuntoBits == numero3bits)
			{
				for (indice = 0; indice < bitsRestantes; indice++)
				{
					conjuntoResultado3bits[indice] = conjuntoBytes  [(indice) + ((numero3bits-1) * 3)];
				}


				if (bitsRestantes != 0)
			    {			
					numeroBitsConjunto = bitsRestantes;
				}
			}


		    else
			{
				while (indiceWhile < 3)
				{
					conjuntoResultado3bits[indiceWhile] = conjuntoBytes  [(indiceConjuntoBits-1) * 3 + indiceWhile];
					indiceWhile++;
				}
			}


			indiceResultado [0] = (conjuntoResultado3bits[0] >> 2) & 0x3F;
			resultado[indiceString] = alfabetoBase64 [indiceResultado [0]];

			indiceString++;
			numeroCaracteres++;
			

			if (indicadorFinalLinha == 1)
			{
				if (numeroCaracteres % 76 == 0) 
				{
					resultado[indiceString + 1] = PULA_LINHA;
					indiceString += 2;
				}
			}


			if (numeroBitsConjunto == 1) 
			{
				indiceResultado [1] = ((conjuntoResultado3bits[0] << 4) & 0x30);	
				resultado[indiceString] = alfabetoBase64 [indiceResultado [1]];

				indiceString++;
				numeroCaracteres++;

				if (indicadorFinalLinha == 1)
				{	
					if (numeroCaracteres % 76 == 0) 
					{
						resultado[indiceString+1] = PULA_LINHA;
						indiceString += 2;
					}
				}

			}


		    else 
			{ 
				indiceResultado [1] = ((conjuntoResultado3bits[0] << 4) & 0x30) | ((conjuntoResultado3bits[1] >> 4) & 0x0F);
				resultado[indiceString] = alfabetoBase64 [indiceResultado [1]];

				indiceString++;
				numeroCaracteres++;

				if (indicadorFinalLinha == 1)
				{
					if (numeroCaracteres % 76 == 0) 
					{
						resultado[indiceString+1] = PULA_LINHA;
						indiceString += 2;
					}
				}


				if (numeroBitsConjunto == 2)
			    {
					indiceResultado [2] = ((conjuntoResultado3bits[1]) << 2 & 0x3C);
					resultado[indiceString] = alfabetoBase64 [indiceResultado [2]];

					indiceString++;
					numeroCaracteres++;

					if (indicadorFinalLinha == 1)
					{
						if (numeroCaracteres % 76 == 0)
				       	{
							resultado[indiceString+1] = PULA_LINHA;
							indiceString += 2;
						}
					}

				} 


				else 
				{
					indiceResultado [2] = ((conjuntoResultado3bits[1]) << 2 & 0x3C) | ((conjuntoResultado3bits[2] >> 6 & 0x03));
					resultado[indiceString] = alfabetoBase64 [indiceResultado [2]];

					indiceString++;
					numeroCaracteres++;

					if (indicadorFinalLinha == 1)
					{

						if (numeroCaracteres % 76 == 0)
						{
							resultado[indiceString+1] = PULA_LINHA;
							indiceString += 2;
						}
					}


					indiceResultado [3] = ((conjuntoResultado3bits[2]) & 0x3F);
					resultado[indiceString] = alfabetoBase64 [indiceResultado [3]];

					indiceString++;
					numeroCaracteres++;


					if (indicadorFinalLinha == 1)
					{
						if (numeroCaracteres % 76 == 0) 
						{
							resultado[indiceString+1] = PULA_LINHA;
							indiceString += 2;
						}
					}
				}
			}
		}
	
		if (bitsRestantes > 0)
	    {
			resultado[indiceString] = PADDING;
			indiceString ++;

			if (bitsRestantes == 1) 
			{
				resultado[indiceString] = PADDING;
				indiceString ++;	
			}
		}

		resultado[indiceString] = EOS;

		indiceAuxiliar++;
	
	return ok;
	
} /* CodificarBase64 */

tipoErros
DecodificarBase64 (char *resultado, tipoFinalLinha indicadorFinalLinha, byte *conjuntoBytes , unsigned long long *numeroBytes)
{
	unsigned indice = 0, 
			 numeroRepetidos = 0, 
			 numero4Bits = 0, 
			 indiceAuxiliar, 
			 indiceString, 
			 indiceResultado, 
			 entradasConvertidas[2000];
	
	byte byteDecodificado;
	
	
	while (resultado [indice] != EOS) 
	{	
		
		if (numeroRepetidos == 2)
		{		
			return baseInvalida;
		}

	    else if ((indice) % 4 == 0) 
		{
			numero4Bits ++;
		}

		switch (resultado [indice]) 
		{	
			case '=':
			{
				indiceAuxiliar = 64;
			}
			break;

			case '+':
			{
				indiceAuxiliar = 62;
			}
			break;

			case '/':
			{
				indiceAuxiliar = 63;
			}
			break;

			default:
			{
				if (resultado [indice] >= 'A' && resultado [indice] <= 'Z') 
				{
					indiceAuxiliar = resultado [indice] - 'A';
				} 


				else if (resultado [indice] >= 'a' && resultado [indice] <= 'z')
				{
					indiceAuxiliar = resultado [indice] - 'a' + 26;
				} 


				else if (resultado [indice] >= '0' && resultado [indice] <= '9')
				{
					indiceAuxiliar = resultado [indice] - '0' + 52;			
				} 


				else 
				{
					indiceAuxiliar = FORA_BASE_64;
				}

			}

		}


		if (indiceAuxiliar == 64)
	    {
			if ((indice + 1) % 4 != 0 && (indice + 2) % 4 != 0)
		    {	
				return baseInvalida;
			}
		
			numeroRepetidos += 1;
		} 


		else if (indiceAuxiliar == FORA_BASE_64) 
		{	
			return argumentoInvalido;
		} 


		else if (numeroRepetidos == 0)
		{
			if (resultado [indice+1] == EOS && (indice + 1) % 4 != 0)
		    {	
				return baseInvalida;
			}
		
			entradasConvertidas[indice] = indiceAuxiliar;
			
		}


		else 
		{	
			return baseInvalida;
		}
	
	
		indice++;
	}


	indiceResultado = 0;
	indiceString = 0;
	

	for (indice = 0; indice < numero4Bits; indice++)
    {
		if (indice == numero4Bits - 1)
		{	
			byteDecodificado = ((entradasConvertidas[indiceString] << 2) & 0xFC) | ((entradasConvertidas[indiceString+1] >> 4) & 0x03);
	
			if (numeroRepetidos < 2)
		    {	
				byteDecodificado = ((entradasConvertidas[indiceString+1] << 4) & 0xF0) | ((entradasConvertidas[indiceString+2] >> 2) & 0X0F);
				conjuntoBytes [indiceResultado] = byteDecodificado;
			
				indiceResultado ++;

				if (numeroRepetidos == 0) 
				{
					byteDecodificado = ((entradasConvertidas[indiceString+2] << 6) & 0xC0) | (entradasConvertidas[indiceString + 3] & 0x3F);
					conjuntoBytes [indiceResultado] = byteDecodificado;
				
					indiceResultado ++;
				}
			}
		}


		else 
		{
			byteDecodificado = ((entradasConvertidas[indiceString] << 2) & 0xFC) | ((entradasConvertidas[indiceString + 1] >> 4) & 0x03);
			conjuntoBytes [indiceResultado] = byteDecodificado;


			byteDecodificado = ((entradasConvertidas[indiceString+1] << 4) & 0xF0) | ((entradasConvertidas[indiceString + 2] >> 2) & 0x0F);
			conjuntoBytes [indiceResultado + 1] = byteDecodificado;
				

			byteDecodificado = ((entradasConvertidas[indiceString+2] << 6) & 0xC0) | ((entradasConvertidas[indiceString + 3]) & 0x3F);
			conjuntoBytes [indiceResultado + 2] = byteDecodificado;


			indiceResultado += 3;
			indiceString += 4;
		}	

	}
	

	conjuntoBytes [indiceResultado] = EOS;


	*numeroBytes = indiceResultado;

	return ok;
	
} /* DecodificarBase64 */

/* $RCSfile$ */ 