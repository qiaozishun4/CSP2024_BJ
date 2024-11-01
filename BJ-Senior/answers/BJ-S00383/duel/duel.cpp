#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    for(int r=2;r<=n;r++){
        if(a[r]>a[l]){
            ans++;
            l++;
        }
    }
    cout<<n-ans;
    return 0;
}
