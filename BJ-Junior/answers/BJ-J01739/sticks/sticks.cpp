#include <bits/stdc++.h>
using namespace std;

int n;
int a;
int num[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a;
        if(a<=14)cout<<num[a]<<endl;
        else{
            cout<<num[a%7+7];
            for(int i=1;i<a/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
