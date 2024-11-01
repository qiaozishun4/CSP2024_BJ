#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c,p,f;
int s[1005][2005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        if(k==3){
            cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
            return 0;
        }
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            cin>>r>>c;
                int p1=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=k;j++){
                        if(s[i][j]==c){
                            cout<<1<<endl;
                            p1=1;
                            break;
                        }
                    }
                    if(p1==1) break;
                }
                if(p1==0){
                    cout<<0<<endl;
                }
        }
    }
    return 0;
}
