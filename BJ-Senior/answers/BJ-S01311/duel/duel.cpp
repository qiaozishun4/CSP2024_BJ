#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    //cin>>n;
    scanf("%d",&n);
    vector<int> ve;
    for(int i=1;i<=n;i++){
        int num;
        //cin>>num;
        scanf("%d",&num);
        ve.push_back(num);
    }
    sort(ve.begin(),ve.end());
    deque<int> dq;
    for(int i=0;i<=(n-1);i++){
        if((!dq.empty())&&(dq.front()<ve[i])){
            dq.pop_front();
        }
        dq.push_back(ve[i]);
    }
    //cout<<dq.size()<<endl;
    printf("%d",dq.size());
    return 0;
}
