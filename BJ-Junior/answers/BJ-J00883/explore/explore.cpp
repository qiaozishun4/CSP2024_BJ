#include<iostream>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,ans[100001],k=0;
    cin>>t;
    int t1=t;
    while(t--){
        int n,m,x0,y0,d,k,x,y;
        cin>>n>>m>>k>>x0>>y0>>d;
        char ma[100001][100001];
        int bj[100001][100001]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 cin>>ma[i][j];
            }
        }
        x=x0;
        y=y0;
        while(k--){
            d%=5;
            bj[x][y]++;
            int x1=x,y1=y;
            if(!d) y1+=1;
            if(d==1) x1+=1;
            if(d==2) y1-=1;
            if(d==4) x1-=1;
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&ma[x1][y1]=='.'){
                x=x1;
                y=y1;
                bj[x][y]++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(bj[i][j]) ans[k]++;
            }
        }
        k++;
    }

    for(int i=0;i<t1;i++){
        cout<<ans[k]<<endl;
    }
    //fclose("explore.in");
    //fclose("explore.out");
    return 0;
}
