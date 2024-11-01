#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            if(n<=1)
                {
                    cout<<-1<<endl;
                    continue;
                }
            if(n%7==0)
                {
                    for(int i=1;i<=n/7;i++)cout<<8;
                    cout<<endl;
                    continue;
                }
            stack<int>s;
            while(n)
                {
                    if(n<=14)
                        {
                            if(n==14)
                                {
                                    s.push(8);
                                    s.push(8);
                                }
                            if(n==13)
                                {
                                    s.push(8);
                                    s.push(6);
                                }
                            if(n==12)
                                {
                                    s.push(8);
                                    s.push(2);
                                }
                            if(n==11)
                                {
                                    s.push(0);
                                    s.push(2);
                                }
                            if(n==10)
                                {
                                    s.push(2);
                                    s.push(2);
                                }
                            if(n==9)
                                {
                                    s.push(8);
                                    s.push(1);
                                }
                            if(n==8)
                                {
                                    s.push(0);
                                    s.push(1);
                                }
                            if(n==7)s.push(8);
                            if(n==6)s.push(6);
                            if(n==5)s.push(2);
                            if(n==4)s.push(4);
                            if(n==3)s.push(7);
                            if(n==2)s.push(1);
                        }
                    else if(n==17)s.push(0),n-=6;
                    else s.push(8),n-=7;
                }
            while(!s.empty())
                {
                    int abc=s.top();
                    s.pop();
                    cout<<abc;
                }
            cout<<endl;
        }
    return 0;
}