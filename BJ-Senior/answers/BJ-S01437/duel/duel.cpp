#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int k=0;
    cnt[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            k++;
        }
        cnt[k]++;
    }
    int sum=0;
    for(int i=1;i<=k;i++){
        sum-=min(sum,cnt[i]);
        sum+=cnt[i];
    }
    cout<<sum;
    return 0;
}

