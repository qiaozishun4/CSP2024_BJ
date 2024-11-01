#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    int f=1;
    int n,m,k;
    int x1,y1;
    int d,x,y;
    char aa[n][m];


    for(int i=1;i<=T;i++){
        freopen("explore.in","r",stdin);
        freopen("explore.out","w",stdout);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int k=0;k<n;k++){
            for (int j=0;j<m;j++){
                cin>>aa[k][j];
            }
        }


            if(d==0){
                x1=x;
                y1=y+1;
            }else if(d==1){
                x1=x+1;
                y1=y;
            }else if(d==2){
                x1=x;
                y1=y-1;
            }else {
                x1=x-1;
                y1=y;
            }

        while(k>0){

            if(x1>=1&&y1>=1){
                if(x1<=n&&y<=m){
                    if(aa[x1][y1]!=x){
                        x=x1;
                        y=y1;
                        k--;
                        f++;
                    }

                }

            }else{
                d=(d+1)%4;
                k--;
            }



        }
    }

    cout<<f<<endl;
    /*
    &&y1>=1
    &&y1<=m
    &&aa[x1][y1]!=x
*/




    fclose(stdin);
    fclose(stdout);
    return 0;
}
