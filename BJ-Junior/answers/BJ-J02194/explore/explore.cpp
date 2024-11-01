#include<iostream>
using namespace std;
int a[1005][1005],visit[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                char c;
                cin>>c;
                if(c=='x'){
                    a[j][p]=1;
                }else{
                    a[j][p]=0;
                }
            }
        }
        int sum=1;
        visit[x][y]=1;
        for(int j=0;j<k;j++){
            if(d==0){
                y++;
                if(y>m||a[x][y]!=0){
                    y--;
                    d++;
                    continue;
                }else{
                    if(!visit[x][y]){
                        visit[x][y]=!visit[x][y];
                        sum++;
                    }
                }
            }
            if(d==1){
                x++;
                if(x>n||a[x][y]!=0){
                    x--;
                    d++;
                    continue;
                }else{
                    if(!visit[x][y]){
                        visit[x][y]=!visit[x][y];
                        sum++;
                    }
                }
            }
            if(d==2){
                y--;
                if(y==0||a[x][y]!=0){
                    y++;
                    d++;
                    continue;
                }else{
                    if(!visit[x][y]){
                        visit[x][y]=!visit[x][y];
                        sum++;
                    }
                }
            }
            if(d==3){
                x--;
                if(x==0||a[x][y]!=0){
                    x++;
                    d=0;
                    continue;
                }else{
                    if(!visit[x][y]){
                        visit[x][y]=!visit[x][y];
                        sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                visit[j][p]=0;
            }
        }
    }
    return 0;
}