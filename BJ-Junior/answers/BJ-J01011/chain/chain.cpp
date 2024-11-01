#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,a[100002][200002],b[100002],c[100002],d[100002];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            for(int j=1;j<=d[i];j++){
                cin>>a[i][j];
            }
        }
        bool fl=false;
        for(int i=1;i<=q;i++){
            cin>>b[i]>>c[i];
            if(b[i]==1){
                if(c[i]==1){
                    fl=true;
                }
            }
        }
        bool f=false;
        for(int i=1;i<=q;i++){
            for(int j=1;j<=c[i];j++){
                for(int v=n;v>=1;v--){
                    for(int b=d[v];b>=1;b--){
                        if(a[v][b]==1 && a[v+1][b]-a[v][b]<=k){
                            cout<<1<<endl;
                            f=true;
                            break;
                        }
                    }
                }
            }
            if(f==true){
                contine;
            }else if(fl=true){
                cout<<1<<endl;
                continue;
            }else{
                cout<<0<<endl;
                continue;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}