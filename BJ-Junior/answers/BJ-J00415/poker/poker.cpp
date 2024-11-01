#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int n;
struct pk{
    char h,s;
    bool b = 0;
}a[60];
int main(){
    //cout<<"1";
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    int sum = 52;
    for(int i = 1;i<=n;i++){
        cin>>a[i].h>>a[i].s;
        if(a[i].h == 'D'){
            if(a[i].s == 'A') a[1].b = 1;
            else if(a[i].s == 'T')a[10].b=1;
            else if(a[i].s == 'J')a[11].b= 1;
            else if(a[i].s == 'Q')a[12].b = 1;
            else if(a[i].s == 'K')a[13].b = 1;
            else a[a[i].s-'0'].b = 1;

        }
        if(a[i].h == 'H'){
            if(a[i].s == 'A') a[1+13].b = 1;
            else if(a[i].s == 'T')a[10+13].b = 1;
            else if(a[i].s == 'J')a[11+13].b = 1;
            else if(a[i].s == 'Q')a[12+13].b = 1;
            else if(a[i].s == 'K')a[13+13].b = 1;
            else a[a[i].s-'0'+13].b = 1;

        }
        if(a[i].h == 'C'){
            if(a[i].s == 'A') a[1+26].b = 1;
            else if(a[i].s == 'T')a[10+26].b = 1;
            else if(a[i].s == 'J')a[11+26].b = 1;
            else if(a[i].s == 'Q')a[12+26].b = 1;
            else if(a[i].s == 'K')a[13+26].b = 1;
            else a[a[i].s+26-'0'].b = 1;

        }
        if(a[i].h == 'S'){
            if(a[i].s == 'A') a[1+39].b = 1;
            else if(a[i].s == 'T')a[10+39].b = 1;
            else if(a[i].s == 'J')a[11+39].b = 1;
            else if(a[i].s == 'Q')a[12+39].b = 1;
            else if(a[i].s == 'K')a[13+39].b = 1;
            else a[a[i].s+39-'0'].b = 1;
        }
    }
    sum = 52;
    for(int i = 1;i<=52;i++){
        if(a[i].b == 1){
            sum--;

        }
    }
    cout<<sum;
    return 0;
}
