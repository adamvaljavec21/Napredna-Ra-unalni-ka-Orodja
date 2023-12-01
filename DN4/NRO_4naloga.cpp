#include <iostream>
#include <fstream>
#include <vector>

// Funkcija za centralno diferenco
double CentralnaShema(const std::vector<double>& x, const std::vector<double>& fx, int index, double dx) {
    return (fx[index + 1] - fx[index - 1]) / (2 * dx);
}

// Funkcija za diferenco naprej
double ShemaNaprej(const std::vector<double>& x, const std::vector<double>& fx, int index, double dx) {
    return (-3 * fx[index] + 4 * fx[index + 1] - fx[index + 2]) / (2 * dx);
}

// Funkcija za diferenco nazaj
double ShemaNazaj(const std::vector<double>& x, const std::vector<double>& fx, int index, double dx) {
    return (3 * fx[index] - 4 * fx[index - 1] + fx[index - 2]) / (2 * dx);
}

int main() {
    // Odpremo datoteko "poly.txt" za branje
    std::ifstream datotekaPoly("poly.txt");

    // Odpremo datoteko "diff_poly.txt" 
    std::ofstream datotekaDiffPoly("diff_poly.txt");

    // Preberemo število vrednosti iz prve vrstice datoteke
    int steviloVrednosti;
    datotekaPoly >> steviloVrednosti;

    // Ustvarimo vektorja za shranjevanje vrednosti x in f(x)
    std::vector<double> vrednostiX;
    std::vector<double> vrednostiFx;

    // Shranjevanje v vektor
    for (int i = 0; i < steviloVrednosti; ++i) {
        int id;
        double x, fx;
        char locilo;

        datotekaPoly >> id >> locilo >> x >> fx;

        vrednostiX.push_back(x);
        vrednostiFx.push_back(fx);
    }

    // Zapremo vhodno datoteko
    datotekaPoly.close();

    // Izračunamo korak dx med sosednjimi vrednostmi x
    double dx = vrednostiX[1] - vrednostiX[0];

    // Izračunamo odvode in zapisujemo rezultate v izhodno datoteko
    for (int i = 0; i < steviloVrednosti; ++i) {
        double odvod;

        // Za prvo vrednost
        if (i == 0) {
            odvod = ShemaNaprej(vrednostiX, vrednostiFx, i, dx);
        }
        // Za zadnjo vrednost
        else if (i == steviloVrednosti - 1) {
            odvod = ShemaNazaj(vrednostiX, vrednostiFx, i, dx);
        }
        // Za notranje vrednosti
        else {
            odvod = CentralnaShema(vrednostiX, vrednostiFx, i, dx);
        }

        // Zapišemo odvode v datoteko
        datotekaDiffPoly << odvod << std::endl;
    }

    // Zapremo izhodno datoteko
    datotekaDiffPoly.close();

   

    return 0;
}
