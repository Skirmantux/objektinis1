#include <iostream>
#include <vector>
#include <locale>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono> // Added chrono library

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<double> namudarburez;
    double egzaminorez = 0.0;
    double namudarburezsuma = 0.0;
    double vidurkis = 0.0;
    double galutinisbalasvidurkis = 0.0;
    double mediana = 0.0;
    double galutinisbalasmediana = 0.0;
};

void NetinkamaIvestis()
{
    cout << "Netinkama �vestis. Programa i�jungiama...";
}
void NeraFailo()
{
    cout << "Failas nerastas. Programa i�jungiama...";
}

void Rikiavimas(vector<double>& mas)
{
    sort(mas.begin(), mas.end());
}

double Mediana(const vector<double>& namudarburez)
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

string GeneruotiVardus()
{
    vector<string> vardai = { "Jonas", "Petras", "Antanas", "Marius", "Tomas" };
    return vardai[rand() % vardai.size()];
}

string GeneruotiPavardes()
{
    vector<string> pavardes = { "Kazlauskas", "Petrauskas", "Stankevi�ius", "Gudelis", "Luk�ys" };
    return pavardes[rand() % pavardes.size()];
}

bool vardolyginimas(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.vardas;
}

bool pavardeslyginimas(const Studentas& a, const Studentas& b)
{
    return a.pavarde < b.pavarde;
}

bool vidurkiolyginimas(const Studentas& a, const Studentas& b)
{
    return a.galutinisbalasvidurkis < b.galutinisbalasvidurkis;
}

bool medianoslyginimas(const Studentas& a, const Studentas& b)
{
    return a.galutinisbalasmediana < b.galutinisbalasmediana;
}

void PrintStudents(const vector<Studentas>& studentai)
{
    auto start_print = chrono::high_resolution_clock::now();
    cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    for (const auto& stud : studentai)
    {
        cout << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
    }
    auto end_print = chrono::high_resolution_clock::now();
    chrono::duration<double> write_time = end_print - start_print;
    cout << "Rasymo i ekrana trukme: " << write_time.count() << " sekundes" << endl;
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    srand(time(NULL));
    vector<Studentas> studentai;
    int pasirinkimas;
    chrono::duration<double> process_time;
    chrono::duration<double> read_time;
    cout << "Pasirinkite b�d� �vesti balus:\n1. �vesti rankiniu b�du\n2. Sugeneruoti atsitiktinius balus\n3. Sugeneruoti balus, vardus ir pavardes\n4. Skaitymas i� failo.\n5. Baigti program�.\nPasirinkimas: ";
    while (true) {
        if (cin >> pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3 || pasirinkimas == 4)) {
            break;
        }
        else if (pasirinkimas == 5) {
            cout << "Programa i�jungiama...";
            return 0;
        }
        else {
            cout << "Netinkama �vestis. Pasirinkite b�d� �vesti balus:\n1. �vesti rankiniu b�du\n2. Sugeneruoti atsitiktinius balus\n3. Sugeneruoti balus, vardus ir pavardes\n4. Skaitymas i� failo.\n5. Baigti program�.\nPasirinkimas: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true)
    {
        Studentas stud;
        if (pasirinkimas == 1) {
            while (true) {
                Studentas stud;
                cout << "�veskite studento vard� ir pavard�. Nor�dami baigti �vedim�, �veskite -1: ";
                cin >> stud.vardas;
                if (stud.vardas == "-1")
                    break;
                cin >> stud.pavarde;
                if (stud.pavarde == "-1")
                    break;
                cout << "�veskite nam� darb� rezultatus. Nor�dami baigti �vedim�, �veskite -1: ";
                while (true) {
                    double namudarburez;
                    if (!(cin >> namudarburez)) {
                        cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (namudarburez == -1)
                        break;
                    if (namudarburez >= 0 && namudarburez <= 10) {
                        stud.namudarburez.push_back(namudarburez);
                    }
                    else {
                        cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                    }
                }
                double egzaminorez;
                cout << "�veskite egzamino rezultat�: ";
                cin >> egzaminorez;
                if (egzaminorez >= 0 && egzaminorez <= 10) {
                    stud.egzaminorez = egzaminorez;
                }
                else {
                    cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                    continue;
                }

                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
            }
        }
        else if (pasirinkimas == 2) {
            while (true) {
                cout << "�veskite studento vard� ir pavard�. Nor�dami baigti �vedim�, �veskite -1: ";
                cin >> stud.vardas;
                if (stud.vardas == "-1")
                    break;
                cin >> stud.pavarde;
                cout << "Generuojami atsitiktiniai balai u� nam� darbus..." << endl;
                for (int i = 0; i < 5; ++i) {
                    stud.namudarburez.push_back(GenerateRandomGrade());
                }
                stud.egzaminorez = GenerateRandomGrade();
                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
                stud.namudarburez.clear();
            }
        }
        else if (pasirinkimas == 3) {
            cout << "Generuojami balai, vardai ir pavard�s ir student� kiekis spausdinimui" << endl;
            int studentukiekis;
            studentukiekis = rand() % 200;
            for (int i = 0; i < studentukiekis; ++i) {
                Studentas stud;
                for (int j = 0; j < 5; ++j) {
                    stud.namudarburez.push_back(GenerateRandomGrade());
                }
                stud.egzaminorez = GenerateRandomGrade();
                stud.vardas = GeneruotiVardus();
                stud.pavarde = GeneruotiPavardes();
                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
                stud.namudarburez.clear();
            }
        }
        else if (pasirinkimas == 4)
        {
            auto start_read = chrono::high_resolution_clock::now();
            cout << "Kuri faila norite atidaryti:\n1 - studentai10000.txt\n2 - studentai100000.txt\n3 - studentai1000000.txt\nPasirinkimas: ";
            int failopasirinkimas;
            cin >> failopasirinkimas;
            ifstream failas;
            switch (failopasirinkimas)
            {
            case 1:
                failas.open("studentai10000.txt");
                break;
            case 2:
                failas.open("studentai100000.txt");
                break;
            case 3:
                failas.open("studentai1000000.txt");
                break;
            default:
                NeraFailo();
                return -1;
            }
            if (!failas.is_open())
            {
                NeraFailo();
                return -1;
            }
            auto end_read = chrono::high_resolution_clock::now();
            read_time = end_read - start_read;
            auto start_process = chrono::high_resolution_clock::now();
            string line;
            getline(failas, line);
            istringstream iss(line);
            int stulpeliai = 0;
            string zodziai;
            while (iss >> zodziai)
            {
                stulpeliai++;
            }
            int namudarbai = stulpeliai - 3;
            while (failas.good())
            {
                Studentas stud;
                if (!(failas >> stud.vardas >> stud.pavarde))
                    break;
                double grade;
                for (int i = 0; i < namudarbai; i++)
                {
                    failas >> grade;
                    stud.namudarburez.push_back(grade);
                }
                failas >> stud.egzaminorez;
                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
                stud.namudarburez.clear();
            }
            auto end_process = chrono::high_resolution_clock::now();
            process_time = end_process - start_process;
            failas.close();
        }
        if (!studentai.empty())
        {
            cout << "Norite �ra�yti duomenis atspausdinant � ekran� ar � fail�?: 1 - ekran�; 2 - fail�" << endl;
            int skaicbudas;
            cin >> skaicbudas;
            cout << "Pasirinkite rikiavimo b�d�:\n1 - pagal vardus\n2 - pagal pavardes\n3 - pagal galutin� bal� (vid.)\n4 - pagal galutin� bal� (med.)\nPasirinkimas: ";
            int sorting_choice;
            cin >> sorting_choice;
            switch (sorting_choice)
            {
            case 1:
                sort(studentai.begin(), studentai.end(), vardolyginimas);
                break;
            case 2:
                sort(studentai.begin(), studentai.end(), pavardeslyginimas);
                break;
            case 3:
                sort(studentai.begin(), studentai.end(), vidurkiolyginimas);
                break;
            case 4:
                sort(studentai.begin(), studentai.end(), medianoslyginimas);
                break;
            default:
                NetinkamaIvestis();
                break;
            }
            if (skaicbudas == 1)
            {
                PrintStudents(studentai);
                break;
            }
            if (skaicbudas == 2)
            {
                auto start_writing = chrono::high_resolution_clock::now();
                ofstream failasr("kursioku_duomenys.txt");
                failasr << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
                failasr << "---------------------------------------------------------------------------------------------------" << endl;
                for (const auto& stud : studentai)
                {
                    failasr << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
                }
                cout << "�ra�ymas s�kmingas. Rezultatai i�saugoti faile kursioku_duomenys.txt" << endl;
                failasr.close();
                auto end_writing = chrono::high_resolution_clock::now();
                chrono::duration<double> writeFile_time = end_writing - start_writing;
                cout << "Skaitymas i� failo truko: " << read_time.count() << " sekundes" << endl;
                cout << "Mokini� vidurkio/medianos skai�iavimas u�truko: " << process_time.count() << " sekundes" << endl;
                cout << "�ra�ymas � fail� truko: " << writeFile_time.count() << " sekundes" << endl;
                break;
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
    }
    return 0;
}
