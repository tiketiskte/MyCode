/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;
size_t equallength(string &s1, string &s2) {
   size_t len1 = s1.size();
   size_t len2 = s2.size();
   if(len1 < len2) {
      for(int i = 0; i < len2 - len1; i++) {
         s1 = '0' + s1;
      }
      return len2;
   } else if(len1 > len2) {
       for(int i = 0; i < len1 - len2; i++) {
         s2 = '0' + s2;
      }
   }
   return len1;
}
string straddition(string s1, string s2) {
   string ret;
   int carry = 0;
   size_t len = equallength(s1, s2);

   for(int i = len - 1; i >= 0; i--) {
      int firstBit = s1.at(i) - '0';
      int secondBit = s2.at(i) - '0';

      int sum = (firstBit ^ secondBit ^ carry) + '0';
      ret = static_cast<char>(sum) + ret;

      carry = (firstBit & secondBit) | (firstBit & carry) | (secondBit & carry);
   }
   if(carry) {
      ret = '1' + ret;
   }
   return ret;
   
}


long int kasatsuba(string s1, string s2) {
   size_t len = equallength(s1, s2);
   if(len == 0) {
      return 0;
   }
   if(len == 1) {
      return (s1[0] - '0') * (s2[0] - '0');
   }
   size_t floor = len / 2;
   size_t ceil = len - floor;
   string a = s1.substr(0, floor);
   string b = s1.substr(floor, ceil);
   string c = s2.substr(0, floor);
   string d = s2.substr(floor, ceil);

   long int p1 = kasatsuba(a, c);
   long int p2 = kasatsuba(b, d);
   long int p3 = kasatsuba(straddition(a, b) , straddition(c, d));

   return (1 << (2 * ceil)) * p1 + (1 << (ceil)) * (p3 - p1 - p2) + p2;
}
int main()
{
   IOS
   //string x = "3141592653589793238462643383279502884197169399375105820974944592";
   //string y = "2718281828459045235360287471352662497757247093699959574966967627";
   string s1 = "10101010";
   string s2 = "111101";
   cout << kasatsuba(s1, s2) << endl;
   system("pause");
   return 0;
}