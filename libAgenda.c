#include "libAgenda.h"

/* esta função transforma uma data lida pelo usuário para uma struct data
 * em uma data do tipo struct tm definida pela biblioteca time.h. 
 * Esta data é então transformada em segundos com a função mktime, para que
 * os outros membros da struct sejam preenchidos automaticamente, e então
 * reconvertida para uma data do tipo struct tm, reescrevendo a variável 
 * original. Com isso, pode-se obter o membro tm_yday, que representa o
 * dia do ano representado pela data: um inteiro entre 0 e 364 */
int obtemDiaDoAno(struct data d) {
	struct tm tipodata = {0};
	time_t segundos;
	int dia_do_ano;

	tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes-1;
    tipodata.tm_year = d.ano-1900;
    tipodata.tm_isdst = -1;
	tipodata.tm_hour = 0;

	/* converte data para época, isto é, segundos desde 1970 */
	segundos = mktime(&tipodata);
	/* converte época em data, obtendo assim automaticamente
	 * o campo 'dia do ano' (tm_yday) que será o índice do
	 * vetor necessário para marcar um compromisso */
	tipodata = *localtime(&segundos);
	/* da reconversão da data, obtém o dia do ano, um número
	 * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;
	
	return dia_do_ano;
}

/* DAQUI PARA BAIXO É COM VOCÊS! SIGAM O ENUNCIADO E O HEADER DISPONÍVEL */

int obtemHora(struct compromisso compr){
	return compr.hora_compr;
}

int obtemAno(struct agenda ag){
	return ag.ano;
}

struct agenda criaAgenda(int ano){
	struct agenda agendaAtual;
	agendaAtual.ano = ano;

	for(int indexDia = 0; indexDia < DIAS_DO_ANO; indexDia++){
		for(int indexHora = 0; indexHora < HORAS_DO_DIA; indexHora++){
			agendaAtual.agenda_do_ano[indexDia].horas[indexHora] = 0;
		}
	}
	return agendaAtual;
}

int validaData(struct data d, struct agenda ag){
	if (ag.ano != d.ano ){
		return 0;

	}else if(d.mes <= 0 || d.mes > 12){
		return 0;

	}else if(d.dia <= 0 || d.dia > 31){
		return 0;

	}
	return 1;
}

struct compromisso leCompromisso(struct agenda ag){
	struct compromisso compromissoNovo;
	struct data dataValid;
	int horaValid;
	int validoData = 0;
	int validoHora = 0;

	do{
		printf("Para marcar um compromisso, primeiro informe a data.\n");
		printf("Digite o dia: ");
		scanf("\n %d", &dataValid.dia);
		printf("Digite o mês: ");
		scanf("\n %d", &dataValid.mes);
		printf("Digite o ano: ");
		scanf("\n %d", &dataValid.ano);
		printf("Agora, informe o horário:\n");
		scanf("\n %d", &horaValid);

		validoData = validaData(dataValid, ag);

		if(horaValid >=0 && horaValid < HORAS_DO_DIA){
			validoHora = 1;
		}

		if(validoData == 0 || validoHora == 0){
			printf("Data/hora inválida. Por favor, tente novamente.");
		}
	}while (validoData == 0 || validoHora == 0);

	compromissoNovo.data_compr = dataValid;
	compromissoNovo.hora_compr = horaValid;

	return compromissoNovo;
}

int verificaDisponibilidade(struct compromisso compr, struct agenda ag){
	int diaCompromisso;

	diaCompromisso = obtemDiaDoAno(compr.data_compr);
	if (ag.agenda_do_ano[diaCompromisso].horas[compr.hora_compr] == 0){
		return 1;
	}
	return 0;
}

struct agenda marcaCompromisso(struct agenda ag, struct compromisso compr){
	int diaCompromisso;

	diaCompromisso = obtemDiaDoAno(compr.data_compr);
	ag.agenda_do_ano[diaCompromisso].horas[compr.hora_compr] = 1;

	return ag;
}

/* mostra as datas e horas de todos os compromissos marcados na agenda */
void listaCompromissos(struct agenda ag){
	for(int indexDia = 0; indexDia < DIAS_DO_ANO; indexDia++){
		for(int indexHora = 0; indexHora < HORAS_DO_DIA; indexHora++){
			if (ag.agenda_do_ano[indexDia].horas[indexHora] == 1){
				//printf("\n Data: %d/%d/%d, %d:00.", dia, mes, ano, hora);
			}

		}
	}
}

