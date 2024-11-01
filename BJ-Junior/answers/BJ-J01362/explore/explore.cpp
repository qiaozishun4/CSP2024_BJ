#include <bits/stdc++.h>

using namespace std;
bool a[2000][2000];
bool b[2000][2000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void Main0(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            b[i][j+1]=(s[j]=='x');
        }
        b[i][0]=1;
        b[i][m+1]=1;
    }
    for(int j=1;j<=m;j++){
        b[0][j]=1;
        b[n+1][j]=1;
    }
    a[x][y]=1;/*
        for(int i=1;i<=n;i++){//
            for(int j=1;j<=m;j++){
                if(i==x&&j==y)cout<<'!';
                else cout<<b[i][j];
            }
            cout<<endl;
        }//
        cout<<endl;//
        */
    int ans=1;
    for(int i=1;i<=k;i++){
        if(b[x+dx[d]][y+dy[d]]){
            d=(d+1)%4;
        }else{
            x+=dx[d];
            y+=dy[d];
        }
        if(!a[x][y])ans++;
        a[x][y]=1;


    }
    cout<<ans<<endl;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    while(t--)Main0();
    return 0;
}
