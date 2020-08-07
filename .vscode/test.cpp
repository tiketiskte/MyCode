/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

const int maxn = 100 + 5;
using namespace std;
class Graph {
    int V;
    list <int>* adj; // 邻接表
    queue <int> q; // 维护一个入度为0的顶点的集合
    int* indegree; //每个顶点的入度
    
    public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool Topological_Sort();
};
Graph::Graph(int v) {
    this -> V = V;
    adj = new list <int> [V];
    indegree = new int[V];
    for(int i = 0; i < V; i++) {
        indegree[i] = 0;
    }
}
Graph::~Graph() {
    delete [] adj;
    delete [] indegree;
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    indegree[w]++;
}
bool Graph::Topological_Sort() {
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        ++count;
        list <int> :: iterator beg = adj[v].begin();
        for(; beg != adj[v].end(); beg++) {
            if(!(--indegree[*beg])) {
                q.push(*beg);
            }
        }
    }
    if(count < V) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    IOS
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.Topological_Sort();
    system("pause");
    return 0;
}
