#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,r[maxn],cnt[maxn];
int findback(int x){
    x--;
    while(cnt[x]==0&&x>0)
        x--;
    return x;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){cin>>r[i]; cnt[r[i]]++;}
    sort(r+1,r+n+1);
    int res=n;
    for (int i=1;i<=n;i+=cnt[r[i]]){
        int fl=cnt[r[i]];
        while (findback(r[i])>0&&fl>0) {
            res-=min(cnt[r[i]],cnt[findback(r[i])]);
            fl-=min(cnt[r[i]],cnt[findback(r[i])]);
            cnt[findback(r[i])]-=min(cnt[r[i]],cnt[findback(r[i])]);
        }
    }
    cout<<res;
    return 0;
}