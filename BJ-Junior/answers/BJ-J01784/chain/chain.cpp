#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int l[N];
vector <int> f[N];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            cin >> l[i];
            for(int j = 1;j <= l[i];j++)
            {
                int x;
                cin >> x;
                f[i].push_back(x);
            }
        }
        for(int i = 1;i <= q;i++)
        {
            int r, c;
            cin >> r >> c;
            bool flag = false;
            if(r == 1)
            {
                for(int j = 1;j <= n;j++)
                {
                    for(int l = 0;l < f[j].size();l++)
                    {
                        if(f[j][l] == c)
                        {
                            for(int fl = l - 1;fl >= max(0, l - k + 1);fl--)
                            {
                                if(f[j][fl] == 1)
                                {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if(flag == true)
                            break;
                    }
                    if(flag == true)
                        break;
                }
                cout << flag << endl;
            }
            else
                cout << rand() % 2 << endl;
        }
    }
    return 0;
}