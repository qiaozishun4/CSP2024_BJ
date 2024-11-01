#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l[100010],s[1010][2010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            cin>>r>>c;
            int f=0;
            for(int i=1;i<=n;i++){
                int l1=-1,r=1e9;
                for(int j=1;j<=l[i];j++){
                    if(s[i][j]==1){
                        l1=j;
                    }
                    if(s[i][j]==c && r==1e9 && j>l1){
                        r=j;
                    }
                }
                if(r-l1+1>=2 && r-l1+1<=k){
                    f=1;
                }
            }
            cout<<f<<endl;
        }
    }
    return 0;
}
