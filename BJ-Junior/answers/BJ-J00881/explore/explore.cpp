#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,sum,x,y,d;
        vector<int> s[2];
        cin>>n>>m>>sum;
        cin>>x>>y>>d;
        s[0].push_back(x);
        s[1].push_back(y);
        char a[n+1][m+1];
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++)cin>>a[j][k];
        }
        for(int j=0;j<sum;j++){
            if(d==0){
                y++;
                if(y>m||a[x][y]=='x'){
                    y--;
                    d++;
                }else{
                    bool num=true;
                    for(int k=0;k<s[0].size();k++){
                        if(s[0][k]==x&&s[1][k]==y){
                            num=false;
                            break;
                        }
                    }
                    if(num){
                        s[0].push_back(x);
                        s[1].push_back(y);
                    }
                }
            }else if(d==1){
                x++;
                if(x>n||a[x][y]=='x'){
                    x--;d++;
                }else{
                    bool num=true;
                    for(int k=0;k<s[0].size();k++){
                        if(s[0][k]==x&&s[1][k]==y){
                            num=false;
                            break;
                        }
                    }
                    if(num){
                        s[0].push_back(x);
                        s[1].push_back(y);
                    }
                }
            }else if(d==2){
                y--;
                if(y<=0||a[x][y]=='x'){
                    y++;d++;
                }else{
                    bool num=true;
                    for(int k=0;k<s[0].size();k++){
                        if(s[0][k]==x&&s[1][k]==y){
                            num=false;
                            break;
                        }
                    }
                    if(num){
                        s[0].push_back(x);
                        s[1].push_back(y);
                    }
                }
            }else{
                x--;
                if(x<=0||a[x][y]=='x'){
                    x++;d=0;
                }else{
                    bool num=true;
                    for(int k=0;k<s[0].size();k++){
                        if(s[0][k]==x&&s[1][k]==y){
                            num=false;
                            break;
                        }
                    }
                    if(num){
                        s[0].push_back(x);
                        s[1].push_back(y);
                    }
                }
            }
        }
        cout<<s[0].size()<<endl;
    }
    return 0;
}
