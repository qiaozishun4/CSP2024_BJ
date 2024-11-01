#include<bits/stdc++.h>
using namespace std;
bool a[1001][1001]={};
bool b[1001][1001]={};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long kkkk;
    cin>>kkkk;
    for(long long qqqq=0;qqqq<kkkk;qqqq++){
        long long n,m,k,x,y,d;
        char c;
        cin>>n>>m>>k>>x>>y>>d;
        b[x][y]=1;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>c;
                if(c=='x'){
                    a[i][j]=1;
                }
            }
        }for(long long i=0;i<k;i++){
            long long 1=y+1,a2=y-1,a3=x+1,a4=x-1;
            if(d==0){
                if(a1>m){
                    d=1;
                }else if(a[x][a1]){
                    d=1;
                }else{
                    y++;
                }
            }else if(d==1){
                if(a3>n){
                    d=2;
                }else if(a[a3][y]){
                    d=2;
                }else{
                    x++;
                }
            }else if(d==2){
                if(a2<1){
                    d=3;
                }else if(a[x][a2]){
                    d=3;
                }else{
                    y--;
                }
            }else if(d==3){
                if(a4<1){
                    d=0;
                }else if(a[a4][y]){
                    d=0;
                }else{
                    x--;
                }
            }b[x][y]=1;
        }
        long long um=0;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                a[i][j]=0;
                if(b[i][j]){
                    sum++;
                    b[i][j]=0;
                }
            }
        }cout<<sum<<endl;
    }

    fclose(stdin);
    fclose(stdout);
	return 0;
}
