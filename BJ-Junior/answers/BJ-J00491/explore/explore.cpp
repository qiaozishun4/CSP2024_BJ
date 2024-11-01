#include <iostream>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int i =1 ;i<= T;i++)
    {
        int n,m,k;
        cin >> n>>m>>k;
        int x,y,d;
        cin >> x>> y>> d;
        int a[1006][1006];//空地>=1；障碍=0
        for(int i = 1;i<= n;i++)
        {
            for(int j = 1;j<= m;j++)
            {
                char tp;cin >> tp;
                if(tp=='.')a[i][j]=1;
                else if(tp=='x')a[i][j]=0;
            }
        }
        a[x][y]++;
        int ans = 1;
        int tx = x+dx[d];
        int ty = y+dy[d];
        for(int i =1;i<= k;i++)
        {
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty])
            {
                x= tx;y=ty;
                if(a[x][y]==1){ans++;a[x][y]++;}
            }
            else
            {
                d=(d+1)%4;
            }
            tx = x+dx[d];ty = y+dy[d];

        }
        cout << ans<<endl;
    }

    return 0;
}