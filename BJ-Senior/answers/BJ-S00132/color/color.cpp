#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;

ifstream fin("color.in");
#define cin fin
ofstream fout("color.out");
#define cout fout

int T;
int n;
ll a[maxn];

ll f[2010][2010][2];

int main(){
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int t=0;t<2;t++){
                    if(j==i-1){
                        f[i][j][t]=0;
                        for(int k=1;k<i-1;k++)
                            f[i][j][t]=max(f[i][j][t],f[i-1][k][t^1]+(a[i]==a[k])*a[i]);
                    }
                    else{
                        f[i][j][t]=f[i-1][j][t]+(a[i]==a[i-1])*a[i];
                    }
                }
            }
        }
        ll ans=0;
        for(int j=1;j<n;j++){
            ans=max(ans,max(f[n][j][0],f[n][j][1]));
        }
        cout<<ans<<endl;
        
    }


    return 0;
}
// g++ color.cpp -o color.exe -std=c++14 -O2 -Wall && ./color.exe