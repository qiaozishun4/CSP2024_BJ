#include <bits/stdc++.h>
using namespace std;
long long a[1003][2001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long T;
    cin>>T;
    long long n,k,q;
    long long l;
    long long ans = 0;
    long long r,c;
    for(int o=0;o<T;o++){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l;
            for(int j=0;j<l;j++){
                cin>>a[i][j];
            }
        }
        for(int u=0;u<q;u++){
            ans = 0;
            cin>>r>>c;
            for(int i=0;i<n&&ans ==0;i++){
                for(int j=0;j<2000;j++){
                    if(a[i][j]==c){
                        for(int h=j-1;h>=0&&(j-h)<k&&ans == 0;h--){
                            if(a[i][h]==1){
                                ans = 1;
                                h = -1;
                            }
                        }
                    }
                }
            }

            cout<<ans<<endl;
        }
    }
    return 0;
}