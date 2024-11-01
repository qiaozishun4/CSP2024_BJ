#include<iostream>
using namespace std;
const int num[10]={6,2,5,5,4,5,6,3,7,6},bl[6]={6,2,5,4,3,7},cl[6]={2,5,4,6,3,7};
int ans[15000],mn;
int end_pri(int x){
    if(x==2)return 1;
    if(x==3)return 7;
    if(x==4)return 4;
    if(x==5)return 2;
    if(x==6)return 6;
    if(x==7)return 8;
    return -1;
}
int _pri(int x){
    if(x==2)return 1;
    if(x==3)return 7;
    if(x==4)return 4;
    if(x==5)return 2;
    if(x==6)return 0;
    if(x==7)return 8;
    return -1;
}
int dfs(int x,int i){
    if(i>mn)return 0;
    if(x<=7){
        if(x>=2){
            ans[i]=_pri(x);
            return 1;
        }
        else{
            return 0;
        }
    }
    if(i==1){
        for(int k=0;k<6;k++){
            int j=cl[k];
            if(dfs(x-j,i+1)){
                x-=j;
                ans[i]=end_pri(j);
                return 1;
            }
        }
        return 0;
    }
    else{
        for(int k=0;k<6;k++){
            int j=bl[k];
            if(dfs(x-j,i+1)){
                x-=j;
                ans[i]=_pri(j);
                return 1;
            }
        }
        return 0;
    }
}
void doing(int n){
    if(n<=1){
        cout<<"-1\n";
        return ;
    }
    if((n-1)%7==0){
        cout<<"10";
        for(int i=1;i<n/7;i++)cout<<8;
        cout<<'\n';
        return ;
    }
    if(n%7==0){
        for(int i=1;i<=n/7;i++)cout<<8;
        cout<<'\n';
        return ;
    }
    mn=(n+6)/7;
    if(dfs(n,1)==0){
        cout<<"-1\n";
        return ;
    }
    bool flag=0;
    for(int fl=1;fl<=mn;fl++){
        if(ans[fl])flag=1;
        if(flag)cout<<ans[fl];
    }
    cout<<'\n';
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        doing(n);
    }
    return 0;
}