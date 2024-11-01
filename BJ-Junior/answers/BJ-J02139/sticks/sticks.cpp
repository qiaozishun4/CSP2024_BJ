#include <bits/stdc++.h>
using namespace std;
int n,a[100002],num[51],maxx;
int jilu[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","r",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>num[i];
        if (num[i]>maxx){
            maxx=num[i];
        }
    }
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=0;
    a[7]=8;
    for (int i=8;i<=maxx;i++){
        a[i]=999999;
        for (int j=0;j<10;j++){

            if (i>=jilu[j] && a[i-jilu[j]]!=0){
                a[i]=min(a[i],a[i-jilu[j]]*10+j);

            }
        }
    }
    for (int i=0;i<n;i++){
        if (num[i]==6){
            cout<<"6"<<endl;
        }
        else if (a[num[i]]==0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<a[num[i]]<<endl;
        }
    }
}
