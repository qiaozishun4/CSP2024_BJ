#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
ll t;
ll n,a[200005],can[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int t1=1;t1<=t;t1++){
        ll allans=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        while(can[n+1]!=1){
            ans=0;
            can[1]++;
            ll now=1;
            while(can[now]>=2){
                if(now>n){
                    break;
                }
                can[now]=0;
                can[now+1]++;
                now++;
            }
            if(can[n+1]==1){
                break;
            }
            ll r=0,b=0;
            for(int i=1;i<=n;i++){
                if(can[i]==1){
                    if(r==a[i]){
                        ans=ans+a[i];
                    }
                    r=a[i];
                }else if(can[i]==0){
                    if(b==a[i]){
                        ans=ans+a[i];
                    }
                    b=a[i];
                }
            }
            allans=max(allans,ans);
        }
        cout<<allans<<endl;
    }
    return 0;
}
