#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,stick[15]={6,2,5,5,4,5,6,3,7,6},ans[N];
bool haveans=false;
void dfs(int n2,int tot)
{
    if(n2<0)return;
    if(n2==0)
    {
        haveans=1;
        for(int i=1;i<=tot;i++)cout << ans[i];
    }
    for(int i=0;i<=9;i++)
    {
        if(n==n2&&i==0)continue;
        ans[++tot]=i;
        dfs(n2-stick[i],tot);
        tot--;
        if(haveans)return;
    }
    cout << -1;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        if(n%7==0)
            for(int i=1;i<=n/7;i++)cout << 8;
        else if(n%7==1&&n!=1)
             {
                cout << 10;
                for(int i=1;i<=n/7-1;i++)cout << 8;
             }
        else dfs(n,0);
        cout << endl;
    }
    return 0;
}

