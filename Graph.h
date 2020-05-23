/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <deque>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <thread>
#include "MutablePriorityQueue.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
    T info;                // contents
    vector<Edge<T> > adj;  // outgoing edges
    bool visited;          // auxiliary field
    double dist = 0;
    Vertex<T> *path = nullptr;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    Vertex<T> *path2 = nullptr; ///Project
    void addEdge(Vertex<T> *dest, double w, bool isReverse);

    ///Project
    bool isRoot;
    long int num,low;
    bool isArticulationPoint;
public:
    Vertex(T in);
    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
    T getInfo() const;
    double getDist() const;
    Vertex *getPath() const;
    friend class Graph<T>;
    friend class MutablePriorityQueue<Vertex<T>>;
    ///Project
    vector<Edge<T>> & getAdj();
    void setAdj(vector<Edge<T>> &adj);
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {isRoot = false; num = INF; low = INF;}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w, bool isReverse) {
    adj.push_back(Edge<T>(this, d, w, isReverse));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
    return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
    Vertex<T> *orig; 	// Fp07
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight

    bool selected; // Fp07
    ///Project
    bool hasConstruction;
    bool isReverse;
public:
    Edge(Vertex<T> *o, Vertex<T> *d, double w, bool isReverse);
    friend class Graph<T>;
    friend class Vertex<T>;

    // Fp07
    double getWeight() const;

    ///Project
    Vertex<T>* getOrig();
    Vertex<T>* getDest();
    void setConstruction(bool construction);
};

template <class T>
Edge<T>::Edge(Vertex<T> *o, Vertex<T> *d, double w, bool isReverse): orig(o), dest(d), weight(w), isReverse(isReverse) {hasConstruction = false;}

template <class T>
double Edge<T>::getWeight() const {
    return weight;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
    vector<Vertex<T> *> vertexSet;    // vertex set

    ///Project
    map<long int,int> idIndice;
    double maxX,maxY,minX,minY;
    void dfsVisit(Vertex<T> *v,  vector<T> & res);
    long int visitCounter;
    bool conexo;
    long int numCounter;

    // Fp05
    Vertex<T> * initSingleSource(const T &orig);
    bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
    double ** W = nullptr;   // dist
    int **P = nullptr;   // path
    int findVertexIdx(const T &in) const;
public:
    Vertex<T> *findVertex(const T &in) const;
    bool addVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w);
    int getNumVertex() const;
    vector<Vertex<T> *> getVertexSet() const;

    // Fp05 - single source
    Vertex<T>* dijkstraShortestPath(const T &s,bool useTwoPaths); ///Project
    void unweightedShortestPath(const T &s);
    void bellmanFordShortestPath(const T &s);
    vector<T> getPath(const T &origin, const T &dest) const;

    // Fp05 - all pairs
    void floydWarshallShortestPath();
    vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;
    ~Graph();

    // Fp07 - minimum spanning tree
    bool addBidirectionalEdge(const T &sourc, const T &dest, double w);

    //Auxiliary functions
    bool findInverseEdge(const Edge<T> &edge);

    ///Project
    Graph();
    Vertex<T> getVertex(int index);
    deque<Vertex<T>*> bidirectionalDijkstra(const T &start, const T &end);
    T getTfromId(long int id);
    void addMapPair(long int id);
    void addEdgeWithIds(long int id1, long int id2,double w);
    double getMaxX();
    double getMaxY();
    double getMinX();
    double getMinY();
    void setMaxX(double maxX);
    void setMaxY(double maxY);
    void setMinX(double minX);
    void setMinY(double minY);
    Vertex<T>* getVertexFromId(long int id);
    vector<T> dfs();
    void analyseConectivity();
};

template<class T>
Vertex<T> *Edge<T>::getOrig() {
    return this->orig;
}

template<class T>
Vertex<T> *Edge<T>::getDest() {
    return this->dest;
}

template<class T>
void Edge<T>::setConstruction(bool construction) {
    this->hasConstruction = construction;
}

template<class T>
vector<Edge<T>> &Vertex<T>::getAdj() {
    return this->adj;
}

template<class T>
void Vertex<T>::setAdj(vector<Edge<T>> &adj) {
    this->adj = adj;
}

template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
template <class T>
int Graph<T>::findVertexIdx(const T &in) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->info == in)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    /*
    if (findVertex(in) != nullptr)
        return false;
    */
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}


/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
    for(auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
        v->visited = false;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

template<class T>
Vertex<T>* Graph<T>::dijkstraShortestPath(const T &origin, bool useTwoPaths) {
    Vertex<T>* s;
    if (!useTwoPaths) s = initSingleSource(origin);
    else
    {
        s = findVertex(origin);
        s->dist = 0;
    }
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if (!v->visited) v->visited = true;
        else return v;
        for(auto e : v->adj) {
            if (e.hasConstruction) continue;
            auto oldDist = e.dest->dist;
            if (oldDist > (v->dist + e.weight))
            {
                e.dest->dist = (v->dist + e.weight);
                if (!useTwoPaths) e.dest->path = v;
                else e.dest->path2 = v;
            }
            if (!e.dest->visited)
            {
                if (oldDist == INF) q.insert(e.dest);
                else q.decreaseKey(e.dest);
            }
        }
    }
    return nullptr;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    vector<T> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for ( ; v != nullptr; v = v->path)
        res.push_back(v->info);
    reverse(res.begin(), res.end());
    return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
    auto s = initSingleSource(orig);
    queue< Vertex<T>* > q;
    q.push(s);
    while( ! q.empty() ) {
        auto v = q.front();
        q.pop();
        for(auto e: v->adj)
            if (relax(v, e.dest, 1))
                q.push(e.dest);
    }
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    initSingleSource(orig);
    for (unsigned i = 1; i < vertexSet.size(); i++)
        for (auto v: vertexSet)
            for (auto e: v->adj)
                relax(v, e.dest, e.weight);
    for (auto v: vertexSet)
        for (auto e: v->adj)
            if (relax(v, e.dest, e.weight))
                cout << "Negative cycle!" << endl;
}


/**************** All Pairs Shortest Path  ***************/

template <class T>
void deleteMatrix(T **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}



template <class T>
Graph<T>::~Graph() {
    deleteMatrix(W, vertexSet.size());
    deleteMatrix(P, vertexSet.size());
}

template<class T>
void Graph<T>::floydWarshallShortestPath() {
    unsigned n = vertexSet.size();
    deleteMatrix(W, n);
    deleteMatrix(P, n);
    W = new double *[n];
    P = new int *[n];
    for (unsigned i = 0; i < n; i++) {
        W[i] = new double[n];
        P[i] = new int[n];
        for (unsigned j = 0; j < n; j++) {
            W[i][j] = i == j? 0 : INF;
            P[i][j] = -1;
        }
        for (auto e : vertexSet[i]->adj) {
            int j = findVertexIdx(e.dest->info);
            W[i][j]  = e.weight;
            P[i][j]  = i;
        }
    }

    for(unsigned k = 0; k < n; k++)
        for(unsigned i = 0; i < n; i++)
            for(unsigned j = 0; j < n; j++) {
                if(W[i][k] == INF || W[k][j] == INF)
                    continue; // avoid overflow
                int val = W[i][k] + W[k][j];
                if (val < W[i][j]) {
                    W[i][j] = val;
                    P[i][j] = P[k][j];
                }
            }
}


template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
    vector<T> res;
    int i = findVertexIdx(orig);
    int j = findVertexIdx(dest);
    if (i == -1 || j == -1 || W[i][j] == INF) // missing or disconnected
        return res;
    for ( ; j != -1; j = P[i][j])
        res.push_back(vertexSet[j]->info);
    reverse(res.begin(), res.end());
    return res;
}

/**************** Minimum Spanning Tree  ***************/
template <class T>
bool Graph<T>::addBidirectionalEdge(const T &sourc, const T &dest, double w) {
    Vertex<T>* edgeOrigin;
    Vertex<T>* edgeDest;

    for (auto i : vertexSet)
    {
        if (i->info == sourc)
        {
            edgeOrigin = i;
            for (auto i2 : vertexSet)
            {
                if (i2->info == dest)
                {
                    edgeDest = i2;
                    i->adj.push_back(Edge<T>(edgeOrigin,edgeDest,w));
                    i2->adj.push_back(Edge<T>(edgeDest,edgeOrigin,w));
                    return true;
                }

            }
        }
    }



    return false;
}

template <class T>
bool Graph<T>::findInverseEdge(const Edge<T> &edge)
{
    return edge.orig->path == edge.dest;
}

template <class T>
Graph<T>::Graph()
{
    vertexSet.clear();
    visitCounter = 0;
    conexo = false;
}

template <class T>
Vertex<T> Graph<T>::getVertex(int index)
{
    return vertexSet.at(index);
}

template <class T>
deque<Vertex<T>*> Graph<T>::bidirectionalDijkstra(const T &start, const T &end)
{
    deque<Vertex<T>*> result;
    //thread second (&Graph<T>::dijkstraShortestPath,this,end,true);
    /*auto middle = */dijkstraShortestPath(start,false);

    //second.join();

    //auto vert = middle;
   /*
    while (vert != nullptr)
    {
        result.push_front(vert->info);
        vert = vert->path;
    }
    result.pop_back();
    vert = middle;
    while (vert != nullptr)
    {
        result.push_back(vert->info);
        vert = vert->path2;
    }*/

   auto dest = findVertex(end);

   while (dest->path != nullptr) {
       result.push_front(dest);
        dest = dest->path;
   }
    result.push_front(dest);
    return result;
}

template<class T>
T Graph<T>::getTfromId(long int id)
{
    int index = idIndice[id];
    return vertexSet.at(index)->info;
}

template <class T>
void Graph<T>::addMapPair(long int id)
{
    idIndice.insert(pair<long int, int>(id,vertexSet.size() - 1));
}

template <class T>
void Graph<T>::addEdgeWithIds(long int id1, long int id2,double w)
{
    int index1 = idIndice[id1];
    int index2 = idIndice[id2];

    auto origVert = vertexSet.at(index1);
    auto destVert = vertexSet.at(index2);

    origVert->addEdge(destVert,w,false);
    destVert->addEdge(origVert,w,true);
}

template<class T>
double Graph<T>::getMaxX() {
    return maxX;
}

template<class T>
double Graph<T>::getMaxY() {
    return maxY;
}

template<class T>
double Graph<T>::getMinX() {
    return minX;
}

template<class T>
double Graph<T>::getMinY() {
    return minY;
}

template<class T>
void Graph<T>::setMaxX(double maxX) {
    this->maxX = maxX;
}

template<class T>
void Graph<T>::setMaxY(double maxY) {
    this->maxY = maxY;
}


template<class T>
void Graph<T>::setMinX(double minX) {
    this->minX = minX;
}

template<class T>
void Graph<T>::setMinY(double minY) {
    this->minY = minY;
}

template<class T>
Vertex<T> *Graph<T>::getVertexFromId(long int id) {
    return vertexSet.at(idIndice[id]);
}

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::dfs() {
    vector<T> res;

    for (auto i : vertexSet)
    {
        i->visited = false;
        i->isArticulationPoint = false;
    }
    numCounter = 1;
    for (auto i : vertexSet)
    {
        visitCounter = 0;
        if (!i->visited) {i->isRoot = true; dfsVisit(i,res);i->isRoot = false;}
        if (visitCounter == vertexSet.size()) conexo = true;
    }

    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) {
    v->visited = true;
    visitCounter++;
    v->num = numCounter++;
    v->low = v->num;
    res.push_back(v->info);
    for (auto i : v->adj)
    {
        if (i.isReverse) continue;
        if (v->isRoot && i.dest != v->adj.front().dest && !i.dest->visited) v->isArticulationPoint = true;
        if (!i.dest->visited) dfsVisit(i.dest,res);
        if (i.dest->num < v->low) v->low = i.dest->num;
        if (i.dest->low < v->low) v->low = i.dest->low;
        if (i.dest->low >= v->num && !v->isRoot) v->isArticulationPoint = true;
    }

}

template<class T>
void Graph<T>::analyseConectivity() {
    dfs();
    if (!conexo) cout << "O grafo nao e conexo.\n";
    else cout << "O grafo e conexo.\n";
    cout << "Os pontos de articulacao tem os ids: \n";

    for (auto vert : vertexSet)
    {
        if (vert->isArticulationPoint)
        {
            cout << to_string(vert->info.getId()) << " ";
        }

    }
    cout << endl;
}

#endif /* GRAPH_H_ */
