/*
algoritmos avanzados

LCS

nombre: leonardo gonzalez guerra
matricula: a01721434
fecha: 15/03/2023
*/

#include <iostream>

using namespace std;

string S1 = "xblzkhoshddyliqcelivudakdnsmuharmxjplmrlouvcdfapugfngmasmssovggtchoedrfqzegolnjqagtyuohtrgkacomzxxoghnitmjbgyqyyqsmpsnyrkoxawnxrecatxabqnveqxynwhsgenuqgtsgmohkwntftusxlndwodspetapoezdekuwzfpkmcnqeimuzfarpizugcupjbewsdpagznlxjdfoickyqtwzebyupayoxhgmaw";

string S2 = "srrrfkzhbbzaokoorahkqwdjxqhhfxbyfhqooftnbjcwwprdnknwawycoarjtyvjxqjnduegwafmxsjaxifccqehnphzidrerwyupakhyhchwoklyarqgnmfmaorpmokpqyejqwbbvjhtlfxgedqzchoimqvctxdyjdoijwnhtnqyjlhqhnmxhacjfgolwmdnuqnbdcwwopkeechipdolwlgucakwaskeangjwzhmsgzdpcxuflmgjwlay";

string LCS(string S1, string S2)
{
    unsigned char LCS[250][250];
    int n = S1.length();
    int m = S2.length();
    int max = 0;
    int end_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (S1[i] == S2[0])
        {
            LCS[i][0] = 1;
            max = 1;
            end_index = i;
        }
        else
        {
            LCS[i][0] = 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (S1[0] == S2[j])
        {
            LCS[0][j] = 1;
            max = 1;
            end_index = 0;
        }
        else
        {
            LCS[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (S1[i] == S2[j])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (LCS[i][j] > max)
                {
                    max = LCS[i][j];
                    end_index = i;
                }
            }
            else
            {
                LCS[i][j] = 0;
            }
        }
    }

    if (end_index == -1)
    {
        return "";
    }
    else
    {
        return S1.substr(end_index - max + 1, max);
    }
}

int main()
{
    string longest_substring = LCS(S1, S2);
    if (longest_substring == "")
    {
        cout << "No common substring found" << endl;
    }
    else
    {
        cout << "Longest common substring: " << longest_substring << endl;
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