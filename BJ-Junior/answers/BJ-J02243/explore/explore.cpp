#include<bits/stdc++.h>
using namespace std;
string a[1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k;
        long long x,y,d;
        long long sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        while(k--){
            if(d==0&&y<m&&a[x][y+1]=='.'){
                y++;
                sum++;
            }
            else if(d==1&&x<n&&a[x+1][y]=='.'){
                x++;
                sum++;
            }
            else if(d==2&&y>=0&&a[x][y-1]=='.'){
                y--;
                sum++;
            }
            else if(d==3&&x>=0&&a[x-1][y]=='.'){
                x--;
                sum++;
            }
            else{
                d++;
                if(d==4) d=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
