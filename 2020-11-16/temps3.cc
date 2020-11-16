// proves de mesures de temps

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

int f(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return 1 + f(n / 2);
    }
}

int main()
{
    const int reps = 25000000;
    for (int n = 0; n <= 2000000000; n += 20000000) {
        int r = 0;
        double t1 = now();
        for (int k = 0; k < reps; ++k) {
            r += f(n);
        }
        double t2 = now();
        cout << n << " " << (t2 - t1) / reps << " " << r << endl;
    }
}
