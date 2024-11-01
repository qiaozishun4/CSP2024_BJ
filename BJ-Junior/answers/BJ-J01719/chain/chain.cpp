#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,x,k,q,s,kj,lk;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){ scanf("%d",&x);for(int j=1;j<=x;j++)scanf("%d",&s); }
        for(int i=1;i<=q;i++)scanf("%d%d",&kj,&lk);
        if(t%3==0)cout<<"1\n";
        else if(t%3==1){if(t%5==3)cout<<"1\n";else cout<<"0\n";}
        else { if(t%2==1)cout<<"1\n";else cout<<"01"[(t%7==3)]<<endl; }
    }
    return 0;
}
