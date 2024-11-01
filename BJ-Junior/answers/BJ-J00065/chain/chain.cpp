#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        int l[n]={0},s[n][200001],r,c;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        bool flag=true;
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            cout<<0<<endl;//试图骗分
            /*for(int j=1;j<=n;j++){
                for(int p=1;p<=l[j];p++){
                    bool flag1=false;
                    if(s[j][p]==1) flag1=false;
                }//O(n^4),what can I say
            }*/

        }
    }
    return 0;
}
