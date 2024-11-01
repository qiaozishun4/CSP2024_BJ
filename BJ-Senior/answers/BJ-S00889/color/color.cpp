#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int n,a[100010];
bool choose[100010];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int pref0=0,pref1=0,ans=0,cnt=0;
    for(int i=0;i<=(1<<n);i++){
        memset(choose,0,sizeof(choose));
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                choose[j+1]=true;
            }
        }
        pref0=pref1=cnt=0;
        for(int j=1;j<=n;j++){
            if(!pref0&&choose[j]==0){pref0=j;continue;}
            if(!pref1&&choose[j]){pref1=j;continue;}
            if(pref0&&a[j]==a[pref0]&&choose[j]==choose[pref0]&&choose[j]==0){
                pref0=j;
                cnt+=a[pref0];
                continue;
            }
            if(pref1&&a[j]==a[pref1]&&choose[j]==choose[pref1]&&choose[j]==1){
                pref1=j;
                cnt+=a[pref1];
                continue;
            }
            if(choose[j])pref1=j;
            if(!choose[j])pref0=j;
            //if(cnt==5)cout<<i<<endl;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}