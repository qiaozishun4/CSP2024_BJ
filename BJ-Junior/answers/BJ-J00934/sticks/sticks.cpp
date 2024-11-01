#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},ans,n,f=1,t;
bool check(int x){
    int cnt=0;
    while(x){
        cnt+=a[x%10];
        x/=10;
    }
    return cnt==n;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;;i++){
            if(check(i)){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
