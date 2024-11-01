#include<bits/stdc++.h>
using namespace std;
int n,t,k,q;
bool f[200100];
vector<int> e[100100];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            for(int j=1;j<=x;j++){
                int kkk;
                cin>>kkk;
                e[i].push_back(kkk);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<e[i].size();j++){
                if(e[i][j]==1){
                    for(int l=1;l+j<min(int(e[i].size()),k+j);l++){
                        f[e[i][j+l]]=1;
                    }
                }
            }
        }
        for(int j=1;j<=q;j++){
            int i,b;
            cin>>i>>b;
            cout<<f[b]<<endl;
        }
    }
}
