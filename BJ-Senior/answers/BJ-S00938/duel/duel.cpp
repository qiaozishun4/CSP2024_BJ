#include<bits/stdc++.h>
#define MAXN 100001;
using namespace std;
int n,a[MAXN],b[MAXN];
int main(){
    freopen("duel.in","r","stdin");
    freopen("duel.out","w","stdout");
    cin>>n;
    int l=1000000,r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=n;
    sort(a+1,a+n);
    int l=1,r=n;
    while(l<=r){
        if(a[l]<a[r]){
            ans--;
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
