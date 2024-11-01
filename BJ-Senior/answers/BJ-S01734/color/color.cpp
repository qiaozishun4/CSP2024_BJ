#include<bits/stdc++.h>
using namespace std;

int a[114514];
int book[2];
int color[114514];

int work(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];  
    int answer=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++)color[j]=(i>>j)&1;
        book[0]=book[1]=-1;
        int ans=0;
        for(int j=0;j<n;j++){
            if(book[color[j]]==a[j])ans+=a[j];
            book[color[j]]=a[j];
        }
        /*for(int i=0;i<n;i++)cout<<color[i]<<' ';cout<<endl;
        cout<<endl;*/
        answer=max(ans,answer);
    }
    cout<<answer<<endl;
    return 0;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)work();
    return 0;
}