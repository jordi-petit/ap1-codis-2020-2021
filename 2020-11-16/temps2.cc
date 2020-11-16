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
        return 1 + f(n - 1) + f(n - 1);
    }
}

int main()
{
    for (int n = 0; n <= 34; n += 1) {
        double t1 = now();
        int r = f(n);
        double t2 = now();
        cout << n << " " << t2 - t1 << " " << r << endl;
    }
}
