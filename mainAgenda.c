#include "libAgenda.h"

int main(){
    struct agenda agendaAtual;
    struct compromisso compromissoNovo;
    int opcao;
    int disponivel = 0;
    int end = 0;
    char saida;

    agendaAtual = criaAgenda(2023);

    while(end == 0){
    
        printf("\n==================");
        printf("\nMENU AGENDA 2023");
        printf("\n");
        printf("\nSelecione uma das opcoes:");
        printf("\n");
        printf("\n(1) Marcar novo compromisso.");
        printf("\n(2) Verificar compromissos existentes.");
            scanf("%d", &opcao);

        if(opcao == 1){
            compromissoNovo = leCompromisso(agendaAtual);

        }
        if(opcao == 2){
            listaCompromissos(agendaAtual);
        }

        printf("\nVocê quer sair do programa? (s/n)\n ");
        scanf("\n %c", &saida);
        if(saida == 's'){
            printf("\nMenu encerrado.");
            end = 1;
        }

    }

}
