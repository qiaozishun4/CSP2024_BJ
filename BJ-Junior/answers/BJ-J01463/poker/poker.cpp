#include<iostream>
#include<set>
#include<cstring>
using namespace std;
set<int> a;
string b;
int main(){
    freopen("poker3.in","r",stdin);
    freopen("poker3.out","w",stdout);
    int n,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        if(b[0]=='D'){
            c=1;
        }
        else if(b[0]=='C'){
            c=2;
        }
        else if(b[0]=='H'){
            c=3;
        }
        else if(b[0]=='S'){
            c=4;
        }
        if(b[1]=='T'){
            d=10;
        }
        else if(b[1]=='J'){
            d=11;
        }
        else if(b[1]=='Q'){
            d=12;
        }
        else if(b[1]=='K'){
            d=13;
        }
        else{
            d=b[1];
        }
        a.insert(c*d);
    }
    cout<<52-a.size();
    return 0;
}