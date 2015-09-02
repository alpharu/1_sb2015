#include "lib/ligador.h"

using namespace std;
//fazer ligacao entre os dois primeiros modulos resultando em um arquivo de saida
int main(int argc,char **argv){ // recebe 3: .o (texto com opcodes e operandos sem quebra de linha ) .o .e
    string arg_entrada(argv[1]);
    string arg_saida(argv[2]);

    string entrada = arg_entrada + ".asm";
    string saida = arg_saida + ".o";

    printf("%s e %s \n",entrada.c_str(), saida.c_str());



    return 0;

}
