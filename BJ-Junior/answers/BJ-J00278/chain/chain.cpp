#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,x,y,z,a;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int r=1;r<=t;r++){
            cin>>n>>k>>q;
            for(int i=1;i<=n;i++){
                cin>>x;
                for(int j=1;j<=x;j++)
                    cin>>a;
            }
            for(int i=1;i<=q;i++){
                cin>>y>>z;
                if(y==1)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
    }
    return 0;
}