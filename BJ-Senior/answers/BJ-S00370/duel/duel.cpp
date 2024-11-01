#include <iostream>
#include <algorithm>

#include <map>
#define int long long
using namespace std;
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int ashuzu[100005]={};
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> ashuzu[i];

    }
    sort(ashuzu,ashuzu+n);
    int now_lisanhua=0;
    map <int,int> lisanhua_duiying_map;
    // 2->1 3->2 7->3
    map <int,int> tong;
    for (int i=0;i<n;i++)
    {
        int tmp=ashuzu[i];
        if(lisanhua_duiying_map[tmp]==0)
        {
            now_lisanhua++;
            lisanhua_duiying_map[tmp]=now_lisanhua;
            tong[now_lisanhua]++;
        }
        else
        {
            tong[lisanhua_duiying_map[tmp]]++;
        }
    }

    int ans=n;
    //ans-=tong[now_lisanhua];
    for (int i=2;i<=now_lisanhua;i++)
    {

        int weishiyong=tong[i];

        for (int j=i-1;j>=1&&weishiyong!=0;j--)
        {

            if(weishiyong==0)
            {

                break;
            }
            if(tong[j]>weishiyong)
            {
                ans-=weishiyong;
                tong[j]-=weishiyong;
                weishiyong=0;
            }
            else
            {
                int cha=weishiyong-tong[j];
                ans-=tong[j];
                weishiyong-=tong[j];
                tong[j]=0;
            }

        }
    }
    cout << ans << endl;
}