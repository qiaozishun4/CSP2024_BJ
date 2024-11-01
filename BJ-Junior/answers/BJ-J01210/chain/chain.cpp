#include<bits/stdc++.h>
using namespace std;
int a[1000][2000];
bool f[10];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(f,0,sizeof(f));
        int n,k,q;
        cin>>n>>k>>q;
        bool fl;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            fl=0;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
                if(fl>0){
                    fl++;
                }
                if(fl>0){
                    f[a[i][j]]=fl;
                }
                if(a[i][j]==1){
                    fl=1;
                }
            }
        }
        while(q--){
             int c;
             cin>>c>>c;
             if(f[c] && f[c]<=k){
                cout<<1<<endl;
             }else{
                cout<<0<<endl;
             }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
