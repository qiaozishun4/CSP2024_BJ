#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N];
int in[N];
int out[N];
vector<int> g[N];
bool cmp(int a,int b)
{
    return a < b;
}
bool al[N];
int ans;
int n;
signed main()
{
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin >> n;
    ans = n;
    int id = 1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    for(int i = 2;i <= n;i++)
    {
        if(a[id] < a[i])
        {
            ans--;
            id++;

        }


    }
    cout << ans << endl;
    
    return 0;
}
