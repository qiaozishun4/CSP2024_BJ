#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v;
    bool h,g;
}a[100005];
int cmp(node A,node B)
{
    return A.v<B.v;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].h=1;
        a[i].g=0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j].v>a[i].v && !a[j].g)
            {
                a[i].h=0;
                a[j].g=1;
                break;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].h) ans++;
    }
    cout<<ans;
}
