#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char hs[57];
char sz[57];
bool pock[9][80];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i= 1;i<=4;i++)
    {
        for(int j = 1;j <= 80;j++) pock[i][j] = false;
    }
    int n;
    cin >>n;
    for(int i= 1;i <= n;i++)
    {
        cin>>hs[i];
        cin>>sz[i];
        if(hs[i] == 'D')
        {
            pock[1][int(sz[i])] = true;
        }
        if(hs[i] == 'C')
        {
            pock[2][int(sz[i])] = true;
        }
        if(hs[i] == 'H')
        {
            pock[3][int(sz[i])] = true;
        }
        if(hs[i] == 'S')
        {
            pock[4][int(sz[i])] = true;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(j == 10)
            {
                if(pock[i][int('T')] == true) cnt++;
                continue;
            }
            if(j == 11)
            {
                if(pock[i][int('J')] == true) cnt++;
                continue;
            }
            if(j == 12)
            {
                if(pock[i][int('Q')] == true) cnt++;
                continue;
            }
            if(j == 13)
            {
                if(pock[i][int('K')] == true) cnt++;
                continue;
            }
            if(j == 1)
            {
                if(pock[i][int('A')] == true) cnt++;
                continue;
            }
            if(pock[i][j] == true) cnt++;
        }
    }
    cout <<52-cnt<<endl;
    return 0;
}
