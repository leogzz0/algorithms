/*
algoritmos avanzados
by leogzz0
nombre: leonardo gonzalez guerra
fecha: 28/03/2023
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_CHAR = 26; // número de letras del alfabeto

class TrieNode
{
public:
    bool isEnd;                   // indica si el nodo es el final de una palabra
    TrieNode *children[MAX_CHAR]; // nodos hijos para cada letra del alfabeto

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < MAX_CHAR; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    // toma una palabra y la inserta en el trie
    void insert(string word)
    {
        TrieNode *node = root;
        for (std::string::size_type i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!node->children[index])
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true; // marca el final de la palabra
    }

    // toma una palabra como argumento y busca esa palabra en el trie
    bool search(string word)
    {
        TrieNode *node = root;
        for (std::string::size_type i = 0; i < word.length(); i++)
        {
            char c = word[i];
            int index = c - 'a';
            if (!node->children[index])
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd; // retorna true si el nodo es el final de una palabra
    }

    // recorrido dfs (depth first search) que sirve para imprimir todas las palabras encontradas en el trie
    void printTrieDfs()
    {
        cout << "Recorrido DFS del Trie:" << endl;
        printTrieDfs(root, "");
        cout << endl;
    }

private:
    TrieNode *root;

    void printTrieDfs(TrieNode *node, string word)
    {
        if (node->isEnd)
        {
            cout << word << " ";
        }
        for (int i = 0; i < MAX_CHAR; i++)
        {
            if (node->children[i])
            {
                printTrieDfs(node->children[i], word + char(i + 'a'));
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n;
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        trie.insert(word);
    }
    trie.printTrieDfs();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        cout << (trie.search(word) ? "true" : "false") << endl;
    }
    return 0;
}

/*
 *
 *     ("`-''-/").___..--''"`-._
 *      `6_ 6  )   `-.  (     ).`-.__.`)
 *      (_Y_.)'  ._   )  `._ `. ``-..-'
 *    _..`--'_..-_/  /--'_.' ,'
 *   (il),-''  (li),'  ((!.-'      @leogzz0
 *
 */
