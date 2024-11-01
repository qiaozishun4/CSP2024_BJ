#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int t,n;
int v[10]={6,2,5,5,4,5,6,3,7,6};
bool judge(int cost,int di){
	if(di==0){
		if(cost==n){
			return 1;
		}else{
			return 0;
		}
	}
    if(cost+di*7>=n){
        return 1;
    }else{
        return 0;
    }
}
void dfs(int c,int d){
    if(d==0){
        return;
    }
    for(int i=0;i<=9;i++){
        if(judge(c+v[i],d-1)){
                q.push(i);
                dfs(c+v[i],d-1);
                return;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1||n==0){
			cout<<-1<<endl;
			continue;
		}
        int d=n/7;
        if(n%7!=0){
            d++;
        }
        for(int j=1;j<=9;j++){
            if(judge(v[j],d-1)){
                q.push(j);
                dfs(v[j],d-1);
                break;
            }
        }
        while(!q.empty()){
            cout<<q.front();
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}
