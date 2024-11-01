#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int fun(int x){
    int ans=0;
    while(x){
        ans+=a[x%10];
        x/=10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0&&n>=100){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }else if(n%7==1&&n>=100){
            cout<<1;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }else{
            for(int i=0;;i++){
                if(fun(i)==n){
                    cout<<i<<endl;
                    break;
                }
                if(i>100004){
                    cout<<-1<<endl;
                    break;
                }
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

