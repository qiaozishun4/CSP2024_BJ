#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;int l;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            if(y==1)if(x%2==0)cout<<1<<endl;else cout<<0<<endl;
            else{
                int c=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=l;j++){
                        if(a[i][j]==y)c++;
                    }
                }
                if(c%2==0){
                    if(x%2!=0)cout<<1<<endl;
                    else cout<<0<<endl;
                }else{
                    if(x%2!=0)cout<<0<<endl;
                    else cout<<1<<endl;
                }
            }
        }
    }
    return 0;
}
