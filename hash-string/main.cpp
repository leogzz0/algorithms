#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // check if the corect number of command line arguments were provided
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " filename n\n";
        return 1;
    }

    // parse input parameters (text file, n)
    string filename = argv[1];
    int n = stoi(argv[2]);

    // checking that n is a multiple of 4
    if (n % 4 != 0 || n < 16 || n > 64)
    {
        cerr << "Error: n must be a multiple of 4 and between 16 and 64\n";
        return 1;
    }

    // open input file
    ifstream input(filename);
    if (!input)
    {
        cerr << "Error: cannot open input file " << filename << endl;
        return 1;
    }

    // read input file into a string
    stringstream buffer;
    buffer << input.rdbuf();
    string contents = buffer.str();

    // pad contents with push character ("0") if necessary
    if (contents.length() % n != 0)
    {
        int padding = n - contents.length() % n;
        contents.append(padding, '0');
    }

    // calculate each column sum and store them in an array
    vector<int> sums(n, 0);
    for (int i = 0; i < static_cast<int>(contents.length()); i++)
    {
        int col = i % n;
        sums[col] += contents[i];
    }

    // calculate checksums and output as hexadecimal string
    stringstream output;
    for (int i = 0; i < n; i++)
    {
        int checksum = sums[i] % 256;
        output << setw(2) << setfill('0') << uppercase << hex << checksum;
    }

    cout << output.str() << endl;

    return 0;
}
