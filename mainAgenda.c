#include "libAgenda.h"

int main(){
    int inputAno = 0;
    struct agenda agAtual;
    struct compromisso compromissoNovo;
    char saida = 'n';
    int end = 0;
    int valido = 0;

    scanf("\n%4d", &inputAno);
    agAtual = criaAgenda(inputAno);

    do{
        valido = leCompromisso(&agAtual, &compromissoNovo);

        if(!valido)
            printf("\nData e/ou hora invalidos, compromisso nao inserido");
        else {
            valido = verificaDisponibilidade(&agAtual, &compromissoNovo);

            if(!valido)
                printf("\nData/Hora ocupada, compromisso nao inserido");
            else{
                marcaCompromisso(&agAtual, &compromissoNovo);
                printf("\nCompromisso inserido com sucesso!");
            }
        }

        scanf("\n %c", &saida);
        if(saida == 's')
            end = 1;
    
    }while(!end);

    listaCompromissos(&agAtual);
}
