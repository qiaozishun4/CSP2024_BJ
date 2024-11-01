#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a[100],res,num,numm;
void sti(){
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=5;
    cin>>n;
    if(n<=1){
        cout<<"-1"<<endl;
        return;
    }
    else if(n%7==0){
       k=n/7;
       for(int i=0;i<k;i++){
           cout<<"8";
       }
       cout<<endl;
       k=0;
       return;
    }
    else if(n%7==1){
       k=n/7-1;
       cout<<10;
       for(int i=0;i<k;i++){
           cout<<"8";
       }
       cout<<endl;
       k=0;
       return;
    }
    else{
        for(int i=1;i<1000000;i++){
            num=i;
            while(num>0){
                numm=num%10;
                num/=10;
                res+=a[numm];
            }
            if(res==n){
                cout<<i<<endl;
                return;
            }
            res=0;
        }
    }
    num=numm=n=k=0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        sti();
    }
    return 0;
}
