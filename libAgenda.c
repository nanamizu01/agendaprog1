/* 
 * Feito por Marcos Castilho em 06/04/2023
 * para a disciplina CI1001 - Programacao 1
 * obs.: a funcao obtemDiaDoAno foi feita
 * pelo prof. Andre Gregio.
 */

#include <stdio.h>
#include <time.h>
#include "libAgenda.h"

#define LIVRE 0
#define OCUPADA 1

int obtemDiaDoAno(struct data d){
    struct tm tipodata={0};
    time_t segundos;
    int dia_do_ano;

    tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes - 1;
    tipodata.tm_year = d.ano - 1900;
    tipodata.tm_isdst = -1;
    tipodata.tm_hour = 0;

    /* converte data para epoca, isto eh, segundos desde 1970 */
    segundos = mktime(&tipodata);

    /* converte epoca em data, obtendo assim automaticamente
     * o campo 'dia do ano' (tm_yday) que sera o indice do
     * vetor necessario para marcar um compromisso */
    tipodata = *localtime(&segundos);

    /* da reconversao da data, obtem o dia do ano, um numero
     * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;

    return dia_do_ano;
}

/* Daqui para frente eh com voces! */

int obtemAno(struct agenda *ag){
    return (*ag).ano;
}

int obtemHora(struct compromisso *compr){
    return (*compr).hora_compr;
}

int validaData(struct agenda *ag, struct data *d){
    if(obtemAno(ag) != d->ano)
        return 0;

    else if(d->mes <= 0 || d->mes > MESES_NO_ANO)
        return 0;

    else if(d->dia <= 0 || d->dia > 24)
        return 0;

    else 
        return 1;    
}

int validaHora(struct compromisso *compr){
    if(obtemHora(compr) <= 0 || obtemHora(compr) > HORAS_DO_DIA)
        return 0;
    else
        return 1;
}

/* Le um compromisso do teclado (dia, mes, ano e hora, nesta ordem) 
 * Devolve o compromisso no parametro e retorna 1 se o compromisso
 * eh valido ou 0 caso contrario */
int leCompromisso(struct agenda *ag, struct compromisso *compr){

}
