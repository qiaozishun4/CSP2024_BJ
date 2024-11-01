#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int b[30]={0,-1,1,7,4,2,6,8,10,18,22,20};
int s[1010],a[10]={2,5,4,6,3,7},c[10]={1,2,4,6,7,8};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        if(n<=11){
            cout<<b[n]<<endl;
            continue;
        }
        
        long long t1=n/7,t2=n%7;
        if(t2==1){
            cout<<10;
            while(t1--) cout<<8;
            cout<<endl;
        }else{
            for(int i=0;i<=5;i++){
                if(t2==a[i]){
                    cout<<c[i];
                    t2=0;
                    break;
                }
            }
            while(t1--) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}