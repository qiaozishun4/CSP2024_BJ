#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int num,a,ans;
    int N[100005],m[2];
    cin>>num;
    m[0] = 0;
    m[1] = 0;
    a=0;
    for(int i=0;i<num;i++){
        cin>>N[i];
    }

    if (num>30){
        for(int i=0;i<num;i++){
            if (N[i]==1) {m[0] += 1;}
            else{m[1] += 1;)
        }
        if m[1]>=m[0]{cout<<m[1]}
        else if m[1]<m[0]{cout<<m[0]-m[1]+m[0]}
        }

    if (num<=30){
        sort(N);
        for(i=1,i<num,i++){
            if (N[i-1]<N[i]){
                a++;
            }
        }
        cout<<a;
    }
    return 0;
}