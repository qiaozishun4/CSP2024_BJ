#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    cout<<rand()%10000000;
    return 0;
}
