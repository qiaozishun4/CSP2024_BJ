#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int t,n,m,k,x,y,x1,x2,d,g;
string s[N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        g=0;
        for(int i=1;i<=k;i++){
            if(d==0){
                x2=y+1;
            }
            else if(d==1){
                x1=x+1;
            }
            else if(d==2){
                x1=x-1;
            }
            else if(d==3){
                x2=y-1;
            }
            if(1<=x1 && x1<=n && 1<=x2 && x2<=n && s[x1][x2]=='.'){
                y=x2;
                x=x1;
                g++;
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<g<<endl;
    }
    return 0;
}
