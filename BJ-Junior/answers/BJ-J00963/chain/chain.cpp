#include <bits/stdc++.h>
using namespace std;
int t,n,k,p,r,c;
map<int,int> m;
int main(){

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        int l,x;
        cin>>l;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l;j++){
                cin>>x;
                m[x]++;
            }
        }
        for(int i=1;i<=p;i++){
            cin>>r>>c;
            if(c==1)cout<<0<<endl;
            else if(m[c]<=0)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
