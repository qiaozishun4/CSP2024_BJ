#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int t;
int co[200005];
int l;
int s[200005];
int r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l>>s[i];
            co[s[i]]=1;
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            if(co[c]!=1){
                cout<<0<<endl;
            }else if(r%2==1&&c!=2){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }
    return 0;
}
