/* 
 * Feito por Marcos Castilho em 06/04/2023
 * para a disciplina CI1001 - Programacao 1
 * obs.: a funcao obtemDiaDoAno foi feita
 * pelo prof. Andre Gregio.
 */

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

struct agenda criaAgenda(int ano){
    struct agenda novaAg;
    novaAg.ano = ano;

    for(int indexDia = 0; indexDia < DIAS_DO_ANO; indexDia++){
        for(int indexHora = 0; indexHora < HORAS_DO_DIA; indexHora++){
            novaAg.agenda_do_ano[indexDia].horas[indexHora] = 0;
        }
    }
    return novaAg;
}

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
    else if(d->dia <= 0 || d->dia > 31)
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

int leCompromisso(struct agenda *ag, struct compromisso *compr){
    scanf("\n%d %d %d %d", &compr->data_compr.dia, &compr->data_compr.mes,
        &compr->data_compr.ano, &compr->hora_compr);
    
    if(!validaData(ag, &compr->data_compr))
        return 0;
    else if(!validaHora(compr))
        return 0;
    else return 1;
}

int verificaDisponibilidade(struct agenda *ag, struct compromisso *compr){
    int diaCompromisso = obtemDiaDoAno(compr->data_compr);

    if(ag->agenda_do_ano[diaCompromisso].horas[obtemHora(compr)] == LIVRE)
        return 1;
    else return 0;
}

void marcaCompromisso(struct agenda *ag, struct compromisso *compr){
    int diaCompromisso = obtemDiaDoAno(compr->data_compr);

    ag->agenda_do_ano[diaCompromisso].horas[obtemHora(compr)] = OCUPADA;
}

void listaCompromissos(struct agenda *ag){

    for(int indexDia = 0; indexDia < DIAS_DO_ANO; indexDia++){

		for(int indexHora = 0; indexHora < HORAS_DO_DIA; indexHora++){

			if (ag->agenda_do_ano[indexDia].horas[indexHora]){
				printf ("dia: %3d, ", indexDia);
                printf ("ano: %4d, ", obtemAno(ag));
                printf ("hora: %2d, compromisso!\n", indexHora);
			}
		}
	}
}
