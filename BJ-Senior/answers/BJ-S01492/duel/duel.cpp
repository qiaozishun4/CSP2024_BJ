#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],ans;
priority_queue<int> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        if((!q.empty()) && a[i]>-q.top())
        {
            q.pop();
            --ans;
        }
        q.push(-a[i]);
    }
    printf("%d",ans);
    return 0;
}
