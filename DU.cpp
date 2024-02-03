#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Nabytok {
    string nazov, vyrobca, znamka;
    int ID{}, pocetK{}, cena{};
    bool valid;
    void vypis() {
        cout << "ID: " << ID << "\nNazov: " << nazov << "\nVyrobva: " << vyrobca << "\nCena: " << cena << "\nPocet:  " << pocetK << "\nTrieda: " << znamka << endl << endl;
    }
};
Nabytok SpcecifickyProdukt(string riadok) {
    string Textak[6];
    int currentLine = 0;
    int x = 0;
    struct Nabytok nabytok;
    struct Nabytok NIC;


    do {
        Textak[x] += riadok[currentLine];
        currentLine++;
        if (riadok[currentLine] == ' ') {
            currentLine++;
            x++;
        }
    } while (riadok[currentLine]);

    nabytok.ID = stoi(Textak[0]);
    nabytok.nazov = Textak[1];
    nabytok.vyrobca = Textak[2];
    nabytok.cena = stoi(Textak[3]);
    nabytok.pocetK = stoi(Textak[4]);
    nabytok.znamka = Textak[5];

    nabytok.valid = true;

    short int IDcko = nabytok.ID;

    return nabytok;
 
}

int main()
{
    struct Nabytok* specNabytok;
    fstream Subor;
    string novyRiadok;
    int pocetRiadkov = 0;
    int x = 0;
    Subor.open("Text.txt", ios::in);
    if (Subor.is_open()) {
        while (getline(Subor, novyRiadok)) {
                pocetRiadkov++;
        }
        Subor.close();
    }
    
    specNabytok = new Nabytok[pocetRiadkov];
    
    Subor.open("Text.txt", ios::in);
    if (Subor.is_open()) {
        while (getline(Subor, novyRiadok)) { 
                specNabytok[x] = SpcecifickyProdukt(novyRiadok);
                if (specNabytok[x].valid != false) {
                    x++;
                }else pocetRiadkov--;
        }
        Subor.close();
    }
    for (int i = 0; i < pocetRiadkov; i++) {
        specNabytok[i].vypis();
    }
    cout << "Pocet riadokv: " << pocetRiadkov << endl;
    delete[] specNabytok;
    specNabytok = NULL;
    return 0;
}