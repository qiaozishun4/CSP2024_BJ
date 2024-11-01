#include<bits/stdc++.h>
using namespace std;
int n,t,si[10]={6,2,5,5,4,5,6,3,7,6},l;
string s,minn;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        minn="";
        if(n<=1){
            cout<<-1<<'\n';
            continue;
        }
        if(n==6){
            cout<<6<<'\n';
            continue;
        }
        if(n==7){
            cout<<8<<'\n';
            continue;
        }
        if(n==8){
            cout<<27<<'\n';
            continue;
        }
        for(int i=0;1;i++){
            s="";
            if(i*8>n)break;
            n-=si[8]*i;
            l=n/si[0];
            switch(n%si[0]){
                case 0:
                    s="6";
                    l--;
                    break;
                case 1:
                    continue;
                    break;
                case 2:
                    s="1";
                    break;
                case 3:
                    s="7";
                    break;
                case 4:
                    s="4";
                    break;
                case 5:
                    s="2";
                    break;
            }
            n+=i*si[8];
            for(int i=0;i<l;i++)s+='0';
            for(int k=0;k<i;k++)s+='8';
            if(minn=="")minn=s;
            if(s.size()<minn.size()||(s.size()==minn.size()&&s<minn))minn=s;
        }
        if(minn=="")cout<<-1<<'\n';
        else cout<<minn<<'\n';
    }
    return 0;
}