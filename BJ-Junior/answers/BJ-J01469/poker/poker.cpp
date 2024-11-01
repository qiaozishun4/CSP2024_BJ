#include<bits/stdc++.h>
using namespace std;

int n;
map<string,bool> vis;
int cnt;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string x;
        cin >> x;
        if(vis[x] == false)
        {
            vis[x] = true;
            cnt++;
        }
    }
    cout << 52 - cnt << endl;
    return 0;
}
