/*
algoritmos avanzados
actividad 3.6
algoritmo graph coloring
nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 27/04/2023
*/

#include <iostream>
#include <vector>

bool isSafe(int node, int color, const std::vector<std::vector<int> > &graph, const std::vector<int> &colorAssignment)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[node][i] && colorAssignment[i] == color)
        {
            return false;
        }
    }
    return true;
}

// la funcion se llama recursivamente para cada nodo del grafo y en cada llamada recursiva
// se realizan bucles para probar todos los colores posibles. esto implica que el numero de llamadas
// recursivas y bucles aumenta exponencialmente con respecot al tamaño del grafo y el numero de colores posibles
// en terminos de notacion big O, podemos decir que la comlejidad del algoritmo es O(x^n) donde x es el
// numero maximo de colores posibles y N el numero de nodos en el grafo. Eso significa que el tiempo de ejecucion
// aumenta exponencialmente a medida que se incrementa el numero de nodos o colores posibles
bool graphColoringUtil(int node, int numColors, const std::vector<std::vector<int> > &graph, std::vector<int> &colorAssignment)
{
    if (node == graph.size())
    {
        return true; // a todos los nodos se le han agregado colores
    }

    for (int color = 0; color < numColors; ++color)
    {
        if (isSafe(node, color, graph, colorAssignment))
        {
            colorAssignment[node] = color;

            if (graphColoringUtil(node + 1, numColors, graph, colorAssignment))
            {
                return true;
            }

            colorAssignment[node] = -1; // retrocede y prueba con otro color
        }
    }

    return false; // no hay color
}

void graphColoring(const std::vector<std::vector<int> > &graph)
{
    int numNodes = graph.size();
    std::vector<int> colorAssignment(numNodes, -1); // inicializa la asignacion de colora -1

    int numColors = 0;
    while (true)
    {
        if (graphColoringUtil(0, numColors, graph, colorAssignment))
        {
            break; // color valido
        }
        ++numColors; // intenta con otro color adicional
    }

    // imprimir el color
    for (int node = 0; node < numNodes; ++node)
    {
        std::cout << "Node: " << node << ", Assigned Color: " << colorAssignment[node] << std::endl;
    }
}

int main()
{
    int numNodes;
    std::cin >> numNodes;

    std::vector<std::vector<int> > graph(numNodes, std::vector<int>(numNodes));

    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    graphColoring(graph);

    return 0;
}
