#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+15;
int n,l,r,ans;
int a[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+1+n);
    l=r=1;
    while(r<=n){
        if(a[l]>=a[r]) r++;
        else{
            ans++;
            l++;
            r++;
        }
    }
    cout<<n-ans;
    return 0;
}
