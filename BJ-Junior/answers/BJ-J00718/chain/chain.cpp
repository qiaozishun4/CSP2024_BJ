#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,k,q,z=0;
int l[N],s[N][N],r[N],c[N];
int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        bool flag=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
                cin>>s[i][j];
        }
        for(int i=1;i<=q;i++)
            cin>>r[i]>>c[i];
        for(int i=c[i];i>=r[i];i--)
            for(int j=r[i];j<=c[i];j++)
                if(s[i][j]!=s[j][i])
                    flag=1;
        if(flag) cout<<"1";
        else cout<<"0";
    }
    return 0;
}