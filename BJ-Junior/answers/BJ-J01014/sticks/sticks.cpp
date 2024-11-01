#include<bits/stdc++.h>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
int need(int x){
    int ans=0;
    while(x){
        ans+=a[x%10];
        x/=10;
    }
    return ans;
}
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int wei;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }else{
            wei=n/7+1;
        }
        string ans="";bool flag=0;
        for(int k=1;k<=wei;k++){
            if(k==wei){
                if(n==2)ans+='1';
                else if(n==3)ans+='7';
                else if(n==4)ans+='4';
                else if(n==5)ans+='2';
                else if(n==6&&k!=1)ans+='0';
                else if(n==6&&k==1)ans+='6';
                else if(n==7)ans+='8';
                else{
                    cout<<-1<<endl;
                    flag=1;
                    break;
                }
            }
            else for(int i=0;i<=9;i++){
                if(i==0&&k==1)continue;
                int x=n-a[i];
                if(7*(wei-k)>=x&&x>7*(wei-k-1)){
                    ans+=(i+'0');
                    n-=a[i];
                    break;
                }
            }
        }
        if(!flag)cout<<ans<<endl;
    }
    return 0;
}
