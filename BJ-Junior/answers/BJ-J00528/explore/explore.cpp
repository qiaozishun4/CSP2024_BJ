#include<bits/stdc++.h>
using namespace std;
struct ground{
    int state=false;//初始状态
    int ground=false;
};
const int OA=1000;
vector<vector<ground> > a(OA,vector<ground>(OA));
int main(){
    int t;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w+",stdout);
    cin>>t;
    for(int timesp=0;timesp<t;timesp++){
        int n,m,k,x,y,d,cmp=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
        string chizu;//chizu是地图
        cin>>chizu;
            for(int j=1;j<=m;j++){
                a[i][j].ground=chizu[j]+0==46?1:0;
            }
        }
        a[x][y].state=true;
        cmp++;
        while(k<=0){
            int prey,prex;
            for(int qwe=1;qwe<=2;qwe++){
                if(d==0){
                    y++;
                }else if(d==1){
                    x++;
                }else if(d==2){
                    y--;
                }else if(d==3){
                    x--;
                }
                if(a[x][y].ground==true;a[x][y].state==false&&qwe==1){
                    a[x][y].state=true;
                    cmp++;
                    prex=x;
                    prey=y;
                }
                if(x>n||x<1||y>m||y<1||a[x][y].ground==false){
                    if(qwe==2){
                        d=(d+1)%4;
                    }
                }
            }
            x=prex;
            y=prey;
        }
        cout<<cmp<<endl;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
