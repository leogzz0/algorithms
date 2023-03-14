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

The program consists of a single function that reads the input file, calculates the checksums for each column, and outputs the result to the console.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/hash-string
