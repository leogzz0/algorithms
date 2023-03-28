# Trie Algorithm in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

The code implements the Trie (digital tree) data structure in C++. The program receives a number N followed by N words to insert into the Trie. Then you receive a number M followed by M words to search for in the Trie. Finally, the DFS path of the Trie is shown and for each searched word it is indicated if it is present in the Trie or not.

The TrieNode class represents a node of the Trie, which contains an array of pointers to child nodes for each letter of the alphabet. Each node has a boolean variable indicating whether it is the end of a word.

The Trie class represents the complete structure of the Trie, which contains a pointer to the root node and has methods for inserting and searching for words in the Trie, as well as for printing the DFS traversal of the Trie.

The program uses the namespace std and the MAX_CHAR constant to define the number of letters in the alphabet, which in this case is 26 for the English alphabet.

## Table of Contents 

- [Input](#input)

- [Output](#output)

- [License](#license)

- [Test](#test)

- [Functions](#functions)

- [Questions](#questions)

## Input

The input file format should be as follows:

- First line: an integer N, the number of words to be inserted into the Trie
- N lines: N words to be inserted into the Trie
- Next line: an integer M, the number of words to search for in the Trie
- M lines: M words to search for in the Trie

(Three examples are in this repository)

## Output

The output of the program will be:

- The DFS traversal of the Trie
- M Boolean values indicating whether each of the M words was found in the Trie or not.

## Test

The program outputs a string of length 2n that is a hexadecimal representation of the checksums for each column of the input file.

To test this algorithm run compiler and then copy in terminal:
```
g++ main.cpp -o main
./main < in.txt 
```

example of output:
```
Recorrido DFS del Trie:
adios carro casa gato hola perro 
true
true
true
false
```

## Functions

```
TrieNode()
```
Constructor for the TrieNode class.

```
insert(string word)
```
Inserts a word into the trie by traversing the tree and adding nodes where needed. 

```
search(string word)
```
Searches for a word in the trie by traversing the tree and checking if the final node is marked as the end of a word.

```
printTrieDfs()
```
Prints all words in the trie using a depth-first search algorithm.

```
int main()
```
Reads in words from standard input and inserts them into a trie. Then reads in queries from standard input and searches for them in the trie. Finally, prints the result of each query.

## License

This code is released under the MIT License. See LICENSE.md for more information.

## Questions

If you have any questions about the repository, open an issue or contact any of us contributors in https://github.com/leogzz0/trie
