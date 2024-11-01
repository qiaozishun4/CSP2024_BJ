#include<bits/stdc++.h>
using namespace std;
int n;
int r[100001];
int a[100001],sy[100001],cnt,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        if(r[i]!=r[i-1]){
            cnt++;
        }
        a[cnt]++;
        sy[cnt]++;
    }
    int j;
    for(int i=1;i<=cnt;i++){
        j=i+1;
        while(j<=cnt&&sy[j]<=a[i]){
            a[i]-=sy[j];
            sy[j]=0;
            j++;
        }
        a[i]-=min(a[i],sy[j]);
        sy[j]-=min(a[i],sy[j]);
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
