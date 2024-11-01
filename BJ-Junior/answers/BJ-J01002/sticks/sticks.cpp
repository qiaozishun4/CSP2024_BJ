#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
int a[N],m[N],la,lm,t,n;
int num[11]={6,2,5,5,4,5,6,3,7,6};
bool cmp(){
    if(la!=lm){
        return la<lm;
    }
    for(register int i=1;i<=lm;i++){
        if(a[i]!=m[i]){
            return a[i]<m[i];
        }
    }
    return false;
}
void dfs(int step){
    if(step<0)return;
    if(step==0){
        if(cmp()){
            lm=la;
            for(register int i=1;i<=la;i++){
                m[i]=a[i];
            }
        }
        return;
    }
    for(register int i=0;i<10;i++){
        if(step==n && i==0)continue;
        a[++la]=i;
        dfs(step-num[i]);
        la--;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        lm=50000;
        if(ceil(n*1.0/7)==n/7){
            for(int i=1;i<=(n/7);i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }else if(ceil((n-1)*1.0/7)==(n-1)/7 && n!=1){
            cout<<10;
            for(int i=1;i<=((n-1)/7)-1;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        dfs(n);
        if(lm==50000)cout<<"-1\n";
        else{
            for(int i=1;i<=lm;i++){
                cout<<m[i];
            }
            cout<<'\n';
        }
    }
    return 0;
}