#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,q,r,c;
int s[1010][2010];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--){
        vector <int> a[200010];
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++){
            cin>>s[i][0];
            for (int j=1;j<=s[i][0];j++){
                cin>>s[i][j];
                a[s[i][j]].push_back(j);
            }
        }
        while (q--){
            cin>>r>>c;
            bool de=false,de2=false;
            if (r==1){
                de=false;
                de2=true;
                for (int i=1;i<=n;i++){
                    if (a[1].size() && a[c].size()){
                        for (auto e:a[1]){
                            for (auto o:a[c]){
                                if (o-e+1>k){
                                    break;
                                }
                                else if (o>e){
                                    cout<<1;
                                    de=true;
                                    break;
                                }
                            }
                            if (de){
                                break;
                            }
                        }
                    }
                    if (de){
                        break;
                    }
                }
                if (!de){
                    cout<<0;
                }
            }
            if (!de2){
                cout<<0;
            }
            cout<<"\n";
        }
    }
    return 0;
}
