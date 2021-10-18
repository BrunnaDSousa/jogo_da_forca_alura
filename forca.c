//by: Brunna Sousa out/2021
//array de chars 

#include <stdio.h>
#include <string.h>

//VARIAVEIS GLOBAIS = nao precisa mais passar os parametros/ponteiro como abaixo
char palavrasecreta [20];
char chutes[26]; //chutes do usuario
int chutesdados = 0;//quantos chutes ele deu 

void abertura(){
    printf("********************\n");
    printf("*  Jogo de Forca  * \n");
    printf("********************\n");
}

void chuta(){ 
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados ] = chute;  // * pegar o conteudo que esse ponteiro aponta
    chutesdados++; 

}

int jachutou(char letra){ //a letra ja foi chutada?
    int achou = 0;

    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra ) {
            achou = 1;
            break;
        }
    }
    
    return achou; //pq precisa saber o resultado do achou dps de resolver = achou
}

void desenhaforca(){
    for(int i = 0; i < strlen(palavrasecreta); i++) {  //imprime a palavra secreta

        int achou = jachutou(palavrasecreta[i]);
            
        if(achou) {
            printf("%c", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");

}

void escolhepalavra(){
    sprintf(palavrasecreta,"MELANCIA" );//de string: parametro + palavra
}

int enforcou (){

    int erros = 0;

    for(int i = 0; i < chutesdados; i++){
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta){

                existe = 1;
                break;
            }
        }

        if( !existe ) erros++;
    }

    return erros >= 7; //deixa errar so 5x

}


int main (){
    
    int acertou = 0;

    escolhepalavra(palavrasecreta);
    abertura();

    do {//pra executar 1x
        
        desenhaforca(palavrasecreta, chutes, chutesdados);
        chuta(chutes, &chutesdados); // & pegar o endereço de memória da variavel
            

    } while (!acertou && !enforcou());

}






//CODIGO SEM AS VARIAVEIS GLOBAIS E OS PARAMETROS / PONTEIROS
/*
#include <stdio.h>
#include <string.h>

void abertura(){
    printf("********************\n");
    printf("*  Jogo de Forca  * \n");
    printf("********************\n");
}

void chuta(char chutes[26], int* tentativas){ //guardar o chute do jogador - captura um novo chute
    char chute;
    scanf(" %c", &chute);

    chutes[ (*tentativas) ] = chute;  // * pegar o conteudo que esse ponteiro aponta
    (*tentativas)++; 

}

int jachutou(char letra, char chutes[26], int tentativas){ //a letra ja foi chutada?
    int achou = 0;

    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra ) {
            achou = 1;
            break;
        }
    }
    
    return achou; //pq precisa saber o resultado do achou dps de resolver = achou
}

void desenhaforca(char palavrasecreta[20], char chutes[26], int tentativas ){
    for(int i = 0; i < strlen(palavrasecreta); i++) {  //imprime a palavra secreta

        int achou = jachutou(palavrasecreta[i], chutes, tentativas );
            
        if(achou) {
            printf("%c", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");

}

void escolhepalavra(char palavrasecreta[20]){
    sprintf(palavrasecreta,"MELANCIA" );//de string: parametro + palavra
}

int main (){
    char palavrasecreta [20];

    int acertou = 0;
    int enforcou = 0;

    char chutes[26]; //chutes do usuario
    int tentativas = 0;//quantos chutes ele deu 

    escolhepalavra(palavrasecreta);
    abertura();

    do {//pra executar 1x
        
        desenhaforca(palavrasecreta, chutes, tentativas);
        chuta(chutes, &tentativas); // & pegar o endereço de memória da variavel
            

    } while (!acertou && !enforcou);

}



*/

