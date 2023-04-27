#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void printBST(int A[][100], int i, int j, int parent, vector<int> &node)
{
    if (i > j)
        return;
    if (parent == -1)
        node.push_back(A[i][j]);
    else
    {
        cout << "node " << parent << " is the parent of its ";
        if (A[i][j] < parent)
            cout << "left child ";
        else
            cout << "right child ";
        cout << "node " << A[i][j] << endl;
    }
    printBST(A, i, A[i][j] - 1, A[i][j], node);
    printBST(A, A[i][j] + 1, j, A[i][j], node);
}

float BSTOp(vector<float> p, int n)
{
    float pacum[100];
    pacum[0] = 0;
    for (int i = 1; i <= n; i++)
        pacum[i] = pacum[i - 1] + p[i - 1];
    float A[100][100];
    int root[100][100];
    for (int i = 1; i <= n; i++)
    {
        A[i][i - 1] = 0;
        A[i][i] = p[i - 1];
        root[i][i] = i;
    }
    A[n + 1][n] = 0;
    for (int diag = 1; diag < n; diag++)
    {
        for (int i = 1; i <= n - diag; i++)
        {
            int j = i + diag;
            A[i][j] = 1e9;
            for (int k = i; k <= j; k++)
            {
                if (A[i][k - 1] + A[k + 1][j] < A[i][j])
                {
                    A[i][j] = A[i][k - 1] + A[k + 1][j];
                    root[i][j] = k;
                }
            }
            A[i][j] += pacum[j] - pacum[i - 1];
        }
    }
    vector<int> node;
    printBST(root, 1, n, -1, node);
    cout << setprecision(2) << fixed << A[1][n] << endl;
    return A[1][n];
}

int main()
{
    ifstream infile("input.txt");
    int n;
    infile >> n;
    vector<float> p(n);
    for (int i = 0; i < n; i++)
        infile >> p[i];
    BSTOp(p, n);
    return 0;
}