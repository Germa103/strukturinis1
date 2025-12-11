#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[], int &n) {
    ifstream fin("menu.txt");
    if (!fin) {
        cout << "Nepavyko atidaryti failo menu.txt" << endl;
    }
    n = 0;

    while (fin >> menuList[n].menuItem >> menuList[n].menuPrice) {
        n++;
    }
    fin.close();
}

void showMenu(menuItemType menuList[], int n) {
    cout << "Sveiki atvyke i restorana ,,Stasio kampas''\n\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << menuList[i].menuItem << " " << menuList[i].menuPrice << " EUR\n";
    }
    cout << "\nPasirinkite patiekalus pagal numerius.\n\n";
}

void printCheck(menuItemType menuList[], int pasirinkimas[], int kiekis[], int skaicius) {
    ofstream fout("receipt.txt");
    double suma = 0;
    cout << fixed << setprecision(2);
    fout << fixed << setprecision(2);

    cout << "---SASKAITA---\n";
    fout << "---SASKAITA---\n";
    cout << endl;
    fout << endl;

    for (int i = 0; i < skaicius; i++) {
        int idx = pasirinkimas[i] - 1;
        double eilute = menuList[idx].menuPrice * kiekis[i];
        suma += eilute;

        cout << kiekis[i] << " " << menuList[idx].menuItem << " " << eilute << " EUR\n";
        fout << kiekis[i] << " " << menuList[idx].menuItem << " " << eilute << " EUR\n";
    }
    double pvm = suma * 0.21;
    double total = suma + pvm;
    cout << "\nMokesciai (21%): " << pvm << " EUR\n";
    cout << "Galutine suma: " << total << " EUR\n";
    fout << "\nMokesciai (21%): " << pvm << " EUR\n";
    fout << "Galutine suma: " << total << " EUR\n";
    fout.close();
}
int main () {
    menuItemType menuList[20];
    int n = 0;
    getData(menuList, n);
    showMenu(menuList, n);
    int pasirinkimas[50];
    int kiekis[50];
    int skaicius = 0;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        cout << "Patiekalo numeris: ";
        cin >> pasirinkimas[skaicius];

        cout << "Kiek porciju? ";
        cin >> kiekis[skaicius];
        skaicius++;
        cout << "Ar dar kazko noresite? (y/n): ";
        cin >> cont;
        cout << endl;
    }
    printCheck(menuList, pasirinkimas, kiekis, skaicius);
    return 0;
}