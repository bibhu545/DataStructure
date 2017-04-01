#include<iostream>
#include<cstring>
using namespace std;
int n,adj[100][100];
int min(int key[],bool state[])
{
    int index,min = 9999;
    for(int i=1;i<=n;i++)
    {
        if(state[i] == false && key[i]<=min)
        {
            min = key[i];
            index = i;
        }
    }
    cout<<" ";
    return index;
}
void prims()
{
    int parent[100],key[100];
    bool state[100];
    for(int i=1;i<=n;i++)
    {
        key[i] = 9999;
        state[i] = false;
    }
    key[1] = 0;
    parent[1] = -1;
    for(int i=1;i<=n;i++)
    {
        for(int v=1;v<=n;v++)
        {
            int u = min(key,state);
            state[u] = true;
            if(state[v] == false && adj[u][v] <= key[v] && adj[u][v] != 0)
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    cout<<"Edges : \n";
    for(int i=1;i<=n;i++)
    {
        if(key[i] != 9999)
        {
            cout<<i<<"--->"<<parent[i]<<"--->"<<key[i];
        }
    }
}
int main()
{
    memset(adj,0,sizeof(adj));
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the adjacency matrix : \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>adj[i][j];
        }
    }
    prims();
}
