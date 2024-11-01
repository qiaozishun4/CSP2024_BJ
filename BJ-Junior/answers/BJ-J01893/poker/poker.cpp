#include <iostream>
using namespace std;
int n,hs,num,ans;
string pc;
bool a[5][14];
int main ()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> pc;
        if (pc[0]=='D')
        {
            hs=1;
        }
        else if (pc[0]=='C')
        {
            hs=2;
        }
        else if (pc[0]=='H')
        {
            hs=3;
        }
        else
        {
            hs=4;
        }
        if (pc[1]>='2'&&pc[1]<='9')
        {
            num=pc[1]-'0';
        }
        else if (pc[1]=='A')
        {
            num=1;
        }
        else if (pc[1]=='T')
        {
            num=10;
        }
        else if (pc[1]=='J')
        {
            num=11;
        }
        else if (pc[1]=='Q')
        {
            num=12;
        }
        else
        {
            num=13;
        }
        a[hs][num]=true;
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=13;j++)
        {
            if (!a[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
