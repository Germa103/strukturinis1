#include <iostream>
using namespace std;

int main()
{
                          // 1-2 Uzduotis //

    // int a = 2;
    // int b = 2;
    // int c = 2;
    // int d = 3;
    // int vidurkis = (a+b+c+d) / 4;
    //
    // if (vidurkis >= 5)
    //     cout << "Vidurkis teigiamas" << endl;
    // else
    //     cout << "Vidurkis neigiamas" << endl;

                          // 3-4 Uzduotis //

    // int pazymys = 10;
    // if (pazymys==10) {
    //     cout << "Puiku" << endl;
    // } else if (pazymys>=9) {
    //     cout << "Labai gerai" << endl;
    // } else if (pazymys>=7) {
    //     cout << "Gerai" << endl;
    // } else if (pazymys>=5) {
    //     cout << "Patenkinamai" << endl;
    // } else if (pazymys<5) {
    //     cout << "Egzaminas neislaikytas" << endl;
    // }

    // int pazymys = 10;
    // switch (pazymys) {
    // case 10:
    //     cout << "Puiku" << endl;
    //     break;
    // case 9:
    //     cout << "Labai gerai" <<endl;
    //     break;
    // case 8:
    // case 7:
    //     cout << "Gerai" << endl;
    //     break;
    // case 6:
    // case 5:
    //     cout << "Patenkinamai" << endl;
    //     break;
    // default:
    //     cout << "Egzaminas neislaikytas" << endl;
    // }

                         // 5 Uzduotis //

    // int suma = 0;
    //
    // for (int i = 1; i <= 10; i++) {
    //     if (i % 2 !=0) {
    //         suma += i;
    //     }
    // }
    // cout << "Nelyginiu skaiciu suma intervale [1; 20]: "<< suma << endl;
    // return 0;

                         // 6 Uzduotis //

    // double indelis = 1000.0;
    // double palukanos = 0.05;
    // int metai = 10;
    // double sum = indelis;
    // for (int i = 0; i < metai; i++) {
    //     sum *= (1 + palukanos);
    // }
    // cout << "Po 10 metu gaus: " << sum << endl;

                         // 7 Uzduotis //

    // for (int i = 1; i <= 20; i++)
    // {
    //     if (i % 4==0)
    //     {
    //         cout << i << endl;
    //     }
    // }

                         // Papildoma //

    int pasirinkimas, sk1 ,sk2, rezultatas;
    do {
        //MENU ISVEDIMAS
        cout << "Pasirinkite veiksma: \n";
        cout << "1 - sudetis \n";
        cout << "2 - skirtumas \n";
        cout << "3 - kvadratas \n";
        cout << "4 - iseiti is programos \n";
        cout << "Iveskite pasirinkima: " << endl;
        cin >> pasirinkimas;
    switch (pasirinkimas)
    {
    case 1:
        {
            cout << "Iveskite pirma skaiciu: " << endl;
            cin >> sk1;
            cout << "Iveskite antra skaiciu: " << endl;
            cin >> sk2;
            rezultatas = sk1 + sk2;
            cout << "Suma rezultatas: " << rezultatas << endl;
        }
        break;
    case 2:
        {
            cout << "Iveskite pirma skaiciu: " << endl;
            cin >> sk1;
            cout << "Iveskite antra skaiciu: " << endl;
            cin >> sk2;
            rezultatas = sk1 - sk2;
            cout << "Skirtumo rezultatas: " << rezultatas << endl;
        }
        break;
    case 3:
        {
            cout << "Iveskite pirma skaiciu: " << endl;
            cin >> sk1;
            rezultatas = sk1 * sk1;
            cout << "Kvadrato rezultatas: " << rezultatas << endl;
        }
    case 4:
        {
            cout << "Programa baigta " << endl;
            break;
        }
    default:
        cout << "Tokio pasirinkimo nera." << endl;
    }

    } while (pasirinkimas!=4);
    return 0;
}