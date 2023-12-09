/***********************************************************************
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
 * $Author: alan.goncalves $
 * $Date: 2022/08/14 01:49:31 $
 * $Log: aula0501.h,v $
 * Revision 1.2  2022/08/14 01:49:31  alan.goncalves
 * Computacao II - aulas praticas - Aula05
 * Inclusao do prototipo da funcao ValidarRg.
 *
 * Revision 1.1  2022/08/10 17:05:10  alan.goncalves
 * Initial revision
 *
 * 
 ***********************************************************************/

#ifndef _AULA0501_
#define _AULA0501_                "@(#)aula0501.h $Revision: 1.2 $"

#define COMPRIMENTO_RG            9

typedef unsigned char byte;

typedef enum
{
	ok,
	argumentoNulo,
	digitoInvalido,
	erroGerarDigitoVerificador,
	digitoVerificadorInvalido,
	digitoVerificadorValido
} tipoErros;

tipoErros
GerarDigitosVerificadoresRg (byte[] /* entrada/saida */);

tipoErros
ValidarRg (byte [] /* entrada */);

#endif

/* $RCSfile: aula0501.h,v $ */
