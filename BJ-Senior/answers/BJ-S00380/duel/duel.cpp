#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[100005];
bool vis[100005];
int minn = -1e9;
int cnt;

int main()
{
     freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int l = 1,r = 2;
    for(;r <= n;)
    {
        if(a[r] > a[l])
            vis[l] = 1,r++,l++;
        else r++;
    }
    for(int i = 1;i <= n;i++)
    {/*cout << vis[i] << " ";*/
        if(vis[i]) cnt++;}
    cout << n -cnt << endl;
    return 0;
}













/*
int main()
{
   // freopen("duel.in","r",stdin);
   // freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    int j,i;
    i = j = 1;
    for(;i <= n;i++)
    {
        if(a[i]== -1 || a[j] == -1) continue;
        if(j > n || i > n) break;
        for(;j <= n;j++)
            if(a[i] > a[j]) break;
        //cout << i << " " << j << endl;
        if(a[i] > a[j])a[j] = -1,j++;

    }
    for(int i = 1;i <= n;i++)
    {cout << a[i] << " ";
        if(a[i] != -1) cnt++;}
    cout << cnt << endl;

    return 0;
}
*/
