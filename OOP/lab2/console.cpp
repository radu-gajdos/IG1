int main() {
    double value1, value2, scale_factor;
    std::string unit1, unit2;

    std::cout << "Länge 1 eingeben (z.B. 5m): ";
    std::cin >> value1 >> unit1;
    Length len1(value1, unit1);

    std::cout << "Länge 2 eingeben (z.B. 3.7m): ";
    std::cin >> value2 >> unit2;
    Length len2(value2, unit2);

    std::cout << "Skalierungsfaktor eingeben (z.B. 2.5): ";
    std::cin >> scale_factor;

    Length sum = len1.add(len2);
    std::cout << "Länge 1 + Länge 2 = " << sum.text() << std::endl;

    Length diff = len1.subtract(len2);
    std::cout << "Länge 1 - Länge 2 = " << diff.text() << std::endl;

    Length scaled = len1.scale(scale_factor);
    std::cout << "Länge 1 skaliert mit Faktor " << scale_factor << " = " << scaled.text() << std::endl;

}