#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int r[1000000];
    int t,max=0,min;
    for(int i=1;i<=n;i++){
        cin>>t;
        r[t]++;
        if(t>max)
            max=t;
        if(t<min||i==1)
            min=t;
    }
    int front=0;
    for(int i=min;i<=max;i++)
    {
        ans+=r[i];
        if(r[i]>=front)
            ans-=front;
        else
            ans-=r[i];
        front=ans;
    }
    cout<<ans;
    return 0;
}
