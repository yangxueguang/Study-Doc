#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int N = 20;

typedef struct node
{
    int adj;
    struct node *nextarc;
}arcNode;

typedef struct vecNode
{
    string data;
    arcNode *firstArc;
}vexNode;

typedef struct
{
    int n, e; //顶点个数和边的个数
    vecNode adjList[N];
}adjGraph;

void CreateGraph(adjGraph &g)
{
    cin>>g.n>>g.e;
    for (int i = 0; i < g.n; i++)
    {
        cin>>g.adjList[i].data;
        g.adjList[i].firstArc = nullptr;
    }
    int u, v;
    for (int i = 0; i < g.n; i++)
    {
        cin>>u>>v;
        arcNode *s = new arcNode;
        s->adj = v;
        s->nextarc = g.adjList[u].firstArc;
        g.adjList[u].firstArc = s;
    }
}

int  TopoSort(const adjGraph &g)
{
    stack<int> s;
    arcNode *p;
    int indegree[N] = {0};
    for(int i = 0; i < g.n; i++)
    {
        p = g.adjList[i].firstArc;
        while (p)
        {
            indegree[p->adj]++;
            p = p->nextarc;
        }
    }
    for(int i = 0;  i < g.n; i++)
    {
        if (indegree[i] == 0) s.push(i);
    }
    int count = 0;
    int u;
    while (!s.empty())
    {
        u = s.top();
        s.pop();
        cout<<g.adjList[u].data<<" ";
        count++;
        p = g.adjList[u].firstArc;
        while(p)
        {
            indegree[p->adj]--;
            if (indegree[p->adj] == 0) s.push(p->adj);
            p = p->nextarc;
        }
    }
    if (count < g.n) return 0;
    else return 1;
    
}

int main()
{
    adjGraph g;
    CreateGraph(g);
    if(TopoSort(g) == 0)
        cout<<"图有回路"<<endl;
    else
        cout<<"拓扑排序"<<endl;
    return 0;
}