#include <iostream>
#include <cmath>

using namespace std;

const double Q = pow(10, -9); //hardcode constant for formula Q
const double Ke = 9 * pow(10, 9) / pow(Q, 2); //hardcode constant for formula Ke

double Efield(double r, double a = 50) { //a = 50 is default value
    double E = 0;
    if (r < a) {
        E = Ke * Q * (r / pow(a, 3));
    }
    else if (r >= a) {
        E = (Ke * Q) / pow(r, 2);
    }
    return E;
}

int main()
{
    double rmin = 0;
    double rmax = 100;
    int n = static_cast<int>(rmax) - static_cast<int>(rmin) + 1;
    double r[n], E[n]; //arrays for r, E - type double
    double a;
    int i;

    cout << "Enter the radius of sphere in m: " << endl;
    cin >> a;

    cout << "Total Charge in Sphere, Q = " << Q << endl;
    cout << "Radius of Sphere, a = " << a << " m" << endl;
    cout << endl;
    cout << "r, m        E, N/C" << endl;

    for (i = 0; i < 101; ++i)
    {
        r[i] = i;
        E[i] = Efield(r[i], a);
    if ( i < 10)
      cout << i << "      " << E[i] << endl;
    else if ( i < 100)
      cout << i << "      " << E[i] << endl;
    else
      cout << i << "      " << E[i] << endl;

    }

    return 0;

}
