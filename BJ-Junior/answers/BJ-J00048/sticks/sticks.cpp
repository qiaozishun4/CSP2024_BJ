#include<bits/stdc++.h>
using namespace std;
class num{
public:
    long long n;//now number
    int l;//now num
    num(){

    }
    num(int a,int b){
        n=a;
        l=b;
    }
};
int stnum[10]={6,2,5,5,4,5,6,3,7,6};
long long res=LONG_MAX;
void bfs(int n){
    queue<num> q;
    for(long long i=1;i<10;i++){
        if(stnum[i]<n)
            q.push(num(i,stnum[i]));
        if(stnum[i]==n)
            res=min(res,i);
    }
    while(!q.empty()){
        if(q.front().l==n-1){
            q.pop();
            continue;
        }
        for(int i=0;i<10;i++){
            if(q.front().l+stnum[i]<n)
                q.push(num(q.front().n*10+i,q.front().l+stnum[i]));
            if(q.front().l+stnum[i]==n)
                res=min(res,q.front().n*10+i);
        }
        q.pop();
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int iii=0;iii<t;iii++){
        int n;
        cin>>n;
        bfs(n);
        if(res==LONG_MAX)    cout<<-1;
        else cout<<res;
        if(iii<t-1) cout<<'\n';
        res=LONG_MAX;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
