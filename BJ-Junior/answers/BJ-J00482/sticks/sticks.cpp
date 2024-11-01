#include <iostream>
using namespace std;
int t,n,s[15]={-1,-1,1,7,4,2,6,8,10,18,22,26,28,68,88},y[7]={108,188,206,208,288,688,888};
void stick();
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int qw=0;qw<t;++qw){
        cin>>n;
        stick();
    }
    return 0;
}
void stick(){
    if(n<15)cout<<s[n];
    else{
        n-=15;
        cout<<y[n%7];
        for(int i=0,len=n/7;i<len;i++)
            cout<<8;
    }
    cout<<endl;
}
