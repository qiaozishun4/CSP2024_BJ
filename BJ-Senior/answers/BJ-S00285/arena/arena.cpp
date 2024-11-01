#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 1e5 + 10;
const int K = 40;
int d[K][N];
int a[N];
int c[N];
int T;
int val[N];
int k;
int x[4];
int pk[N];
int id[N];
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
    cin >> n >> m;
    
    k = log2(n);
    if(!(pow(2,k) == n)) k++;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> c[i];
    }
    for(int i = 1;i <= k;i++)
    {
        string temp;
        getline(cin,temp);
        for(int j = pow(2,k - i) - 1;j >= 0;j--)
        {
            d[i][j] = temp[i] - '0';
        }


    }
    cin >> T;
    while(T--)
    {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1;i <= n;i++)
        {
            val[i] = a[i] ^ x[i % 4];
            pk[i] = val[i];
            id[i] = i;
        }
        for(int i = 1;i <= m;i++)
        {
            int len;
            int tot;
            int turn = 1;
            len = c[m];
            tot = 1;
            while(len > 1)
            {
                for(int j = 1;j <= len;j += 2)
                {
                    if(d[turn][tot] == 0)
                    {
						id[tot++] = (pk[j] >= turn) ? id[j] : id[j + 1];
                        pk[tot - 1] = (pk[j] >= turn) ? pk[j] : pk[j + 1];
                        
                    }
                    else
                    {
						id[tot++] = (pk[j + 1] < turn) ? id[j] : id[j + 1];
                        pk[tot - 1] = (pk[j + 1] < turn) ? pk[j] : pk[j + 1];
		
                    }

                }
                len = tot;
                tot = 1;
                turn++;
            }
            cout << id[1] << endl;
        }
    }

    return 0;
}
