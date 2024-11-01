#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void output(int n)
{
    while(n){
        cout<<8;
        n-=7;
    }
}
int lista[14]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        if(n<=13)
        {
            cout<<lista[n];
        }
        else{
            int k=n%7;
            if(k==0)    output(n);
            if(k==1)    cout<<10,output(n-8);
            if(k==2)    cout<<1,output(n-2);
            if(k==3)    cout<<200,output(n-17);
            if(k==4)    cout<<20,output(n-11);
            if(k==5)    cout<<2,output(n-5);
            if(k==6)    cout<<6,output(n-6);
        }
        cout<<endl;
    }

    return 0;
}
