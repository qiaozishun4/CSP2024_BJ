#include<bits/stdc++.h>
using namespace std;
long long t;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
long long n,m,k,xa,ya,da;
long long sum;
string a[1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        sum=1;
        cin>>n>>m>>k;
        cin>>xa>>ya>>da;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int x=xa,y=ya;
        for(int i=1;i<=k;i++){
            x+=dx[da];
            y+=dy[da];
            if(1<=x&&x<=n&&1<=y&&y<=m){
                if(a[x][y]=='.'){
                   sum+=1;
                }
            }else{
                x-=dx[da];
                y-=dy[da];
                da=(da+1)%4;
            }
        }
        cout<<sum;
    }

    return 0;
}