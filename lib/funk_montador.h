#ifndef FUNK_MONTADOR_H
#define FUNK_MONTADOR_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

extern const string USE;
extern const string DEF;
extern const string CODE;

typedef struct instrucao{
    string nome; 
    int opcode; // opcode
    int args; // qtd operandos - quanto ocupa na memoria
}tipoInstrucao;

typedef enum erros{ // atenção -> vale 6 pontos do trabalho!! verificar variações: comentários abaixo
    ERRO_LEXICO,
    ERRO_SINTATICO,
    ERRO_SEMANTICO,

    ERRO_REDEFINICAO, // semantico - redefinicao de simbolos
    ERRO_INVALIDO, // lexico - token invalido
    ERRO_SIMBOLO_NAO_DEFINIDO, // semantico - simbolo nao definido
    ERRO_TEXT_AUSENTE, // semantico - text ausente
    ERRO_DATA_AUSENTE, // semantico - data ausente
    ERRO_BEGIN_AUSENTE, // semantico - definicao de END mas nao de BEGIN
    ERRO_STOP_AUSENTE, // semantico - stop ausente
    ERRO_USO_INCORRETO, // sintatico - uso incorreto de token
    ERRO_COMANDO_NAO_ENCONTRADO, // sintatico - instrucao/diretiva nao encontrada
    ERRO_FALTA_DEFINICAO_EXTERN, // semantico - falta definicao de simblos extern
    ERRO_LOCAL_INCORRETO, // semantico - token no lugar errado
    ERRO_DIVISAO_POR_ZERO, // semantico - divisao por zero
    ERRO_ALTERANDO_CONSTANTE, // semantico - nao pode alterar const
    ERRO_SECTION_DATA_ANTES, // semantico - .data antes da .text
    ERRO_ACESSO_ENDERECO_NAO_RESERVADO, // semantico - segfault
    ERRO_JMP_INVALIDO, // semantico - pulo para rotulo invalido
    ERRO_OP_INVALIDO, // semantico - operacao com rotulo invalido
    ERRO_DEF_LABELS_MESMA_LINHA, // sintatico - def de mais de um simbolo na mesma linha
    ERRO_QTD_ARG, // sintatico - instrucao com qtd de argurmentos errada
    ERRO_ARG_INVALIDO, // semantico - instrucao ok mas com argumento invalido
    ERRO_ENCERRA_PROGRAMA, // semantico - nao colocar instrucao depois de STOP
    ERRO_REDEFINICAO_ROTULO, // semantico - redefinicao de rotulo
    ERRO_ARG_INCORRETO // sintatico - instrucao ou diretiva com tipo de argumento errado
}tipoErro;

// erros do Renato: correcao do monitor 
// 3 - Detecção de Erros (valor: 6.0 -> 0.2 cada)
//     erro-begin-SINTATICO: indica um erro semântico de rótulo indefinido. Porém não verifica a construção sintática de BEGIN (-0.15)
//     erro-decl-ausente-SEMANTICO  (2 linhas de erro): OK
//     erro-decl-repetida-SEMANTICO:                    OK
//     erro-desvio1-SEMANTICO:     não indica erro (-0.2)
//     erro-desvio2-SEMANTICO:     não indica erro (-0.2)
//     erro-diretiva1-SINTATICO:   não indica erro (-0.2) 
//     erro-diretiva2-SEMANTICO:   OK
//     erro-diretiva3-SINTATICO:   não indica erro (-0.2)
//     erro-divisao-SINTATICO:     OK
//     erro-end-ausente-SEMANTICO: não indica erro (-0.2)
//     erro-gramatica-SEMANTICO:   OK
//     erro-instrucao-SINTATICO (ou Lexico): Indica o erro duas vezes, mas OK. 
//     erro-LEXICO1: não indica erro (-0.2)
//     erro-LEXICO2: pode ser interpretado como erro sintático, mas, nesse caso, também deveria indicar erro léxico (-0.1) na mesma linha.
//     erro-LEXICO3: pode ser interpretado como erro semântico, mas, nesse caso, também deveria indicar erro léxico (-0.1) na linha 8.
//     erro-numero-SINTATICO:     não indica erro (-0.2)
//     erro-numero-SINTATICO2:    não indica erro (-0.2)
//     erro-operandos1-SINTATICO: OK
//     erro-operandos2-SINTATICO: OK
//     erro-output-SINTATICO: indica erro semântico e não sintático como deveria, pois a construção da intrução output está errada (-0.1)
//     erro-rotulo-ausente-SEMANTICO:  OK
//     erro-rotulo-dobrado-SINTATICO:  OK
//     erro-rotulo-repetido-SEMANTICO: OK
//     erro-secao1-SEMANTICO (ou Sintatico):  OK
//     erro-secao2-SINTATICO:  OK
//     erro-tipo1-SEMANTICO:   não indica erro (-0.2)
//     erro-tipo2-SEMANTICO:   não indica erro (-0.2)
//     erro-vetor1-SEMANTICO:  OK
//     erro-vetor2-SEMANTICO:  OK
//     erro-vetor3-SINTATICO:  não indica erro (-0.2)



typedef struct linhaErro{
    int num_linha;
    tipoErro erros;
}tipoLinhaErro;

void initFiles(string input, string output);
void tableUse(string input, string output);
void tableDef(string input, string output);
void codeOut(string input, string output);

void preProcess(string input, string tempcode);
string removeComentarios(string linha_entrada_mod);
string removeLineFeed(string linha_entrada_mod);
string removeCReturn(string linha_entrada_mod);
string modificaTabs(string linha_entrada_mod);
string modificaSpace(string linha_entrada_mod);



#endif // FUNK_MONTADOR_H

