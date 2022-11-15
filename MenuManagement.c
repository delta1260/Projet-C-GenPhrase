//
// Created by Mathys on 15/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenuManagement.h"

int estDansChoix(char * nombre,char * choixList){
    int tailleTableau = strlen(choixList);
    for(int i = 0; i < tailleTableau; i++){
        if(nombre == choixList[i]){
            return 1;
        }
    }

    return 0;
}
char ask(char* message,int mode, char * choiceList){
    char answer;
    printf("( > ) %s : \n",message);

    switch(mode){
        case 1:{ // Saisie d'un choix numerique
            scanf("%s",&answer);
            while( estDansChoix(answer,choiceList) == 0 /* La saisie est dans le tableau ? */){
                printf("(i) Saisie Invalide. \n");
                printf("( > ) %s : \n",message);
                scanf("%s",&answer);
            }

            break;
        }
        default:{
            printf("Mode Invalide.");
        }


    }

    return answer;
}
void afficherMenu(){
    char* menuTemplate =
            "==============================\n"
            "      GENERATEUR DE PHRASES   \n"
            "==============================\n"
            "(1) Proposer une recherche de mot\n"
            "(2) Extraire une forme de base au hasard\n"
            "(3) Genererez des phrases au hasard\n"
    ;

    printf("%s",menuTemplate);
    char menuAction = ask("Que souhaitez vous faire ?",1,"123");
    if(menuAction == '1'){
        GenererPhrase();
    }else if(menuAction == '2'){
        printf("Extraire une forme de base au hasard");
    }else if(menuAction == '3'){
        printf("Genererez des phrases au hasard");
    }
}
void GenererPhrase(){
    nettoyerEcran();
    char* menuTemplate =
            "==============================\n"
            "      GENERATEUR DE PHRASES   \n"
            "==============================\n"
            "(1) Avec les formes de base\n"
            "(2) Avec les formes flechies\n"
    ;
    printf("%s",menuTemplate);
    char grilleMenuAction = ask("Quelle grille souhaitez-vous ?",1,"12");
    if(grilleMenuAction == '1'){
        printf("Avec les formes de base");
    }else if(grilleMenuAction == '2'){
        printf("Avec les formes flechies");
    }
}
void nettoyerEcran(){
    printf("\n\n\n");
}
#include "MenuManagement.h"
