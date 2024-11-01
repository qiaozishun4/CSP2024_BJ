#include<bits/stdc++.h>
using namespace std;

long long n,m,t,k,x,y,d;
char a[10005],b[10005];

long long flag,f;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int ans=0;
    cin>>t;
    for(long long h=1;h<=t;h++){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(long long i=1;i<=m;i++){
        cin>>a[i];
    }
    for(long long j=1;j<=k;j++){
    if(d==0) {
        if(m>=y+1) flag=1;
        else flag=0;

    }
    else if(d==1) {
        if(n>=x+1) flag=1;
        else flag=0;

    }
    else if(d==2) {
        if(m>=y-1) flag=1;
        else flag=0;

    }
    else if(d==3) {
        if(n>=x-1) flag=1;
        else flag=0;

    }
    if(d==0 && a[y+1]!=114) {
        f=1;
    }
    else if(d==1 && a[x+1]!=114) {
        f=1;
    }


    else if(d==2 && a[y-1]!=114) {
        f=1;
    }


    else if(d==3 && a[x-1]!=114) {
        f=1;
    }
    if(flag==1 && f==1 && d==0) {
        y+=1;
        ans++;
        break;
    }
    else if(flag==1 && f==1 && d==1) {
        x+=1;
        ans++;
        break;
    }

    else if(flag==1 && f==1 && d==2) {
            y-=1;
            ans++;
            break;
    }
    else if(flag==1 && f==1 && d==3){
       x-=1;
       ans++;
       break;
    }
    else d=(d+1)%4;

    }

       cout<<ans;
    }

return 0;
}

