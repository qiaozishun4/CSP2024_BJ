#include<bits/stdc++.h>
using namespace std;

int a[100010],n;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cnt=n,cur=1;
    for(int i=2;i<=n;i++)
    {
        int pos=a[cur];
        if(a[i]>pos)
        {
            cnt--;
            cur++;
        }
    }
    cout << cnt << endl;
    return 0;
}
