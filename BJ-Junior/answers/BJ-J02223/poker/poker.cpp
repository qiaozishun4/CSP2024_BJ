#include <iostream>
#include <string>
using namespace std;
int n, po[6][15], sum;
string Gs;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; ++i)
    {
        cin >> Gs;
        if(Gs[0]=='D')
        {
            if(Gs[1]=='A')
                po[1][1]=1;
            else if(Gs[1]=='T')
                po[1][10]=1;
            else if(Gs[1]=='J')
                po[1][11]=1;
            else if(Gs[1]=='Q')
                po[1][12]=1;
            else if(Gs[1]=='K')
                po[1][13]=1;
            else
                po[1][int(Gs[1])-48]=1;
        }
        else if(Gs[0]=='C')
        {
            if(Gs[1]=='A')
                po[2][1]=1;
            else if(Gs[1]=='T')
                po[2][10]=1;
            else if(Gs[1]=='J')
                po[2][11]=1;
            else if(Gs[1]=='Q')
                po[2][12]=1;
            else if(Gs[1]=='K')
                po[2][13]=1;
            else
                po[2][int(Gs[1])-48]=1;
        }
        else if(Gs[0]=='H')
        {
            if(Gs[1]=='A')
                po[3][1]=1;
            else if(Gs[1]=='T')
                po[3][10]=1;
            else if(Gs[1]=='J')
                po[3][11]=1;
            else if(Gs[1]=='Q')
                po[3][12]=1;
            else if(Gs[1]=='K')
                po[3][13]=1;
            else
                po[3][int(Gs[1])-48]=1;
        }
        else
        {
            if(Gs[1]=='A')
                po[4][1]=1;
            else if(Gs[1]=='T')
                po[4][10]=1;
            else if(Gs[1]=='J')
                po[4][11]=1;
            else if(Gs[1]=='Q')
                po[4][12]=1;
            else if(Gs[1]=='K')
                po[4][13]=1;
            else
                po[4][int(Gs[1])-48]=1;
        }
    }
    for (int i=1; i<=4; ++i)
    {
        for (int j=1; j<=13; ++j)
        {
            if(po[i][j])
            {
                ++sum;
            }
        }
    }
    cout << 52-sum;
    return 0;
}
