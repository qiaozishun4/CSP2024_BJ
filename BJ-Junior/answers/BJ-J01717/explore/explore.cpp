#include<iostream>
using namespace std;
char mapp[1010][1010];
int num[5][1010][1010];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin>>t;
    for(int c=0;c<t;c++)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapp[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            num[c][x][y]=1;
            int x1=x,y1=y;
            if(d==0) y1++;
            else if(d==1) x1++;
            else if(d==2) y1--;
            else if(d==3) x1--;
            int f=0;
            if(1<=x1&&x1<=n&&1<=y1&&y1<=m){
                if(mapp[x1][y1]=='.'){
                    f=1;
                    x=x1,y=y1;
                }
            }
            if(!f){
                d++;
                if(d==4)
                    d=0;
            }
            //cout<<x1<<" "<<y1<<endl;
        }
        num[c][x][y]=1;
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                //cout<<num[i][j];
                if(num[c][i][j])
                    sum++;
        cout<<sum<<endl;
    }
    return 0;
}

