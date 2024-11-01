#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    string s;
};
queue<node> q;
int dis1[7]={2,3,4,5,6,6,7};
string dis2[7]={"1","7","4","2","0","6","8"};
bool comp(string a,string b){
    int aweishu=a.size();
    int bweishu=b.size();
    long long an=0;long long bn=0;
    int power=1;
    for(int i=aweishu-1;i>=0;i--){
        an+= (a[i]-'0')*power;
        power*=10;
    }
    power=1;
    for(int i=bweishu-1;i>=0;i--){
        bn+=(b[i]-'0')*power;
        power*=10;
    }
    return an<=bn;
}



int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string tans="zzzzzzzz";
        q.push({n,""});
        while(!q.empty()){
            node r1=q.front();node r=q.front();
            reverse(r1.s.begin(),r1.s.end());
            if(r1.s[0]!='0'&&r1.num==0){
                if(comp(tans,r1.s)){
                    tans=tans;
                }
                else{
                    tans=r1.s;
                }
            }
            q.pop();
            node l;
            for(int i=0;i<7;i++){
                l.num=r.num-dis1[i];
                l.s=r.s+dis2[i];
                if(l.num>=0){
                    q.push({l.num,l.s});
                    //cout<<"l.num:"<<l.num<<" "<<"l.s:"<<l.s<<endl;
                }
            }
        }
        if(tans=="zzzzzzzz") cout<<-1<<endl;
        else{
            cout<<tans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}



