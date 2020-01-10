#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_V 10000
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        if (!used[G[v][i]])
            dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++)
    {
        if (!used[rG[v][i]])
            rdfs(rG[v][i], k);
    }
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++)
    {
        if (!used[v])
            dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
    {
        if (!used[vs[i]])
            rdfs(vs[i], k++);
    }
    return k;
}

int main()
{
    V = 6;

    add_edge(3, 4);
    add_edge(1, 0);

    add_edge(4, 2);
    add_edge(5, 1);

    add_edge(2, 3);
    add_edge(0, 5);

    scc();

    for (int i = 0; i < 3; i++)
    {
        if (cmp[i] == cmp[3 + i])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    for (int i = 0; i < 3; i++)
    {
        if (cmp[i] > cmp[3 + i])
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}
