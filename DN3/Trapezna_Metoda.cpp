#include <iostream>
#include <cmath>

double izracunajArktan(double x, int clenov) {
    double rezultat = 0.0;
    for (int n = 0; n < clenov; ++n) {
        // Izračun posameznega člena v razvoju Taylorjeve vrste za arktan
        rezultat += pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
    }
    return rezultat;
}

double izracunajIntegral(double x) {
    // Izračun vrednosti integranda e^(3x) * arktan(x^2)
    return exp(3 * x) * izracunajArktan(x / 2.0, 20);
}

double trapeznaMetoda(double a, double b, int n) {
    double h = (b - a) / n;
    // Približek integrala po trapezni metodi
    double rezultat = 0.5 * (izracunajIntegral(a) + izracunajIntegral(b));

    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        // Dodajanje prispevka vsakega podintervala k integralu
        rezultat += izracunajIntegral(x_i);
    }

    return h * rezultat;
}

int main() {
    double spodnjaMeja = 0.0;
    double zgornjaMeja = M_PI / 4.0;
    int steviloIntervalov = 1000;

    // Izračun približne vrednosti integrala s trapezno metodo
    double priblizekIntegrala = trapeznaMetoda(spodnjaMeja, zgornjaMeja, steviloIntervalov);

    std::cout << "Približna vrednost integrala: " << priblizekIntegrala << std::endl;

    return 0;
}
