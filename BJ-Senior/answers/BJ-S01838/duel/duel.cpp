#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    queue<int>s;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]>s.front()&&!s.empty()){
            s.pop();
            s.push(a[i]);
        }else{
            s.push(a[i]);
        }
    }
    cout<<s.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

