#include<bits/stdc++.h>
using namespace std;
int l[1010][2010],m[1010],n[1010];
int main(){
    int a,b,c,d,e,f,g,h,i;
    cin>>a;
    while (a--)
    {
        cin>>b>>c>>d;
        h=0;
        for (e=1;e<=b;e++)
        {
            cin>>m[e];
            for (g=1;g<=m[e];g++) cin>>l[e][g];
        }
        for (e=1;e<=m[1];e++)
        {
            if (l[1][e]==1&&h==0) h=e;
            if (h>0&&e-h+1<=c) n[l[1][e]]=1;
        }
        while (d--)
        {
            cin>>e>>f;
            if (e==1&&n[f]==1) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    return 0;
}
