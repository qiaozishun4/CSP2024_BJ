#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long n,b[maxn],s[maxn],ans;
int r[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
        b[r[i]]++;
    for(int i=1;i<=r[n];i++){
        s[i]=s[i-1]+b[i];
    }
    for(int i=1;i<=r[n];i++){
        s[i]-=b[i];
    }
    for(int i=1;i<=r[n];i++){
        if(b[i]&&s[i]-ans>0){
            ans+=min(b[i],s[i]-ans);
        }
    }
    cout<<n-ans;
return 0;
}
