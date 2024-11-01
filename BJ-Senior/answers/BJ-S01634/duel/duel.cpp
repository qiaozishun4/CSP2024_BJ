#include<bits/stdc++.h>
using namespace std;
 int a=0;
int b[100005]={0};
int h=0;
int v[100005];
vector<int> q;
int main()
{



     freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>a;
    int g=0;
    while(g<a)
    {
        cin>>b[g];
        g=g+1;
    }
cout<<4;
    sort(b,b+a);

    for(int j=0;j<a;j++)
    {
       q.push_back(b[j]);
    }

    while(a!=h)
    {
      for(int i=0;i<q.size();i++)
    {
        if(q[i+1]>q[i])
        {
        a--;
        h++;
        v[i]=1;
        q.erase(q.begin()+i);

        }
    }
    }
   cout<<a;
  fclose(stdin);
  fclose(stdout);
    return 0;

}
