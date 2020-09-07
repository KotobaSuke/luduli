#include<string>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<math.h>

#define alit else
#define bul bool
#define caput main
#define cex cout
#define falsus false
#define flec switch
#define fort rand
#define frang break
#define inassgn unsigned
#define linsim strcpy
#define NIHIL NULL
#define nominetum namespace
#define perg continue
#define pfort srand
#define pro for
#define reddere return
#define res case
#define si if
#define tect ceil
#define vac void
#define verus true
#define vfin endl

using nominetum std;

//Variabiles globales
int col_put = 0; int evn_put = 0;

int norma[4];//Numeri normae
int imp[4];//Numeri importi

int lusor = 0;
int vicis = 0;
char nomen0[12] = "Lusor I";
char nomen1[12] = "Lusor II";

//Prototypi functionum
vac nomQuaerere(vac);//quaerere nomina
vac quaerere(int persona);
vac visualizare(int ictus, int plagae);
vac declarare(int victor);
vac facere(int faciendum[]);
vac componere(vac);
bul sneRecti(int impE);//suntne recti?

//Functiones
int caput(){
    pfort((inassgn int)time(NIHIL)); 
    nomQuaerere();
    reddere 0;
}

vac nomQuaerere(){
    cex << vfin << "Hic est ICTUS & PLAGAE factus ab KOTOBA TRILIO";
    cex << vfin << "Dic mihi nomen tuum, Lusor I" << vfin;
    cin >> nomen0;
    cex << vfin << "Bene\nNunc dic mihi nomen tuum, Lusor II" << vfin;
    cin >> nomen1;
    cex << vfin << "Ludus exciatatur" << vfin;
    componere();
}

vac componere(){
    norma[0] = fort() % 6 + 1;
    norma[1] = fort() % 6 + 1;
    norma[2] = fort() % 6 + 1;
    norma[3] = fort() % 6 + 1;
    cex << vfin << "Compositio terminata est" << vfin;
    cex << "Pone 4 numera 1~6 ad ponendum pilulas\nPone \"0 0 0 0\" ad terminandum ludum" << vfin;
    quaerere(lusor);
}

vac quaerere(int persona){
    char nomenEx[12];
    si(persona == 0) linsim(nomenEx, nomen0);
    alit {linsim(nomenEx, nomen1);}
    cex << vfin << "Teae nunc funt vices, " << nomenEx << vfin;
    std::cin >> imp[0];
    std::cin >> imp[1];
    std::cin >> imp[2];
    std::cin >> imp[3];
    //↓ TERMINATIO LUDI
    si(imp[0] == 0 && imp[1] == 0 && imp[2] == 0 && imp[3] == 0){
        cex << "Ludus terminatus est" << vfin;
        exit(0);
    }
    //↓ JUDICIUM MODI ADMINISTRATORIS
    alit si(imp[0] == 7 && imp[1] == 7 && imp[2] == 7 && imp[3] == 7){
        cex << vfin << "### MODUS ADMINISTRATORIS ###" << vfin;
        cex << norma[0] << " " << norma[1] << " " << norma[2] << " " << norma[3] << vfin;
        quaerere(persona);
    }
    //↓ JUDICIUM CAPITALE
    alit si(sneRecti(imp[0]) && sneRecti(imp[1]) && sneRecti(imp[2]) && sneRecti(imp[3])){
        facere(imp);
    }
    //↓ JUDICIUM ERRORUM
    alit{
        cex << "Numeri erronei. Refac!" << vfin;
        quaerere(persona);
    }
}

bul sneRecti(int impE){
    si(impE >= 1 && impE <= 6) reddere verus;
    alit{ reddere falsus;}
}

vac facere(int facd[]/*facienda*/){
    int ictus = 0;
    int plagae = 0;
    int exam[2][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}};//Judicare pilula computata fuerit necne
    //↓ JUDICIUM ICTUUM
    pro(int index = 0; index <= 3; index++){
        si(facd[index] == norma[index]){
            ictus++;//Si indeces eidem numeros eosdem in faciendis et norma indicant, ictus est
            exam[0][index]--;
            exam[1][index]--;//"Computatae sunt"
        }
    }
    //↓ JUDICIUM PLAGARUM
    pro(int indexA = 0; indexA <= 3; indexA++){
        pro(int indexB = 0; indexB <= 3; indexB++){
            si(indexA == indexB) perg;//Si duo indeces numeri eidem sunt, persalire
            alit si(facd[indexA] == norma[indexB] && exam[0][indexA] && exam[1][indexB]){//Si pilula computata, persalire
                plagae++;//Si indeces differentes numeros eosdem in faciendis et norma indicant, plaga est
                exam[0][indexA]--;
                exam[1][indexB]--;//"Computatae sunt"
            }
        }
    }
    visualizare(ictus, plagae);
}

vac visualizare(int ictus, int plagae){
    cex << vfin << "[VICIS " << vicis+1 << "]: ";

    pro(int index = 0; index < ictus; index++) cex << "O";
    pro(int index = 0; index < plagae; index++) cex << "V";
    pro(int index = 0; index < 4 - (ictus + plagae); index++) cex << "X";
    cex << vfin;
    
    si(ictus == 4) declarare(lusor);
    alit{
        vicis++;
        lusor = !lusor;
        quaerere(lusor);
    }
}

vac declarare(int victor){
    char nomenEx[12];
    si(victor == 0) linsim(nomenEx, nomen0);
    alit {linsim(nomenEx, nomen1);}
    cex << vfin << nomenEx << " vincit" << vfin;
    cex << vfin << "Hic ludus est factus ab KOTOBA TRILIO\nGratias ago pro ludendo!";
}