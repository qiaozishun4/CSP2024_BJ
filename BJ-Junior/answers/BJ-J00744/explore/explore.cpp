#include <iostream>
#include <cstdio>
using namespace std;
int q,n,m,k,x,y,d,cnt;
char t;
int mymap[1005][1005],box[1005][1005];//map to explore
int changex[4]={0,1,0,-1},changey[4]={1,0,-1,0};//the changes to x and y depending on d
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        box[x][y]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>t;
                if (t=='.')mymap[i][j]=1;//go
                if (t=='x')mymap[i][j]=0;//don't go

            }
        }
        for (int i=1;i<=k;i++)
        {
            int x_=x+changex[d],y_=y+changey[d];//the changes to x and y depending on d
            if (mymap[x_][y_]==1&&x_>=1&&x_<=n&&y_>=1&&y_<=m)//if you can go to the position of the next x and y
            {
                x=x_;
                y=y_;//then go
                box[x][y]=1;
                //cout<<"i="<<i<<" d="<<d<<" x_="<<x_<<" y_="<<y_<<" box["<<x<<"]["<<y<<"]="<<box[x][y]<<endl;
            }
            else //if you can't
            {
                d=(d+1)%4;//turn right
                //cout<<"i="<<i<<" d="<<d<<" x_="<<x_<<" y_="<<y_<<endl;
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (box[i][j]==1)cnt++;
            }
        }
        cout<<cnt<<endl;
        cnt=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                box[i][j]=0;
            }
        }
    }

    return 0;
}
