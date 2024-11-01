#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n;
int a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    for(int i=1;i<=n;i++)if(a[i]>a[l])l++;
    cout<<n-l+1;
    return 0;
}
