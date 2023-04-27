/*
algoritmos avanzados
actividad 3.4
algoritmo kruskal MST
nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 17/04/2023
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;

struct Edge
{
    int u, v, w; // u y v son los indices de los dos vertices conectados por la arista y w es el peso
    bool operator<(const Edge &other) const
    {
        return w < other.w; // comparar bordes en funcion de sus pesos
    }
};

int parent[MAXN], n;
vector<Edge> edges;

void make_set(int v)
{
    // establecer el padre del vertice v a si mismo
    parent[v] = v;
}

int find_set(int v)
{
    // si el padre de v es el mismo regresar el valor
    if (parent[v] == v)
        return v;
        // sino llamada recursiva a find_set en el padre de v y que actualice el padre raiz
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    // encontrar el representante (raiz) del conjunto al que pertenece
    a = find_set(a);
    b = find_set(b);
    // si ya estan en el mismo set no hacer nada
    if (a != b)
        parent[b] = a;
}

// la complejidad temporal del algoritmo de kruskal es O(m log m) donde m es el numero de aristas en el grafico.
// esto se debe a que el algoritmo requiere clasificar los bordes lo que requiere un tiempo de O(m log m) 
// utilizando un algoritmo de clasificacion estandar. las operacions de busqueda de union, que toman un tiempo O(log n)
// en el peor de los casos se llaman como maximo 2m veces en el algoritmo. Por lo que la complejidad temporal total del 
// algoritmo Kruskal esta dominada por la operacion de calsificacion, que es O(m log m)
void kruskal()
{
    sort(edges.begin(), edges.end()); // ordenar los bordes en orden creciente de pesos
    int mst_cost = 0; // inicializar el costo toal de mst para que sea cero
    vector<int> mst_weights; // inicializar un vector para almacenar los pesos de los bordes mst

    // iterar a traves de todos los bordes en el orden ordenado
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w; // obtener los punots finales y el peso del borde actual
        if (find_set(u) != find_set(v))
        {
            mst_cost += w; // agregar el peso del borde actual al costo total de mst
            mst_weights.push_back(w); // agregar el peso del borde actual al vector del peso de borde mst
            union_sets(u, v); // unir los conjuntos que contienen los puntos finales de la arista actual
        }
    }

    // iterar a traves de los pesos de borde e imprimirlos
    for (int i = 0; i < mst_weights.size(); i++)
    {
        cout << mst_weights[i] << endl;
    }
    int max_mst_edge = *max_element(mst_weights.begin(), mst_weights.end()); // obtener el peso maximo de un borde en la mst
    cout << mst_cost << endl; // costo final
}

int main()
{
    // numero de nodos
    cin >> n;

    // leer matriz de adyacencia y crear bordes a partir de ella
    int adj_matrix[MAXN][MAXN];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj_matrix[i][j];
            if (adj_matrix[i][j] != -1)
            {
                Edge e = {i, j, adj_matrix[i][j]};
                edges.push_back(e);
            }
        }
    }

    // inicializar la matriz principal para la estructura de datos de conjuntos disjunto
    for (int i = 0; i < n; i++)
    {
        make_set(i);
    }
    kruskal();
    return 0;
}
