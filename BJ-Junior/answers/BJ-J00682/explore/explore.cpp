#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char map[1005][1005];
int n[10];
int m[10];
int d[10];
int k[10];
int cx[10];
int cy[10];
int cnt[10];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >>t;
    for(int z = 1;z <= t;z++)
    {
        cin >>n[z]>>m[z]>>k[z];
        cin >>cx[z]>>cy[z]>>d[z];
        for(int i = 1;i <= n[z];i++)
        {
            for(int j = 1;j <= m[z];j++)
            {
                cin >>map[i][j];
            }
        }
        cnt[z] = 1;
        while(k[z] > 0)
        {
            if(d[z] == 0)
            {
                if(1 <= cx[z] <= n[z] && 1 <= cy[z] + 1<= m[z] && map[cx[z]][cy[z]+1] == '.')
                {
                    cy[z] = cy[z]+1;
                    cnt[z]++;
                }
                else
                {
                    d[z] = (d[z] + 1) % 4;
                }
                k[z]--;
                continue;
            }
            if(d[z] == 1)
            {
                if(1 <= cx[z] + 1<= n[z] && 1 <= cy[z] <= m[z] && map[cx[z]+1][cy[z]] == '.')
                {
                    cx[z] = cx[z]+1;
                    cnt[z]++;
                }
                else
                {
                    d[z] = (d[z] + 1) % 4;
                }
                k[z]--;
                continue;
            }
            if(d[z] == 2)
            {
                if(1 <= cx[z] <= n[z] && 1 <= cy[z] - 1<= m[z] && map[cx[z]][cy[z]-1] == '.')
                {
                    cy[z] = cy[z]-1;
                    cnt[z]++;
                }
                else
                {
                    d[z] = (d[z] + 1) % 4;
                }
                k[z]--;
                continue;
            }
            if(d[z] == 3)
            {
                if(1 <= cx[z] - 1<= n[z] && 1 <= cy[z] <= m[z] && map[cx[z]-1][cy[z]] == '.')
                {
                    cx[z] = cx[z]-1;
                    cnt[z]++;
                }
                else
                {
                    d[z] = (d[z] + 1) % 4;
                }
                k[z]--;
                continue;
            }

        }
        cout <<cnt[z]<<endl;
    }
    return 0;
}
