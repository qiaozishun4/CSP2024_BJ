#include<bits/stdc++.h>
using namespace std;
const int INF=100005;
int n,ans,r[INF],cnt[INF],sum;
stack<int> s;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    ans=n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    sort(r,r+n);
    cnt[0]=1;
    sum=1;
    for(int i=1;i<n;i++){
        if(r[i-1]==r[i]){
            r[i-1]=INF;
            cnt[sum-1]++;
        }else{
            cnt[++sum-1]++;
        }
    }
    sort(r,r+n);
    s.push(r[0]);
    for(int i=1;i<sum;i++){
        if(cnt[i]>=cnt[i-1]){
            ans-=cnt[i-1];
        }
        if(cnt[i]<cnt[i-1]){
            ans-=cnt[i];
            cnt[i]+=cnt[i-1]-cnt[i];
        }
        s.pop();
        s.push(r[i]);
    }

    cout<<ans;
    return 0;
}
