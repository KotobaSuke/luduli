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
#define def default
#define dum while
#define fac do
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
int abacus[6][7] = //[linea][columna]
{{0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0}};

int lusor = 0;
char nomen0[12] = "Lusor I";
char nomen1[12] = "Lusor II";

//Prototypi functionum
vac nomQuaerere(vac); //quaerere nomina
vac quaerere(int persona);
vac ponere(int columna, int locus);
vac examinare(int columna, int linea);
vac declarare(int victor);
vac visualizare(vac);
char trl(int columna, int linea); //transliterare

//Functiones
int caput(){
    nomQuaerere();
    reddere 0;
}

vac nomQuaerere(){
    cex << vfin << "Hic est QUATTUOR CONTINUA factus ab KOTOBA TRILIO";
    cex << vfin << "Dic mihi nomen tuum, Lusor I" << vfin;
    cin >> nomen0;
    cex << vfin << "Bene\nNunc dic mihi nomen tuum, Lusor II" << vfin;
    cin >> nomen1;
    cex << vfin << "Ludus exciatatur" << vfin;
    cex << "Pone numerum 1~7 ad ponendum pilulam\nPone \"0\" ad terminandum ludum" << vfin;
    cex << "\"O\" = " << nomen0 << ", \"X\" = " << nomen1 << vfin;
    quaerere(lusor);
}

vac quaerere(int persona){
    int imp; //Numerus importus
    char nomenEx[12];
    si(persona == 0) linsim(nomenEx, nomen0);
    alit {linsim(nomenEx, nomen1);}
    cex << vfin << "Teae nunc funt vices, " << nomenEx << vfin;
    std::cin >> imp;
    si(imp == 0){
        cex << "Ludus terminatus est" << vfin; exit(0); //Terminare ludum
    }
    alit si(imp < 0 || imp > 7){
        cex << "Numerus erroneus. Refac!" << vfin; quaerere(persona);
    }
    alit{
        int summa = 0; //Quanti loci vacui sunt
        pro(summa = 0; summa <= 5 && abacus[summa][imp - 1] == 0; summa++);
        //### ADMINISTRATOR ###
        /*cex << vfin << "Summa: " << summa << vfin;*/
        si(summa != 0){
            ponere(imp - 1, summa - 1);
        }
        alit{ //Omnes loci pleni
            cex << "Columna est plena. Refac!" << vfin;
            quaerere(lusor);
        }
    }
}

vac ponere(int columna, int locus){
    abacus[locus][columna] += (lusor + 1);
    visualizare();
    examinare(columna, locus);
}

vac examinare(int columna, int linea){
    //EXAMINATIO DEORSUM
    si(linea <= 2){ //Si "linea > 2", nunquam 4 numeri idem deorsum sunt
        int summaD = 0; //Quanti numeri idem sunt
        pro(int index = linea + 1; index <= 5; index++){
            si(abacus[index][columna] == (lusor + 1)){
                summaD++;
            }
            alit {frang;}
        }
        si(summaD >= 3)
            declarare(lusor);
    }
    //EXAMINATIO AEQUA
    int summaA = 0;
    pro(int index = columna - 1; index >= 0; index--){ //SINISTRORSUM
        si(abacus[linea][index] == (lusor + 1)){
            summaA++;
        }
        alit {frang;}
    }
    pro(int index = columna + 1; index <= 6; index++){ //DEXTRORSUM
        si(abacus[linea][index] == (lusor + 1)){
            summaA++;
        }
        alit {frang;}
    }
    si(summaA >= 3){
        declarare(lusor);
    }
    
    //EXAMINATIO SECUNDUM DIAGONUM PRINCIPEM
    int summaDP = 0;
    pro(int index = 1; columna - index >= 0 && linea - index >= 0; index++){ //SINISTRORSUM
        si(abacus[linea - index][columna - index] == (lusor + 1)){
            summaDP++;
        }
        alit {frang;}
    }
    pro(int index = 1; columna + index <= 6 && linea + index <= 5; index++){ //DEXTRORSUM
        si(abacus[linea + index][columna + index] == (lusor + 1)){
            summaDP++;
        }
        alit {frang;}
    }
    si(summaDP >= 3){
        declarare(lusor);
    }
    //EXAMINATIO SECUNDUM ANTIDIAGONUM
    int summaAD = 0;
    pro(int index = 1; columna - index >= 0 && linea + index <= 5; index++){ //SINISTRORSUM
        si(abacus[linea + index][columna - index] == (lusor + 1)){
            summaAD++;
        }
        alit {frang;}
    }
    pro(int index = 1; columna + index <= 6 && linea - index >= 0; index++){ //DEXTRORSUM
        si(abacus[linea - index][columna + index] == (lusor + 1)){
            summaAD++;
        }
        alit {frang;}
    }
    si(summaAD >= 3){
        declarare(lusor);
    }
    lusor = !lusor;
    quaerere(lusor);
}

vac declarare(int victor){
    char nomenEx[12];
    si(victor == 0) linsim(nomenEx, nomen0);
    alit {linsim(nomenEx, nomen1);}
    cex << vfin << nomenEx << " vincit" << vfin;
    cex << vfin << "Hic ludus est factus ab KOTOBA TRILIO\nGratias ago pro ludendo!";
    exit(0);
}

vac visualizare(){
    cex << vfin << "+-------+" << vfin;
    pro(int indexL = 0; indexL <= 5; indexL++){ //lineatim
        pro(int indexC = 0; indexC <= 6; indexC++){ //columnatim
            si(indexC == 0) cex << "|";
            cex << trl(indexC, indexL);
            si(indexC == 6) cex << "|" << vfin;
        }
    }
    cex << "+-------+" << vfin << " 1234567 " << vfin;
}

char trl(int columna, int linea){
    flec(abacus[linea][columna]){
        res 1: reddere 'O'; frang;
        res 2: reddere 'X'; frang;
        def: reddere ' '; frang;
    }
}