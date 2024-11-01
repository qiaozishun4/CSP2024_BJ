#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
//bool sh[1001][1001]={0}
int j[5][5]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
    int T,ans=1;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int gdhsj=1;gdhsj<=T;gdhsj++){
        ans=1;

        int n,m,k,x,y,c;
        bool sh[1001][1001]={0};


        cin>>n>>m>>k;
        cin>>x>>y>>c;
        sh[x][y]=true;
        for(int i=1;i<=n;i++){
            cin>>a[i]+1;
        }

        for(int i=1;i<=k;i++){
//      	bool ok=false;



            int x1=j[c][0]+x,y1=j[c][1]+y;
            if(x1<=n&&x1>=1&&y1<=m&&y1>=1&&a[x1][y1]=='.'){
              //  ok=true;
                x=x1;
                y=y1;

                if(!sh[x1][y1]){
                    ans++;
                }
                sh[x][y]=true;
            }else{
                c++;
                c=c%4;

            }







        }

        cout<<ans<<endl;
    }
}
