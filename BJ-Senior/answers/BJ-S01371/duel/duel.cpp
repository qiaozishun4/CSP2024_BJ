#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
struct node
{
    int num,time=1;
}a[maxn];
bool cmp(node x,node y)
{
    return x.num>y.num;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
    }
    sort(a+1,a+1+n,cmp);
    int ans=n,r=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=r;j<=n;j++)
        {
            if(a[i].num>a[j].num&&a[j].time)
            {
                a[j].time=0;
                ans--;
                r=j;
                break;
            }
        }
        if(r==i) break;
    }
    cout<<ans;
    return 0;
}