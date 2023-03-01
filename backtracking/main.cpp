/*
algoritmos avanzados

actividad 1.3
algoritmo backtracking

nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 01/03/2023
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

int maze[MAX][MAX]; // el laberinto como una matriz
bool visited[MAX][MAX]; // la matriz que guardara la solucion
int m, n; // el tamaño del laberinto

// funcion que verificara si la casilla es valida
bool isValid(int i, int j) {
    return i >= 0 && i< n && j>= 0 && j< m;
}

// funcnion que buscara resolver el laberinto 
bool solveMaze(int i, int j) {
    // si llegamos a la casilla de salida, la solcuion ha sido encontrada
    if (i == m - 1 && j == n - 1) {
        visited[i][j] = true;
        return true;
    }

    // si la casilla es valida y no ha sido visitada
    if(isValid(i, j) && maze[i][j] == 1 && !visited[i][j]){
        // la marcamos como visitada
        visited[i][j] = true;
        //buscamos una solucion con recursividad en las casillas de alrededor
        if (solveMaze(i + 1, j) || solveMaze(i, j + 1) || solveMaze(i - 1, j) || solveMaze(i, j - 1)) {
            return true;
        }   
        visited[i][j] = false;
    }
    // no se encuentra ninguna solucion
    return false;
}

int main() {
    // leemos el laberinto
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    // inicializacion de la matriz "visited"
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }
    // llamada a la funcion empezando desde (0,0)
    if (solveMaze(0, 0)) {
        // si hay solucion se imprime
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No hay solucion." << endl;
    }
    return 0;
}

/*
 *  
 *     ("`-''-/").___..--''"`-._
 *      `6_ 6  )   `-.  (     ).`-.__.`)
 *      (_Y_.)'  ._   )  `._ `. ``-..-'
 *    _..`--'_..-_/  /--'_.' ,'
 *   (il),-''  (li),'  ((!.-'      @leogzz0
 *      
*/