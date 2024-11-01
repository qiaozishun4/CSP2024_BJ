#include<iostream>
using namespace std;
const int N = 1e5 + 5;

int n,b[N],ans;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        b[a]++;
    }
    for(int i=1;i<=N;i++)
        ans = max(ans,b[i]);
    cout << ans << endl;
    return 0;
}
