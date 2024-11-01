#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];

struct node{
    int r,knum,rnum;
}b[maxn];


int aunique(int n){
    int ind=0;
    b[ind].r=a[0];
    b[ind].knum=1;
    b[ind].rnum=1;
    for(int i=1;i<n;i++){
        if(a[i] != b[ind].r){
            ind++;
            b[ind].r = a[i];
            b[ind].knum = 1;
            b[ind].rnum = 1;
        }
        else{
            b[ind].knum++,b[ind].rnum++;
        }
    }
    return ind+1;
}


int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);

    int ans=n;
    stack<node> sta;
    n = aunique(n);
    sta.push(b[0]);
    for(int i=1;i<n;i++){
        while(!sta.empty()){
            node now=sta.top();
            sta.pop();
            if(b[i].knum > now.rnum){
                ans -= now.rnum;
                b[i].knum -= now.rnum;
            }
            else{
                ans -= b[i].knum;
                now.rnum -= b[i].knum;
                b[i].knum = 0;
                sta.push(now);
                break;
            }
        }
        sta.push(b[i]);
    }
    cout<<ans;
    return 0;
}
