#include <iostream>
#include <locale>
#include <iomanip>

const int N = 50;
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    double namudarburez[N];
    double egzaminorez;
    double namudarburezsuma;
    double vidurkis;
    double galutinisbalas;
};
void NetinkamaIvestis()
{
    cout << "Netinkama �vestis. Programa i�jungiama...";
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int studentukiekis;
    cout << "Kiek bus student�?: " << endl;
    cin >> studentukiekis;
    if (studentukiekis > 0)
    {
        cout << "kiek bus namu darb�?: " << endl;
        double namudarbai;
        cin >> namudarbai;
        studentas stud[N];
        if (namudarbai > 0)
        {
            for (int i = 0; i < studentukiekis; i++)
            {
                cout << "Iveskite studento vard� ir pavarad�: " << endl;
                cin >> stud[i].vardas;
                cin >> stud[i].pavarde;
                stud[i].namudarburezsuma = 0;
                for (int j = 0; j < namudarbai; j++)
                {
                    while (true)
                    {
                        cout << "Iveskite " << j + 1 << "-ojo nam� darbo rezultat� (turi b�ti tarp 0 ir 10): " << endl;
                        if (cin >> stud[i].namudarburez[j] && stud[i].namudarburez[j] >= 0 && stud[i].namudarburez[j] <= 10)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                        }
                    }
                    stud[i].namudarburezsuma += stud[i].namudarburez[j];
                }
                cout << "Iveskite egzamino rezultat�: " << endl;
                cin >> stud[i].egzaminorez;
                stud[i].vidurkis = stud[i].namudarburezsuma / namudarbai;
                stud[i].galutinisbalas = stud[i].vidurkis * 0.4 + stud[i].egzaminorez * 0.6;
            }

            cout << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << setw(30) << endl;
            cout << "-----------------------------------------------------------" << endl;
            for (int i = 0; i < studentukiekis; i++)
            {
                cout << stud[i].pavarde << "         " << stud[i].vardas << "                " << stud[i].galutinisbalas << fixed << setprecision(3) << endl;
            }
        }
        else NetinkamaIvestis();
    }
    else NetinkamaIvestis();
}


