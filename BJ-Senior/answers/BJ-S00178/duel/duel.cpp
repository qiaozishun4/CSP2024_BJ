#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N],b[N],n,c[N],sum;

int main()
{
    freopen("duel.in","r",stdin);freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    int k=0;
    for(int i=1;i<=N;i++)
    {

        if(b[i]!=0)c[++k]=b[i];
    }
    k--;
    for(int i=1;i<k;i++)
    {
        c[i]-=c[i+1];
        sum+=c[i];
        sum=max(0,sum);
    }
    sum+=c[k];
    cout<<sum;
    return 0;
}
