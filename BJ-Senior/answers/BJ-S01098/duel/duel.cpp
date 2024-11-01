#include <bits/stdc++.h>
using namespace std;

int n,a[114514],ans;
bool vis[1145141];

void find(int x)
{
    for(int j=x;j>=1;j--)
        if(a[j]<a[x] && !vis[j]){vis[j]=1;find(j);break;}
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);

    for(int i=n;i>=1;i--)
    {
        if(!vis[i])
        {
            find(i);
        }
    }
    for(int i=1;i<=n;i++)if(!vis[i])ans++;

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}