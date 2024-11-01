#include<bits/stdc++.h>
using namespace std;
int n,k,q,T;
int s[200010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            for(int i=1;i<=a;i++){
                int b;
                cin>>b;
                s[b]=1;
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            if(s[y]){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
