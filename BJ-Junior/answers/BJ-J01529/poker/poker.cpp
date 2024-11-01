#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool a[4][13];
int shu(char n){
    if(n=='D'){
        return 1;
    }else if(n=='C'){
        return 2;
    }else if(n=='H'){
        return 3;
    }else if(n=='S'){
        return 4;
    }
}
int shu2(char n){
    if(n=='A'){
        return 1;
    }else if(n=='2'){
        return 2;
    }else if(n=='3'){
        return 3;
    }else if(n=='4'){
        return 4;
    }else if(n=='5'){
        return 5;
    }else if(n=='6'){
        return 6;
    }else if(n=='7'){
        return 7;
    }else if(n=='8'){
        return 8;
    }else if(n=='9'){
        return 9;
    }else if(n=='T'){
        return 10;
    }else if(n=='J'){
        return 11;
    }else if(n=='Q'){
        return 12;
    }else{
        return 13;
    }
}
int main(){
    int m;
    cin>>m;
    int ans=0;
    for(int i=1;i<=m;i++){
        char A[3];
        cin>>A;
        if(a[shu(A[0])][shu2(A[1])]==false){
            ans++;
            a[shu(A[0])][shu2(A[1])]=true;
        }
    }
    cout<<52-ans;



    return 0;
}
