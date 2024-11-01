#include <bits/stdc++.h>
using namespace std;
int a[1000][10000];
int main(){
    int t,n,k,q,l;
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l;
            for(int j=0;j<l;j++)cin>>a[i][j];
        }
        for(int i=0;i<q;i++){
            int r,c;
            cin>>r;
            cin>>c;
            for(int i=0;i<r;i++){
                if(r==1&&c==1)cout<<0<<endl;
            }
        }
    }
return 0;
}
