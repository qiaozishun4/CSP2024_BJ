#include<iostream>
using namespace std;
int T,n,m,k;
int x1,y1,d1;
string a[1010];
bool s[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x1>>y1>>d1;
        y1--;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=k;i++){
            s[x1][y1]=1;
            int xx=x1+dx[d1];
            int yy=y1+dy[d1];
            while(a[xx][yy]=='x'||xx<=0||xx>n||yy<0||yy>=m){
                d1=(d1+1)%4;
                xx=x1+dx[d1];
                yy=y1+dy[d1];
                i++;

            }
            x1=xx;
            y1=yy;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]==1){
                    sum++;
                    s[i][j]=0;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
