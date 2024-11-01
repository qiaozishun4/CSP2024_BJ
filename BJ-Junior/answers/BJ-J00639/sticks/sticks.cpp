#include <iostream>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
int data[100010],n,temp=0,ri=0;
using namespace std;
const int numsti[11]={6,2,5,5,4,5,6,3,7,6};
const int more[11]={8,0,6,9,2,3,5,4,7,1};
void sot() {
    if(ri==0)return;
    sort(data,data+temp);
    ri=1;
    if(data[0]==0) {
        for(int i=1;i<temp;i++) {
            if(data[i]!=0) {swap(data[0],data[i]);break;}
        }
    }
}
void jiancha1() {
    for(int i=0;i<temp;i++)
        if(data[i]!=0) {
            ri=1;
            break;
        }
}
void dfs(int next) {
    if(n==0) {
        jiancha1();
        if(ri) {
            sot();
        }
        if(ri) for(int i=0;i<temp;i++) cout<<data[i];
        return;
    }
    for(int i=0;i<10;i++) {
        data[temp]=more[i];
        if(n-numsti[data[temp]]<0)continue;
        n-=numsti[data[temp]];
        temp++;
        dfs(next);
        if(ri)return;
        data[temp]=0;
        n+=numsti[data[temp]];
        temp--;
    }
}
void fun() {
    memset(data,0,sizeof(data));
    ri=0;
    temp=0;
    cin>>n;
    if(n%7==0) {
        n/=7;
        for(int i=0;i<n;i++) cout<<8;
        cout<<endl;
    }
    else if(n==1) cout<<-1<<endl;
    else if(n%7==1) {
        cout<<10;
        n-=8;
        n/=7;
        for(int i=0;i<n;i++) cout<<8;
        cout<<endl;
    }
    else {dfs(0);
    if(ri==0)cout<<-1;
    cout<<endl;
    }
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)fun();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
