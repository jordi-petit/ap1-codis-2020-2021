// Jan S
// P33147

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Rectangle {
    int amplada, alcada, area, perimetre;
};

using Rectangles = vector<Rectangle>;

Rectangle llegir_rectangle()
{
    Rectangle rectangle;
    cin >> rectangle.amplada >> rectangle.alcada;
    rectangle.area = rectangle.amplada * rectangle.alcada;
    rectangle.perimetre = 2 * rectangle.amplada + 2 * rectangle.alcada;
    return rectangle;
}

Rectangles llegir_rectangles(int n) //per cada posicio i llegeix el rectangle i
{
    Rectangles rectangles(n);
    for (int i = 0; i < n; ++i)
        rectangles[i] = llegir_rectangle();
    return rectangles;
}

bool comparador_rectangles(const Rectangle& x, const Rectangle& y)
{
    if (x.area != y.area) // Ordenacio creixent
        return x.area < y.area;
    if (x.perimetre != y.perimetre) // Ordenacio decreixent
        return x.perimetre > y.perimetre;
    return x.amplada < y.amplada; // Ordenacio creixent
}

void ordenar_rectangles(Rectangles& rectangles) //ordenem amb la funcio sort del paquet algorithm
{
    sort(rectangles.begin(), rectangles.end(), comparador_rectangles);
}

void escriure_rectangle(const Rectangle& rectangle)
{
    cout << rectangle.amplada << " " << rectangle.alcada << endl;
}

void escriure_rectangles(const Rectangles& rectangles)
{
    int n = rectangles.size();
    for (int i = 0; i < n; ++i)
        escriure_rectangle(rectangles[i]);
}
int main()
{
    int n;
    while (cin >> n) { //bucle que para quan ja no vulguem ordenar mes rectangles
        Rectangles rectangles = llegir_rectangles(n); //fem un vector de n rectangles
        ordenar_rectangles(rectangles); //ordenem el vector segons les condicions
        escriure_rectangles(rectangles); //escrivim el vector ordenat
        cout << "----------" << endl;
    }
}
