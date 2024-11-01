#include<bits/stdc++.h>
using namespace std;
#define int long long
//20 pts
const int N=2e5+5;
int a[N];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<(1<<n);++i){
            int red=0,blue=0,tmp=0;
            for(int j=n-1;j>=0;--j){
                if((i>>j)&1){
                    if(red){
                        if(a[red]==a[j]){
                            tmp+=a[j];
                        }
                    }
                    red=j;
                }
                else{
                    if(blue){
                        if(a[blue]==a[j]){
                            tmp+=a[j];
                        }
                    }
                    blue=j;
                }
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;

My luogu uid=1015780,QQ number=3544859511
*/
