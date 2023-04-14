# Knapsack in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

program takes as input the number of possible items available, followed by N integers representing the value of each of those elements, followed by N integers representing the weights associated with each element, and finally an integer W, which represents the maximum weight or capacity of the backpack.

The output of the program is the maximum possible value or profit that can be obtained by selecting a subset of the available items such that their total weight does not exceed W.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

The program takes as input the number of possible items available, which should be an integer N (1 <= N <= 100), followed by N integers representing the value of each item, which should be non-negative integers (0 <= value_i <= 1000). Next, the program expects N integers representing the weights associated with each item, which should also be non-negative integers (0 <= weight_i <= 1000). Finally, the program requires an integer W (1 <= W <= 1000), which represents the maximum weight or capacity of the backpack. The input values should be entered one at a time, separated by a space or a new line, and should be entered in the order specified above. The program will prompt the user to enter each value in turn.

```
3
1
2
3
4
5
1
4
3
```

## Output

The output of the program is a single integer representing the maximum possible value or profit that can be obtained by selecting a subset of the available items such that their total weight does not exceed W. The program outputs this value to the console. If no valid subset of items can be found that meets the weight constraint, the program will output 0. Note that the program assumes that the input values are valid and does not perform any error checking or input validation. If invalid input values are provided, the program may produce unexpected output or behavior.

```
3
```

## Test

To test this algorithm run compiler and then copy in terminal:
```
g++ main.cpp -o main
./main < input1.txt 
```

## Functions

```
mochDP()
```
The mochDP function takes as input a vector of obj structs representing the available items, along with an integer PESO representing the maximum weight or capacity of the backpack. The function returns an integer representing the maximum possible value or profit that can be obtained by selecting a subset of the available items such that their total weight does not exceed PESO.

The function implements the knapsack problem using dynamic programming. Specifically, it initializes a two-dimensional array mat of size (N+1) x (PESO+1) and fills it in using a nested loop. The outer loop iterates over the items, while the inner loop iterates over the possible backpack weights. For each combination of item and backpack weight, the function computes the maximum possible value that can be obtained using the items considered so far and the available backpack weight. This maximum value is stored in the corresponding cell of the mat array.

Once the array is fully filled in, the maximum possible value that can be obtained is the value in the last cell of the array (mat[N][PESO]). The function returns this value as the result. Note that the time complexity of the function is O(N*PESO), where N is the number of available items and PESO is the maximum backpack weight.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/knapsack
