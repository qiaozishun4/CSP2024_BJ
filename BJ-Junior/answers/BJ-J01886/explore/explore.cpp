#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
int p,a,b;
char ma[N][N];
int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int xd(int x,int y,int f,int b,int sum){
    for(int i=1;i<=4;i++){
        if(b==0){
            return sum;
        }
        else if(x+d[f][1]>=1&&x+d[f][1]<=a&&y+d[f][2]>=1&&y+d[f][2]<=b&&ma[x+d[f][1]][y+d[f][2]]=='.'){
            xd(x+d[f][1],y+d[f][2],f,b--,sum++);
        }
        else {
            f++;
            b--;
        }
    }
    return sum;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>p;
    for(int i=1;i<=p;i++){
        int c,f,sum=0,x,y;
        cin>>a>>b>>c;
        cin>>x>>y>>f;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cin>>ma[i][j];
            }
        }
        cout<<xd(x,y,f,c,sum)+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

