#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define size 100
typedef struct buca Buca;

struct buca{
    int riga;
    int colonna;
};

int main(int argc, char const *argv[])
{
    Buca fine;              //buca finale
    Buca buche_40[size];
    Buca buche_20[size];
    srand(time(NULL));
    int i;                  //indice riga
    int j;                  //indice colonna
    char a[size][size];     //campo da gioco
    int r, c;               //indici r(riga) e c(colonna) della posizione della pallina
    char z=254;             //numero ASCII per il quadratino
    int volte=1;            //numero di tiri effettuati 
    int direction;          //direzione nella quale si vuole tirare
    int gioco=0;            //condizione di fine gioco
    int pseudo_fine=0;      //condizione di pseudofine delle 20 buche
    int tiri[size];
    int w;                  //indice ripetizioni

    fine.riga=rand()%50;
    fine.colonna=rand()%50;

    r=rand()%50;
    c=rand()%50;
    printf("lista delle cordinate delle 40: \n");
    /*--------INIZIALIZZAZIONE DELLE 40 BUCHE CASUALI----------*/
    for (i=0; i<40; i++){
        buche_40[i].riga=rand()%50;
        buche_40[i].colonna=rand()%50;

        printf("%d\t%d\n", buche_40[i].riga, buche_40[i].colonna);
    }

    printf("\n\n");
    printf("lista delle cordinate delle 20: \n");
    /*---------INIZIALIZZAZIONE DELLE 20 BUCHE PSEUDOFINALI-------*/
    for (i=0; i<20; i++){
        buche_20[i].riga=rand()%50;
        buche_20[i].colonna=rand()%50;

        printf("%d\t%d\n", buche_20[i].riga, buche_20[i].colonna);
    }

    
    /*-----CONTROLLO PER INIZIO E FINE DIVERSI-----*/
    while(r==fine.riga && c==fine.colonna){
        r=rand()%50;
        c=rand()%50;
    }
    
    /*----------IMPOSTO LA MAPPA AL VUOTO--------*/
    for (i=0; i<50; i++){
        for (j=0; j<50; j++){
            a[i][j]=' ';
        }
    }

    /*--------PRIMO POSIZIONAMENTO DELLA BIGLIA----------*/
    for (i=0; i<50; i++){
        if(i==r){
            for (j=0; j<50; j++){
                if(j==c)
                    a[i][j]=z;
            }
        }
    }

    /*-----------INIZIO GIOCO---------------*/
    //for (w=0; w<10; w++){
        while (volte<=5 && gioco==0 && pseudo_fine==0)
        {
            printf("\nr=%d\tc=%d\tfine.riga=%d\tfine.colonna=%d\n\n%c =tu sei qui\n\n", r, c, fine.riga, fine.colonna, z);

        /*----------STAMPA DELLA MAPPA-----------*/   
            for (i=0; i<50; i++){
                for (j=0; j<50; j++){
                    if(j==0)
                        printf("|%c|", a[i][j]);
                    else
                        printf("%c|", a[i][j]);
                }
                printf("\n");
            }

        /*--------SPOSTAMENTO DELLA BIGLIA-------*/
            if(volte<6)
            {
                printf("Digitare il numero della direzione nella quale ci si vuole muovere:\n");
                printf("1-NORD-OVEST\n2-NORD\n3-NORD-EST\n4-OVEST\n5-EST\n6-SUD-OVEST\n7-SUD\n8-SUD-EST\n");
                scanf("%d", &direction);
            
                switch(direction){
                    case 1:
                        printf("nord-ovest\n");
                        if(r==0){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }
                        else{
                            a[r-1][c-1]=z;
                            a[r][c]='x';
                            r-=1;
                            c-=1;
                        }
                        break;
                    case 2:
                        printf("nord\n");
                        if(r==0){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }
                        else{                   
                            a[r-1][c]=z;
                            a[r][c]='x';
                            r-=1;
                        }
                        break;
                    case 3:
                        printf("nord-est\n");
                        if(r==0){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r-1][c+1]=z;
                            a[r][c]='x';
                            r-=1;
                            c+=1;
                        }
                        break;
                    case 4:
                        printf("ovest\n");
                        if(c==0){
                            a[r][c]='x';
                            r=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r][c-1]=z;
                            a[r][c]='x';
                            c-=1;
                        }
                        break;
                    case 5:
                        printf("est\n");
                        if(c==49){
                            a[r][c]='x';
                            r=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r][c+1]=z;
                            a[r][c]='x';
                            c+=1;
                        }
                        break;
                    case 6:
                        printf("sud-ovest\n");
                        if(r==49){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r+1][c-1]=z;
                            a[r][c]='x';
                            r+=1;
                            c-=1;
                        }
                        break;
                    case 7:
                        printf("sud\n");
                        if(r==49){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r+1][c]=z;
                            a[r][c]='x';
                            r+=1;
                        }
                        break;
                    case 8:
                        printf("sud-est\n");
                        if(r==49){
                            a[r][c]='x';
                            c=rand()%50;
                            a[r][c]=z;
                        }else{
                            a[r+1][c+1]=z;
                            a[r][c]='x';
                            r+=1;
                            c+=1;
                        }
                        break;
                    default:
                        printf("comando non valido non ti sei mosso\n");
                }

        /*----------CONTROLLO PER LE 40 BUCHE CASUALI------------*/
                for(i=0; i<40; i++){
                    if (r==buche_40[i].riga && c==buche_40[i].colonna){
                        a[r][c]='b';
                        r=rand()%50;
                        c=rand()%50;
                        a[r][c]=z;
                    }
                }

        /*--------CONTROLLO PER LE 20 BUCHE PSEUDOFINALI----------*/
                for(i=0; i<20; i++){
                    if (r==buche_20[i].riga && c==buche_20[i].colonna){
                        pseudo_fine=1;
                    }
                }

        /*---------CONTROLLO BUCA FINALE----------*/
                if(fine.colonna==c && fine.riga==r)
                    gioco=1;
            }
            volte++;
        //}
        
        /*--------------STAMPA DELL' ULTIMA POSIZIONE DELLA BIGLIA--------------*/
        printf("\nr=%d\tc=%d\tfine.riga=%d\tfine.colonna=%d\n\n%c =tu sei qui\n\n", r, c, fine.riga, fine.colonna, z);  
        for (i=0; i<50; i++){
            for (j=0; j<50; j++){
                if(j==0)
                    printf("|%c|", a[i][j]);
                else
                    printf("%c|", a[i][j]);
            }
            printf("\n");
        }

        if(gioco==1)
            printf("COMPLIMENTI HAI COMPLETATO IL PERCORSO CON LA BIGLIA!!!\n");
        else if(pseudo_fine==1)
            printf("il gioco e' terminato perchè sei finito in una buca pseudo-finale!!\n");
        else
            printf("non hai finito il labirinto!\n");

        volte=0;
        gioco=0;
        pseudo_fine=0;
    }

    return 0;
}



/*
no n ne
o     e
so s se 
*/