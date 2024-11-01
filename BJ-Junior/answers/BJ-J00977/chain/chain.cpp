#include<bits/stdc++.h>
using namespace std;
long long l[100000],s[1000][1000],c[1000],r[1000],flag=0,t,n,k,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int z=1;z<=t;z++){
        flag=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++)cin>>s[i][j];
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=q;i++){
            flag=0;
            for(int j=1;j<=n;j++){
                for(int p=1;p<=l[j];p++){
                    if(s[j][p]==c[j]){
                        for(int e=p-1;e>=p-k+2;e--){
                            if(s[j][p]==1) flag=1;
                        }
                    }
                }
            }
            if(flag==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}

//0 1 2 3 4 5 6 7 8 9
//6 2 5 5 4 5 6 3 7 6
