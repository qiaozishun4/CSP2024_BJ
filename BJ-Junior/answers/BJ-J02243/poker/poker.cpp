#include<bits/stdc++.h>
using namespace std;
string a[10010];
bool b[150];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        string s=a[i];
        long long l=0;
        if(s[0]=='D') l=0;
        else if(s[0]=='C') l=1;
        else if(s[0]=='H') l=2;
        else if(s[0]=='S') l=3;
        long long m=0;
        if(s[1]=='A') m=0;
        else if(s[1]=='2') m=1;
        else if(s[1]=='3') m=2;
        else if(s[1]=='4') m=3;
        else if(s[1]=='5') m=4;
        else if(s[1]=='6') m=5;
        else if(s[1]=='7') m=6;
        else if(s[1]=='8') m=7;
        else if(s[1]=='9') m=8;
        else if(s[1]=='T') m=9;
        else if(s[1]=='J') m=10;
        else if(s[1]=='Q') m=11;
        else if(s[1]=='K') m=12;
        b[4*m+l]=true;
    }
    long long saum=0;
    for(int i=0;i<52;i++){
        if(b[i]==false){
            saum++;
        }
    }
    cout<<saum<<endl;
    return 0;
}
