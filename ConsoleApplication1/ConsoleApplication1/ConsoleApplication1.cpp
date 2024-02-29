#include <iostream>
#include <vector>
#include <locale>
#include <iomanip>
#include <numeric>   
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<double> namudarburez; // vektorius dinaminiam namu darbu rezultatu saugojimui
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

void Rikiavimas(vector<double>& mas)
{
    sort(mas.begin(), mas.end()); // std::sort sortinimui
}

double Mediana(const vector<double>& namudarburez) // perduodame vektoriu kaip konstanta, kad nebutu galima jo pakeisti
{
    double mediana = 0.0;
    int namudarbai = namudarburez.size();
    if (namudarbai % 2 == 0)
    {
        mediana = (namudarburez[namudarbai / 2] + namudarburez[namudarbai / 2 - 1]) / 2.0;
    }
    else
    {
        mediana = namudarburez[namudarbai / 2];
    }
    return mediana;
}

double GenerateRandomGrade()
{
    return rand() % 11; 
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    srand(time(NULL));

    vector<Studentas> studentai; // student� vektorius

    while (true)
    {
        Studentas stud;
        cout << "�veskite studento vard� ir pavard�. Nor�dami baigti �vedim�, �veskite -1: ";
        cin >> stud.vardas;
        if (stud.vardas == "-1")
            break;
        cin >> stud.pavarde;
        cout << "Pasirinkite b�d� �vesti balus:\n1. �vesti rankiniu b�du\n2. Sugeneruoti atsitiktinius balus\nPasirinkimas: ";
        int pasirinkimas;
        cin >> pasirinkimas;
        if (pasirinkimas == 1) {
            cout << "�veskite nam� darb� rezultatus. Nor�dami baigti �vedim�, �veskite -1: ";
            double namudarburez;
            while (true)
            {
                if (!(cin >> namudarburez)) {
                    cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (namudarburez == -1)
                    break;
                if (namudarburez >= 0 && namudarburez <= 10)
                {
                    stud.namudarburez.push_back(namudarburez); // kisame rezultata i vektoriu
                }
                else
                {
                    cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                }
            }
        }
        else if (pasirinkimas == 2) {
            cout << "Generuojami atsitiktiniai balai u� nam� darbus..." << endl;
            for (int i = 0; i < 5; ++i)
            {
                stud.namudarburez.push_back(GenerateRandomGrade());
            }
        }
        Rikiavimas(stud.namudarburez); // rikiuojame vektoriu su std::sort
        if (pasirinkimas == 1) {
            cout << "�veskite egzamino rezultat� (turi b�ti tarp 0 ir 10): ";
            cin >> stud.egzaminorez;
        }
        else if (pasirinkimas == 2) {
            stud.egzaminorez = GenerateRandomGrade();
            cout << "Sugeneruotas atsitiktinis egzamino balas: " << stud.egzaminorez << endl;
        }
        stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
        stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
        stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
        stud.mediana = Mediana(stud.namudarburez); // mediana skaiciuojama is rikiuoto vektoriaus
        stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
        studentai.push_back(stud); // siunciame studenta i vektoriu
    }
    if (!studentai.empty())
    {
        cout << "Kur� galutinio balo skai�iavimo b�d� renkat�s? (1 - vidurkis; 2 - mediana)" << endl;
        int skaicbudas;
        cin >> skaicbudas;
        if (skaicbudas == 1)
        {
            cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << endl;
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            for (const auto& stud : studentai)
            {
                cout << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasvidurkis << endl;
            }
        }
        else if (skaicbudas == 2)
        {
            cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (med.)" << endl;
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            for (const auto& stud : studentai)
            {
                cout << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
            }
        }
        else
        {
            NetinkamaIvestis();
        }
    }
    else
    {
        NetinkamaIvestis();
    }
    return 0;
}
//nesamone baigta