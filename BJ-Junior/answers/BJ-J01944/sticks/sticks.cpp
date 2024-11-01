#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll t,n,ans[100005],maxn=1,s[30]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    memset(ans,0x3f,sizeof(ans));
    ans[2]=1;
    ans[5]=2;
    ans[4]=4;
    ans[6]=6;
    ans[3]=7;
    ans[7]=8;
    cin>>t;
    for(int t1=1;t1<=t;t1++){
        cin>>n;
        for(int i=maxn;i<=n;i++){
            for(int j=0;j<=9;j++){
                if(i-s[j]<0){
                    continue;
                }
                ans[i]=min(ans[i],ans[i-s[j]]*10+j);
            }
        }
        maxn=max(maxn,n);
        if(ans[n]==0x3f3f3f3f3f3f3f3f){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans[n]<<endl;
    }
    return 0;
}
