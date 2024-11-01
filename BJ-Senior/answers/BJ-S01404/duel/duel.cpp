#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e5+5;
int n,r[N];
vector<int> Row[N];
int tot[N],cnt=0;
int hashes[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
    }
    sort(r+1,r+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(hashes[r[i]]==0)
        {
            cnt=0;
            cnt++;
            Row[cnt].push_back(r[i]);
            hashes[r[i]]=1;
        }
        else
        {
            cnt++;
            Row[cnt].push_back(r[i]);
        }
        ans=max(ans,cnt);
    }
    cout << ans;
    return 0;
}
