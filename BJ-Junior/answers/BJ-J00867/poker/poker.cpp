#include <bits/stdc++.h>
using namespace std;
map<string,long long> m;
long long n,ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (long long i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        if (m[s]==0)
        {
            m[s]=1;
            ans--;
        }
    }
    cout << ans;
    return 0;
}
