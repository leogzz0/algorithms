/*
algoritmos avanzados

actividad 2.2
suffix array

nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 12/03/2023
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// returns a vector containing all substrings of the given string
vector<string> getSubstrings(string str)
{
    vector<string> substrings;

    for (string::size_type i = 0; i < str.length(); i++)
    {
        for (string::size_type j = i + 1; j <= str.length(); j++)
        {
            substrings.push_back(str.substr(i, j - i));
        }
    }

    return substrings;
}

int main()
{
    string line;
    vector<string> substrings;

    // read each line of the text file
    while (getline(cin, line))
    {
        // get substrings of the current line
        vector<string> sub = getSubstrings(line);
        // add the substrings to the end of the existing vector
        substrings.insert(substrings.end(), sub.begin(), sub.end());
    }

    // sort the substring vector in alphabetical order
    sort(substrings.begin(), substrings.end());

    // display the sorted substring ons the console
    cout << "Substrings in alphabetical order:\n";
    for (vector<string>::size_type i = 0; i < substrings.size(); i++)
    {
        cout << substrings[i] << "\n";
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