#include<string>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#define caput main
using namespace std;

//Variabiles globales
int status[2][6] = {{4,4,4,4,4,4},{4,4,4,4,4,4}};
int optenta[2] = {0,0};
int lusor = 0;
char nomen0[12] = "Lusor I";
char nomen1[12] = "Lusor II";

//Prototypi functionum
void visualizare(void);
int summatio(int lusorN);
void declarare(void);
void facere(int stagnum);
void quaerere(int persona);
void nomenQuaerere(void);

//Functiones
void visualizare(){
    cout << endl;
    cout << nomen1 << ": [[";
    cout << setw(2) << optenta[1];
    cout << "]]" << endl;
    cout << setw(2) << status[1][5];
    cout << ",";
    cout << setw(2) << status[1][4];
    cout << ",";
    cout << setw(2) << status[1][3];
    cout << ",";
    cout << setw(2) << status[1][2];
    cout << ",";
    cout << setw(2) << status[1][1];
    cout << ",";
    cout << setw(2) << status[1][0];
    cout << endl;
    cout << setw(2) << status[0][0];
    cout << ",";
    cout << setw(2) << status[0][1];
    cout << ",";
    cout << setw(2) << status[0][2];
    cout << ",";
    cout << setw(2) << status[0][3];
    cout << ",";
    cout << setw(2) << status[0][4];
    cout << ",";
    cout << setw(2) << status[0][5];
    cout << endl;
    cout << nomen0 << ": [[";
    cout << setw(2) << optenta[0];
    cout << "]]" << endl;
    cout << endl;
}

int summatio(int lusorN){
    int summus = 0;
    for(int index = 0; index <= 5; index++){
        summus += status[lusorN][index];
    }
    return summus;
}

void declarare(){
    int victor;
    char nomenEx[12];
    if(summatio(1) == 0){
        if (summatio(0) == 1){
            cout << nomen0 << " " << summatio(0) << " lapidem reliquum cepit" << endl;
        }
        else{
            cout << nomen0 << " " << summatio(0) << " lapides reliquos cepit" << endl;
        }
        optenta[0] += summatio(0);
    }
    else if(summatio(0) == 0){
        if (summatio(1) == 1){
            cout << nomen1 << " " << summatio(1) << " lapidem reliquum cepit" << endl;
        }
        else{
            cout << nomen1 << " " << summatio(1) << " lapides reliquos cepit" << endl;
        }
        optenta[1] += summatio(1);
    }
    if(optenta[1] < optenta[0]){
        victor = 0;
        strcpy(nomenEx, nomen0);
        cout << "Vincis, " << nomenEx << endl;
    }
    else if(optenta[1] > optenta[0]){
        victor = 1;
        strcpy(nomenEx, nomen1);
        cout << "Vincis, " << nomenEx << endl;
    }
    else{
        cout << "Nemo vincit" << endl;
    }
    cout << "EVENTUS EST \n <" << nomen0 << "> "<< optenta[0] << " : " << optenta[1] << " <" << nomen1 << ">" << endl;
    cout << endl << "Hic ludus est factus ab KOTOBA TRILIO\nGratias ago pro ludendo!";
}

void facere(int stagnum){ 
    int ponenda = status[lusor][stagnum];
    if(status[lusor][stagnum] == 0){
        cout << "Stagnum est vacuum, cape lapides ex alio" << endl;
        quaerere(lusor);
    }
    else{
        status[lusor][stagnum] = 0;
        int locus[2] = {lusor, stagnum};
        int lusorVerus = lusor;
        bool estneStagnumFinaleStagnumOptentorum = false;
        while(ponenda != 0){
            ponenda--;
            locus[1]++;
            if(locus[1] == 6){
                if(locus[0] == lusor){
                    optenta[lusor]++;
                    if(ponenda == 0 && summatio(1) != 0 && summatio(0) != 0){
                        cout << endl << "<< Postes facere semel plus >>" << endl;
                        lusor = !lusor;
                    }
                }
                else{
                    ponenda++;
                }
                locus[1] = -1;
                locus[0] = !locus[0];
            }
            else{
                status[locus[0]][locus[1]]++;
                if(ponenda == 0 && locus[0] == lusorVerus && status[lusorVerus][locus[1]] == 1 && status[!lusorVerus][5-locus[1]] != 0){
                cout << endl << "<< CORREPTIO! >> +" << status[!lusorVerus][5-locus[1]]+1 << endl;
                optenta[lusorVerus] += status[!lusorVerus][5-locus[1]];
                optenta[lusorVerus]++;
                status[lusorVerus][locus[1]] = 0;
                status[!lusorVerus][5-locus[1]] = 0;
                }
            }
        }
        lusor = !lusor;
        visualizare();
        if(summatio(1) == 0 || summatio(0) == 0){
            declarare();
        }
        else{
            quaerere(lusor);
        }
    }
}

void quaerere(int persona){
    char nomenEx[12];
    if(persona == 0){
        strcpy(nomenEx, nomen0);
    }
    else{
        strcpy(nomenEx, nomen1);
    }
    cout << "Teae nunc funt vices, " << nomenEx << endl;
    cout << "Pone numerum 1~6 ad initiandum actionem\nPone numerum 0 ad terminandum ludum" << endl;
    int faciendum;
    std::cin >> faciendum;
    if(faciendum >= 1 && faciendum <= 6){
        facere(faciendum - 1);
    }
    else if(faciendum == 0){
        cout << "Ludus terminatus est" << endl;
        exit(0);
    }
    else if(faciendum == 777){
        cout << endl << "### LUDUM COEGISTI FACERE EVENTUM ###" << endl;
        declarare();
    }
    else{
        cout << "Numerus est erroneus. Refac!" << endl;
        quaerere(persona);
    }
}

void nomenQuaerere(){
    cout << endl << "Hic est MANCALA facta ab KOTOBA TRILIO";
    cout << endl << "Dic mihi nomen tuum, Lusor I" << endl;
    cin >> nomen0;
    cout << endl << "Bene\nNunc dic mihi nomen tuum, Lusor II" << endl;
    cin >> nomen1;
    cout << endl <<"Ludus exciatatur" << endl;
    visualizare();
    quaerere(0);
}

int caput(){
    nomenQuaerere();
    return 0;
}