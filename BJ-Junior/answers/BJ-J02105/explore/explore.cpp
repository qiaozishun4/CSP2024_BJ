#include<bits/stdc++.h>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
int main1(){
    long long a,c,d,e,f,g,h,i=1,n,m,k,x,y;
    fin>>n>>m>>k;
    char b[n+2][m+2];
    bool tong[n+2][m+2];
    int fx[5][3];
    fx[0][1]=0;fx[0][2]=1;
    fx[1][1]=1;fx[1][2]=0;
    fx[2][1]=0;fx[2][2]=-1;
    fx[3][1]=-1;fx[3][2]=0;
    fin>>x>>y>>d;
    tong[x][y]=1;
    for(a=1;a<=n;a++){
        for(c=1;c<=m;c++){
            fin>>b[a][c];
        }
        b[a][0]='x';
        b[a][m+1]='x';
    }
    for(a=0;a<=m+1;a++){
        b[0][a]='x';
        b[n+1][a]='x';
    }
    for(a=1;a<=k;a++){
        if(b[x+fx[d][1]][y+fx[d][2]]=='x'){
            d=(d+1)%4;
            fout<<d<<'\n';
        }
        else {
            x=x+fx[d][1];
            y=y+fx[d][2];
            if(!tong[x][y]){
                tong[x][y]=1;
                i++;
            }
            fout<<x<<' '<<y<<' '<<i<<'\n';
        }
    }
    fout<<i<<'\n';
    return 0;
}
int main(){
    long long a,t;
    fin>>t;
    for(a=1;a<=t;a++){
        main1();
    }
}