# LCS Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This C++ program implements the LCS (longest common substring) algorithm to find the longest common substring of two input strings, S1 and S2. The program uses a dynamic programming approach to solve the problem, where a 2D array (LCS) is used to store the lengths of the longest common substrings at each index. The program initializes LCS[0][j] and LCS[i][0] to 0 or 1, depending on whether S1[i] or S2[j] is equal to the first character of the other string. Then, the program iterates through the remaining indices of the array, updating LCS[i][j] according to the LCS algorithm. The program returns the maximum value in the array, which corresponds to the length of the longest common substring.

The program defines the two input strings, S1 and S2, in the code, but they can be modified to test different input values. The main function is currently empty, so the program needs to be called with appropriate input values in order to execute.

Overall, this program provides a useful implementation of the LCS algorithm in C++, which can be used to find the longest common substring of any two strings.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

S1 and S2

## Output

The program outputs the result of the lcs. In this case is 'yupa'

## Test

To test this algorithm run compiler and then copy in terminal:
```
g++ main.cpp -o main
./main
```

example of output:
```
yupa
```

## Functions

The LCS (longest common substring) function implemented in this program takes two input strings, S1 and S2, and returns the length of their longest common substring. The function uses a dynamic programming approach to solve the problem, where a 2D array (LCS) is used to store the lengths of the longest common substrings at each index. The function initializes LCS[0][j] and LCS[i][0] to 0 or 1, depending on whether S1[i] or S2[j] is equal to the first character of the other string. Then, the function iterates through the remaining indices of the array, updating LCS[i][j] according to the LCS algorithm. The function returns the maximum value in the array, which corresponds to the length of the longest common substring.

To use the function, simply call it with the two input strings as arguments. The function assumes that the input strings are non-empty and contain only ASCII characters. If either input string is empty, the function will return 0. The function returns an integer, which represents the length of the longest common substring.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/hash-string
