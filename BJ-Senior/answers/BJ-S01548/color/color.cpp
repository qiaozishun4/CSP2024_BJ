#include <bits/stdc++.h>
using namespace std;
int n,a[200000],mx=-1;
bool col[200000];
void c(int pos,int score){
    if(pos==n){mx=max(mx,score);return;}
    col[pos]=0;
    if(pos!=1){
        int m=pos-1;
        while(m>=0&&col[m]!=0)m--;
        if(m==-1)c(pos+1,score);
        else if(a[m]==a[pos])c(pos+1,score+a[m]);
        else c(pos+1,score);
    }else c(pos+1,score);
    col[pos]=1;
    if(pos!=1){
        int m=pos-1;
        while(m>=0&&col[m]!=1)m--;
        if(m==-1)c(pos+1,score);
        else if(a[m]==a[pos])c(pos+1,score+a[m]);
        else c(pos+1,score);
    }else c(pos+1,score);
}
int main(){
   freopen("color.in","r",stdin);
   freopen("color.out","w",stdout);
   int t;cin>>t;
   while(t--){
       cin>>n;mx=-1;
       for(int i=0;i<n;i++)cin>>a[i];
       c(0,0);
       cout<<mx<<endl;
   }
}
