#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("explore.in","r",stdin);
 freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int s=1;
        char a[1005][1005];
        int x,y,d;
        cin>>x>>y>>d;
        for(int l=1;l<=n;l++){
            for(int j=1;j<=m;j++){
                cin>>a[l][j];
            }
        }


        for(int j=1;j<=k;j++){
            if(d==0){///
                if(a[x][y+1]!='x'&&(y+1)<=m){
                     s++;
                    y++;
                }else{

                    d=(d+1)%4;
                }

            }else if(d==1){///
                if(a[x+1][y]!='x'&&(x+1)<=n){
                    s++;
                    x++;
            }else{
                    d=(d+1)%4;
            }
            }else if(d==2){///
                if(a[x][y-1]!='x'&&y-1>0){
                    s++;
                    y--;

                }else{
                    d=(d+1)%4;
                }
}else{///
                if(a[x-1][y]!='x'&&x-1>0){
                    s++;
                    x--;
                }else{
                d=(d+1)%4;
                }
            }
            
            
                 }
            cout<<s<<endl;
    }
  fclose(stdin);
  fclose(stdout);
    return 0;
}
