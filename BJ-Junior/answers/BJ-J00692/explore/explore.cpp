#include<bits/stdc++.h>
using namespace std;
int s,count1;
char a[1010][1010];
bool is_valid(long long n,long long m,long long r,long long c){
    return (r>=1&&r<=n&&c>=1&&c<=m&&a[r][c]!='x');
}
void dfs(long long n,long long m,long long r,long long c,long long d,long long k){
    if(s==k){
        return;
    }
    if(d==0){
       if(!is_valid(n,m,r,c+1)){
           d=(d+1)%4;
       }else{
           c=c+1;
           count1++;
       }
    }else if(d==1){
        if(!is_valid(n,m,r+1,c)){
            d=(d+1)%4;
        }else{
            r=r+1;
            count1++;
        }
    }else if(d==2){
        if(!is_valid(n,m,r,c-1)){
            d=(d+1)%4;
        }else{
            c=c-1;
            count1++;
        }
    }else if(d==3){
        if(!is_valid(n,m,r-1,c)){
            d=(d+1)%4;
        }else{
            r=r-1;
            count1++;
        }
    }
    s++;
    dfs(n,m,r,c,d,k);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t,n,m,k,x,y,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(n,m,x,y,d,k);
        cout<<count1+1<<endl;
        count1=0;
    }
    return 0;
}
