#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,x,y,b[200001],c;
map<int,bool>p;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        map<int,bool>().swap(p);
        cin>>n>>k>>q;
        for(int i=1;i<=n;++i){
            cin>>l;
            for(int j=1;j<=l;++j){
                cin>>b[j];
                if(j-k>=1&&b[j-k]==1) --c;
                if(c) p[b[j]]=1;
                if(b[j]==1) ++c;
            }
        }
        for(int i=1;i<=q;++i){
            cin>>x>>y;
            if(x==1){
                if(p[y]) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
