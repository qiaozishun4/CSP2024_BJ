#include<bits/stdc++.h>
using namespace std;
int n;
int r[100010],buc[100010];
int maxn=-1;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        buc[r[i]]++;
    }
    for(int i=0;i<=100000;i++)
    {
        if(buc[i]>maxn)
        {
            maxn=buc[i];
        }
    }
    cout<<maxn;
    return 0;
}