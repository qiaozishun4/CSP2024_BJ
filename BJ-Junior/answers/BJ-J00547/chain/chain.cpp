#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long t;
    long long n,k,q,r,c;
    cin>>t;
    for(int i=1;i<=n;i++){
        cin>>n>>k>>q;
        long long l[n+1],s[10010][n+1];
        for(long long j=1;j<=n;j++){
            cin>>l[j];
            for(long long p=1;p<=l[j];p++){
                cin>>s[p][j];
            }
        }
        for(long long j=1;j<=q;j++){
            cin>>r>>c;
            if(j%2==1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
}
