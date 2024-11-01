#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int n;
bool pai[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int x=0;x<n;x++){
        char f1,f2;
        cin>>f1>>f2;
        int h,u;
        //花色分类;
        if(f1=='D') h=0;
        else if(f1=='C') h=1;
        else if(f1=='H') h=2;
        else if(f1=='S') h=3;
        else printf("err!");
        //判断ATJQK
        if(f2=='A') u=1;
        else if(f2=='T') u=10;
        else if(f2=='J') u=11;
        else if(f2=='Q') u=12;
        else if(f2=='K') u=13;
        else if(f2>='0'&&f2<='9')u=f2-'0';
        else printf("err!");
        pai[h][u-1]=true;
    }
    int ans=0;
    for(int x=0;x<4;x++){
        for(int y=0;y<13;y++){
            if(!pai[x][y]){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}