#include <iostream>
using namespace std;

bool a[5][20];
int main ()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        char hua,shu;
        int x,y;
        cin >> hua >> shu;

        if(hua=='D')x=1;
        if(hua=='C')x=2;
        if(hua=='H')x=3;
        if(hua=='S')x=4;

        if(shu=='A')y=1;
        if(shu>='2'&&shu<='9')y=shu-'0';
        if(shu=='T')y=10;
        if(shu=='J')y=11;
        if(shu=='Q')y=12;
        if(shu=='K')y=13;

        a[x][y]=true;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==false)ans++;
        }
    }
    cout << ans;
}
