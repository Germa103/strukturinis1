#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    int pasirinkimas;
    double kaina;
    double kiekis;
    do {
        cout <<"\nDuomenu apdorojimo sistema\n";
        cout <<"1 - Bilietu pardavimu suma\n";
        cout <<"2 - Atlyginimu atnaujinimas\n";
        cout <<"0 - Baigti\n";
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 1: {
                ifstream bilietuFailas("bilietai.txt");

                if (bilietuFailas.fail()) {
                    cout << "Nepavyko atidaryti failo bilietai.txt"<< endl;
                    return 1;
                }
                double parduotiBilietai = 0;
                double bendraSuma = 0;

                while (bilietuFailas >> kaina >> kiekis) {
                    parduotiBilietai += kiekis;
                    bendraSuma += kaina * kiekis;
                }
                cout << fixed << setprecision(2) << "Parduotu bilietu skaicius: " << parduotiBilietai << endl;
                cout << fixed << setprecision(2) << "Bendra pardavimu suma: " << bendraSuma << endl;

                bilietuFailas.close();

                ofstream bilietuIsvestis("bilietai_isv.txt");

                if (bilietuIsvestis.fail()) {
                    cout << "Nepavyko atidaryti isvesties failo bilietai_isv.txt" << endl;
                    return 1;
                }
                bilietuIsvestis << fixed << setprecision(2) << "Parduotu bilietu skaicius: " << parduotiBilietai << endl;
                bilietuIsvestis << fixed << setprecision(2) << "Bendra pardavimu suma: " << bendraSuma << endl;

                bilietuIsvestis.close();

                cout << endl << "Rezultatai isvesti i faila bilietai_isv.txt" << endl;
                break;
            }
            case 2: {                                                                           
                ifstream atlyginimuFailas("salary.txt");

                if(atlyginimuFailas.fail()) {
                    cout << "Nepavyko atidaryti failo salary.txt" << endl;
                    return 1;
                }
                ofstream atnaujintiAtlyginimai("newSalary.txt");

                if(atnaujintiAtlyginimai.fail()) {
                    cout << "Nepavyko atidaryti failo newSalary.txt" << endl;
                    return 1;
                }
                string pavarde;
                string vardas;
                double esamasAtlyginimas;
                double padidejimoProcentas;
                double atnaujintasAtlyginimas;

                while (atlyginimuFailas >> pavarde >> vardas >> esamasAtlyginimas >> padidejimoProcentas) {
                    atnaujintasAtlyginimas = esamasAtlyginimas * (1.0 + padidejimoProcentas / 100.0);
                    cout << fixed << setprecision(2) << pavarde << " " << vardas << " " << atnaujintasAtlyginimas << endl;
                    atnaujintiAtlyginimai << fixed << setprecision(2) << pavarde << " " << vardas << " " << atnaujintasAtlyginimas << endl;
                }
                cout << endl << "Rezultatai isvesti i faila newSalary.txt" << endl;
                atlyginimuFailas.close();
                atnaujintiAtlyginimai.close();
                break;
            }
            case 0: {
                cout << "Programa baigta." << endl;
                break;
            }
            default:
                cout << "Tokio pasirinkimo nera." << endl;
                break;
        }        
    } while (pasirinkimas!=0);     
 return 0;
}