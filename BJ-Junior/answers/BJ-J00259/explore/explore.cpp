#include<iostream>
using namespace std;
int Tn;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> Tn;
    while(Tn--){
        int n,m,k,x,y,d,wx,wy,ans=0;
        cin >> n>> m >> k >> x >> y >> d;
        char Map[n+1][m+1];
        bool bMap[n+1][m+1];
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin >> Map[i][j],bMap[i][j]=false;
        for(int i=0;i<k;i++){
            bMap[x][y]=true;
            wx=x,wy=y;
            if(d==0)wy++;
            if(d==1)wx++;
            if(d==2)wy--;
            if(d==3)wx--;
            if((1<=wx && wx<=n) && (1<=wy && wy<=m) && (Map[wx][wy]=='.'))x=wx,y=wy;
            else d=(d+1)%4;
        }
        bMap[x][y]=true;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(bMap[i][j])ans++;
        cout << ans << endl;
    }
    return 0;
}
