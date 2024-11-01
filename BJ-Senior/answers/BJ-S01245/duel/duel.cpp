#include <fstream>
using namespace std;

int num[100001];

int main()
{
    ifstream fin("duel.in");
    ofstream fout("duel.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        int r;
        fin >> r;
        num[r]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100000; i++)
    {
        ans = max(ans, num[i]);
    }
    fout << ans << endl;
}