#include <iostream>
#include <string>
#include <stack>

using namespace std;
const int N = 20;
//临近弧长
class AdjArc 
{
public:
//临近弧长
    int adjFrom;
    int adjTo; 
    AdjArc * nextArc;
};

class VecNode
{
    public:
        string data;
        AdjArc *firstArc;
};

class AdjGraph
{
    public:
        int m_n, m_e;// 顶点个数 和 边的个数
        VecNode vecList[N];   //节点列表

        AdjGraph(int n, int e);
        int  TopoSort();
    
};

AdjGraph::AdjGraph( int n, int e)
{
    this->m_n = n;
    this->m_e = e;
    for (int i = 0; i < n; i++) //n个顶点的数据                                    
    {
        cout<<"please enter the data of <"<<i<<">\n";
        cin>>vecList[i].data;
        vecList[i].firstArc = nullptr;
    }
    int u, v;
    for (int i = 0; i < e; i++) //n条边的关系
    {
        cout<<"please enter the link from u to v in ["<<i<<"]\n";
        cin>>u>>v;
        AdjArc *pAdjArc = new AdjArc;
        pAdjArc->adjFrom = u;
        pAdjArc->adjTo = v;
        pAdjArc->nextArc = vecList[u].firstArc;
        vecList[u].firstArc = pAdjArc;
    }
}
int  AdjGraph::TopoSort()
{
    stack<int> stk;
    int indegree[N] = {0};
    AdjArc *p;
    for(int i = 0; i < m_n; i++) //遍历n个顶点
    {
        p = vecList[i].firstArc;
        while (p)
        {
            indegree[p->adjTo]++;
            p = p->nextArc;
        }
    }
    for(int i = 0;  i < m_n; i++)
    {
        if (indegree[i] == 0) stk.push(i); //入度为零
    }
    int count = 0;
    int vertex;
    while (!stk.empty())
    {
        vertex = stk.top();
        stk.pop();
        cout<<"<"<<vertex<<">"<<vecList[vertex].data<<" ";
        count++;
        p = vecList[vertex].firstArc;
        while(p)
        {
            indegree[p->adjTo]--;
            if (indegree[p->adjTo] == 0) stk.push(p->adjTo);
            p = p->nextArc;
        }
    }
    if (count < m_n) return 0;
    else return 1;
}

int main()
{
    int n,e;
    cout<<"please enter the num of vertex and edge\n";
    cin >>n>>e;
    AdjGraph *g = new AdjGraph(n, e);
    if(g->TopoSort() == 0)
        cout<<"图有回路"<<endl;
    else
        cout<<"拓扑排序"<<endl;
    return 0;
}