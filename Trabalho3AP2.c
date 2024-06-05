#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cipherChar(char mensagem, char chave){
    if(mensagem >= 'A' && mensagem <= 'Z' || mensagem >= 'a' && mensagem <= 'z'){
        int desloc, ajuste;

        if(chave >= 'a' && chave <= 'z'){
            desloc = chave - 'a';
        }
        else{
            desloc = chave - 'A';
        }

        if(mensagem >= 'a' && mensagem <= 'z'){
            ajuste = 'a';
        }
        else{
            ajuste = 'A';
        }
        return((mensagem - ajuste + desloc) % 26) + ajuste;
    }
    else{
        return mensagem;
    }
}

void cipherMensagem(char *mensagem, char *chave, char *msgCipher){
    int msgLen, chvLen;
    msgLen = strlen(mensagem);
    chvLen = strlen(chave);

    for(int i = 0, j = 0; j < msgLen; j++){
        msgCipher[j] = cipherChar(mensagem[j], chave[i %chvLen]);
        if(mensagem[j] >= 'A' && mensagem[j] <= 'Z' || mensagem[j] >= 'a' && mensagem[j] <= 'z'){
            i++;
        }
    }
    msgCipher[msgLen] = '\0'; // fim da mensagem
}

int main(){
    char mensagem[500], chave[500], msgCipher[500];
    printf("Digite a mensagem aberta: ");
    gets(mensagem);
    printf("Digite a palavra-chave: ");
    gets(chave);

    cipherMensagem(mensagem, chave, msgCipher);
    printf("Mensagem cifrada: %s\n", msgCipher);
    return 0;
}
