#include<bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool box[1005][1005];
int n,m,k;

bool in(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(box,false,sizeof(box));
        int xs,ys,ds;
        int sum=0;
        cin >> n >> m >> k;
        cin >> xs >> ys >> ds;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cin >> a[i][j];
        for (int i=0;i<=k;i++)
        {
            if (!box[xs][ys])
            {
                box[xs][ys]=true;
                sum++;
                //cout << "***" << i << " " << sum << endl;
            }
            int nx,ny;
            if (ds==0)
            {
                nx=xs,ny=ys+1;
                if (in(nx,ny) && a[nx][ny]!='x') xs=nx,ys=ny;
                else ds=1;
            }
            else if (ds==1)
            {
                nx=xs+1,ny=ys;
                if (in(nx,ny) && a[nx][ny]!='x') xs=nx,ys=ny;
                else ds=2;
            }
            else if (ds==2)
            {
                nx=xs,ny=ys-1;
                if (in(nx,ny) && a[nx][ny]!='x') xs=nx,ys=ny;
                else ds=3;
            }
            else
            {
                nx=xs-1,ny=ys;
                if (in(nx,ny) && a[nx][ny]!='x') xs=nx,ys=ny;
                else ds=0;
            }
            //cout << "&&&" << xs << " " << ys << endl;
        }
        cout << sum << endl;
    }

    return 0;
}
