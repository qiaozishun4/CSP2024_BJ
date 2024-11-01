#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
string s[MAX];
int maxx,vis[MAX];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    s[2]="1";s[3]="7";s[4]="4";s[5]="2";s[6]="6";s[7]="8";
    vis[2]=1;vis[3]=1;vis[4]=1;vis[5]=1;vis[6]=1;vis[7]=1;
    maxx=8;
    while(T--){
        int n;
        cin>>n;
        for(int i=maxx;i<=n;i++){
            if(vis[i-2]){
                s[i]=s[i-2]+"1";
                vis[i]=1;
            }
            if(vis[i-3]){
                string tmp=s[i-3]+"7";
                if(vis[i]){
                    if(s[i].length()==tmp.length()&&s[i]>tmp)s[i]=tmp;
                    else if(s[i].length()>tmp.length())s[i]=tmp;
                }
                else{
                    s[i]=tmp;
                    vis[i]=1;
                }
            }
            if(vis[i-4]){
                string tmp=s[i-4]+"4";
                if(vis[i]){
                    if(s[i].length()==tmp.length()&&s[i]>tmp)s[i]=tmp;
                    else if(s[i].length()>tmp.length())s[i]=tmp;
                }
                else{
                    s[i]=tmp;
                    vis[i]=1;
                }
            }
            if(vis[i-5]){
                string tmp=s[i-5]+"5";
                if(vis[i]){
                    if(s[i].length()==tmp.length()&&s[i]>tmp)s[i]=tmp;
                    else if(s[i].length()>tmp.length())s[i]=tmp;
                }
                else{
                    s[i]=tmp;
                    vis[i]=1;
                }
            }
            if(vis[i-6]){
                string tmp=s[i-6]+"0";
                if(vis[i]){
                    if(s[i].length()==tmp.length()&&s[i]>tmp)s[i]=tmp;
                    else if(s[i].length()>tmp.length())s[i]=tmp;
                }
                else{
                    s[i]=tmp;
                    vis[i]=1;
                }
            }
            if(vis[i-7]){
                string tmp=s[i-7]+"8";
                if(vis[i]){
                    if(s[i].length()==tmp.length()&&s[i]>tmp)s[i]=tmp;
                    else if(s[i].length()>tmp.length())s[i]=tmp;
                }
                else{
                    s[i]=tmp;
                    vis[i]=1;
                }
            }
        }
        maxx=max(maxx,n);
        //cout<<vis[n]<<endl;
        if(!vis[n])cout<<-1<<endl;
        else cout<<s[n]<<endl;
    }
    return 0;
}
