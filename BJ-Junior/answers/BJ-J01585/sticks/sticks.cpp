#include<bits/stdc++.h>
using namespace std;
int ans[100005],cnt,T,n,x,num,a0[10]={2,3,4,5,5,5,6,6,6,7},a1[10]={1,7,4,2,3,5,0,6,9,8},a2[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //3
    for(int i=0;i<10;i++);
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        x=n/7;
        if(n%7){
            num=7-n%7;
            x++;
        }else num=0;
        if(x==1){
            for(int j=0;j<=9;j++){
                if(a1[j]==0) continue;
                if(7-a0[j]<=num) {
                    ans[1]=a1[j];
                    num-=7-a0[j];
                    break;
                }
            }
        }else{
            for(int i=1;i<=x;i++){
                if(i==1){
                    for(int j=1;j<=9;j++){
                        if(7-a2[j]<=num) {
                            ans[i]=j;
                            num-=7-a2[j];
                            break;
                        }
                    }
                }else{
                    for(int j=0;j<=9;j++){
                        if(7-a2[j]<=num) {
                            ans[i]=j;
                            num-=7-a2[j];
                            break;
                        }
                    }
                }
            }
        }
        if(num) cout<<-1<<endl;
        else for(int i=1;i<=x;i++) cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
