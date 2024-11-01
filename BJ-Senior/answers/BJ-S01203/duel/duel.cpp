#include<bits/stdc++.h>
using namespace std;

int n,a[100010],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(r<=n){
        while(r<=n&&a[r]<=a[l])r++;
        if(r>n)break;
        while(r<=n&&a[r]>a[l]){
            ans++;
            l++;
            r++;
        }
    }
    cout<<n-ans;
    return 0;
}
