#include<bits/stdc++.h>
using namespace std;
char a[60][3];
bool vis[60];
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int cnt = n;
    for(int i = 1;i <= n;i++) cin>>a[i][1]>>a[i][2];
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            if(a[i][1] == a[j][1] && a[i][2] == a[j][2] && !vis[j])
            {
                cnt--;
                vis[j] = true;
            }
        }
    }
    cout<<52 - cnt<<endl;
    return 0;
}
