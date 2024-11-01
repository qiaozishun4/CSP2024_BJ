#include <iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int d[10086],h[10086],c[10086],s[10086];
    string str1;
    for(int i=0;i<n;i++){
            cin>>str1;
        if(str1[0]=='D'){
            if(str1[1]=='T'){
                d[9]++;
            }
            else if(str1[1]=='J'){
                d[10]++;
            }
            else if(str1[1]=='Q'){
                d[11]++;
            }
            else if(str1[1]=='K'){
                d[12]++;
            }
            else if(str1[1]=='A'){
                d[0]++;
            }
            else{
                d[str1[1]-'0'-1]++;
            }
        }
        else if(str1[0]=='C'){
            if(str1[1]=='T'){
                c[9]++;
            }
            else if(str1[1]=='J'){
                c[10]++;
            }
            else if(str1[1]=='Q'){
                c[11]++;
            }
            else if(str1[1]=='K'){
                c[12]++;
            }
            else if(str1[1]=='A'){
                c[0]++;
            }
            else{
                c[str1[1]-'0'-1]++;
            }
        }
        else if(str1[0]=='H'){
            if(str1[1]=='T'){
                h[9]++;
            }
            else if(str1[1]=='J'){
                h[10]++;
            }
            else if(str1[1]=='Q'){
                h[11]++;
            }
            else if(str1[1]=='K'){
                h[12]++;
            }
            else if(str1[1]=='A'){
                h[0]++;
            }
            else{
                h[str1[1]-'0'-1]++;
            }
        }
        else if(str1[0]=='S'){
            if(str1[1]=='T'){
                s[9]++;
            }
            else if(str1[1]=='J'){
                s[10]++;
            }
            else if(str1[1]=='Q'){
                s[11]++;
            }
            else if(str1[1]=='K'){
                s[12]++;
            }
            else if(str1[1]=='A'){
                s[0]++;
            }
            else{
                s[str1[1]-'0'-1]++;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<13;i++){
        if(d[i]<1){
            cnt++;
        }
        if(c[i]<1){
            cnt++;
        }
        if(h[i]<1){
            cnt++;
        }
        if(s[i]<1){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

