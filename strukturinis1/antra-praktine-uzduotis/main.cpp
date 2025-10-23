#include <iostream>
using namespace std;
int main()
{
    const int max_mokiniai = 3;
    const int max_pazymiai = 3;
    string vardai[max_mokiniai];
    int pazymiai[max_mokiniai][max_pazymiai];
    int pazymiuKiekis[max_mokiniai];
    int mokiniuKiekis = 0;
    int pasirinkimas;
    do {
        cout <<"\n===== Mokiniu pazymiu sistema ===== \n";
        cout <<"1 - Prideti mokini ir jo pazymius\n";
        cout <<"2 - Perziureti visu mokiniu pazymius\n";
        cout <<"3 - Perziureti konkretaus mokinio pazymius\n";
        cout <<"4 - Atnaujinti konkretu pazymi konkreciam mokiniui\n";
        cout <<"5 - Pasalinti mokini is saraso\n";
        cout <<"6 - Baigti\n";
        cout <<"Pasirinkite veiksma: ";
        cin >> pasirinkimas;
        switch (pasirinkimas) {
        case 1:
            {
                if (mokiniuKiekis >= max_mokiniai)
                {
                    cout << "Negalima prideti daugiau mokiniu."<<endl;
                    break;
                }
                cout << "Iveskite naujo mokinio varda (max 100 mokiniu): ";
                cin >> vardai[mokiniuKiekis];
                cout << "Pazymiu kiekis (max "<< max_pazymiai << "): ";
                cin >> pazymiuKiekis[mokiniuKiekis];
                if (pazymiuKiekis[mokiniuKiekis] > max_pazymiai)
                    pazymiuKiekis[mokiniuKiekis] = max_pazymiai;
                for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++)
                {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniuKiekis][i];
                }
                mokiniuKiekis++;
                cout << "Mokinys pridetas" << endl;
                break;
            }
        case 2: {
                if (mokiniuKiekis == 0)
                {
                    cout << "Nera mokiniu duomenu bazeje" << endl;
                    break;
                }
                cout << "===== Visi mokiniai =====" << endl;
                for (int i = 0; i < mokiniuKiekis; i++)
                {
                    cout << i + 1 << ". " << vardai[i] << ": ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++)
                    {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
                case 3: {
                        if (mokiniuKiekis == 0)
                        {
                             cout << "Nera mokiniu duomenu bazeje" << endl;
                            break;
                        }
                        int numeris;
                        cout << "Iveskite mokinio numeri (1-"<< mokiniuKiekis << "): ";
                        cin >> numeris;
                        if (numeris < 1 || numeris > mokiniuKiekis ) {
                            cout << "Tokio mokinio nera." << endl;
                            break;
                        }
                        numeris--;
                        cout << "Mokinio vardu " << vardai[numeris] << " pazymiai: ";
                        for (int j = 0; j < pazymiuKiekis[numeris]; j++) {
                            cout << pazymiai[numeris][j] << " ";
                        }
                        break;
                    }
                case 4: {
                        if (mokiniuKiekis == 0)
                        {
                            cout << "Nera mokiniu duomenu bazeje" << endl;
                            break;
                        }
                        int numeris;
                        cout << "Iveskite mokinio numeri (1-" << mokiniuKiekis << "): ";
                        cin >> numeris;
                        if (numeris < 1 || numeris > mokiniuKiekis ) {
                            cout << "Tokio mokinio nera." << endl;
                            break;
                        }
                        numeris--;
                        cout << "Kurio pazymio numeri norite pakeisti (1-" << pazymiuKiekis[numeris] << "): ";
                        int nr2;
                        cin >> nr2;
                        if (nr2 < 1 || nr2 > pazymiuKiekis[numeris]) {
                            cout << "Nera tokio numerio." << endl;
                            break;
                        }
                        cout << "Iveskite nauja pazymi: ";
                        cin >> pazymiai[numeris][nr2 - 1];
                        cout << "Pazymys pakeistas." << endl;
                        break;
                    }
                case 5: {
                        if (mokiniuKiekis == 0)
                        {
                            cout << "Nera mokiniu duomenu bazeje" << endl;
                            break;
                        }
                        int numeris;
                        cout << "Iveskite mokinio numeri, kuri norite pasalinti (1-" << mokiniuKiekis << "): ";
                        cin >> numeris;
                        if (numeris < 1 || numeris > mokiniuKiekis ) {
                            cout << "Tokio mokinio nera." << endl;
                            break;
                        }
                        numeris--;
                        for (int i = numeris; i < mokiniuKiekis; i++) {
                            vardai[i] = vardai[i + 1];
                            pazymiuKiekis[i] = pazymiuKiekis[i + 1];
                            for (int j = 0; j < max_pazymiai; j++) {
                                pazymiai[i][j] = pazymiai[i + 1][j];
                            }
                        }
                        mokiniuKiekis--;
                        cout << "Mokinys pasalintas." << endl;
                        break;
                    }
                case 6:
                        cout << "Programa baigta." << endl;
                        break;
                default:
                    cout << "Neteisingas pasirinkimas." << endl;
                    break;

            }
        } while (pasirinkimas != 6);

    return 0;
}

