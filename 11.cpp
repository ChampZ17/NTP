#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct ispiti{
    int brIndexa;
    string predmet;
    int ocjena;
};
int main() {
    ispiti isp[20];
    ispiti temp;
    int pom=0;
    ifstream ulaz ("ispiti.txt");
    if (!ulaz){
        cout<<"Ne mozemo pristupiti datoteci!!!"<<endl;
    }else{
        while (ulaz>>temp.brIndexa>>temp.predmet>>temp.ocjena){
            isp[pom]=temp;
            pom++;
        }
    }
    ulaz.close();
    cout<<"1. NTP"<< endl;
    cout<<"2. OS"<<endl;
    cout<<"3. RM"<<endl;
    cout<<"4. DM"<<endl;
    cout<<"5. EJ"<<endl;
    cout<<"Na osnovu rednog broja izaberite predmet za koji zelite podatke";
    int x;
    cin>>x;
    float prosjecnaOcjena, suma=0;
    int br=0, brProlaznih=0;
    switch (x) {
        case 1:
            for (int i = 0; i < pom; i++) {
                if (isp[i].predmet=="NTP"){
                    suma+=isp[i].ocjena;
                    br++;
                    if (isp[i].ocjena>5) brProlaznih++;
                }
            } break;
        case 2:
            for (int i = 0; i < pom; i++) {
                if (isp[i].predmet=="OS"){
                    suma+=isp[i].ocjena;
                    br++;
                    if (isp[i].ocjena>5) brProlaznih++;
                }
            } break;
        case 3:
            for (int i = 0; i < pom; i++) {
                if (isp[i].predmet=="RM"){
                    suma+=isp[i].ocjena;
                    br++;
                    if (isp[i].ocjena>5) brProlaznih++;
                }
            } break;
        case 4:
            for (int i = 0; i < pom; i++) {
                if (isp[i].predmet=="DM"){
                    suma+=isp[i].ocjena;
                    br++;
                    if (isp[i].ocjena>5) brProlaznih++;
                }
            } break;
        case 5:
            for (int i = 0; i < pom; i++) {
                if (isp[i].predmet=="EJ"){
                    suma+=isp[i].ocjena;
                    br++;
                    if (isp[i].ocjena>5) brProlaznih++;
                }
            } break;
    }
    prosjecnaOcjena=suma/br;
    cout<<"Prosjecna ocjena iznosi: "<<prosjecnaOcjena<<endl;
    cout<<"Prolaznost je: "<<(float(brProlaznih)/br)*100<<"%"<<endl;

    cout<<"Unesite broj Index-a studenta: ";
    int index;
    cin>>index;
    int brSlusanih=0, brPolozenih=0;
    float s=0, prosjek;
    for (int i = 0; i < pom; i++) {
        if(isp[i].brIndexa==index){
            if(isp[i].predmet=="NTP") brSlusanih++;
            if(isp[i].predmet=="OS") brSlusanih++;
            if(isp[i].predmet=="RM") brSlusanih++;
            if(isp[i].predmet=="DM") brSlusanih++;
            if(isp[i].predmet=="EJ") brSlusanih++;
            if(isp[i].ocjena>5) brPolozenih++;
            s+=isp[i].ocjena;
        }
    }
    prosjek=s/brProlaznih;
    cout<<"Student sa index-om "<<index<<" je slusao ukupno "<< brSlusanih<<" predmeta!!!"<<endl;
    cout<<"Student sa index-om "<<index<<" je polozio ukupno "<< brPolozenih<<" predmeta!!!"<<endl;
    cout<<"Student sa index-om "<<index<<" ima prosjek od"<< prosjek<<endl;
    system("pause");
    return 0;
}
