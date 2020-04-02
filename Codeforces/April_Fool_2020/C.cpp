/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
   IOS
   int ans = 0, x = 0, i = 0;
   int a, arr[6];
   memset(arr, 0, sizeof(arr));
   cin >> a;
   while (a > 0)
   {
       arr[i] = a % 2;
       i++;
       a /= 2;
       /* code */
   }
  /*  cout << "###1:" << endl; 
   for(int i = 0; i < 6; i++){
       cout << arr[i] << " ";
   } */
   cout << endl;
   swap(arr[0], arr[4]);
   swap(arr[2], arr[3]);
   /* cout << "###2:" << endl; */
   for(int i = 0; i < 6;){
      if(arr[i] == 1){
          x = pow(2, i);
          ans += x; 
          i++;
      }
      else{
          ans += 0;
          i++;
      }
   }
   cout << ans << endl;
   //system("pause");
   return 0;
}
