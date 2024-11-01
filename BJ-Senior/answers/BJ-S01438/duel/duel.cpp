#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
int n,ai[maxn],ans;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n; ans=n;
    for(int i=1;i<=n;i++)cin>>ai[i];
    sort(ai+1, ai+n+1);
    for(int i=1,j=1;i<=n;i++)if(j<i&&ai[i]>ai[j])j++,ans--;
    cout<<ans<<endl;
}