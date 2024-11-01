#include <bits/stdc++.h>
using namespace std;

int n;
int r[100005];
bool vr[100005];
bool br[100005];
int ans;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> r[i];
    }
    ans = n;
    sort(r + 1,r + n + 1);
    for(int i = 1;i <= n;i++)
    {
        if(vr[i] == true)
        {
            continue;
        }
        for(int j = 1;j <= n;j++)
        {
            if(vr[j] == false && r[j] < r[i] && br[i] == false && i != j)
            {
                br[i] = true;
                vr[j] = true;
                br[j] = true;
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
