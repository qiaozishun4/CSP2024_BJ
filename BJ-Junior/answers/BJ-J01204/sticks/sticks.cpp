#include<iostream>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int useful[15]={0,0,1,2,4,5,6,7,8};
int n,ans,k;
int dfs(int sticks,int num1,string num2){
    if(sticks<=0){
        if(num2[1]!='0' && sticks==0){
            return num1;
        }
        else return 0x3f3f;
    }
    else {
        int min_=0x3f3f;
        for(int i=1;i<=8;i++){
            char s;
            s=useful[i]+'0';
            min_=min(min_,dfs(sticks-num[useful[i]],num1*10+useful[i],num2+s));
        }
        return min_;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>k;
    for(int awa=1;awa<=k;awa++){
        cin>>n;
        ans=-1;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        ans=dfs(n,0," ");
        if(ans!=0x3f3f)cout<<ans<<endl;
        else cout<<-1<<endl;

    }
    return 0;
}
