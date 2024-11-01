#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
bool pd[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","r",stdout);
    cin>>t;
    while(t--){
        int ans=1,jw;
        bool flag=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        if(d==1){
            k-=3;
        }
        else if(d==2){
            k-=2;
        }
        else if(d==3){
            k-=1;
        }
        if(k<=m-y){
            cout<<k+1<<endl;
            continue;
        }
        else if(k>=m-y){
            if(k<=(m-y)*2){
                cout<<k-m+y+1<<endl;
                continue;
            }
            else if(k<m+y){
                cout<<k-m+y+1+y-(k-m+y)<<endl;
                continue;
            }
            else if(k>=m+y){
                cout<<m+1<<endl;
                continue;
            }
        }
    }
    return 0;
}