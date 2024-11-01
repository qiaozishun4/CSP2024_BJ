#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int h[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        h[a[i]]++;
        if(h[a[i]]!=1){
            i--;
            n--;
        }
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=2;i<=n;i++){
        ans+=min(h[a[i]],h[a[i-1]]);
    }
    cout<<m-ans;
    return 0;
}
