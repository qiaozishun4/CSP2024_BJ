#include <iostream>
#include <set>
using namespace std;
constexpr int N=1e3+5,M=N;
bool ava[N][M];
struct Point
{
    int x,y;
    bool operator<(const Point& other) const
    {
        if (x==other.x)
        {
            return y<other.y;
        }
        else
        {
            return x<other.x;
        }
    }
};
set<Point> s;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if (c=='.')
                {
                    ava[i][j]=true;
                }
                else
                {
                    ava[i][j]=false;
                }
            }

        }
        s.clear();
        s.insert({x,y});
        for (int i=1;i<=k;i++)
        {
            int xp=x,yp=y;
            switch (d)
            {
            case 0:
                yp++;
                break;
            case 1:
                xp++;
                break;
            case 2:
                yp--;
                break;
            case 3:
                xp--;
                break;
            default:
                break;
            }
            if (!(1<=xp&&xp<=n)||!(1<=yp&&yp<=m)||!ava[xp][yp])
            {
                d++;
                if (d==4)
                {
                    d=0;
                }
            }
            else
            {
                x=xp;
                y=yp;
                s.insert({x,y});
            }
            //cout<<x<<" "<<y<<" "<<d<<endl;
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
