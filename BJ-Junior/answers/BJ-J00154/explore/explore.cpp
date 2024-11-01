#include<bits/stdc++.h>
using namespace std;
int a[5][3];
char c[10001][10001];
int n,m,t,k,x,y,d;
bool gt(){
    if(c[x+a[d][1]][y+a[d][2]]!='x'&&x+a[d][1]<=n&&y+a[d][2]<=m&&x+a[d][1]>=1&&y+a[d][2]>=1)
        return true;
    else
        return false;
}
void go(){
    if(gt()){
        x+=a[d][1];
        y+=a[d][2];
        return;
    }else{
        d=(d+1)%4;
        return;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int i,num=0;
    a[0][2]=1;
    a[1][1]=1;
    a[2][2]=-1;
    a[3][1]=-1;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>c[j][l];
            }
        }
        c[x][y]='#';
        for(int j=1;j<=k;j++){
            go();
            c[x][y]='#';
        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(c[j][l]=='#')num++;
            }
        }
        cout<<num<<endl;
        num=0;
    }
    return 0;
}