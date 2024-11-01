#include<bits/stdc++.h>
#define N 500001
using namespace std;
int mon[N]={0},change[N],h=0;
int cmp(int x,int y){
    return x>y;
}
int main(){
    FILE* f1=freopen("duel.in","r",stdin);
    FILE* f2=freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mon[i];
    }
    sort(mon+1,mon+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(mon[i]!=mon[i-1]){
            change[++h]=i;
        }
    }
    int hp=h-1;
    int l=change[h]-1,r=n,p=change[hp]-1,ans=0;
    while(1){
        p=change[hp]-1;
        int num1=l-p,num2=r-l,l2=l,r2=r;
        int beat=min(num1,num2);
        ans+=beat;
        r2-=beat;
        l2-=beat;
        if(r2==l){
            r=r2;
            l=p;
        }
        else if(l2==p){
            l=l2;
            r=r2;
        }
        hp--;
        if(hp<1){
            break;
        }
    }
    cout<<n-ans;
    fclose(f1);
    fclose(f2);
    return 0;
}
