#include <iostream>
#include <locale>

const int N = 50;
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    int namudarburez[N];
    int egzaminorez;
    int namudarburezsuma;
    double vidurkis;
};

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int studentukiekis; 
    cout << "Kiek bus student�?: " << endl;
    cin >> studentukiekis;
    cout << "kiek bus namu darb�?: " << endl;
    int namudarbai;
    cin >> namudarbai;
    studentas stud[N];
    int galutinisvertinimas[N];
    for (int i = 0; i < studentukiekis; i++)
    {
        cout << "Iveskite studento vard� ir pavarad�: " << endl;
        cin >> stud[i].vardas;
        cin >> stud[i].pavarde;
        if (namudarbai > 0)
        {
        for (int j = 0; j < namudarbai; j++) {
            cout << "Iveskite " << j+1 << "-ojo nam� darbo rezultat� : " << endl;
            cin >> stud[j].namudarburez[j];
            stud[i].namudarburezsuma += stud[i].namudarburez[j];
        }
        }
        cout << "Iveskite egzamino rezultat�: " << endl;
        cin >> stud[i].egzaminorez;
        stud[i].vidurkis = stud[i].namudarburezsuma / namudarbai;


    }
    cout << "Pavard�          Vardas           Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < studentukiekis; i++)
    {
        cout << stud[i].pavarde << "         " << stud[i].vardas << "         " << stud[i].vidurkis << endl;
    }
}

