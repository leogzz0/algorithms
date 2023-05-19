#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
// complejidad: O(n log n)
// ordena los puntos de acuerdo con sus coordenadas x: esto se hace una vez y toma O(n log n) tiempo
// dividir los puntos en dos mitades hace que cada paso de la recursion tome O(n) tiempo
// eencontrar los puntos mas cercanos que crucen la linea divisoria hace que tome O(n)
struct Point
{
    int x, y;
};

bool compareX(Point p1, Point p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

bool compareY(Point p1, Point p2)
{
    return p1.y < p2.y;
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float roundDist(Point p1, Point p2)
{
    return round(dist(p1, p2));
}

pair<Point, Point> bruteForce(vector<Point> points, int n, float &min)
{
    float min_val = min;
    Point p1, p2;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (roundDist(points[i], points[j]) < min_val)
            {
                min_val = roundDist(points[i], points[j]);
                p1 = points[i];
                p2 = points[j];
            }
    min = min_val;
    return {p1, p2};
}

pair<Point, Point> stripClosest(vector<Point> strip, int size, float d)
{
    float min = d;
    Point p1, p2;

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (roundDist(strip[i], strip[j]) < min)
            {
                min = roundDist(strip[i], strip[j]);
                p1 = strip[i];
                p2 = strip[j];
            }
    return {p1, p2};
}

pair<Point, Point> closestUtil(vector<Point> points, int n)
{
    if (n <= 3)
    {
        float min = FLT_MAX;
        return bruteForce(points, n, min);
    }

    int mid = n / 2;
    Point midPoint = points[mid];

    pair<Point, Point> dl = closestUtil(vector<Point>(points.begin(), points.begin() + mid), mid);
    pair<Point, Point> dr = closestUtil(vector<Point>(points.begin() + mid, points.end()), n - mid);

    float d = min(roundDist(dl.first, dl.second), roundDist(dr.first, dr.second));

    vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(points[i].x - midPoint.x) < d)
            strip.push_back(points[i]);

    pair<Point, Point> strip_pair = stripClosest(strip, strip.size(), d);
    float strip_dist = roundDist(strip_pair.first, strip_pair.second);

    if (strip_dist < d)
        return strip_pair;

    if (roundDist(dl.first, dl.second) < roundDist(dr.first, dr.second))
        return dl;
    else
        return dr;
}

pair<Point, Point> closest(vector<Point> points, int n)
{
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, n);
}

int main()
{
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x;
        cin >> points[i].y;
    }

    pair<Point, Point> result = closest(points, n);

    cout << roundDist(result.first, result.second) << "\n";
    cout << result.first.x << " " << result.first.y << "\n";
    cout << result.second.x << " " << result.second.y << "\n";

    return 0;
}
