#include<bits/stdc++.h>
using namespace std;
int n;
char c[10]={'0','0','1','7','4','2','6','8'};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<"-1\n";
        else{
            int w=n/7,w1=n%7;
            if(w1==1){ string s="10";for(int i=1;i<w;i++)s=s+'8';cout<<s<<endl; }
            else if(w1==0){ string s="";for(int i=1;i<=w;i++)s=s+'8';cout<<s<<endl; }
            else if(w1==4&&n>=11){ string s="20";for(int i=1;i<w;i++)s=s+'8';cout<<s<<endl; }
            else if(w1==3&&n>=17){ string s="200";for(int i=1;i<w-1;i++)s=s+'8';cout<<s<<endl; }
            else if(w1==6&&n>=13){ string s="80";for(int i=1;i<w;i++)s=s+'8';cout<<s<<endl; }
            else{
                string s;
                s+=c[w1];
                for(int i=1;i<=w;i++)s=s+'8';
                cout<<s<<endl;
            }
        }
    }
    return 0;
}
