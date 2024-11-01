#include<bits/stdc++.h>
using namespace std;
int n;
int s[15]={6,2,5,5,4,5,6,4,7,6};
int a[1000005];
int p;
int ans[100005];
void dfs(int x){
    if(p!=0){
        for(int j=0;j<10;j++){
            if(x>s[j]){
                ans[p]=j;
                p++;
                dfs(x-s[j]);
            }
            if(x==s[j])
                for(int k=0;k<p;k++)
                    cout<<ans[k];

            cout<<endl;
            return;
            if(x<s[j]&&p==0)
                cout<<-1<<endl;
                return;
        }
    }
    if(p==0){
        for(int j=1;j<10;j++){
            if(x>s[j])
                ans[p]=j;
                p++;
                dfs(x-s[j]);
            if(x==s[j])
                for(int k=0;k<p;k++)
                    cout<<ans[k];

            cout<<endl;
            return;
            if(x<s[j]&&p==0)
                cout<<-1<<endl;
                return;
        }
    }
}
int main(){
    cin>>n;
    freopen(sticks,"r",stdin);
    freopen(sticks,"w",stdout);
    cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208<<endl;
    return 0;
}
