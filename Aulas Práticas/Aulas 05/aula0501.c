/***********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao das funcoes GeraDigitosVerificadoresRg e ValidarRg
 * *
 * $Author: alan.goncalves $
 * $Date: 2022/08/14 01:50:54 $
 * $Log: aula0501.c,v $
 * Revision 1.2  2022/08/14 01:50:54  alan.goncalves
 * Computacao II - Aulas Praticas - Aula05.
 * Inclusao da funcao ValidarRg.
 *
 * Revision 1.1  2022/08/10 17:06:34  alan.goncalves
 * Initial revision
 *
 ***********************************************************************************/

#include "aula0501.h"

tipoErros
GerarDigitosVerificadoresRg (byte digitosRg [COMPRIMENTO_RG])
{
	unsigned short indice;
	unsigned short soma;
	unsigned short resto;
	byte digitoVerificador;

	if (!digitosRg)
		return argumentoNulo;

	soma = 0;

	for (indice = 0; indice < COMPRIMENTO_RG - 1; indice++)
	{
		if (digitosRg [indice] > 9)
			return digitoInvalido;
		soma += digitosRg [indice] * (indice + 2);
	}

	resto = (soma % 11);

	if (resto == 0)
		digitoVerificador = 0;

	if (resto == 1)
		digitoVerificador = 'X';

	digitoVerificador = (11 - resto);

	digitosRg [indice] = digitoVerificador;
	
	return ok;

} /* GerarDigitosVerificadoresRg */

tipoErros
ValidarRg (byte digitosRg [COMPRIMENTO_RG])
{
	unsigned short indice;
	byte verificarRg [COMPRIMENTO_RG];
	tipoErros codigoRetorno;

	if (!digitosRg)
                return argumentoNulo;

	for (indice = 0; indice < COMPRIMENTO_RG - 1; indice++)
		verificarRg [indice] = digitosRg [indice];

	codigoRetorno = GerarDigitosVerificadoresRg (verificarRg);
	
	if (codigoRetorno != ok)
		return erroGerarDigitoVerificador;

	if (verificarRg [COMPRIMENTO_RG - 1] != digitosRg [COMPRIMENTO_RG - 1])
		return digitoVerificadorInvalido;

	return digitoVerificadorValido;

} /* ValidarRg */

/* $RCSfile: aula0501.c,v $ */
