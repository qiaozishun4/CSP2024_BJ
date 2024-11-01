#include<bits/stdc++.h>
using namespace std;
vector<int> a[100010];
bool dfs(int i, int j, int r, int c, int k, int n)
{
    if(r == 0) return false;
    for(int m = 1;m <= k - 1;m++)
    {
        if(j + m < a[i].size())
        {
            if(a[i][j + m] == c && r == 1) return true;
            else
            {
                for(int l = 1;l <= n;l++)
                {
                    if(l != i)
                    {
                        for(int o = 0;o < a[l].size();o++)
                        {
                            if(a[l][o] == a[i][j + m])
                            {
                                if(dfs(l, o, r - 1, c, k, n)) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("chain.in", ios::in);
    ofstream fout("chain.out", ios::out);
    fin.tie(0); fout.tie(0);
    int t;
    fin >> t;
    while(t--)
    {
        int n, k, q;
        fin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int l; fin >> l;
            for(int j = 0;j < l;j++)
            {
                int x; fin >> x; a[i].push_back(x);
            }
        }
        while(q--)
        {
            int r, c;
            fin >> r >> c;
            bool x = false;
            for(int i = 1;i <= n;i++)
            {
                for(int j = 0;j < a[i].size();j++) if(a[i][j] == 1)
                {
                    if(dfs(i, j, r, c, k, n))
                    {
                        x = true;
                        goto finish;
                    }
                }
            }
            finish:
            if(x == true) fout << "1" << endl;
            else fout << "0" << endl;
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < a[i].size();j++) a[i][j] = -1;
        }
    }
    return 0;
}
