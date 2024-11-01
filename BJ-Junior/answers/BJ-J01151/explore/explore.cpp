#import<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t,n,m,k,x,y,d,ans;
long long a[N][N],c[N][N];
int cxx[4]={0,1,0,-1};
int cxy[4]={1,0,-1,0};
string s;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        a[x][y]=1;
        for(int j=1;j<=n;j++)
        {
            for(int q=1;q<=m;q++)
            {
                cin>>s[q];
                if(s[q]=='x')
                    c[j][q]=1;
            }

        }
        for(int j=1;j<=n;j++)
        {
            c[j][m+1]=1;
            c[j][0]=1;
        }
        for(int j=0;j<=m+1;j++)
        {
            c[0][j]=1;
            c[n+1][j]=1;
        }
        for(int j=0;j<k;j++)
        {
            if(c[x+cxx[d]][y+cxy[d]]==1)
                d=(d+1)%4;
            else
            {
                x+=cxx[d];
                y+=cxy[d];
                a[x][y]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                    ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
         for(int j=0;j<=n+1;j++)
        {
            for(int q=0;q<=m+1;q++)
            {
                a[j][q]=0;
                c[j][q]=0;
            }
        }
        s="";
    }
    return 0;
}
