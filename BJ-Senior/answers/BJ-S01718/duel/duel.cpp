#include<bits/stdc++.h>
using namespace std;
struct node{
    int r;
    bool f;
};
bool cmp(node a,node b){
    return a.r<b.r;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    node m[100002]={};
    int p,k=1,n;
    int a[100002]={};
    bool f1,f2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i].r;
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    int x,y,i=1,cnt=1;
    while(1){
        sort(m+1,m+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(m[i].r==0)continue;
            if(m[i].r!=0){
                p=m[1].r;
                x=i;
                break;
            }
        }//cout<<x<<endl;
        for(int i=x;i<=n+1;i++){
            if(m[i].r!=p){
                a[k++]=i-1;
                p=m[i].r;
            }
        }
        i=1,cnt=0;
        while(i<k){
            x=a[i]-a[i-1];
            y=a[i+1]-a[i];
            if(x==y){
                for(int j=a[i-1]+1;j<=a[i];j++)m[j].r=0;
                for(int j=a[i]+1;j<=a[i+1];j++)m[j].f=1;
            }else if(x<y){
                for(int j=a[i-1]+1;j<=a[i];j++)m[j].r=0;
                for(int j=a[i]+1;j<=a[i]+x;j++)m[j].f=1;
            }else{
                for(int j=a[i-1]+1;j<=a[i-1]+y;j++)m[j].r=0;
                for(int j=a[i]+1;j<=a[i]+y;j++)m[j].f=1;
            }
            i++;
        }
        //for(int i=1;i<=n;i++)cout<<m[i].r<<" "<<m[i].f<<endl;
        for(int i=n;i>=1;i--){
            if(m[i].r&&!m[i].f==1){
                cnt++;
            }
        }
        f1=1,f2=0;
        if(cnt)break;
        //cout<<"h";
        for(int i=n;i>=1;i--){
            if(m[i].f==0&&m[i].r)f1=0;
            if(f1&&m[i].r)f2=1;
        }if(f1&&f2)break;
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        if(m[i].r)cnt++;
    }cout<<cnt;
    return 0;
}