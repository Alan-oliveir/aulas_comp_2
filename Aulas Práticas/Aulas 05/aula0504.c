/**************************************************************************
 * 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Implementacao da funcao GeraDigitosVerificadoresRg.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ***************************************************************************/

#include <string.h>

#include "aula0504.h"

tipoErros
GerarDigitosVerificadoresRg (char* digitosRg, char* digitoVerificadorSaida)
{
	unsigned short indice;
	unsigned short soma;
	unsigned short resto;
	char digitoVerificador;

	if (!digitosRg)
		return argumentoNulo;

	if (strlen (digitosRg) != COMPRIMENTO_RG - 1)
		return comprimentoArgumentoInvalido;

	soma = 0;

	for (indice = 0; indice < COMPRIMENTO_RG - 1; indice++)
		soma += (digitosRg [indice] - '0') * (indice + 2);
	
	resto = (soma % 11);
	digitoVerificador = (11 - resto);
	digitosRg [indice] = (digitoVerificador + '0');

	if (resto == 0)
	{
		digitoVerificador = '0';
		digitosRg [indice] = digitoVerificador;
	}

	if (resto == 1)
	{
		digitoVerificador = 'X';
		digitosRg [indice] = digitoVerificador;
	}

	if ((digitoVerificador != '0') || (digitoVerificador != 'X'))
		digitoVerificador = (digitoVerificador + '0');
	
	digitoVerificadorSaida = &digitoVerificador;
	digitosRg [indice + 1] = EOS;

	return ok;
	
} /* GerarDigitosVerificadoresRg */

tipoErros
ValidarRg (char* digitosRg)
{
	unsigned short indice;
	char* verificarRg;
	char digitoVerificadorRg;
	tipoErros codigoRetorno;
	
	if (!digitosRg)
		return argumentoNulo;

	verificarRg = "0";

	for (indice = 0; indice < COMPRIMENTO_RG - 1; indice++)
		verificarRg [indice] = digitosRg [indice];

	codigoRetorno = GerarDigitosVerificadoresRg (verificarRg, &digitoVerificadorRg);
	
	if (codigoRetorno != ok)
		return erroGerarDigitoVerificador;

	if (verificarRg [COMPRIMENTO_RG - 1] != digitosRg [COMPRIMENTO_RG - 1])
		return digitoVerificadorInvalido;

	return digitoVerificadorValido;
	
} /* ValidarRg */

/* $RCSfile$ */
