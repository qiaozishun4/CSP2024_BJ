#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool f[60];
    for(int i=1;i<=52;i++)
    {
        f[i]=0;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int t=0;
        //cout<<a<<" "<<b;
        if(b=='A')
            t+=1;
        else if(b=='T')
            t+=10;
        else if(b=='J')
            t+=11;
        else if(b=='Q')
            t+=12;
        else if(b=='K')
            t+=13;
        else
            t+=b-'0';
        if(a=='D')
            t+=13;
        if(a=='C')
            t+=26;
        if(a=='H')
            t+=39;
        if(a=='S')
            t+=0;
        if(f[t]==0)
            f[t]=1;
           // cout<<t<<endl;
    }
    int ans=0;
    for(int i=1;i<=52;i++)
    {
        if(f[i]==0)
          ans++;
    }
    cout<<ans;
    return 0;
}
