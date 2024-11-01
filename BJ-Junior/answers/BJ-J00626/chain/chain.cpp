#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,q,l,r,c,f=0;
vector <int> s[100010];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            cin>>r>>c;
            for(int j=1;j<=n;j++){
                for(int p=1;p<=s[j].size();p++){
                    if(s[j][p]==c){
                        for(int w=p;w>=p-k+1;w--){
                            if(s[j][w]==1){
                                cout<<1;
                                f=1;
                                break;
                            }
                        }
                        if(f)break;
                    }
                }
            }
            if(!f){
                    cout<<0;
                    break;
                }
        }
    }
    return 0;
}
