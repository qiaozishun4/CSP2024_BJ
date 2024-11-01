#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,k,q,l[N],a[N][N],r[N],c[N];
set<int>st[N];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>a[i][j];
                st[a[i][j]].insert(i);
            }
        }
        bool flag=false;
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            for(auto x:st[c[i]]){
                for(int j=1;j<=l[x];j++){
                    for(int m=j+1;m<=min(l[k],j+k);m++){
                        if(a[j][m]==c[i]){
                            for(int o=1;o<=n;o++){
                                for(int p=1;p<=l[o];p++){
                                    if(a[o][p]==a[i][j]){
                                        cout<<1<<endl;
                                        flag=true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag==false)
            cout<<0<<endl;
    }
    return 0;
}