#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
string crte = "\n------------------------------------------------------------------------------------------------------------------\n";

int main() {
    ifstream test("test.txt");

    if(test.is_open()){
        string temp;
        while(getline(test, temp)){
            if(sqrt(temp.size()) != floor(sqrt(temp.size()))){
                cout << "GRESKA!!";
                break;
            }
            double vel = sqrt(temp.size());
            int brojac = 0;
            vector<vector<char>>matrica;
            for(int i = 0; i < vel; i++){
                vector<char>temp1;
                for(int y = 0; y < vel; y++){
                    temp1.push_back(temp[brojac]);
                    brojac++;
                }
                matrica.push_back(temp1);
            }
            for(int i = 0; i < vel; i++){
                for(int y = 0; y < vel; y++){
                    cout << matrica[y][i];
                }
            } cout << endl;
        }
    } else {
        cout << "Datoteka nije pronadjena!";
    }
    test.close();
    system("pause");
}
