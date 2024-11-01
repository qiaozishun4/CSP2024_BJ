#include<bits/stdc++.h>
using namespace std;
bool d[130],c[130],h[130],j[130];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,d1=0,d2=0,d3=0,d4=0,sum=0;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[2]=='A')
            s[2]=1;
        if(s[1]=='D'){
            d[s[2]]=1;
            string s=0;
        }
        else if(s[1]=='C'){
            c[s[2]]=1;
            string s=0;
        }
        else if(s[1]=='H'){
            h[s[2]=1;
            string s=0;
        }
        else{
            j[s[2]=1;
            string s=0;
        }

   }
   for(int i=1;i<=130;i++)
        if(d[i]==1)
            sum++;
   for(int i=1;i<=130;i++)
        if(c[i]==1)
            sum++;
    for(int i=1;i<=130;i++)
        if(h[i]==1)
            sum++;
    for(int i=1;i<=130;i++)
        if(j[i]==1)
            sum++;
   // int a=52-sum;
    cout<<52-sum;
    return 0;
}
