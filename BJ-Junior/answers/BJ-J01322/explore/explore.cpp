#include <iostream>

using namespace std;
int map[1010][1010]={0};
int walked[1010][1010]={0};
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
int m,n,k,ans=1,a,b,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=1;
        cin>>n>>m>>k;
        cin>>a>>b>>d;
        for(int j=1;j<=n;j++)
        {
            for(int q=1;q<=m;q++)
            {
                char s;
                cin>>s;
                if(s=='x') map[j][q]=1;
            }
        }
        for(int j=1;j<=m;j++)
            map[0][j]=1;
        for(int j=1;j<=m;j++)
            map[n+1][j]=1;
        for(int j=1;j<=n;j++)
            map[j][0]=1;
        for(int j=1;j<=n;j++)
            map[j][m+1]=1;

        for(int j=1;j<=k;j++)
        {
            if(map[a+x[d]][b+y[d]]==1) d=(d+1)%4;
            else if(map[a+x[d]][b+y[d]]==0){
                a=a+x[d];
                b=b+y[d];
                walked[a][b]++;
                if(walked[a][b]==1) ans++;
            }
        }

        cout<<ans<<endl;
        for(int j=0;j<=n;j++)
        {
            for(int q=0;q<=m;q++)
            {
                map[j][q]=0;
                walked[j][q]=0;
            }
        }
    }
    return 0;
}
