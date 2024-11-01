#include<bits/stdc++.h>
using namespace std;
char a[5][1010][1010];
int k[5],x[5],y[5],n[5],m[5],b,d[5],c[5][1010][1010]={},cnt=0;
void go(int i){
    int o,p;
    if(d[i]==0){
        p++;
    }else if(d[i]==1){
        o++;
    }else if(d[i]==2){
        p--;
    }else{
        o--;
    }
    if(a[i][o][p]!=' '&&a[i][o][p]!='x'){
        x[i]=o;
        y[i]=p;
        c[i][x[i]][y[i]]=1;
    }else{
        d[i]=(d[i]+1)%4;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>b;
    for(int i=0;i<b;i++){
        cin>>n[i]>>m[i]>>k[i]>>x[i]>>y[i]>>d[i];
        c[i][x[i]][y[i]]=1;
        for(int j=1;j<=n[i];j++){
            for(int k=1;k<=m[i];k++){
                cin>>a[i][j][k];
            }
        }
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<k[i];j++){
            go(i);
        }
        for(int j=1;j<=n[i];j++){
            for(int k=1;k<=m[i];k++){
                if(c[i][j][k]==1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}