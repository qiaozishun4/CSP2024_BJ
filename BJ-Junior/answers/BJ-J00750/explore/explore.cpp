#include<iostream>
using namespace std;
char a[1010][1010];
long long k,d;
int ans=1;
int main(){
 freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,xx,yy,m,s[15];
    cin>>T;
    for(int i=1;i<=T;i++){
            ans=1;
        cin>>n>>m>>k;
        cin>>yy>>xx>>d;
        for(int p=1;p<=n;p++){
                for(int q=1;q<=m;q++){
                    cin>>a[q][p];
                }
            }
            a[xx][yy]='1';
            for(int j=1;j<=k;j++){
                if(d%4==0){
                if(a[xx+1][yy]!='x'&&xx<m){
                    xx=xx+1;
                    if(a[xx][yy]!='1'){
    ans++;           a[xx][yy]='1';
}
                }
                else {d++;continue;}
                }
            if(d%4==1){
                if(a[xx][yy+1]!='x'&&yy<n){
                     yy=yy+1;
                     if(a[xx][yy]!='1'){
    ans++;            a[xx][yy]='1';
}
                }
                else {d++;continue;}
            }
             if(d%4==2){
                if(a[xx-1][yy]!='x'&&xx>1){
                   xx=xx-1;
                   if(a[xx][yy]!='1'){
    ans++;            a[xx][yy]='1';
}
                }
                else {d++; continue;}
            }
             if(d%4==3){
                if(a[xx][yy-1]!='x'&&yy>1){
                     yy=yy-1;
                     if(a[xx][yy]!='1'){
    ans++;             a[xx][yy]='1';
}
                }
                else {d++;continue;}
    }
            }
            s[i]=ans;
    }
    for(int i=1;i<=T;i++){
    cout<<s[i]<<endl;
    }
    return 0;
}
