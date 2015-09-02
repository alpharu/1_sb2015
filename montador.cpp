#include "lib/montador.h"


int main(int argc,char **argv){ // recebe nome da input (.asm) e output (.o)
    if(argc != 3){
        printf("Quantidade de argumentos incorreta\n");
        exit(0);
    }
    string input(argv[1]);
    string output(argv[2]);
    string tempcode = "tempcode.txt";
    FILE *fp_i, *fp_o;




    input = input + ".asm"; //         precisa testar o caso que o usuario entra com extensão?
    output = output + ".o";


    printf("%s e %s \n\n %s \n",input.c_str(), output.c_str(), CODE.c_str());

    initFiles(input,output);

    tableUse(input,output);
    tableDef(input,output);
    codeOut(input,output);



    // info instruções
    // info gramática
    // info diretiva

    preProcess(input, tempcode);
    fp_i = fopen("tempcode.txt", "r");
    fp_o = fopen(output.c_str(), "r");
    //primeira passada:
    //segunda passada:




    fclose(fp_i);
    fclose(fp_o);
    remove("tempcode.txt");

    return 0;   
}


// TABLE USE
// 	ROT1 11
// 	ROT1 15
// 	ROT2 18entrada
// TABLE DEFINITION
// 	ROT3 4
// CODE
// 	14 12 12 15 04 12 5


