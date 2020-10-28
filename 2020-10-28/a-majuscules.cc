// acció que converteix les lletres minúscules d'un text a majúscules

#include <iostream>
#include <string>
using namespace std;

void a_majuscules1(string& s)
{
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= 'a' and c <= 'z') {
            s[i] = c - 'a' + 'A';
        }
    }
}

void a_majuscules(string& s)
{
    for (char& c : s) {
        if (c >= 'a' and c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
}

int main()
{
    string s;
    cin >> s;
    a_majuscules(s);
    cout << s << endl;
}
