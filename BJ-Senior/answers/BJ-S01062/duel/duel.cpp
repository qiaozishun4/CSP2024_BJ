#include<bits/stdc++.h>
using namespace std;
int n;
int r[100001];
int maxr,ans;
stack<int> lst;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        r[x]++;
        maxr=max(maxr,x);
    }
    for(int i=1;i<=maxr;i++){
        if(r[i]>0){
            int atk=r[i];
            while(!lst.empty()&&atk>0){
                int num=min(atk,r[lst.top()]);
                ans+=num;
                atk-=num;
                r[lst.top()]-=num;
                if(r[lst.top()]==0) lst.pop();
            }
            lst.push(i);
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
