/* 
algoritmos avanzados

actividad 1.1 
merge sort usando divide y venceras 

nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 20/02/2023
*/

#include <iostream>
#include <vector>
using namespace std;

// funcion de separacion de vectores
void merge(vector<double> &arr, int left, int mid, int right) {
    // tamaño de los subarreglos
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // vectores en los que se almacenan los subarreglos
    vector<double> L(n1), R(n2);

    // se añaden los elementos en los vectores correspondientes
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // mezcla los vectores para el resultado final
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // agregar elementos restantes del arreglo izquierdo y derecho
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// funcion merge sort con tecnica "dividir y conquistar" 
void mergeSort(vector<double> &arr, int left, int right) {
    if (left < right) {
        //calcular el indice del medio(mid)
        int mid = left + (right - left) / 2;

        // recursividad para orderan los elementos
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // mezclar los subarreglos ya ordenados en uno solo
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    // vector de entrada
    vector<double> arr(n);

    // imprimir titulo
    cout << "Merge Sort (dividir y conquistar): \n\n";

    // leer entrada
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // llamada a la funcion merge sort
    mergeSort(arr, 0, n - 1);

    // imprimir vector ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n\n";
    }
    cout << endl;

    return 0;
}