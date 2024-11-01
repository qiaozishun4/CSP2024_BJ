#include <iostream>
#include <string>
using namespace std;
int n;
string s;
bool f[10][20];
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        char a=s[0];
        char b=s[1];
        int temp;
        if(b=='A')
        {
            temp=1;
        }
        else if(b=='T')
        {
            temp=10;
        }
        else if(b=='J')
        {
            temp=11;
        }
        else if(b=='Q')
        {
            temp=12;
        }
        else if(b=='K')
        {
            temp=13;
        }
        else
        {
            temp=b-'0';
        }
        if(a=='D')
        {
            f[1][temp]=1;
        }
        else if(a=='C')
        {
            f[2][temp]=1;
        }
        else if(a=='H')
        {
            f[3][temp]=1;
        }
        else if(a=='s')
        {
            f[4][temp]=1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!f[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
