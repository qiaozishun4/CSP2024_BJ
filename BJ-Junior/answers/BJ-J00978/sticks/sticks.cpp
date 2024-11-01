#include<bits/stdc++.h>
using namespace std;
int number[10]={6,2,5,5,4,5,6,3,7,6};
int a[1000005],x=0;
int n;
bool flag=0;
int minn=INT_MAX;
void dfs(int step){
    if(n==0){
        flag=1;
        int sum=0;
        int s=1;
        for(int i=x;i>=1;i--){
            sum+=a[i]*s;
            s*=10;
        }
        minn=min(minn,sum);
    }else{
        for(int i=0;i<=9;i++){
            if(i==0&&step==1){
                continue;
            }
            if(n>=number[i]){
                n-=number[i];
                a[++x]=i;
                dfs(step+1);
                n+=number[i];
                x--;
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        x=0;
        minn=INT_MAX;
        flag=0;
        cin>>n;
        dfs(1);
        if(!flag){
            cout<<-1<<endl;
        }else{
            cout<<minn<<endl;
        }
    }
    return 0;
}
