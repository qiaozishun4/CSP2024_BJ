#include<bits/stdc++.h>
using namespace std;
int ans;
int stepk=0;
int step=0;
char a[1001][1001];
void ss(int x,int y,int d){
    if(step==stepk){
        return;
    }
    ans++;
    if(d==0){
        int xn=x;
        int yn=y+1;
        step++;
        if(x<1||x>n||y<1||y>m){
            int dn=(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }else if(a[xn][yn]=='x'){
            int dn(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }
    }else if(d==1){
        int xn=x+1;
        int yn=y;
        step++;
        if(x<1||x>n||y<1||y>m){
            int dn=(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }else if(a[xn][yn]=='x'){
            int dn(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }
    }else if(d==2){
        int xn=x;
        int yn=y-1;
        step++;
        if(x<1||x>n||y<1||y>m){
            int dn=(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }else if(a[xn][yn]=='x'){
            int dn(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }
    }else if(d==3){
        int xn=x-1;
        int yn=y;
        step++;
        if(x<1||x>n||y<1||y>m){
            int dn=(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }else if(a[xn][yn]=='x'){
            int dn(d+1)%4;
            ans--;
            ss(x,y,dn);
            return;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int ac=0;ac<T;ac++){
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        int x,y,d;
        cin>>x>>y>>d;
        stepk=k;
        for(int i=1;i<=n;i++){
            for(int i=1;i<=m;i++){
                cin>>a[i][j];
            }
        }
        ss(x,y,d);
        cout<<ans<<endl;
        ans=0;
        stepk=0;
        step=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
