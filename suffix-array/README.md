# Suffix Array Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This C++ program reads one or more input strings from standard input and calculates all possible substrings for each input string. The program then sorts the resulting substrings in alphabetical order and displays them on the console.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

The program reads input from standard input. Each line of input represents a string for which all substrings should be calculated.

## Output

The program displays the calculated substrings in alphabetical order on the console.

## Test

The program outputs a string of length 2n that is a hexadecimal representation of the checksums for each column of the input file.

To test this algorithm run compiler and then copy in terminal:
```
./main < case-2.txt 
```

example of output:
```
a
ar
ard
ardo
d
do
e
eo
eon
eona
eonar
eonard
eonardo
l
le
leo
leon
leona
leonar
leonard
leonardo
n
na
nar
nard
nardo
o
o
on
ona
onar
onard
onardo
r
rd
rdo
```

## Functions

```
vector<string> getSubstrings(string str)
```
Returns a vector containing all substrings of the given string str.

```
int main()
```
Reads input from standard input, calculates all substrings for each input string using the getSubstrings function, sorts the resulting vector of substrings in alphabetical order, and displays the sorted substrings on the console.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/suffix-array
