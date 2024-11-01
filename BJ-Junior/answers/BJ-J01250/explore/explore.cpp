#include<iostream>
#include<cstdio>
using namespace std;
char a[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        bool b[1010][1010]={};
//        cout<<"2"<<endl;
        int dx[4]={},dy[4]={};
        dx[0]=0;
        dy[0]=1;
        dx[1]=1;
        dy[1]=0;
        dx[2]=0;
        dy[2]=-1;
        dx[3]=-1;
        dy[3]=0;
        int cnt=0;
        b[x][y]=true;
        for(int i=1;i<=k;i++){
            int x1=x+dx[d],y1=y+dy[d];
            if(x1>0&&x1<=n&&y1>0&&y1<=m){
                if(a[x1][y1]=='.'){
                    x=x1;
                    y=y1;
                    b[x1][y1]=true;
                }else{
                    d=(d+1)%4;
                }
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==true){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
