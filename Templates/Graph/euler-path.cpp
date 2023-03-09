class EulerGraph
{
public:
    struct Edge
    {
        int other;
        int oi;
        bool vis;
        Edge(int other, int oi): other(other), oi(oi){ vis=false; }
    };

    vector<vector<Edge>> adj;
    int* cnt;
    bool* sig;
    EulerGraph(int n)
    {
        adj.resize(n);
        cnt=new int[n];
        sig=new bool[n];
        memset(cnt, 0, sizeof(int)*n);
        memset(sig, 0, n);
    }

    void addEdge(int u, int v){
        int un=adj[u].size(), vn=adj[v].size();
        adj[u].eb(v, vn), adj[v].eb(u, un);
    }

    deque<int> getCircuit(int src){
        deque<int> circuit;
        circuit.push_back(src);

        int ecnt=adj[src].size();
        while(ecnt){
            int v=circuit.back();
            sig[v]=true;
            if(cnt[v]==adj[v].size()){
                circuit.pop_back();
                circuit.push_front(circuit.back());
            }
            else if(adj[v][cnt[v]].vis){
                cnt[v]++;
                ecnt--;
            }
            else {
                int other=adj[v][cnt[v]].other;
                int oi=adj[v][cnt[v]].oi;
                adj[other][oi].vis=true;

                circuit.push_back(other);
                if(!sig[other]) ecnt+=adj[other].size();

                cnt[v]++;
                ecnt--;
            }
        }
        return circuit;
    }

};
