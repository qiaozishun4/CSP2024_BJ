#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,cnth,cntr;
struct st
{
    bool heat = 0,hp = 1;
    int go,fa,number;
}a[N];
int main()
{
    bool flag = 1;
    cin.tie(0)->sync_with_stdio(0);
    freopen("duel2.in","r",stdin);
    freopen("duel2.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int k;cin >> k;
        a[i].go = a[i].fa = k;
        a[i].number = i;
    }
    for(int i = 1;i <= n-1;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            if(a[i].go>a[j].go) swap(a[i],a[j]);
        }
    }
    for(int i = 1;i <= n-1;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            if(a[i].fa<a[j].go and a[i].hp==1 and a[j].hp==1 and a[j].heat == 0)
            {
                a[i].hp = 0;
                a[j].heat = 1;
                cntr++;
                cnth++;
                if(cnth >= n-cntr)
                {
                    cout<<n-cntr;
                    return 0;

                }
                else continue;
                if(n-cntr == 1)
                {
                    cout<<1;
                    return 0;

                }
                for(int k= 1;k <=n-cntr;i++)
                {
                    int l = a[1].go;
                    if(a[k].go != l) flag = 0;
                }
                if(flag)
                {
                    cout<<n-cntr;
                    return 0;
                }
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

