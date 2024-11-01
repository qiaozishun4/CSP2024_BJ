#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n,k,q;
        cin>>n>>k>>q;
        for (int j=1;j<=n;j++){
            int l;
            cin>>l;
            for (int m=1;m<=l;m++){
                int s;
                cin>>s;
            }
        }
        for (int j=1;j<=q;j++){
            int r,c;
            cin>>r>>c;
            if (r%2==0) cout<<1<<endl;
            else if (c%4==0) cout<<0<<endl;
            else if (c%2==0) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}