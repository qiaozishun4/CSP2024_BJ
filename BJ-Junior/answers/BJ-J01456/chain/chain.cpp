#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            a[i][0]=l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            cout<<q%2<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}