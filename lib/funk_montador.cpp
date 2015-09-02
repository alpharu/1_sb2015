#include "funk_montador.h"

const string USE = "TABLE USE";
const string DEF = "TABLE DEFINITION";
const string CODE = "CODE";  


void initFiles(string input, string output){
    FILE *fp_i, *fp_o;

    fp_i = fopen(output.c_str(),"r");
    fp_o = fopen(output.c_str(),"w+");

    fclose(fp_i);
    fclose(fp_o);
}

void tableUse(string input, string output){
    FILE *fp_o;

    fp_o = fopen(output.c_str(), "r+");

    fprintf(fp_o, "%s\n",USE.c_str());
}

void tableDef(string input, string output){
    FILE *fp_o;

    fp_o = fopen(output.c_str(), "a");

    fprintf(fp_o, "\n%s\n",DEF.c_str());

}

void codeOut(string input, string output){
    FILE *fp_o;

    fp_o = fopen(output.c_str(), "a");

    fprintf(fp_o, "\n%s\n",CODE.c_str());

}

string removeComentarios(string linha_entrada_mod){
    std::size_t found = linha_entrada_mod.find(";");
    
    if (found != std::string::npos){
        // std::cout << "first ';' found at: " << found << '\n';
        // linha_entrada_mod.erase(found,linha_entrada_mod.end());

        linha_entrada_mod.erase(found,linha_entrada_mod.length());
    }
    return linha_entrada_mod;
}


string removeLineFeed(string linha_entrada_mod){ // \n


    return linha_entrada_mod;
}

string removeCReturn(string linha_entrada_mod){ // \r


    return linha_entrada_mod;
}

string modificaTabs(string linha_entrada_mod){

    return linha_entrada_mod;
}

string modificaSpace(string linha_entrada_mod){
    return linha_entrada_mod;
}


void preProcess(string input, string tempcode){
    FILE *fp_o;
    ifstream fp_i (input.c_str());
    string linha_entrada;


    fp_o = fopen(tempcode.c_str(), "w+");
    fprintf(fp_o, "#Arquivo Preprocessado#\n");

    //retira comentarios
    //retira espaços extra (ADD      $t1   %t2    %t1)
    //retira tab
    //etc
    // lembrar que windows: \r\n
    //             linux: \n
    //              mac: \r
    while(!fp_i.eof()){ //enquanto nao acaba o arquivo de entrada
        getline(fp_i, linha_entrada, '\n');

        if(!linha_entrada.empty()){
            linha_entrada = removeComentarios(linha_entrada);
            linha_entrada = removeCReturn(linha_entrada);
            linha_entrada = removeLineFeed(linha_entrada);
            linha_entrada = modificaSpace(linha_entrada);
            linha_entrada = modificaTabs(linha_entrada);
        }

        printf("%s\n",linha_entrada.c_str());

    }

    fp_i.close();
    fclose(fp_o);
}





