#include <bits/stdc++.h>
using namespace std;

int ans=2147483647,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};

void dfs(int x,int num,int sum){//x是有几位，num是剩下多少根小木棍,sum是到现在为止拼出来的数字
//    cout<<x<<" "<<num<<" "<<sum<<endl;
    if(x>0&&num==0) return;
    if(x==0){
        if(num!=0) return;
        if(ans==0) ans=sum;
        else ans=min(ans,sum);
        return;
    }
    if(x==(n+6)/7){
        for(int i=1;i<=9;i++){
            if(a[i]<=num){
                dfs(x-1,num-a[i],sum*10+i);
            }
        }
    }else{
        for(int i=0;i<=9;i++){
            if(a[i]<=num){
                dfs(x-1,num-a[i],sum*10+i);
            }
        }    
    }
    
}

int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
//    for(int i=0;i<=9;i++) cout<<a[i]<<" ";
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        int x=(n+6)/7;
        if(n==1||n==0) cout<<-1<<endl;
        else{
            dfs(x,n,0);
            cout<<ans<<endl;    
        }
    }
    //爆搜笑死了
    return 0;
}
