#include<iostream>
using namespace std;
int n,m,k,x,y,t,d;
char a[1005][1005];
int sum=0;
int main(){
    cin>>t;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    for(int l=1;l<=t;l++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(sum<=k){
            if(d%4==0&&y!=m&&y+1!="x"){
                y+=1;
                sum++;
            }else if(d%4==0&&y==m||y+1=="x"){
                d=(d+1)%4;
                sum++;
            }
            if(d%4==1&&x!=n&&x+1!="x"){
                x+=1;
                sum++;
            }else if(d%4==1&&x==n&&x+1=="x"){
                d=(d+1)%4;
                sum++;
            } 
            
            if(d%4==2&&y!=1&&y-1!="x"){
                y-=1;
                sum++;
            }else if(d%4==2&&y==1&&y-1=="x"){
                d=(d+1)%4;
                sum++;
            }
            if(d%4==3&&x!=1&&x-1!="x"){
                x-=1;
                sum++;
            }else if(d%4==1&&x==n&&x-1=="x"){
                d=(d+1)%4;
                sum++;
            } 
            
            
        }
        cout<<sum<<endl;
    }
    

    return 0;
}