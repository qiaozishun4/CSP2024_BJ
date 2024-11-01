#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int stick[]={6,2,5,5,4,5,6,3,7,6};
int getnum(int x){
    int res=0;
    while(x){
        res+=stick[x%10];
        x/=10;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    if(n<=50){
        for(int i=1;i<=8888888;i++){
            if(getnum(i)==n){
                cout<<i<<"\n";
                return;
            }
        }
        cout<<-1<<endl;
        return;
    }
    if(n%7==0){
        cout<<string(n/7,'8')<<endl;
        return;
    }
    if(n%7==1){
        cout<<"10"<<string(n/7-1,'8')<<endl;
        return;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}