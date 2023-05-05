#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
};

// la complejidad temporal del algoritmo depende del numero de segmentos de linea "n" dados como entrada
// el algoritmo compara cada par de segmentos de linea para verificar si se cruzan. en el peor de los casos, necesitara
// comparar cada segmento de linea con otros
// la complejidad temporal del algoritmo se aproxima a O(n^2) donde n es el numero de segmentos de linea
// funcion para checar si tres puntos son colineales
bool areCollinear(const Point &p1, const Point &p2, const Point &p3)
{
    return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0;
}

// funcion para verificar si dos segmentos de linea se cruzan
bool doIntersect(const Point &p1, const Point &q1, const Point &p2, const Point &q2)
{
    // comprobar la orientacion de los segmentos de linea
    int o1 = (q1.y - p1.y) * (p2.x - q1.x) - (q1.x - p1.x) * (p2.y - q1.y);
    int o2 = (q1.y - p1.y) * (q2.x - q1.x) - (q1.x - p1.x) * (q2.y - q1.y);
    int o3 = (q2.y - p2.y) * (p1.x - q2.x) - (q2.x - p2.x) * (p1.y - q2.y);
    int o4 = (q2.y - p2.y) * (q1.x - q2.x) - (q2.x - p2.x) * (q1.y - q2.y);

    // comprobar si los segmentos se cruzan
    if ((o1 * o2 < 0) && (o3 * o4 < 0))
        return true;

    // verificar casos de cuando los segmentos de linea comparten puntos finales
    if ((o1 == 0) && areCollinear(p1, q1, p2))
        return true;
    if ((o2 == 0) && areCollinear(p1, q1, q2))
        return true;
    if ((o3 == 0) && areCollinear(p2, q2, p1))
        return true;
    if ((o4 == 0) && areCollinear(p2, q2, q1))
        return true;

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<bool> results(n / 4); // crear un vector 

    for (int i = 0; i < n / 4; i++)
    {
        Point p1, q1, p2, q2;
        std::cin >> p1.x >> p1.y >> q1.x >> q1.y >> p2.x >> p2.y >> q2.x >> q2.y;
        bool intersect = doIntersect(p1, q1, p2, q2);
        results[i] = intersect; 
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << (results[i] ? "true" : "false") << std::endl;
    }

    return 0;
}
