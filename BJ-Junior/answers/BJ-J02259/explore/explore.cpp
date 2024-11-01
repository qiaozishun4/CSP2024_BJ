#include<bits/stdc++.h>
using namespace std;
char a[1000000][1000000];
int find(int n,int m,int k,int x,int y,int d,int ans){
    while(k>0){
        k--;
        if(d==0){
            if(y+1<=m && a[x+1][y]=='.'){
                ans++;
                find(n,m,k,x,y+1,d,ans);
            }else{
                find(n,m,k,x,y,d+1,ans);
            }
        }
        if(d==1){
            if(x+1<=n && a[x+1][y]=='.'){
                ans++;
                find(n,m,k,x+1,y,d,ans);
            }else{
                find(n,m,k,x,y,d+1,ans);
            }
        }
        if(d==2){
            if(y-1>=0 && a[x][y-1]=='.'){
                ans++;
                find(n,m,k,x,y-1,d,ans);
            }else{
                find(n,m,k,x,y,d+1,ans);
            }
        }
        if(d==3){
            if(x+1<=m && a[x+1][y]=='.'){
                ans++;
                find(n,m,k,x+1,y,d,ans);
            }else{
                find(n,m,k,x,y,0,ans);
            }
        }
    }
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int num;
    cin>>num;
    int n[num],m[num],k[num],x[num],y[num],d[num];
    for(int i=0;i<num;i++){
        cin>>n[1]>>m[i]>>k[i]>>x[i]>>y[i]>>d[i];
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<n[i];j++){
            for(int l=0;l<m[i];l++){
                cin>>a[j][l];
            }
        }
        int ans=find(n[i],m[i],k[i],x[i],y[i],d[i],1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
