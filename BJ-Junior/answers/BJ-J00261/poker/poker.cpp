#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[4][13] = {};
    int n;
    cin>>n;
    string s;
    for(int i = 0;i<n;i++)
    {
        cin>>s;
        int x,y;
        if(s[0] == 'D')
            x = 0;
        else if(s[0] == 'C')
            x = 1;
        else if(s[0] == 'H')
            x = 2;
        else if(s[0] == 'S')
            x = 3;
        if(s[1] == 'A')
            y = 0;
        else if(s[1] == 'T')
            y = 9;
        else if(s[1] == 'J')
            y = 10;
        else if(s[1] == 'Q')
            y = 11;
        else if(s[1] == 'K')
            y = 12;
        else
            y = (s[1]-'0')-1;
        a[x][y] = 1;
    }
    int sum = 0;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<13;j++)
        {
            if(!a[i][j])
                sum++;
        }
    }
    cout<<sum;
    return 0;
}