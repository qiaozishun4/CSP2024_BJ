#include <iostream>
using namespace std;
int T,n,m,k,x1,y1,cnt,d;
char a[1005][1005];
int tong[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>x1>>y1>>d;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=m;z++){
                cin>>a[j][z];
            }
        }
        for(int j=1;j<=m;j++){
            a[n+1][j]='1';
            tong[n+1][j]=0;
        }
        for(int j=1;j<=n;j++){
            a[j][m+1]='1';
            tong[j][m+1]=0;
        }
        cnt=1;
        tong[x1][y1]=1;
        for(int m=1;m<=k;m++){
            if(d==0){
                if(a[x1][y1+1]=='.'){

                    if(tong[x1][y1+1]==0){
                        tong[x1][y1+1]=1;
                        cnt++;
                    }
                    y1++;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
             if(d==1){
                if(a[x1+1][y1]=='.'){

                    if(tong[x1+1][y1]==0){
                        tong[x1+1][y1]=1;
                        cnt++;

                    }
                    x1++;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3){
                if(a[x1-1][y1]=='.'){

                    if(tong[x1-1][y1]==0){
                        tong[x1-1][y1]=1;
                        cnt++;

                    }
                    x1--;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2){
                if(a[x1][y1-1]=='.'){

                    if(tong[x1][y1-1]==0){
                        tong[x1][y1-1]=1;
                        cnt++;

                    }
                    y1--;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        cout<<cnt<<endl;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=m;z++){
                tong[j][z]=0;
            }
        }

    }

    return 0;
}