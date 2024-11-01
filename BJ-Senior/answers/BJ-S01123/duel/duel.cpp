#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,a[maxn],l=1,r=2;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(r<=n){
        if(a[l]<a[r]){
            l++;
        }
        r++;
    }
    cout<<n-l+1;
    return 0;
}
