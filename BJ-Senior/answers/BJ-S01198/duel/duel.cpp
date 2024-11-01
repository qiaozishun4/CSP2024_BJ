#include<bits/stdc++.h>
using namespace std;
struct node
{
    int k,v;
};
int n,a[100005],kil[100005],q[100005],ans;
node dis[100005];
vector<int> o;
bool cmp(node x,node y)
{
    return x.k < y.k;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans = n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    o.push_back(0);
    for(int i = 1;i <= n;i++)
    {
        if(dis[a[i]].v == 0)
        {
            o.push_back(a[i]);
        }
        dis[a[i]].k = a[i];dis[a[i]].v++;
        kil[a[i]]++;
    }
    for(int i = 2;i <= o.size()-1;i++)
    {
        for(int j = i-1;j >= 1 && kil[o[i]] > 0;j--)
        {
            int r = min(dis[o[j]].v,min(dis[o[i]].v,max(0,kil[o[i]])));
            dis[o[j]].v -= r;
            kil[o[i]] -= r;
            ans -= r;
        }
    }
    cout<<ans;
}
