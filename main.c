#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fnc.h"

int main()
{
    char *phrase,* mot;
    phrase=calloc(20,sizeof(char));
    mot=calloc(6,sizeof(char));
    int continuer=1,clic=0,win=0,open=0;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO); 
    SDL_Surface *ecran =NULL,*zoneSaisie=NULL,*curseur=NULL;
    TTF_Font *police = NULL;
    SDL_Color blanc = {255, 255, 255};
    TTF_Init();
    police = TTF_OpenFont("font/font.ttf",50);
    ecran=SDL_SetVideoMode(448, 720, 32, SDL_HWSURFACE); 
    SDL_Rect poszoneSaisie;
    poszoneSaisie.x=140;
    poszoneSaisie.y=200;
    SDL_WM_SetCaption("enigme4", NULL); 
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1){printf("%s",Mix_GetError());}
////////////////////////////////////////////////////
    image background,clock23;
    background=init_image("images/clock/1.png",0,0);
    affichage(ecran,background);
    clock23=init_image("images/clock/26.png",0,0);
    annimation clock,door,feuille;
    clock=init_annimation(clock,26,"images/clock");
    door=init_annimation(door,30,"images/door");
    feuille=init_annimation(feuille,20,"images/feuille");
    //////////////////////////////////
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {

                if((event.button.x >351 && event.button.y >287 && event.button.x <419 && event.button.y <376)&&clic==0)
                {
                clic=1;
                printf("click clock !\n");
                sound_clock();
                afficher_annimation(clock,ecran);
                }
                if((event.button.x >326 && event.button.y >139 && event.button.x <388 && event.button.y <201)&&clic==1)
                {
                clic=0;
                affichage(ecran,background);
                printf("Exit clock !\n");
                }
                if((event.button.x >256 && event.button.y >384 && event.button.x <297 && event.button.y <427)&&clic==1)
                {
                strcpy(mot,"c");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("c Souris !\n");
                }
                if((event.button.x >205 && event.button.y >384 && event.button.x <246 && event.button.y <427)&&clic==1)
                {
                strcpy(mot,"0");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("0 Souris !\n");
                }
                if((event.button.x >127 && event.button.y >273 && event.button.x <172 && event.button.y <317)&&clic==1)
                {
                strcpy(mot,"1");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("1 Souris !\n");
                }
                if((event.button.x >179 && event.button.y >274 && event.button.x <222 && event.button.y <315)&&clic==1)
                {
                strcpy(mot,"2");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("2 Souris !\n");
                }
                if((event.button.x >230 && event.button.y >275 && event.button.x <273 && event.button.y <316)&&clic==1)
                {
                strcpy(mot,"3");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("3 Souris !\n");
                }
                if((event.button.x >281 && event.button.y >271 && event.button.x <324 && event.button.y <316)&&clic==1)
                {
                strcpy(mot,"4");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("4 Souris !\n");
                }
                if((event.button.x >129 && event.button.y >328 && event.button.x <172 && event.button.y <374)&&clic==1)
                {
                strcpy(mot,"5");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("5 Souris !\n");
                }
                if((event.button.x >180 && event.button.y >328 && event.button.x <221 && event.button.y <371)&&clic==1)
                {
                strcpy(mot,"6");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("6 Souris !\n");
                }
                if((event.button.x >231 && event.button.y >329 && event.button.x <272 && event.button.y <372)&&clic==1)
                {
                strcpy(mot,"7");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("7 Souris !\n");
                }
                if((event.button.x >282 && event.button.y >329 && event.button.x <323 && event.button.y <372)&&clic==1)
                {
                strcpy(mot,"8");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("8 Souris !\n");
                }
                if((event.button.x >155 && event.button.y >383 && event.button.x <196 && event.button.y <426)&&clic==1)
                {
                strcpy(mot,"9");
                if(strlen(phrase)<6)strcat(phrase,mot);
                printf("9 Souris !\n");
                }
                if((event.button.x >334 && event.button.y >146 && event.button.x <440 && event.button.y <252)&&clic==0)
                {            
                open=1;  
                afficher_annimation(feuille,ecran);
                printf("Ouvrir la feuille!\n"); 
                }
                if((event.button.x >39 && event.button.y >122 && event.button.x <78 && event.button.y <163)&&open==1)
                {
                open=0;
                affichage(ecran,background);
                printf("Quitter la feuille!\n");               
                }

            }break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_RETURN:
            {
            if(win==0&&clic==1)
            {  
                if(strcmp(phrase,"602317")==0)//602317
                {sound_correct();printf("win\n");win=1;
                 memset(phrase,0,sizeof(char));phrase=calloc(20,sizeof(char));}
              else{sound_wrong();memset(phrase,0,sizeof(char));phrase=calloc(20,sizeof(char));printf("False Enigme 1\n");}
            }
            }break;
            case SDLK_BACKSPACE:
                printf("Effacer\n");
                int casee = 0,longeur;
                longeur=strlen(phrase);
                longeur--;
                while(phrase[casee] != '\0')
                {
                    if(casee >=longeur)
                    {
                        phrase[casee] = phrase[casee+1];
                    }
                    casee++;
                }
                break;
            case SDLK_KP0:
                strcpy(mot,"0");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("0\n");}
                break;
            case SDLK_KP1:
                strcpy(mot,"1");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("1\n");}
                break;
            case SDLK_KP2:
                strcpy(mot,"2");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("2\n");}
                break;
            case SDLK_KP3:
                strcpy(mot,"3");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("3\n");}
                break;
            case SDLK_KP4:
                strcpy(mot,"4");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("4\n");}
                break;
            case SDLK_KP5:
                strcpy(mot,"5");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("5\n");}
                break;
            case SDLK_KP6:
                strcpy(mot,"6");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("6\n");}
                break;
            case SDLK_KP7:
                strcpy(mot,"7");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("7\n");}
                break;
            case SDLK_KP8:
                strcpy(mot,"8");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("8\n");}
                break;
            case SDLK_KP9:
                strcpy(mot,"9");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("9\n");}
                break;
                //////////alphabet//////////
            case SDLK_c:
                strcpy(mot,"c");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("c\n");}
                break;
         }
     }
            if(clic==1&&win==0)
            {
            affichage(ecran,clock23);
            zoneSaisie=TTF_RenderText_Blended(police,phrase,blanc);
            SDL_BlitSurface(zoneSaisie,NULL,ecran,&poszoneSaisie);
            SDL_Flip(ecran); 
            }
            if(win==1)
             {
              sound_door();
              afficher_annimation(door,ecran);
              win=2;
             }
            SDL_Flip(ecran);                  
    } 
    TTF_CloseFont(police);
    SDL_Quit(); // Arrêt de la SDL
    librer_image(background);
    SDL_FreeSurface(zoneSaisie);
   
    return EXIT_SUCCESS; 
}







