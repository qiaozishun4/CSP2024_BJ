#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int n,a[100005],cnt[100005],minn[100005],l;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    for(int i=1;i<=n;i++){
        if(a[i]>a[l+1])l++;
    }
    cout<<n-l;
    return 0;
}
