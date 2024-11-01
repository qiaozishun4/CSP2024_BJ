#include<bits/stdc++.h>
using namespace std;
const int K=2e5+1;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        int s[n+1][K],l[n+1];
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            int r,c;
            bool f=0;
            cin>>r>>c;
            for(int i=1;i<=r;i++){
                for(int j=1;j<=n;i++){
                    for(int al=1;al<=l[i];al++){
                        if(s[al]==1){
                            for(int ar=al+1;ar<=l[i]){
                                if(s[ar]==c&&ar-al<k){
                                    cout<<1<<endl;
                                    f=1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(!f)cout<<0<<endl;
        }
    }
    return 0;
}
