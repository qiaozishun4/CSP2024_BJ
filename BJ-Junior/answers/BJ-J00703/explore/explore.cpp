#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d,cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int j1=x,j2=y;
        char a[n+10][m+10];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(k>=1){
                    if(d==1){
                        if(j1+1<=n&&a[j2][j1+1]!='x'){
                            j1+=1;
                            cnt++;
                            k--;
                        }else{
                            d=2;
                        }
                    }else if(d==0){
                        if(j2+1<=m&&a[j2+1][j1]!='x'){
                            j2+=1;
                            cnt++;
                            k--;
                        }else{
                            d=1;
                        }
                    }else if(d==3){
                        if(j1-1>=1&&a[j2][j1-1]!='x'){
                            j1-=1;
                            cnt++;
                            k--;
                        }else{
                            d=0;
                        }
                    }else if(d==2){
                        if(j2-1>=1&&a[j2-1][j1]!='x'){
                            j2-=1;
                            cnt++;
                            k--;
                        }else{
                            d=3;
                        }
                    }
                }else{
                    break;
                }
            }
        }cout<<cnt<<"\n";
    }
    return 0;
}
