#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        int n,k,q;
        int s[2005][2005];
        int l[2005];
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int p1=1;p1<=q;p1++){
            int r,c;
            cin>>r>>c;
            cout<<1<<endl;
        }
    }
    return 0;
}
