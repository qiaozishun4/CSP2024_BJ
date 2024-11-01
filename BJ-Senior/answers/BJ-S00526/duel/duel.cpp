//duel
#include<iostream>
using namespace std;
const int E=2e6;
int vis[E];
bool et[E];
int ans=0;
int a[E];
int maxs(int *b,int b_11){
    int old=0;
    for(int i=0;i<b_11;i++){
        old = max(old,b[i]);
    }
    return old;
}
int indexs;
int maxcs(int *b,int b_11){
    int zmin = 100000;
    int zmax = 0;
    int jz = 100000;
    for(int i=0;i<b_11;i++){
        if(et[i]==false)zmin = min(b[i],zmin);
    }
    for(int i=0;i<b_11;i++){
        if(et[i]==false)zmax = max(b[i],zmax);
    }
    for(int i=0;i<b_11;i++){
        if(et[i]==false){
            int jzback = jz;
            jz = min(b[i]-zmin,jz);
            if(jz==0)jz=jzback;
            if(jz!=0) if(min(b[i]-zmin,jz) == b[i]-zmin) indexs = i;
        }
    }
    return b[indexs];
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(et[i] == false && vis[i] == false){
            int ls_1 = a[i];
            int ls_2 = maxcs(a,n);
            if(ls_2 > ls_1){
                vis[indexs] = true;
                et[i] = true;
                ans++;
            }if(ls_2 < ls_1){
                vis[i] = true;
                et[indexs] = true;
                ans++;
            }
        }
    }
    cout<<n-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
