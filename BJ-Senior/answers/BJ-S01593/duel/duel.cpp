#include<bits/stdc++.h>
using namespace std;
int n;
int r[100001],minn;
bool a,c[100001];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> r[i];
    }
    sort(r+1,r+n+1);
    for (int i = 1;i <= n;i++)
    {
       a = true;
       for (int j = i + 1;j <= n;j++)
       {
           if (r[j] > r[i] && !c[j])
           {
               n--;
               a = false;
               c[j] = true;
               break;
           }
       }
       if (a)
       {
           break;
       }
    }
    cout << n;
    return 0;
}
