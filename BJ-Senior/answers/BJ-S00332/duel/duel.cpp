#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n,arr[maxn];
int main () {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    priority_queue<int,vector<int>,greater<int> > curr;
    for(int i = 0; i < n; i++) {
        if(curr.size() != 0 && arr[i] > curr.top()) curr.pop();
        curr.push(arr[i]);
    }
    printf("%lu\n",curr.size());
    return 0;
}
