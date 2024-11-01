#include<bits/stdc++.h>
using namespace std;
string a[1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t,x,y,d,n,m,k;
    cin>>t;
    while(t--){
        long long cnt=1;
        k=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[x][y-1]='1';
        for(int p=1;p<=k;p++){
            if(d==0){
                if(a[x][y]=='x' || y+1>m) d=(d+1)%4;
                else y++;
            }
            else if(d==1){
                if(a[x+1][y-1]=='x' || x+1>n) d=(d+1)%4;
                else x++;
            }
            else if(d==2){
                if(a[x][y-2]=='x' || y-1<1) d=(d+1)%4;
                else y--;
            }
            else if(d==3){
                if(a[x-1][y-1]=='x' || x-1<1) d=(d+1)%4;
                else x--;
            }
            if(a[x][y-1]!='1'){
                a[x][y-1]='1';
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
