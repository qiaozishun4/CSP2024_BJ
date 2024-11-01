#include <bits/stdc++.h>
using namespace std;
#define ll long long
char a[1010][1010];
ll n,m,k,x,y,d;
ll cnt;
ll T;
ll sum;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
     cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='.'){
                    cnt++;
                }

                if(a[i][j]=='x'){
                    if(a[i][j+1]=='.'){
                        cnt++;
                        j=j+1;
                    }
                    if(a[i+1][j]=='.'){
                        cnt++;
                        i=i+1;
                    }
                    if(a[i-1][j]=='.'){
                        cnt++;
                        i=i-1;
                    }
                }
            }
        }
        cout<<cnt-1<<endl;
        cnt=0;
    }
    return 0;
}
