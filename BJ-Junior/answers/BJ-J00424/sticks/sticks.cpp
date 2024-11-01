#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans[100005],tmp[100005];
int num[10]={6,2,5,5,4,5,6,3,7,6};
bool minn(int a[],int b[],int len){
    for(int i=1;i<=len;i++){
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return 0;
    }
    return 0;
}
void dfs(int tot,int step){
    if(step==ceil(n/7.0)+1){
        if(tot==0){
            if(minn(ans,tmp,ceil(n/7.0))){
                for(int i=1;i<=ceil(n/7.0);i++)ans[i]=tmp[i];
            }

        }
        return ;
    }
    if(tot<=0&&step<ceil(n/7.0)+1||!minn(ans,tmp,step))return ;
    for(int i=0;i<=9;i++){
        if(step==1&&i==0)continue;
        tmp[step]=i;
        dfs(tot-num[i],step+1);
        tmp[step]=0;

    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<-1<<endl;
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else {
            memset(ans,0x3f,sizeof(ans));
            memset(tmp,0,sizeof(tmp));
            dfs(n,1);
            for(int i=1;i<=ceil(n/7.0);i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
