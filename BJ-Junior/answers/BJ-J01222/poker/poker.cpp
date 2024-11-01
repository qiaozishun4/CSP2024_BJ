#include<bits/stdc++.h>
using namespace std;
int d[20],c[20],hh[20],s[20],n;
int main(){
   freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char h,p;
        cin>>h>>p;
        if(h=='D'){
            if(p=='T')d[10]++;
            else if(p=='A')d[1]++;
            else if(p=='J')d[11]++;
            else if(p=='Q')d[12]++;
            else if(p=='K')d[13]++;
            else{
                d[p-'0']++;
            }
        }
        else if(h=='C'){
            if(p=='T')c[10]++;
            else if(p=='A')c[1]++;
            else if(p=='J')c[11]++;
            else if(p=='Q')c[12]++;
            else if(p=='K')c[13]++;
            else{
                c[p-'0']++;
            }
        }
        else if(h=='H'){
            if(p=='T')hh[10]++;
            else if(p=='A')hh[1]++;
            else if(p=='J')hh[11]++;
            else if(p=='Q')hh[12]++;
            else if(p=='K')hh[13]++;
            else{
                hh[p-'0']++;
            }
        }else if(h=='S'){
            if(p=='T')s[10]++;
            else if(p=='A')s[1]++;
            else if(p=='J')s[11]++;
            else if(p=='Q')s[12]++;
            else if(p=='K')s[13]++;
            else{
                s[p-'0']++;
            }
        }
    }
    int j=0;
    for(int i=1;i<=13;i++){
        if(d[i]==0)j++;
    }
    for(int i=1;i<=13;i++){
        if(c[i]==0)j++;
    }for(int i=1;i<=13;i++){
        if(hh[i]==0)j++;
    }
    for(int i=1;i<=13;i++){
        if(s[i]==0)j++;
    }
    cout<<j;

}
