#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,m,l,V;
int ans;
struct car
{
    int d,v,a;

};
car ec[100005];
int p[100005];
bool must[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    int x,y,z;
    while(t--)
    {
        cin >> n >> m >> l >> V;
        ans = n;
        for(int i = 1;i <= n;i++)
        {
            cin >> x >> y >> z;
            ec[i].d = x;
            ec[i].v = y;
            ec[i].a = z;
        }
        for(int i = 1;i <= m;i++)
            cin >> p[i];
        for(int i = 1;i <= n;i++)
        {
            if(ec[i].a == 0 && ec[i].v <= V)ans--;
         //   else if(car[i].a == 0 && car[i].v > V)
        //    {
        //for(int j = 1;j <= m;j++)
                    //if(car[i].d > p[j]]
           //         {
                       // cnt++;
                      //  must[j] = 1;
                   // }
           // }
        }
    }
    cout << ans <<" " <<ans;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
