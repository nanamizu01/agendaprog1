#include "libAgenda.h"

int main(){
    struct agenda agendaAtual;
    struct compromisso compromissoNovo;
    int opcao;
    int disponivel = 0;
    int valido = 0;
    int end = 0;
    char saida;

    agendaAtual = criaAgenda(2023);

    while(end == 0){
    
        printf("\n==================");
        printf("\nMENU AGENDA.");
        printf("\n");
        printf("\nSelecione uma das opcoes:");
        printf("\n");
        printf("\n(1) Marcar novo compromisso.");
        printf("\n(2) Verificar compromissos existentes.");
        scanf("%d", &opcao);

        if(opcao == 1){
            compromissoNovo = leCompromisso(agendaAtual);
            valido = validaData(compromissoNovo.data_compr, agendaAtual);

            if(valido == 1){
                disponivel = verificaDisponibilidade(compromissoNovo, agendaAtual);

                if(disponivel == 1){
                    agendaAtual = marcaCompromisso(agendaAtual, compromissoNovo);
                    printf("\nCompromisso marcado com sucesso para o dia %d/%d/%d, às %d horas.",
                            compromissoNovo.data_compr.dia, compromissoNovo.data_compr.mes,
                            compromissoNovo.data_compr.ano, compromissoNovo.hora_compr);
                }else {
                    printf("\nEsta data já possui outro compromisso marcado. Tente outra data.");
                }
                
            }else {
                printf("Data inválida. Tente novamente.");
            }
            
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
