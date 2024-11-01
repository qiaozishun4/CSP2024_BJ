#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int num[100005];
queue<int>q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[a[i]]++;
    }
    for(int i=1;i<=1e5;i++){
        if(num[i]!=0&&q.empty()){
            q.push(i);
            continue;
        }
        int sum=0;
        while(num[i]!=0&&!q.empty()&&sum<=num[i]){
            int h=q.front();
            sum+=num[h];
            if(sum<=num[i]){
                num[h]=0;
                q.pop();
            }else{
                num[h]=sum-num[i];
            }
        }
        if(num[i]!=0){
            q.push(i);
        }
    }
    for(int i=1;i<=1e5;i++){
        ans+=num[i];
    }
    cout<<ans;
}
