/* Copyright 2022-2024  getfa(R) industries.
 * All Rights Reserved.
 *
 * See license in my(01999) code of CSP-J 2024 Problem 3&4
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;
int tong[1000005];
template<typename Tp>
class que{
    private:
        Tp a[1000005];
        int S=0,E=0,siz=0;
        const int len=1000000;
    public:
        Tp get(int ind){return a[(S+ind)%len];}
        void push(Tp x){a[E]=x;E=(E+1)%len;siz++;}
        void pop(){S=(S+1)%len;siz--;}
        Tp front(){return a[S];}
        bool empty(){return S==E;}
        int size(){return siz;}
        void change(int ind,Tp x){a[(S+ind)%len]=x;}
};
que<pair<int,int>>q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int t;
        cin>>t;
        tong[t]++;
    }
    for(int i=0;i<=100005;++i)if(tong[i]!=0)q.push({tong[i],tong[i]});
    int ans=n,now=0;
    while(!q.empty()){
        int now=q.front().first;
        q.pop();
        int i=0;
        while(i<q.size()&&now!=0){
            int fir=q.get(i).first,nxt=q.get(i).second;
            if(now>=nxt){
                now-=nxt;
                ans-=nxt;
                q.change(i,{fir,0});
            }
            else{
                ans-=now;
                q.change(i,{fir,nxt-now});
                now=0;
            }
            i++;
        }
    }
    cout<<ans;
    return 0;
}