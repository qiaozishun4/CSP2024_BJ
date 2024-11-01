#include<bits/stdc++.h>
using namespace std;
map<string,int> vis;
string c[10] = {"0","D","C","H","S"};
string num[20] = {"0","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        vis[s] = 1;
    }
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j<= 13; j++)
        {
            string t = c[i] + num[j];
            if(!vis[t]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
