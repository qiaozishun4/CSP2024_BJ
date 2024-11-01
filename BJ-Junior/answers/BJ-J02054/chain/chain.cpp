#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n,k,q,x;
    cin>>n>>k>>q>>x;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    int v=x;
    for(int i=1;i<n;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
            int y;
            cin>>y;
        }
    }
    int f=0;
    while(q--){
        int y;
        cin>>x>>y;
        for(int i=1;i<=v;i++){
            if(a[i]==y){
                for(int j=i;j>=i-k+1;j--){
                    if(a[j]==1){
                        cout<<1<<endl;
                        f=1;
                        break;
                    }
                }
                if(f==1){
                    break;
                }
            }
        }
        if(f==0){
            cout<<0<<endl;
        }
    }
    return 0;
}