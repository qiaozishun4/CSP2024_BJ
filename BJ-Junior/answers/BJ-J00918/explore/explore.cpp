#include<cstdio>
#include<utility>
#include<set>
using namespace std;
const int N=1e3+5;
bool mp[N][N];
int n,m,k;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        set<pair<int,int> > st;
        int x,y,d;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++)
        {
            getchar();
            for(int j=1;j<=m;j++)
            {
                char c=getchar();
                while(c!='x'&&c!='.') c=getchar();
                if(c=='x') mp[i][j]=false;
                else mp[i][j]=true;
            }
        }
        int stp=0;
        st.insert(make_pair(x,y));
        while(true)
        {
            if(stp==k) break;
            int nextx=0,nexty=0;
            if(d==0)
            {
                nextx=x;
                nexty=y+1;
            }
            else if(d==1)
            {
                nextx=x+1;
                nexty=y;
            }
            else if(d==2)
            {
                nextx=x;
                nexty=y-1;
            }
            else
            {
                nextx=x-1;
                nexty=y;
            }
            if(nextx<1||nextx>n||nexty<1||nexty>m||mp[nextx][nexty]==false)
            {
                ++stp;
                d=(d+1)%4;
                continue;
            }
            x=nextx;
            y=nexty;
            st.insert(make_pair(x,y));
            ++stp;
        }
        printf("%d\n",st.size());
    }
    return 0;
}