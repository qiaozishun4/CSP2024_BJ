#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int T, N, t0;
int num;
int sn[15]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[MAXN];
int dfs (int s, int t)
{
    if(t==1)
    {
        if(s==1)
        {
            return 0;
        } else if (s==2)
        {
            ans[++num]=1;
            return 1;
        } else if (s==3)
        {
            ans[++num]=7;
            return 1;
        } else if (s==4)
        {
            ans[++num]=4;
            return 1;
        } else if (s==5)
        {
            ans[++num]=2;
            return 1;
        } else if (s==6)
        {
            if(t0==1)
            {
                ans[++num]=6;
            } else
            {
                ans[++num]=0;
            }
            return 1;
        } else if (s==7)
        {
            ans[++num]=8;
            return 1;
        }
    }
    for(int i=0;i<=9;i++)
    {
        if(t0==t&&i==0)continue;
        if(sn[i]<s-7*(t-1))continue;
        if(dfs(s-sn[i], t-1)==1)
        {
            ans[++num]=i;
            return 1;
        } else {
            return 0;
        }

    }
}
int main ()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    while(T)
    {
        num=0;
        cin>>N;
        if(N==1)
        {
            cout<<"-1"<<endl;
            T--;
            continue;
        } else
        {
            t0=(int)ceil(N/7.0);
            dfs(N, t0);
        }
        for(int i=num; i>=1;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
