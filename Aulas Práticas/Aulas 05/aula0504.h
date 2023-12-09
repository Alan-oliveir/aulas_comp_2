/**************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2022/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Alan de Oliceira Goncalves
 * Descricao: Prototipo da funcao GerarDigitosVerificadoresRg
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ***************************************************************************/

#ifndef _AULA0504_
#define _AULA0504_                "@(#)aula0504.h $Revision$"

#define COMPRIMENTO_RG            9

#define EOS                       '\0'

typedef enum
{
	ok,
	argumentoNulo,
	comprimentoArgumentoInvalido,
	digitoInvalido,
	erroGerarDigitoVerificador,
	digitoVerificadorInvalido,
	digitoVerificadorValido
} tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char* /* entrada/saida */, char* /* saida - DV */);

tipoErros
ValidarRg (char* /* entrada */);

#endif

/* $RCSfile$ */
