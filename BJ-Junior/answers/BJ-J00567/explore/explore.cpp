#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore","r",stdin);
    freopen("explore","w",stdout);
    int a;
    cin>>a;
    int n,m,k,x,y,d;
    for(int i=0;i<n;i++)
    {
        int sum=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char b[n][m];
        cin>>b;
        for(int j=0;j<k;j++)
        {
            if(d%4==0&&b[x][y+1]=='.')
            {
                y++;
                sum++;
            }
            if(d%4==1&&b[x+1][y]=='.')
            {
                x++;
                sum++;
            }
            if(d%4==2&&b[x][y-1]=='.')
            {
                y--;
                sum++;
            }
            if(d%4==3&&b[x-1][y]=='.')
            {
                x--;
                sum++;
            }
            else
            {
                d++;
            }
        }
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
