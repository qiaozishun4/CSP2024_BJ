#include<bits/stdc++.h>
using namespace std;
const int N=110;
bool D[N],C[N],H[N],S[N];
int main()
{
    freopen("joker.in","r",stdin);
    freopen("joker.out","w",stdout);
    int n,k;
    char c1,c2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c1>>c2;
        if(c2=='T') k=10;
        else if(c2=='J') k=11;
        else if(c2=='Q') k=12;
        else if(c2=='K') k=13;
        else if(c2=='A') k=1;
        else k=c2-'0';
        if(c1=='D') D[k]=1;
        else if(c1=='C') C[k]=1;
        else if(c1=='H') H[k]=1;
        else if(c1=='S') S[k]=1;
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        if(!D[i]) ans++;
        if(!C[i]) ans++;
        if(!H[i]) ans++;
        if(!S[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
