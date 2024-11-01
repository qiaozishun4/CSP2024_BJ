#include<bits/stdc++.h>
using namespace std;
int  n=ie5+5;
int t[n];
int maxr=-1;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int r;
        maxr=max(maxr,t);
        cin>>r;
        t[r]++;
    }
    int cnt=0,ans=0;
    for(int i=maxr;i>=1;i--)
    {
        if(t[i]>=cnt])
        {
            ans-=cnt;
            cnt=t[i];
        }
        else
        {
            ans-=t[i];
        }
    }
    cout<<t[maxr]<<maxr<<endl;
    cout<<ans;
    return 0;
}