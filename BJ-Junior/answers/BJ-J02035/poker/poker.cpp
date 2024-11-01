#include<bits/stdc++.h>
using namespace std;
bool mark[53];
char c[14]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n, i, m, j;
    string a;
    cin>> n;
    for(i=1;i<=n;i++)
    {
        cin>> a;
        for(j=1;j<=13;j++)
        {
            if(a[1]==c[j])
            {
                m=j;
                break;
            }
        }
        if(a[0]=='C')
        {
            m+=13;
        }
        if(a[0]=='H')
        {
            m+=26;
        }
        if(a[0]=='S')
        {
            m+=39;
        }
        mark[m]=1;
    }
    m=52;
    for(i=1;i<=52;i++)
    {
        if(mark[i])
        {
            m--;
        }
    }
    cout<< m;
    return 0;
}