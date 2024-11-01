#include <bits/stdc++.h>
using namespace std;
long long int t,n;
const int s[10]={6,2,5,5,4,5,6,3,7,6};
bool check(long long int a){
    long long int f=n;
    while(a>0){
        long long int t=a%10;
        f-=s[t];
        a/=10;
        if(f<0){
            return false;
        }
    }
    if(f!=0){
        return false;
    }
    return true;
}
long long int f(long long int a){
    if(a<=10){
        return 100;
    }
    long long int t=1,ans=0;
    for(int i=1;i<=a/2;i++){
        ans+=t;
        t*=10;
    }
    return max(ans,a);
}
int main(){
    //dont forget freopen
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            int l=n/7;
            for(int i=1;i<=l;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            int l=n/7-1;
            cout<<10;
            for(int i=1;i<=l;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        bool flag=false;
        long long int l=f(n);
        for(long long int i=1;i<=l;i++){
            if(check(i)){
                cout<<i<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;//rp++
}//80
