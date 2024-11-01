#include <bits/stdc++.h>
using namespace std;
int n,ans;
int r[100005];
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for (int i=1;i<=n;i++)
        cin>>r[i];
    sort(r+1,r+1+n); //O 500000
    int low=0,now=0,nownum=0;
    for (int i=1;i<=n;i++) {
        if (r[i]>nownum) {
            low+=now;
            now=1;
            nownum=r[i];
        } else {
            now++;
        }
        if (low>0) {
            ans--;
            low--;
        }
    }
    cout<<ans;
    return 0;
}
