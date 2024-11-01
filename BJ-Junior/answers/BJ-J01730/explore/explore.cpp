#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int m=0,n=0,k=0,x=0,y=0,d=0,Ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char CMAP[n][m]={};
        int BL[n][m]={};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>CMAP[i][j];
            }
        }
        int RX=x-1;
        int RY=y-1;
        for(int i=0;i<k;i++){
            if(d==0){
                if(CMAP[RX][RY+1]=='.' && RX>=0 && RX<n && RY+1>=0 && RY+1<m){
                    if(BL[RX][RY+1]==0){
                        Ans++;
                    }
                    RY++;
                    BL[RX][RY]=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(CMAP[RX+1][RY]=='.' && RX+1>=0 && RX+1<n && RY>=0 && RY<m){
                    if(BL[RX+1][RY]==0){
                        Ans++;
                    }
                    RX++;
                    BL[RX][RY]=1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(CMAP[RX][RY-1]=='.' && RX>=0 && RX<n && RY-1>=0 && RY-1<m){
                    if(BL[RX][RY-1]==0){
                        Ans++;
                    }
                    RY--;
                    BL[RX][RY]=1;
                }else{
                    d=(d+1)%4;
                }
            }else{
                if(CMAP[RX-1][RY]=='.' && RX-1>=0 && RX-1<n && RY>=0 && RY<m){
                    if(BL[RX-1][RY]==0){
                        Ans++;
                    }
                    RX--;
                    BL[RX][RY]=1;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<Ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
