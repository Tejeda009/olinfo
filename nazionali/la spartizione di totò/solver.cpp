#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int g, p, ris = 0, last = 1, complici;

    in >> g;
    in >> p;

    complici = p - 1;

    while(g > 0) {
        if ( (g - last) >= 0) {
            ris+=last;
            g-=last;
            g-=complici;
            last += 1;
        }
        else {
            ris+=g;
            g = 0;
        }
    }

    out << ris;

    return 0;
}