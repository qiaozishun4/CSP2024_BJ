#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
char l1[60];
char l2[60];
int flag=0;
char mid1, mid2;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        l1[i]='0';
        l2[i]='0';
    }
    for(int i=0;i<n;i++){
        cin>>mid1>>mid2;
        flag++;
        for(int j=0;j<flag;j++){
            if(mid1==l1[j]&&mid2==l2[j]){
                flag--;
                break ;
            }
        }
        l1[i]=mid1;
        l2[i]=mid2;
    }
    cout<<52-flag;
    fclose(stdin);
    fclose(stdout);
    return 0;
}