#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int r[N];
int ans;
bool vis[N];

void read()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&r[i]);
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    read();
    sort(r+1,r+1+n);
    stack <int> s;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        if (i!=1&&r[i-1]!=r[i])
        {
            while (sum--) s.push(i-1);
            sum=0;
        }
        if (!s.empty()&&r[s.top()]<r[i])
        {
            ans++;
            s.pop();
        }
        sum++;
    }
    printf("%d",n-ans);
    return 0;
}
