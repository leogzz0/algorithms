# Hash String Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This program takes an input text file and an integer value n as command line arguments, and generates a hexadecimal checksum of the file contents.

The program reads the contents of the input file into a string, and then pads the string with zeros at the end if necessary so that its length is a multiple of n. The program then calculates the checksum of each column of the input file, where each column is defined as a vertical slice of n characters.

The checksum for each column is calculated by summing the ASCII values of all the characters in the column, taking the sum modulo 256, and converting the resulting value to a hexadecimal string. The program concatenates these hexadecimal checksums into a single string and outputs the result to the console.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

The program expects two command line arguments: the name of the input text file and an integer value n, where n is an integer multiple of 4 and 16 <= n <= 64. The input text file can contain any ASCII characters, including line breaks and spaces.

## Output

The program outputs a string of length 2n that is a hexadecimal representation of the checksums for each column of the input file.

## Test

The program outputs a string of length 2n that is a hexadecimal representation of the checksums for each column of the input file.

To test this algorithm run compiler and then copy in terminal:
```
./main case-1.txt 16
./main case-2.txt 64
./main case-3.txt 24
```

example of output:
```
E4D1F2BA0F997A03C79D690C88C25428
68690A686F772061726520796F753F0A66696E65207468616E6B20796F7520616E6420796F753F0A696D2066696E650A30303030303030303030303030303030
248F4783B645015C7BDF8FE605B7B02169C40840F6F32595
```

## Functions

The LCS (longest common substring) function implemented in this program takes two input strings, S1 and S2, and returns the length of their longest common substring. The function uses a dynamic programming approach to solve the problem, where a 2D array (LCS) is used to store the lengths of the longest common substrings at each index. The function initializes LCS[0][j] and LCS[i][0] to 0 or 1, depending on whether S1[i] or S2[j] is equal to the first character of the other string. Then, the function iterates through the remaining indices of the array, updating LCS[i][j] according to the LCS algorithm. The function returns the maximum value in the array, which corresponds to the length of the longest common substring.

To use the function, simply call it with the two input strings as arguments. The function assumes that the input strings are non-empty and contain only ASCII characters. If either input string is empty, the function will return 0. The function returns an integer, which represents the length of the longest common substring.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/lcs
