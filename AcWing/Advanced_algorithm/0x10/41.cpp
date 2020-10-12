/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> stackvalue;
    stack <int> stackmin;
    MinStack() {
        
    }
    
    void push(int x) {
        stackvalue.push(x);
        if(stackmin.empty() || x <= stackmin.top()) {
            stackmin.push(x);
        }
    }
    
    void pop() {
        if(stackmin.top() == stackvalue.top()) {
            stackmin.pop();
        }
        stackvalue.pop();
    }
    
    int top() {
        return stackvalue.top();
    }
    
    int getMin() {
        return stackmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main(void)
{
    IOS
    MinStack S;
    system("pause");
    return 0;
}
