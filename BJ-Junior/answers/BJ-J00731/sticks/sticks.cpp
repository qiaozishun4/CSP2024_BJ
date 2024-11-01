#include<iostream>
#include<cstdio>
using namespace std;
int T,cnt;
bool f;
int st[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int t,int num,int step){
    if(t==0){
        cnt=min(cnt,num);
        f=1;
    }
    if(num>=cnt){
        return;
    }
    for(int i=0;i<=9;i++){
        if(step==1&&i==0) continue;
        if(t<st[i])continue;
        dfs(t-st[i],num*10+i,step+1);
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cnt=2147483647;
        dfs(n,0,1);
        if(f==0){
            cout<<-1<<endl;
        }else{
            cout<<cnt<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
