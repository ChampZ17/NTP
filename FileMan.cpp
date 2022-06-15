#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

enum Vrsta{privatni=1, poslovni, super};

struct Datum{
    int dan, mjesec, godina;
};

struct Racun{
    int idPotrosaca;
    char imePrezime[50];
    Datum danIzdavanja;
    float iznos;
    Vrsta vrsta;
};


void unosRacuna(Racun &racun){
    bool ispravno = true;
    cout<<"ID: ";
    cin>>racun.idPotrosaca;
    cin.ignore();
    cout<<"Ime i prezime: ";
    cin.getline(racun.imePrezime, 50);

    do{
        cout<<"Unesite dan, mjesec i godinu racuna: ";
        cin>>racun.danIzdavanja.dan>>racun.danIzdavanja.mjesec>>racun.danIzdavanja.godina;
        ispravno = true;
        if(racun.danIzdavanja.mjesec<1 || racun.danIzdavanja.mjesec>12){
            ispravno = false;
        }
        if(racun.danIzdavanja.mjesec==1 ||
        racun.danIzdavanja.mjesec==3 ||
        racun.danIzdavanja.mjesec==5 ||
        racun.danIzdavanja.mjesec==7 ||
        racun.danIzdavanja.mjesec==8 ||
        racun.danIzdavanja.mjesec==10 ||
        racun.danIzdavanja.mjesec==12 ){
            if(racun.danIzdavanja.dan<1||racun.danIzdavanja.dan>31){
                ispravno = false;
            }
        }
        if(racun.danIzdavanja.mjesec==4 ||
        racun.danIzdavanja.mjesec==6 ||
        racun.danIzdavanja.mjesec==10 ||
        racun.danIzdavanja.mjesec==11 ){
            if(racun.danIzdavanja.dan<1||racun.danIzdavanja.dan>30){
                ispravno = false;
            }
        }
        if(racun.danIzdavanja.mjesec==2){
            if(racun.danIzdavanja.godina<1995||racun.danIzdavanja.godina>2022){
                ispravno = false;
            }else{
                if(racun.danIzdavanja.godina%4==0){
                    if(racun.danIzdavanja.dan<1||racun.danIzdavanja.dan>29){
                ispravno = false;
                    }
                }else {
                    if(racun.danIzdavanja.dan<1||racun.danIzdavanja.dan>28){
                        ispravno = false;
                    }
                }
            }
        }
        if(racun.danIzdavanja.godina<1995||racun.danIzdavanja.godina>2022){
                ispravno = false;
            }
        }while(ispravno==false);
        
        
    cout<<"Unesite iznos racuna: ";
    cin>>racun.iznos;
    int x;
    cout<<"Unesite vrstu racuna: ";
    cout<<"\n\t1 = Privatni\n\t2 = Poslovni\n\t3 = Super\n";
    cout<<"Odabir: ";
    
    
    do{
        cin>>x;
        if(x<1 || x>3){
            cout<<"\nUnesi ponovo:\n";
        }
    }while(x<1 || x>3);
    racun.vrsta = Vrsta(x);
    

    ofstream file("racuni.txt" , ios::app);
    file<<"ID: "<<racun.idPotrosaca<<endl;
    file<<"Korisnik: "<<racun.imePrezime<<endl;
    file<<"Datum: "<<racun.danIzdavanja.dan<<"."<<racun.danIzdavanja.mjesec<<"."<<racun.danIzdavanja.godina<<"."<<endl;
    file<<"Iznos: "<<racun.iznos<<endl;
    file<<"Vrsta: ";
    
    
    if(racun.vrsta == privatni){
        file<<"Privatni"<<endl;
    }else if(racun.vrsta == poslovni){
        file<<"Poslovni"<<endl;
    }else if(racun.vrsta == super){
        file<<"Super"<<endl;
    }
    file.close();
}


void pregledRacuna(){
    string provjera;
    int pom;
    int br = 0;
    int cont = 0;
    
    cout << left << setw(8) << "ID" << setw(20) << "Potrosac" << setw(15) << "Datum" << setw(12) << "Iznos" << setw(14) << "Vrsta" << endl;
    
    ifstream file("racuni.txt");
    
    while(!file.eof()){
        file>>provjera;
        if(provjera=="ID:"){
            file>>provjera;
            cout<<setw(8)<<provjera;  
        }
        
        file>>provjera;
        if(provjera=="Korisnik:"){
            file>>provjera;
            cout<<provjera<<" ";
            file>>provjera;  
            cout<<provjera;
        }
        
        file>>provjera;
        if(provjera=="Datum:"){
            file>>provjera;
            cout<<"\t  "<<provjera;  
        }
        
        file>>provjera;
        if(provjera=="Iznos:"){
            file>>provjera;
            cout<<"\t    "<<provjera;
        }
        
        file>>provjera;
        if(provjera=="Vrsta:"){
            file>>provjera;
            cout<<"\t\t"<<provjera;
        }
        cout<<endl;
    }
    
    file.close();
    cout<<"Povratak na meni pritisnite 1?\n";
    cin>>cont;
}

void ispisUplatnice(){
    string provjera;
    int pom;
    int brojac = 0;
    int odabir = 0;
    
    cout<<"Lista korsnika: "<<endl;
    
    ifstream file("racuni.txt");
    
    while(!file.eof()){
        file>>provjera;
        if(provjera=="ID:"){
            cout<<"----------------\n";
            cout<<"ID: ";
            file>>provjera;
            cout<<provjera<<endl;
            file>>provjera;
            cout<<provjera<<" ";
            file>>provjera;
            cout<<provjera<<" ";
            file>>provjera;
            cout<<provjera<<endl;
        }
        brojac++;
    }
    file.close();

    cout<<"----------------------------------------------\n";
    cout<<"Unesite ID korisnika za kojeg zelite uplatnicu: ";
    cin>>odabir;
    
    ifstream file("racuni.txt");
    
    while(!file.eof()){
        file>>provjera;
        
        if(provjera=="ID:"){
        	
            file>>provjera;
            pom = stoi(provjera);
            
            if(odabir==pom){
                
                ofstream fileID("ID.txt", ios::out);
                fileID<<"----------------------------------------------------"<<endl;
                fileID<<"\t\tMoj Glas.doo\n";
                fileID<<"----------------------------------------------------"<<endl;
                fileID<<"ID: "<<provjera<<"\t";
                file>>provjera;
                fileID<<provjera<<" ";
                file>>provjera;
                fileID<<provjera<<" ";
                file>>provjera;
                fileID<<provjera<<"   ";
                file>>provjera>>provjera;
                file>>provjera;
                fileID<<provjera<<" ",
                file>>provjera;
                fileID<<provjera;
                fileID<<"\n\tPotpis_____________________"<<endl;
                fileID<<"----------------------------------------------------"<<endl;
                fileID.close();
                cout<<"Uplatnica je uspjesno kreirana!"<<endl;
                
            }
        }
    }
    file.close();
}


int main (){
    int br = 0;
    int izbor = 0;
    Racun racun[20];

    do{
        cout << "----------------------------------------------\n";
        cout << "\t\tMeni:\n";
        cout << "----------------------------------------------\n";
        cout << "\t1. Unos racuna\n";
        cout << "\t2. Pregled racuna\n";
        cout << "\t3. Ispis uplatnice\n";
        cout << "\t4. Kraj\n";
        cout << "----------------------------------------------\n";
        cout<<"Odabir: ";
        cin>>izbor;
            if(izbor==1){
                unosRacuna(racun[br]);
            }
            if(izbor==2){
                pregledRacuna();
            }
            if(izbor==3){
                ispisUplatnice();
            }

    }while(izbor!=4);
    
    return 0;
}
