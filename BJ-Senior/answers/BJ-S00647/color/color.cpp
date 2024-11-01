#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int a[N];
int lst[2];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<1<<n;i++){
        int res=0;
        memset(lst,0,sizeof(lst));
        for(int j=1;j<=n;j++){
            if(i&(1<<j-1)){
                int num=lst[1];
                if(num==a[j]){
                    res+=num;
                }
                lst[1]=a[j];
            }else{
                int num=lst[0];
                if(num==a[j]){
                    res+=num;
                }
                lst[0]=a[j];
            }
        }
        ans=max(ans,res);
    }
    cout<<ans<<'\n';
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
