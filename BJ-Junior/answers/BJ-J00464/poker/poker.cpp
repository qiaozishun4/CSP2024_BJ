#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s,h;
}a[100];
bool cmp(node x,node y)
{
    if(x.h != y.h)return x.h < y.h;
    return x.s < y.s;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "51";
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        char x,y;
        cin >> y >> x;
        if(x >= '2' && x <= '9')
            a[i].s = x - '0';
        else if(x == 'A')
            a[i].s = 1;
        else if(x == 'T')
            a[i].s = 10;
        else if(x == 'J')
            a[i].s = 11;
        else if(x == 'Q')
            a[i].s = 12;
        else
            a[i].s = 13;
        if(y == 'D')a[i].h = 1;
        else if(y == 'C')a[i].h = 2;
        else if(y == 'H')a[i].h = 3;
        else a[i].h = 4;
    }
    sort(a+1,a+n+1,cmp);
    int ans = 52-n;
    for(int i = 1;i <= n;i++)
    {
        if(a[i].h == a[i-1].h && a[i].s == a[i-1].s)
            ans++;
    }
    cout << ans;
    return 0;
}
