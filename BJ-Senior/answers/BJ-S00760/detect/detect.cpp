#include <bits/stdc++.h>
using namespace std;
struct car{
    int di,vi,ai;
}a[100005];
int p[100005],ispuse[1000005];
bool ispthere(int x,int m)
{
    for (int i = 1; i <= m; i++)
        if (p[i] == x)
        {
            ispuse[p[i]] = 1;
            return true;
        }
    return false;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,v,i,outspeed_cnt=0,j,temp_ans=0;
    int temp_pos,temp_speed,temp_addspeed;
    cin >> t;
    while (t--)
    {
        cin>>n>>m>>l>>v;
        for (i = 1; i <= n; i++)
            cin>>a[i].di>>a[i].vi>>a[i].ai;
        for (i = 1; i <= m; i++)
            cin >> p[i];
        for (i = 1; i <= n; i++)
        {
            temp_pos=a[i].di,temp_speed=a[i].vi,temp_addspeed=a[i].ai;
            for (j = temp_pos; j <= l; j++)
                if (temp_speed+(j-temp_pos)*temp_addspeed>v && ispthere(j,m))
                {
                    outspeed_cnt++;
                    break;
                }
        }
        cout << outspeed_cnt << " ";
        for (i = 1; i <= 10000; i++)
            if (ispuse[i] == 1)
                temp_ans++;
        cout << temp_ans << "\n";
    }
    return 0;
}