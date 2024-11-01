#include<bits/stdc++.h>
using namespace std;
int l[10];
int main(){
    int a,b,c,d,e;
    cin>>a;
    l[0]=8;
    l[2]=1;
    l[3]=7;
    l[4]=4;
    l[5]=2;
    l[6]=6;
    while (a--)
    {
        cin>>b;
        e=0;
        if (b<=1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if (b%7==0) c=b/7,d=0;
        else c=b/7+1,d=b%7;
        if (c==1)
        {
            cout<<l[d]<<endl;
            continue;
        }
        if (d==1) cout<<"10",c-=2;
        else if (d==2) cout<<"1",c--;
        else if (d==3)
        {
            if (c==2)
            {
                cout<<"22";
                continue;
            }
            else cout<<"200",c-=3;
        }
        else if (d==4) cout<<"20",c-=2;
        else if (d==5) cout<<"2",c--;
        else if (d==6) cout<<"6",c--;
        while (c>0) cout<<"8",c--;
        cout<<endl;
    }
    return 0;
}
