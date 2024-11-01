#include<iostream>
#include<cstdio>
using namespace std;
char r[1010][1010];
int f[1010][1010]={0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int s,n,m,k,x,y,d,sum=1;
    cin>>s;
    for(int i=0;i<s;i++){
        sum=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>r[j][l];
                f[j][l]=0;
            }
        }
//d = 0 代表向东，d = 1 代表向南，d = 2 代表向西，d = 3 代表向北
//若 d = 0，则令 (x ′ , y ′ ) = (x, y + 1)，若 d = 1，则令
//(x ′ , y ′ ) = (x + 1, y)，若 d = 2，则令 (x ′ , y ′ ) = (x, y − 1)，若 d = 3，则令
//(x ′ , y ′ ) = (x − 1, y)
        for(int j=0;j<k;j++){
            if(f[x][y]==0){
                sum++;
                f[x][y]=1;
            }
            if(d==0){
                if(r[x][y+1]=='.' && x<=n&&y+1<=m&&x>=1&&y+1>=1)y+=1;
                else d=1;
            }
            else if(d==1){
                if(r[x+1][y]=='.' && x+1<=n&&y<=m&&x+1>=1&&y>=1)x+=1;
                else d=2;
            }
            else if(d==2){
                if(r[x][y-1]=='.' && x<=n&&y-1<=m&&x>=1&&y-1>=1)y-=1;
                else d=3;
            }
            else if(d==3){
                if(r[x-1][y]=='.' && x-1<=n&&y<=m&&x-1>=1&&y>=1)x-=1;
                else d=0;
            }
            if(f[x][y]==0){
                sum++;
                f[x][y]=1;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
