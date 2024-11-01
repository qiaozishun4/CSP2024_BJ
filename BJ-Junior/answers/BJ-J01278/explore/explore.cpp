#include<iostream>
using namespace std;
int t,n,m,k,x,y,d,stm=1;
char map[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
            }
        }
        for(int i=0;i<k;i++)
        {

            if(d==0&&x>=0&&y>=0&&x<=n&&y<=m)
            {
                if(map[x][y+1]!='x')
                {
                    stm++;
                    y+=1;
                }
                else
                    d++;
            }
            else if(d==1&&x>=0&&y>=0&&x<=n&&y<=m)
            {
                if(map[x+1][y]!='x')
                {
                    stm++;
                    x+=1;
                }
                else
                    d++;
            }
            else if(d==2&&x>=0&&y>=0&&x<=n&&y<=m)
            {
                if(map[x][y-1]!='x')
                {
                    y-=1;
                    stm++;
                }
                else
                    d++;
            }
            else if(d==3&&x>=0&&y>=0&&x<=n&&y<=m)
            {
                if(map[x-1][y]!='x')
                {
                    x-=1;
                    stm++;
                }
                else
                    d=0;
            }

        }
        cout<<stm<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
