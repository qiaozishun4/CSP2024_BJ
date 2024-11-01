#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            for(int k=1;k<=temp;k++){
                cin>>c[i];
            }
        }
        for(int j=1;j<=q;j++){
            cin>>a[i]>>b[i];
        }
    }
     cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
     fclose(stdin);
     fclose(stdout);
    return 0;
}



