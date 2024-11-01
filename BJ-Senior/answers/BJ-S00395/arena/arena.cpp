#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int n,m;
int a[N],aa[N],x[5];
int d[40][40];
int c[N],k[N];
string s[40];
bool flag[N];
int ans;
int T;

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> aa[i];
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> c[i];
    }
    int K = floor(log2(n)) + 1;
    for(int i = 1;i <= K;i++)
    {
        cin >> s[i];
    }
    cin >> T;
    while(T--)
    {
        ans = 0;
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1;i <= n;i++)
        {
            a[i] = aa[i] ^ x[i % 4];
        }
        for(int i = 1;i <= m;i++)
        {
            memset(flag,0,sizeof(flag));
            int k = floor(log2(c[i]));
            for(int R = 1;R <= k;R++)
            {
                int l = 0,r = 0;
                int cnt = 1;
                for(int j = 1;j <= pow(2,k - R);j++)
                {
                    while(flag[cnt])cnt++;
                    l = cnt;
                    cnt++;
                    while(flag[cnt])cnt++;
                    r = cnt;
                    if(s[R][j - 1] == '0')
                    {
                        if(a[l] < R)
                            flag[l] = true;
                        else
                            flag[r] = true;
                    }
                    else
                    {
                        if(a[r] < R)
                            flag[r] = true;
                        else
                            flag[l] = true;
                    }
                    // cout << l << ' ' << r << endl;
                    cnt++;
                }
                
                // for(int ii = 1;ii <= pow(2,k);ii++)
                    // cout << flag[ii] << ' ';
                // cout << endl;
            }
            for(int ii = 1;ii <= n;ii++)
                {
                    if(!flag[ii])
                    {
                        if(i == 1)
                            ans = ii;
                        else
                            ans = ans ^ (ii * i);
                        break;
                    }
                    // cout << flag[ii] << ' ';
                }
        }
        cout << ans << endl;
    }
    return 0;
}
