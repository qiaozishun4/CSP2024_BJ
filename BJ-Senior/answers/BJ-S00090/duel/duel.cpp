#include<bits/stdc++.h>
using namespace std;
int r[100005];
int h[100005];
int cnt=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    sort(r+1,r+n+1);
    int ans=n;
    r[0]=10000000;
    for(int i=1;i<=n;i++){
        if(r[i]!=r[i-1]){
            cnt++;
        }
        h[cnt]++;
    }
    int sum=h[1];
    for(int i=2;i<=cnt;i++){
        ans-=min(sum,h[i]);
        sum-=min(sum,h[i]);
        sum+=h[i];
    }
    cout<<ans;
    return 0;
}