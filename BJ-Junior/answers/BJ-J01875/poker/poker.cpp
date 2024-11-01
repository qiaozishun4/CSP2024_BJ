#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n,cnt;
int a[150][150];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        char x,y;
        cin>>x>>y;
        a[x][y]=1;
    }

    for(int i=1; i<=150; i++)
        for(int j=1; j<=150; j++)
            if(a[i][j]==1)
                cnt++;
    cout<<52-cnt;
    
    return 0;
}