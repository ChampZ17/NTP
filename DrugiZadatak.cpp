#include <iostream>
#include <fstream>
using namespace std;
string crte = "\n------------------------------------------------------------------------------------------------------------------\n";
/*
Data je datoteka ispiti.txt čiji redovi imaju sljedeću strukturu:
brindexa predmet ocjena
Kreirajte ovu datoteku koristeći Notepad i napunite je nekim testnim podacima.
Predmeti su zadani imenom predmeta.
Zatim napravite program koji na ulazu traži broj predmeta, te ispisuje prosječnu ocjenu i prolaznost
(procenat studenata koji su položili tj. dobili ocjenu 6 ili više). Također treba program ispisat ukupan broj
predmeta koje je student odslušao, broj položenih, te prosječnu ocjenu.
 */
struct Ispit{
    int brIndeksa;
    int predmet;
    int ocjena;
};
int main() {
    ifstream ispiti ("ispiti.txt", ios::in);
    Ispit *i = new Ispit[30]; int b = 0, brP;
    int suma = 0, brojacOcjena = 0, procenat = 0;
    if(ispiti.is_open()){
        while(ispiti >> i[b].brIndeksa >> i[b].predmet >> i[b].ocjena){b++;}
        cout << crte << "Predmeti: ";
        for(int I = 0; I < b; I++){
            cout << endl << i[I].predmet;
        }
        cout << endl << "Za koji predmet zelite izvjestaj? "; cin >> brP;
        //za racunanje ocjene
        for(int I = 0; I < b; I++){
            if(i[I].predmet == brP){
                suma += i[I].ocjena;
                brojacOcjena++;
                if(i[I].ocjena >= 6) procenat++;
            }
        }
        //izvjestaj doradit
        cout << suma << " " << brojacOcjena << " " << procenat;
    } else {
        cout << "Datoteka nije pronadjena!";
    }

    system("pause");
}


//100./(procenat/brojacOcjena)