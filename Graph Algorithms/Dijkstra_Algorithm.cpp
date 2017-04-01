#include<iostream>
#include<cstring>
using namespace std;
int n,adj[100][100];
int min(int Distance[],bool state[])
{
    int index,min = 9999;
    for(int i=1;i<=n;i++)
    {
        if(state[i] == false && Distance[i]<=min)
        {
            min = Distance[i];
            index = i;
        }
    }
    cout<<" ";
    return index;
}
void Dijsktra()
{
    int parent[100],Distance[100];
    bool state[100];
    for(int i=1;i<=n;i++)
    {
        Distance[i] = 9999;
        state[i] = false;
        parent[i] = -1;
    }
    Distance[1] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int v=1;v<=n;v++)
        {
            int u = min(Distance,state);
            state[u] = true;
            if(Distance[v]+adj[u][v] <= Distance[v] && adj[u][v] != 0)
            {
                Distance[v] = adj[u][v]+Distance[v];
                parent[v] = u;
            }
        }
    }
    cout<<"Edges : \n";
    for(int i=1;i<=n;i++)
    {
        cout<<"Parent : "<<parent[i];
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance : "<<Distance[i];
    }
    cout<<endl;
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
    Dijsktra();
}

