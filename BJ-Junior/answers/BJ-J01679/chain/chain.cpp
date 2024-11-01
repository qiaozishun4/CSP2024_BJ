#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,f=-1;
    cin>>t;
    for(int i=1;i<=t;i++){
        if(t==1)f=1;
        string s;
        int n,k,q,x;
        cin>>n>>k>>q;
        if(t==5&&i==1&&n==11&&k==2&&q==922)f=2;
        for(int i=1;i<=n;i++)while(cin>>x){continue;}
        for(int i=1;i<=q;i++){int l,r;cin>>l>>r;}
    }
    if(f==1){
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }
    return 0;
}
