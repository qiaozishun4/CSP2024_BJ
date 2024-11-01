#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t=0;
    cin>>t;
    vector<int>v(0);
    for(int a=0;a<t;++a){
        int n=0,m=0,k=0,x=0,y=0,d=0,cnt=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        string s(m+1,'.');
        vector<string>mapex(n+1,s);
        for(int i=1;i<=n;++i){
            string str;
            cin>>str;
            mapex[i]=str;
        }
        
        int i=x;int j=y;
        
        for(int ind=1;ind<=k;++ind){
            
            
            
            if(d==0){
                if(j+1<=m && mapex[i][j+1]!='x'){
                    j=j+1;
                    ++cnt;
                    
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(i+1<=n && mapex[i+1][j]!='x'){
                    i=i+1;
                    ++cnt;
                    
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(j-1>=1 && mapex[i][j-1]!='x'){
                    j=j-1;
                    ++cnt;
                    
                }else{
                    d=(d+1)%4;
                }

            }else if(d==3){
                if(i-1>=1 && mapex[i-1][j]!='x'){
                    i=i-1;
                    ++cnt;
                    
                }else{
                    d=(d+1)%4;
                }
            }
            
        }
        
        v.push_back(cnt);
    }
    for(auto e:v){
        cout<<e<<endl;
    }
}
