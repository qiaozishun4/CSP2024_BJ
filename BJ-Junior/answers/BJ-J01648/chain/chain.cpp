#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k,q;
        long long a[1000005]={};
        int l,p;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int z=1;z<=l;z++){
                cin>>p;
                a[p]=1;
            }
        }
        int r,c;
        for(int j=1;j<=q;j++){
            cin>>r>>c;
            if(a[c]==1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}

