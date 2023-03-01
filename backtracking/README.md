# Backtracking Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

The program takes as input a maze represented as a binary matrix, where 1 represents a path and 0 represents a wall. The task is to find a path from the starting position (0,0) to the ending position (N-1,M-1) in the maze. The program uses the backtracking technique to solve the maze.

The algorithm works as follows:

- Check if the current position is the ending position. If it is, mark it as visited and return true.
- Check if the current position is valid (within the maze bounds), it is a path (not a wall), and it has not been visited before. If all of these conditions are met, mark the current position as visited and recursively check the adjacent positions (up, down, left, and right).
- If any of the adjacent positions leads to a solution, return true.
- If none of the adjacent positions lead to a solution, mark the current position as unvisited and return false.
- The main function reads the maze from standard input, initializes the visited matrix, and calls the solveMaze function starting at position (0,0). If a solution is found, the visited matrix is printed. If no solution is found, a message indicating that there is no solution is printed.

The program has a time complexity of O(2^(N+M)), where N and M are the dimensions of the maze. In the worst case, the program must check every possible path through the maze.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

The program takes as input a maze represented as a binary matrix. The first line of input contains two integers, M and N, separated by a space, which represent the dimensions of the maze. The following M lines contain N integers each, separated by a space, representing the maze. A 1 represents a path, and a 0 represents a wall.

## Output

The output of the program is a binary matrix representing the solution path through the maze. A 1 in the matrix represents a step in the path, and a 0 represents a non-path position.

## Test

To test this algorithm run compiler and then copy in terminal:
```
./main < caso-1.txt
```

## Functions

The program consists of two functions:

bool solveMaze(int maze[N][M], int visited[N][M], int x, int y);

This function takes as input the maze matrix, a visited matrix to keep track of visited positions, and the current position (x,y) in the maze. The function returns true if a path from the current position to the end of the maze is found, and false otherwise. The function uses the backtracking technique to recursively explore paths in the maze.

int main();

This function reads the input matrix from standard input, initializes the visited matrix, and calls the solveMaze function starting at position (0,0). If a solution is found, the visited matrix is printed. If no solution is found, a message indicating that there is no solution is printed.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/merge-sort
