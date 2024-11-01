#include<bits/stdc++.h>
using namespace std;
int r[100005];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> r[i];
    sort(r+1,r+n+1);
    int l = 1;
    for(int i = 1;i <= n;i++) if(r[i] > r[l]) l++;
    cout << n-l+1;
    return 0;
}
