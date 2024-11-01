#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000];
bool vis[1000000];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int cnt = n;
    for(int i = 2;i<=n;i++)
    {
        if(vis[i] == 1)continue;
        for(int j = i-1;j>=1;j--)
        {
            if(a[i]>a[j]&&vis[j]!=1)
            {
                vis[j] = 1;
                cnt--;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
