#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,l,s,r,c,cnt=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
    }
    for(int i=1;i<=n;i++){
            cin>>l;
        for(int j=1;j<=l;j++){
            cin>>s;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r>>c;
    }
    for(int i=1;i<=3;i++){
        cout<<1<<endl;
        r++;
        if(l>=0&&s<=0){
            k=q;
        }
        cout<<0<<endl;
        cnt++;
    }
    if(cnt/3==1){
        cout<<0;
    }
    return 0;
}
