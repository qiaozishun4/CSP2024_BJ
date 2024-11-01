#include<bits/stdc++.h>
using namespace std;
int abc(){
    int n,m,k,x,y,d,sum=1,x1[100010],y1[100010];
    string xy[100010];
    bool f;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=0;i<n;i++){
        cin>>xy[i];
    }
    for(int i=0;i<k;i++){
        f=1;
        x1[i]=x,y1[i]=y;
        if(d==0&&y+1>=m||d==1&&x+1>=n||d==2&&y-1<=0||d==3&&x-1<=0||d==0&&xy[x][y+1]=='x'||d==1&&xy[x+1][y]=='x'||d==2&&xy[x][y-1]=='x'||d==3&&xy[x-1][y]=='x'){
            d++;
            f=0;
        }else if(d==0){
            y++;
            if(x==x1[i]&&y==y1[i]){
                f=0;
            }
        }else if(d==1){
            x++;
            if(x==x1[i]&&y==y1[i]){
                f=0;
            }
        }else if(d==2){
            y--;
            if(x==x1[i]&&y==y1[i]){
                f=0;
            }
        }else if(d==3){
            x--;
            if(x==x1[i]&&y==y1[i]){
                f=0;
            }
        }
        if(f){
            sum++;
        }
    }
    return sum;

}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<abc()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
