#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <windows.h>
using namespace std;

double s(const double x);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double tp, tk, z;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n  = "; cin >> n;

    double dt = (tk - tp) / n;

    double t = tp;
    cout << "\n|------------------------------------------|" << endl;
    cout << "|      t       |      Значення виразу      |"<< endl;
    cout << "--------------------------------------------" << endl;
    cout << fixed << setprecision(5);
    while (t <= tk)
    {
        z = s(2*t+1)+2*s(t*t)+sqrt(s(1));
        cout << "| " << setw(12) << t << " | " << setw(26) << z << "|" << endl;
        t += dt;
    }
    cout << "|--------------|---------------------------|" << endl;
    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1 && x==0)
        return (pow(cos(x),2)+1)/exp(x);
    else
    {
        double Sum = 0;
        int k = 0;
        double a = 2*x;
        Sum = a;
        for (k = 1;k <= 4;k++) {
            double R = (4 * x * x) / (4 * k * k + 2 * k);
            a *= R;
            Sum += a;
        }
        double LastSum = 1 / sin(2 * x) * Sum;
        return LastSum;
    }
}