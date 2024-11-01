#include<bits/stdc++.h>
using namespace std;
string s;
long long n,T,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        k=n;
        d=k/7;
        m=k%7;
        if(m==1){
            cout<<"10";
            while(--d){
                cout<<8;
            }
            cout<<endl;
        }else{
            while(d--){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
