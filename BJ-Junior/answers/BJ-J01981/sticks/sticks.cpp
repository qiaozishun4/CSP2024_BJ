#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long check(long long mid){
    long long tmp=mid,ans=0;
    while(tmp){
        ans+=a[tmp%10];
        tmp/=10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n;
        bool flag=false;
        cin>>n;
        //43 1088888
        //44 1888888
        //45 2008888
        //46 2088888
        //47 2888888
        //48 6888888
        //49 8888888
        //50 10888888
        if(n>=43&&n<=50){
            if(n==43) cout<<1088888<<endl;
            if(n==44) cout<<1888888<<endl;
            if(n==45) cout<<2008888<<endl;
            if(n==46) cout<<2088888<<endl;
            if(n==47) cout<<2888888<<endl;
            if(n==48) cout<<6888888<<endl;
            if(n==49) cout<<8888888<<endl;
            if(n==50) cout<<10888888<<endl;
            continue;
        }if(n%7==0){
            int chu=n/7;
            for(int i=1;i<=chu;i++)
                cout<<8;
            cout<<endl;
            continue;
        }
        if((n-1)%7==0){
            if(n==1){
                cout<<-1<<endl;
                continue;
            }else if(n==8){
                cout<<10<<endl;
                continue;
            }else{
                int chu=(n-1)/7;
                chu=chu-1;
                cout<<10;
                for(int i=1;i<=chu;i++)
                    cout<<8;
                cout<<endl;
                continue;
            }
        }
        for(int i=1;i<=1000000;i++)
            if(check(i)==n){
                cout<<i<<endl;
                flag=true;
                break;
            }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
