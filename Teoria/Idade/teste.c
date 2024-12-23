#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Função para verificar se o ano é bissexto
bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função auxiliar para obter dias no mês
int diasNoMes(int mes, int ano) {
    switch(mes) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ehBissexto(ano) ? 29 : 28;
        default:
            return 31;
    }
}

int diastotais(int diaD,int mesD,int anoD,int diaATUAL,int mesATUAL,int anoATUAL){
    int diasTotais = 0;
    // Adiciona dias dos anos completos
    for(int ano = anoD + 1; ano < anoATUAL; ano++) {
        if(ehBissexto(ano) == 1){
            diasTotais += 366;
        }else
            diasTotais += 365; 
    }
    
    // Adiciona dias dos meses restantes do ano de nascimento
    for(int mes = mesD + 1; mes <= 12; mes++) {
        diasTotais += diasNoMes(mes, anoD);
    }
    
    // Adiciona dias dos meses restantes do ano atual
    for(int mes = 1; mes < mesATUAL; mes++) {
        diasTotais += diasNoMes(mes, anoATUAL);
    }
    
    // Adiciona dias do mês de nascimento (parcial)
    diasTotais += diasNoMes(mesD, anoD) - diaD;
    
    // Adiciona dias do mês atual (parcial)
    diasTotais += diaATUAL;
    
    return diasTotais;
}

int main(){
    // Data atual
    time_t t = time(NULL);
    struct tm *dataAtual = localtime(&t);

    // Obtendo o dia, mês e ano
    int diaATUAL = dataAtual->tm_mday;
    int mesATUAL = dataAtual->tm_mon + 1; // tm_mon começa em 0 para janeiro
    int anoATUAL = dataAtual->tm_year + 1900; // tm_year conta os anos desde 1900
    // Data de Aniversario
    int anoD = 1975, mesD = 10,diaD = 12;
    // Resultados
    int anos = 0,meses = 0,dias = 0; 

    // Caso em que o mês atual é antes do mês do aniversario
    if(mesATUAL < mesD){
        // Tratamento para dia/mês(aproximado)
        if(diaD >= diaATUAL){ // Caso o dia do aniversario for depois do dia atual
            int diasMesAnterior = diasNoMes(mesATUAL == 1 ? 12 : mesATUAL - 1, anoATUAL);
            dias = diaATUAL - diaD + diasMesAnterior;
            if(dias == diasMesAnterior){
                meses = mesATUAL - mesD + 12;
                dias = 0;
            }else
               meses = mesATUAL - mesD + 11;
        // Caso o dia do aniversario for antes do dia atual        
        }else{               
            dias = diaATUAL - diaD;
            meses = mesATUAL - mesD + 12;
        }

        // Tratamento para ano
        anos = anoATUAL - anoD - 1;
    }

    // Caso em que o mês atual é o mês do aniversario
    if(mesATUAL == mesD)
    {
        if(diaATUAL >= diaD){
            // Tratamento para dia(aproximado)
            dias = diaATUAL - diaD;
            //Tratamento para mês
            meses = 0;
            // Tratamento para ano
            anos = anoATUAL - anoD;      
        }else{
            // Tratamento para dia
            int diasMesAnterior = diasNoMes(mesATUAL == 1 ? 12 : mesATUAL - 1, anoATUAL);
            dias = diasMesAnterior + diaATUAL - diaD  ;
            //Tratamento para mês
            meses = 11;
            // Tratamento para ano
            anos = anoATUAL - anoD - 1;
        }
    }
    // Caso em que o mês atual é depois do mês do aniversario
    if(mesATUAL > mesD){
        // Caso o dia do aniversario for depois do dia atual
        if(diaD >= diaATUAL){ 
            int diasMesAnterior = diasNoMes(mesATUAL == 1 ? 12 : mesATUAL - 1, anoATUAL);
            dias = diaATUAL - diaD + diasMesAnterior;
            if(dias == 30){
                meses = mesATUAL - mesD;
                dias = 0;
            }else{
               meses = mesATUAL - mesD -1; 
            }
        // Caso o dia do aniversario for antes do dia atual    
        }else{
            dias = diaATUAL - diaD;
            meses = mesATUAL - mesD;
        }
        // Tratamento para ano
        anos = anoATUAL - anoD;
    }
    int diasTotais = diastotais( diaD, mesD, anoD, diaATUAL, mesATUAL, anoATUAL);

    printf("Anos: %d,Meses:%d,Dias:%d\n",anos,meses,dias); 
    printf("Dias Totais: %d\n",diasTotais);

    return 0;
}
