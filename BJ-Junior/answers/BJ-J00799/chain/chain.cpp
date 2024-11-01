#include<bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int h[100005];
int main (){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(h,0,sizeof(h));
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int m;
            cin>>m;
            for(int j=1;j<=m;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
                h[x]=1;
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(h[c]&&h[1]){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
