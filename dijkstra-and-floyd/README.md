# Dijkstra and Floyd-Warshall Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This C++ program implements two algorithms (Dijkstra's and Floyd's) to calculate the shortest path between nodes in a directed graph, given an adjacency matrix. The program reads input from a file and outputs the results to the console.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

This program reads input from a text file containing an adjacency matrix representing a directed graph. The first line of the file should contain a single integer n representing the number of nodes in the graph. The next n lines should contain n integers each, separated by spaces, representing the weight of the directed edge from node i to node j. If there is no edge from node i to node j, the value in the matrix should be -1. Here's an example of what the input file should look like:

```
4
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0
```

In this example, there are 4 nodes in the graph and the weight of the edge from node 1 to node 2 is 2, while the edge from node 1 to node 3 does not exist.

## Output

After running the program, the user should expect to see two different outputs: the results of Dijkstra's algorithm and the results of Floyd's algorithm.

The output of Dijkstra's algorithm consists of the shortest distance from each node to all other nodes in the graph. For example:

```
Dijkstra:

Node 1 to node 2: 2
Node 1 to node 3: 4
Node 1 to node 4: 3
...
Node 4 to node 2: 5
Node 4 to node 3: 4
```

The output of Floyd's algorithm is a matrix representing the shortest distance between every pair of nodes in the graph. For example:

```
Floyd:

0 2 4 3
3 0 1 5
4 6 0 7
3 5 4 0
```
If there are any errors or warnings while running the program, the user will be prompted with an appropriate message.

## Test

To test this algorithm run compiler and then copy in terminal:
```
g++ main.cpp -o main
./main < input.txt 
```

## Functions

```
dijkstra()
```
Implements Dijkstra's algorithm to find the shortest distance between pairs of nodes in a directed graph.

```
floyd()
```
Implements Floyd's algorithm to find the shortest distance between pairs of nodes in a directed graph.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/dijkstra-and-floyd
