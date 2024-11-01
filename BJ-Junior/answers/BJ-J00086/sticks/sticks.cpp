#include<bits/stdc++.h>
using namespace std;
int n,id=14;
string mn[100010]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","80","88"};
void dfs(int t){
    if(t==0)return;
    mn[id]=mn[id-7]+'8';
    id++;
    dfs(t-1);
}int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    dfs(99990);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cout<<mn[x]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
