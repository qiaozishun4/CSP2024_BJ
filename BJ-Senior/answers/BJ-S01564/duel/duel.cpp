#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100001];
int n;
priority_queue<int,vector<int>,greater<int> >b;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=a[0];
    for(int i=0;i<n;i++){
        if(a[i]==l);
        else b.push(a[i]);
    }
    for(int i=0;i<n;i++){
        n+1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        while(!b.empty()&&a[i]>=b.top()){
            b.pop();
        }
        if(b.empty()){
            break;
        }
        ans++;
        b.pop();

    }
    cout<<n-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}