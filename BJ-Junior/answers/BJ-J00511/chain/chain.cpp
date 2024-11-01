#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,a[200005],l;
bool num[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        bool w=0;
        for(int i=0;i<n;i++){
                cin>>l;
                int x;
            for(int j=0;j<l;j++){
                cin>>a[i];
                if(i>x+k) w=0;
                if(w) num[a[i]]=1;
                if(a[i]==1){ w=1;x=i;num[1]=1;}
            }
        }
        for(int i=0;i<q;i++){
            int r,c;
            cin>>r>>c;
            if(num[c]==1) cout<<1<<endl;
            else cout<<0;
        }
    }
    return 0;
}
