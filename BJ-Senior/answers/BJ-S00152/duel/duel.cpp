#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int n;
int ans=0,pos=1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;){
        int x=upper_bound(a+pos,a+n+1,a[i])-a,y=upper_bound(a+1,a+n+1,a[i])-a;
        if(x==n+1) break;
        int cnt1=n-x+1,cnt2=(y-1)-i+1;
        if(cnt1>=cnt2){
            ans+=cnt2;
            pos=x+cnt2;
            i=y;
        }
        else{
            ans+=cnt1;
            break;
        }
    }
    cout<<n-ans;
    return 0;
}
