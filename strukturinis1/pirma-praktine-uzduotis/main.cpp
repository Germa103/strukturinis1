#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const double GBP_Bendras = 0.8729, GBP_Pirkti = 0.8600, GBP_Parduoti = 0.9220;
    const double USD_Bendras = 1.1793, USD_Pirkti = 1.1460, USD_Parduoti = 1.2340;
    const double INR_Bendras = 104.6918, INR_Pirkti = 101.3862, INR_Parduoti = 107.8546;

    int pasirinkimas, valiuta;
    double kiekis, rezultatas = 0;
    do
    {
        cout << fixed << setprecision(2);

        cout << "\nVALIUTOS KEITYKLA \n";
        cout << "1 - Valiutos kurso palyginimas \n";
        cout << "2 - Pirkti valiuta \n";
        cout << "3 - Parduoti valiuta \n";
        cout << "4 - Iseiti is programos \n";
        cout <<" Iveskite pasirinkima: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 4) {
            cout << "Programa baigta" << endl;
            return 0;
        }

        cout << "\nPASIRINKITE VALIUTA \n";
        cout << "1 - USD \n";
        cout << "2 - GBP \n";
        cout << "3 - INR \n";
        cin >> valiuta;

        switch (pasirinkimas)
        {
        case 1: {
                if (valiuta == 1)
                    cout << "1 EUR = " << USD_Bendras << "USD" << endl;
                else if (valiuta == 2)
                    cout << "1 EUR = " << GBP_Bendras << "GBP" << endl;
                else if (valiuta == 3)
                    cout << "1 EUR = " << INR_Bendras << "INR" << endl;
                else
                    cout << "Tokio valiutos pasirinkimo nera" << endl;
                break;
        }
        case 2: {
                cout << "Iveskite EUR kieki";
                cin >> kiekis;
                if (valiuta == 1)
                    rezultatas = kiekis * USD_Pirkti;
                else if (valiuta == 2)
                    rezultatas = kiekis * GBP_Pirkti;
                else if (valiuta == 3)
                    rezultatas = kiekis * INR_Pirkti;
                else
                    cout << "Tokio valiutos pasirinkimo nera" << endl;
                cout << "Gausite " << rezultatas << " pasirinktos valiutos" << endl;
                break;
        }
        case 3: {
                cout << "Iveskite pasirinktos valiutos kieki";
                cin >> kiekis;
                if (valiuta == 1)
                    rezultatas = kiekis / USD_Parduoti;
                else if (valiuta == 2)
                    rezultatas = kiekis / GBP_Parduoti;
                else if (valiuta == 3)
                    rezultatas = kiekis / INR_Parduoti;
                else
                    cout << "Tokio valiutos pasirinkimo nera" << endl;
                cout << "Pardavus " << kiekis << " pasirinktos valiutos gausite " << rezultatas << " EUR" << endl;
                break;
        }
        case 4: {
                cout << "Programa baigta" << endl;
                break;
        }
        default:
            cout << "Tokio pasirinkimo nera" << endl;
        }
    } while (pasirinkimas != 4);
return 0;
}