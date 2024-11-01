#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

long long t,n,K,q,ans,cnt[200010];
vector<long long> s[100010];

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>K>>q;
        for(long long i=1;i<=n;i++){
            long long l;
            cin>>l;
            long long d=-1e18;
            s[i].push_back(l);
            for(long long j=1;j<=l;j++){
                long long x;
                cin>>x;
                if(j-d+1<=K){
                    cnt[x]++;
                }
                if(x==1){
                    d=j;
                }
                s[i].push_back(x);
            }
        }
        for(long long i=1;i<=q;i++){
            long long r,c;
            cin>>r>>c;
            if(cnt[c]>0){
                cout<<1;
            }else{
                cout<<0;
            }
            cout<<endl;
        }
    }
    return 0;
}
