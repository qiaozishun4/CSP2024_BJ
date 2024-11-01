#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,z[1000001];
char h[1001][1001];
int r(int m,int n,int k){
    int cnt=1;
    while(k){
        k--;
        if(g==0){
            if(n<c&&h[m][n+1]!='x'){
                n++;
                cnt++;
                h[m][n]='x';
            }else g=(g+1)%4;
        }else if(g==1){
            if(m<b&&h[m+1][n]!='x'){
                m++;
                cnt++;
                h[m][n]='x';
            }else g=(g+1)%4;
        }else if(g==2){
            if(n>1&&h[m][n-1]!='x'){
                n--;
                cnt++;
                h[m][n]='x';
            }else g=(g+1)%4;
        }else if(g==3){
            if(m>1&&h[m-1][n]!='x'){
                m--;
                cnt++;
                h[m][n]='x';
            }else g=(g+1)%4;
        }
    }
    return cnt;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b>>c>>d>>e>>f>>g;
        for(int j=1;j<=b;j++){
            for(int w=1;w<=c;w++) cin>>h[i][j];
        }
        z[i]=r(b,c,d);
        for(int j=1;j<=b;j++){
            for(int w=1;w<=c;w++) h[i][j]=' ';
        }
    }
    for(int i=1;i<=a;i++) cout<<z[i]<<endl;
    return 0;
}
