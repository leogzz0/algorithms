/*
algoritmos avanzados
actividad 3.3
algoritmo knapsack
nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 13/04/2023
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct obj
{
    int valor, peso;
};

// la complejidad del algoritmo implementado es de O(N*PESO) donde N es el numero de objetos y PESO 
// es la capacidad maxima de la mochila. Esto es gracias a que la matriz es de tamaño (N+1)*(PESO+1) 
// para almacenar los resutlados
// en el pero de los casos es cuando N y PESO son muy grandes. es donde este algoritmo se vuelve obsoleto
int mochDP(vector<obj> &datos, int PESO)
{
    int N = datos.size(); // obtiene el numero de objetos disponibles
    int mat[N + 1][PESO + 1]; // crea una matriz para almacenar los resultados
    for (int i = 0; i <= N; i++)
    {
        mat[i][0] = 0; // inicializa la primera columna de la matriz como ceros
    }
    for (int j = 0; j <= PESO; j++)
    {
        mat[0][j] = 0; // inicializa la primera fila de la matriz como ceros
    }
    // iteracion en los objetos
    for (int i = 1; i <= N; i++) 
    {
        // para cada posible peso de la mochila
        for (int j = 1; j <= PESO; j++)
        {
            if (datos[i - 1].peso > j) // si el peso del objeto es mayor que el peso actual
            {
                mat[i][j] = mat[i - 1][j]; // copia el resultado del subproblema anterior
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], datos[i - 1].valor + mat[i - 1][j - datos[i - 1].peso]); 
            }
        }
    }
    return mat[N][PESO]; // devuelve el valor maximo posible que se puede obtener
}

int main()
{
    // constructor
    int N, PESO;
    cin >> N;
    vector<obj> datos(N);
    for (int i = 0; i < N; i++)
    {
        cin >> datos[i].valor;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> datos[i].peso;
    }
    cin >> PESO;
    cout << mochDP(datos, PESO) << endl;
    return 0;
}
