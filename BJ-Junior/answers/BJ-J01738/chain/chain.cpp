#include<bits/stdc++.h>
using namespace std;
int t,l[1010],n,k,q,s[1010][2010],r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        if(n>1000){
            cout<<0<<endl;
            continue;
        }
        bool f=1;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            if(l[i]>2000){
                f=0;
                break;
            }
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        if(!f){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            bool fu=0;
            for(int j=1;j<=n;j++){
                for(int m=1;m<=l[j];m++){
                    if(a[j][m]==c){
                        fu=1;
                    }
                }
            }
            if(fu==1)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
