#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=2e5+10;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        int n,k,q,a[N][M],ans=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int j;
            cin>>j;
            a[i][0]=j;
            ans=max(ans,j);
            for(int t=1;t<=j;t++){
                cin>>a[i][t];
            }
        }
        while(q--){
            int r,c,f=0;
            cin>>r>>c;
            for(int i=1;i<=n;i++){
                    int t=a[i][0];
                for(int j=1;j<=t;j++){
                    if(a[i][j]==c&&i!=1&&j!=1){
                        f=1;
                    }
                }
            }
            if(f==0){
                cout<<0<<endl;
                continue;
            }
            if(r==1&&f==1){
                cout<<1<<endl;
                continue;
            }

            cout<<0<<endl;
            }
        }



    fclose(stdin);
    fclose(stdout);
    return 0;
}
