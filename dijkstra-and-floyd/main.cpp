/*
algoritmos avanzados
actividad 3.1
algoritmo dijkstra y floyd
nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 01/03/2023
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;

const int INF = 1e9;

// la complejidad del algoritmo dijkstra depende de la estructura de datos implementada
// en esta version usamos el priority_queue para guardar nodos visitados los cuales estan ordenados por distancia
// cada nodo se agrega al priority_queue al menos una vez y cada vez que se extraen con la menor distancia
// lo que toma O(log n)
// tambien checamos la distancia con nuestro vecino y actualizamos si hay un camino mas corto lo cual toma
// O(m log n) por lo que en general la complejidad del algoritmo Dijkstra en esta implementacion
// es de O((n+m) log n) donde n es el numero de nodos y m el numero de bordes en el grafo
void dijkstra(vector<vector<int> > &adj, int n, int s, vector<int> &dist)
{
    // inicializamos la distancia del vector con valores infinitos a excepcion del primer nodo
    dist.assign(n, INF);
    dist[s] = 0;

    // priorizamos el queue para almacenar los nodos a visitar, ordenados por distancia
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // agregamos el nodo inicial al queue
    pq.push(std::make_pair(0, s));

    // procesaremos los nodos del priority_queue hasta que este vacio
    while (!pq.empty())
    {
        // obtener el nodo con la distancia mas corta
        int u = pq.top().second;
        pq.pop();

        // por cada vecinos "v" del nodo "u", actualizar su distancia si se encuentra un camino mas corto
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != -1 && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
}

// la complejidad del algoritmo de floyd es O(n^3), donde n es el numero de vertices del grafo
// Esto se debe a que el algoritmo involucra tres bucles anidados, cada uno de los cuales va de o a n-1 
// lo que da una complejidad de tiempo total de O(n^3)
// Esto hace que el algoritmo de floyd sea menos eficiente que el de dijkstra para encontrar el camino mas corto
// pero tiene la ventaja de poder encontrar el camino masc orto entre todos los pares de vertices en una sola ejecucion
void floyd(vector<vector<int> > &adj, int n, vector<vector<int> > &dist)
{
    // inicializar la matriz de distancia con los mismos valores que la matriz de adyacencia
    dist.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != -1)
            {
                dist[i][j] = adj[i][j];
            }
        }
    }

    // se realiza el algoritmo de programacion dinamica
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // si hay un camino mas corto de i a j por k, actualizar la distancia
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    vector<vector<int> > adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> adj[i][j];
        }
    }
    in.close();
    vector<vector<int> > dist_floyd;
    floyd(adj, n, dist_floyd);
    cout << "Floyd :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist_floyd[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> dist_dijkstra;
        dijkstra(adj, n, i, dist_dijkstra);
        cout << "Dijkstra from node " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "node " << i + 1 << " to node " << j + 1 << " : " << dist_dijkstra[j] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}


