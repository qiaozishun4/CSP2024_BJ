#include <bits/stdc++.h>
using namespace std;
int n,a[200000],cnt1,cnt2,ans;
bool vis[200000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }else if(a[i]==2){
            cnt2++;
        }
    }
    sort(a+1,a+n+1);
    if(cnt1+cnt2==n){
        cout<<max(cnt1,cnt2);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[i]>a[j] && !vis[j]){
                vis[j]=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

/*
25pts(对于a[i]只有1/2的)： 输出1的数量和2的数量的最大值
50pts(n<=30):1.从前往后扫每扫到一个就从这个数开始从后往前扫每遇到一个小于此数并且没有退出的删除这个数\
一共75pts
*/