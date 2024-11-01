#include<bits/stdc++.h>
using namespace std;
struct task{
    int r,c;
}t[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a[100010][100010];
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            int l;
            cin>>l;
            for(int j=0;j<l;j++) cin>>a[i][j];
        }
        for(int i=0;i<q;i++){
            cin>>t[i].r>>t[i].c;
        }
        cout<<0;
    }
    return 0;
}