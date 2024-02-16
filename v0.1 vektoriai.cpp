#include <iostream>
#include <locale>
#include <iomanip>

const int N = 50;
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    double* namudarburez = new double();
    double egzaminorez;
    double namudarburezsuma;
    double vidurkis;
    double galutinisbalasvidurkis;
    double mediana;
    double galutinisbalasmediana;
};
void NetinkamaIvestis()
{
    cout << "Netinkama �vestis. Programa i�jungiama...";
}
void Rikiavimas(double mas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                double temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}
double mediana(studentas stud[], int namudarbai, int i)
{
    double mediana = 0.0;
    for (int i = 0; i < namudarbai; i++)
    {
        if (namudarbai % 2 == 0)
        {
            mediana = (stud[i].namudarburez[namudarbai / 2] + stud[i].namudarburez[namudarbai / 2 - 1]) / 2.0;
        }
        else
        {
            mediana = stud[i].namudarburez[namudarbai / 2];
        }
        return mediana;
    }

}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int studentukiekis = 0;
    if (studentukiekis > -1 && studentukiekis < INT_MAX)
    {
        cout << "kiek bus nam� darb�?: " << endl;
        int namudarbai;
        cin >> namudarbai;
        studentas* stud = new studentas();
        if (namudarbai > 0 && namudarbai < INT_MAX)
        {
            for (int i = 0; i < INT_MAX; i++)
            {
                cout << "Iveskite studento vardus ir pavardes. Nor�dami baigti �vedim�, �veskite skaitmen� -1: " << endl;
                if (cin >> stud[i].vardas && stud[i].vardas == "-1" || cin >> stud[i].pavarde && stud[i].pavarde == "-1")
                {
					break;
				}
                else
                {
                    studentukiekis++;
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
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        stud[i].namudarburezsuma += stud[i].namudarburez[j];
                    }

                    Rikiavimas(stud[i].namudarburez, namudarbai);
                    stud[i].mediana = mediana(stud, namudarbai, i);
                    while (true)
                    {
                        cout << "Iveskite egzamino rezultat� (turi b�ti tarp 0 ir 10): " << endl;

                        if (cin >> stud[i].egzaminorez && stud[i].egzaminorez >= 0 && stud[i].egzaminorez <= 10)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    stud[i].vidurkis = stud[i].namudarburezsuma / namudarbai;
                    stud[i].galutinisbalasvidurkis = stud[i].vidurkis * 0.4 + stud[i].egzaminorez * 0.6;
                    stud[i].galutinisbalasmediana = stud[i].mediana * 0.4 + stud[i].egzaminorez * 0.6;
                }
            }
            cout << "Kur� galutinio balo skai�iavimo b�d� renkat�s? (1 - vidurkis; 2 - mediana)" << endl;
            int skaicbudas;
            if (cin >> skaicbudas && skaicbudas == 1 && studentukiekis >= 1)
            {
                cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << endl;
                cout << "---------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentukiekis; i++)
                {
                    cout << setw(15) << stud[i].pavarde << setw(15) << stud[i].vardas << setw(30) << fixed << setprecision(2) << stud[i].galutinisbalasvidurkis;
                }
            }
            else if (skaicbudas == 2 && studentukiekis >= 1)
            {
                cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (med.)" << endl;
                cout << "---------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentukiekis; i++)
                {
                    cout << setw(15) << stud[i].pavarde << setw(15) << stud[i].vardas << setw(30) << fixed << setprecision(2) << stud[i].galutinisbalasmediana;
                }
            }
            else
                NetinkamaIvestis();
        }
        else NetinkamaIvestis();
    }
    else NetinkamaIvestis();
}