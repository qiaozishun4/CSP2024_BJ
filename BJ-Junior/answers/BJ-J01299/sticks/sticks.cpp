#include<bits/stdc++.h>
using namespace std;
int x(int a){
    if(a==0)
        return 0;
    else{
        if(a==2){
            assum]=1;
            sum++;
               x(a-2);
        }
        if(a==3){
            s[sum]=7;
            sum++;
            x(a-3);
        }
        if(a==4){
            s[sum]=4;
            sum++;
            x(a-4);
        }
        if(a==5){
            s[sum]=2;
            sum++;
            x(a-5);
        if(a==6&&sum>1){
                s[sum]=0;
                sum++;
                x(a-6);
        }
        if(a==9){
                s[sum]=8;
                sum++;
                x(a-9);
        }
        if(a>0){
            s[sum]=1;
            sum++;
            x(a-1);
        }


    }


}
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
    int n,sum=1;
    string s;
    cin>>n;
    x(n);
    for(int i=1;i<=n;i++)
    cout<<s[i];
   return 0;
}
