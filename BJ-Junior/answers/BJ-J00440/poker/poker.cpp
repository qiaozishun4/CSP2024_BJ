#include<bits/stdc++.h>
using namespace std;
bool a[10][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    int anss=0;
    int z,r;
    char x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(x=='D'){
            z=1;
        }else if(x=='C'){
            z=2;
        }else if(x=='H'){
            z=3;
        }else if(x=='S'){
            z=4;
        }
        if(y=='A'){
            r=1;
        }else if(y=='T'){
            r=10;
        }else if(y=='J'){
            r=11;
        }else if(y=='Q'){
            r=12;
        }else if(y=='K'){
            r=13;
        }else{
            y-='0';
            r=y;
        }
        if(a[z][r]==0){
            anss++;
            a[z][r]=1;
        }
    }
    int zz=52-anss;
    printf("%d",zz);
    return 0;
}
