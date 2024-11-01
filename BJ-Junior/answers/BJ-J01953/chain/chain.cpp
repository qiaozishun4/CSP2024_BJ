#include <bits/stdc++.h>
using namespace std;
using l = long long;
l li[2005];
short T;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(short lun = 1;lun<=T;lun++){
        l n,q,k;
        cin>>n>>k>>q;
        for(l i=1;i<=n;i++){
            cin>>li[i];
            for(l j=1;j<=li[i];j++){
                l s;
                cin>>s;
            }
        }
        for(l i=1;i<=q;i++){
            l r,c;
            cin>>r>>c;
            if(r%2==0)cout<<1<<endl;
            else cout<<0<<endl;
        }

    }
    return 0;
}
