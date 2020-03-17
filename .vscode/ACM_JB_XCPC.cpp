/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], d[maxn << 2];
void push_up(int rt)
{
    d[rt] = d[rt << 1] + d[rt << 1 | 1];
}
void build(int l , int r, int rt)
{
    if(l == r)
    {
        d[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1);
    push_up(rt);
}
void update(int pos,int v,int l ,int r, int rt)
{
    if(l == r)
    {
        d[rt] += v;
        return ;
    }
    int m = (l + r) >> 1;
    if(d[rt << 1] >= pos)
        update(pos, v, l, m, rt << 1);
    else
        update(pos, v, m + 1, r, rt << 1 | 1);
    push_up(rt);

}
void query(int )
{
    
}
int n, x;
int main()
{
   IOS
   string s;
   while (cin >> n)
   {
       for(int i = 0; i < n; i++)
       {
           cin >> s >> x;
           if(s[0] == 'a')
           {
               
           } 
       }
   }
   
   system("pause");
   return 0;
}