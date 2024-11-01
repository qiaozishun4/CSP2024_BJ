#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n,m,k;
ll x,y,d0;
ll a[10086][10086];

int main(){
    //freopen("explore.in","r",stdin);
    //freopen("explore.out","w",stdout);
    cin>>T;
    int sum=0;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='.') sum+=1;
            }
        }
    }


    cout<<sum<<endl;

    return 0;
}
