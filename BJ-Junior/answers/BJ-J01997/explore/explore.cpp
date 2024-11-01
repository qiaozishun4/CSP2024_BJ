#include<bits/stdc++.h>
using namespace std;
void run(int x,int y,int d,int n,int m,int k,char ditu[1002][1002],int ret){
    if(k>0){
        if(d==0){
            if(1 <= x <= n  &&  1 <= y+1 <= m &&ditu[x][y+1]=='.'){
                x=x;
                y=y+1;
                ret++;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else if(1 <= x <= n  &&  1 <= y+1 <= m &&ditu[x][y+1]=='k'){
                x=x;
                y=y+1;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else{
                d=d+1;
                if(d==4){
                    d=0;
                }
                k=k-1;
                run(x,y,d,n,m,k,ditu,ret);
            }
        }
        else if(d==1){
            if(1 <= x+1 <= n  &&  1 <= y <= m &&ditu[x+1][y]=='.'){
                x=x+1;
                y=y;
                ret++;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else if(1 <= x+1 <= n  &&  1 <= y <= m &&ditu[x+1][y]=='k'){
                x=x+1;
                y=y;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else{
                d=d+1;
                if(d==4){
                    d=0;
                }
                k=k-1;
                run(x,y,d,n,m,k,ditu,ret);
            }
        }
        else if(d==2){
            if(1 <= x <= n  &&  1 <= y-1 <= m &&ditu[x][y-1]=='.'){
                x=x;
                y=y-1;
                ret++;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else if(1 <= x <= n  &&  1 <= y-1 <= m &&ditu[x][y-1]=='k'){
                x=x;
                y=y-1;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else{
                d=d+1;
                if(d==4){
                    d=0;
                }
                k=k-1;
                run(x,y,d,n,m,k,ditu,ret);
            }
        }
        else if(d==3){
            if(1 <= x-1 <= n  &&  1 <= y <= m &&ditu[x-1][y]=='.'){
                x=x-1;
                y=y;
                ret++;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else if(1 <= x-1 <= n  &&  1 <= y <= m &&ditu[x-1][y]=='k'){
                x=x-1;
                y=y;
                k=k-1;
                ditu[x][y]='k';
                run(x,y,d,n,m,k,ditu,ret);
            }
            else{
                d=d+1;
                if(d==4){
                    d=0;
                }
                k=k-1;
                run(x,y,d,n,m,k,ditu,ret);
            }
        }
    }
    else if(k==0){
        cout <<ret;
        cout <<"\n";
        return;
    }
}




int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n[10],m[10],k[10],x[10],y[10],d[10],ret=1;
    char ditu1[1002][1002],ditu2[1002][1002],ditu3[1002][1002],ditu4[1002][1002],ditu5[1002][1002];
    cin>>T;
    for(int i=0;i<T;i++){

        if(i==0){
            cin>>n[i]>>m[i]>>k[i];
            cin>>x[i]>>y[i]>>d[i];
            for(int j=0;j<n[i];j++){
                for(int k=0;k<m[i];k++){
                    cin>>ditu1[j][k];
                }
            }
        if(i==1){
            cin>>n[i]>>m[i]>>k[i];
            cin>>x[i]>>y[i]>>d[i];
            for(int j=0;j<n[i];j++){
                for(int k=0;k<m[i];k++){
                    cin>>ditu2[j][k];
                }
            }

        }
        if(i==2){
            cin>>n[i]>>m[i]>>k[i];
            cin>>x[i]>>y[i]>>d[i];
            for(int j=0;j<n[i];j++){
                for(int k=0;k<m[i];k++){
                    cin>>ditu3[j][k];
                }
            }

        }
        if(i==3){
            cin>>n[i]>>m[i]>>k[i];
            cin>>x[i]>>y[i]>>d[i];
            for(int j=0;j<n[i];j++){
                for(int k=0;k<m[i];k++){
                    cin>>ditu4[n[i]][m[i]];
                }
            }

        }
        if(i==4){
            cin>>n[i]>>m[i]>>k[i];
            cin>>x[i]>>y[i]>>d[i];
            for(int j=0;j<n[i];j++){
                for(int k=0;k<m[i];k++){
                    cin>>ditu5[n[i]][m[i]];
                }
            }

        }

        }
    }
    for(int i=0;i<T;i++){
        if(i==0){
         run(x[i],y[i],d[i],n[i],m[i],k[i],ditu1,ret);
        }
        if(i==1){
         run(x[i],y[i],d[i],n[i],m[i],k[i],ditu2,ret);
        }
        if(i==2){
         run(x[i],y[i],d[i],n[i],m[i],k[i],ditu3,ret);
        }
        if(i==3){
         run(x[i],y[i],d[i],n[i],m[i],k[i],ditu4,ret);
        }
        if(i==4){
         run(x[i],y[i],d[i],n[i],m[i],k[i],ditu5,ret);
        }
    }
    return 0;
}

