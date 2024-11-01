#include<iostream>
#include<stdio.h>
using namespace std;
bool a[300][300]={0};
int n=0,cnt=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char h,d;
    for(int i=0;i<n;i++){
        cin>>h>>d;
        if(a[int(h)][int(d)]!=1){
            cnt--;
            a[int(h)][int(d)]=1;
        }
    }
    cout<<cnt;
    return 0;
}
