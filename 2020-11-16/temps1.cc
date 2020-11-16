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
    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s += j;
        }
    }
    return s;
}

int main()
{
    for (int n = 0; n <= 150000; n += 10000) {
        double t1 = now();
        int r = f(n);
        double t2 = now();
        cout << n << " " << t2 - t1 << " " << r << endl;
    }
}
