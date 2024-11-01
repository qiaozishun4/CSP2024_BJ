#include<bits/stdc++.h>

using namespace std;

int n;
int lst[100005];
deque<int> dq;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>lst[i];
    }

    sort(lst,lst+n);

    for(int i=0;i<n;i++){
        dq.push_back(lst[i]);

        if(lst[i]>dq.front()){
            dq.pop_front();
        }

    }

    cout<<dq.size();
    return 0;
}
