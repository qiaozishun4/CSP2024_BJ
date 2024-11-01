#include <fstream>
#include <queue>
using namespace std;

int s[200001];
bool hav[10][10];
int first[10][10];

struct state
{
    int nw, t, lt;
    state(int a, int b, int c)
    {
        nw = a; t = b; lt = c;
    }
};

int bfs(int r, int c)
{
    queue<state> q;
    q.push(state(1, 0, -1));
    while (!q.empty())
    {
        state ns = q.front();
        q.pop();
        if (ns.t == r)
        {
            if (ns.nw == c)
            {
                return 1;
            }
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (hav[ns.nw][i] && (first[ns.nw][i] == -1 || first[ns.nw][i] != ns.lt))
                {
                    q.push(state(i, ns.t + 1, first[ns.nw][i]));
                }
            }
        }
    }
    return 0;
}

int main()
{
    ifstream fin("chain.in");
    ofstream fout("chain.out");

    int t;
    fin >> t;
    while (t--)
    {
        int n, k, q;
        fin >> n >> k >> q;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                hav[i][j] = false;
                first[i][j] = -1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int l;
            int last[10];
            fin >> l;
            for (int j = 0; j < 10; j++)
            {
                last[j] = -k;
            }
            for (int j = 1; j <= l; j++)
            {
                fin >> s[j];
                for (int d = 0; d < 10; d++)
                {
                    if (j - last[d] < k)
                    {
                        if (!hav[d][s[j]])
                        {
                            hav[d][s[j]] = true;
                            first[d][s[j]] = i;
                        }
                        else if (hav[d][s[i]] && first[d][s[j]] != -1)
                        {
                            first[d][s[j]] = -1;
                        }
                    }
                }
                last[s[j]] = j;
            }
        }

        while (q--)
        {
            int r, c;
            fin >> r >> c;
            fout << bfs(r, c) << endl;
        }
    }
}