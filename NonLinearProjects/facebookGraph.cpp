#include <string>

class Vertex
{
public:
    std::string label;

    Vertex(std::string vertexLabel)
    {
        label = vertexLabel;
    }

    Vertex& addVertex(std::string newVertexLabel)
    {
        Vertex* newVertex = Vertex*(newVertexLabel);

        // Every vertex must exist as a key in both maps
        fromEdges.put(newVertex, new ArrayList<Edge>());
        toEdges.put(newVertex, new ArrayList<Edge>());

        return newVertex;
    }
}

class Edge
{
public:
    Vertex* fromVertex;
    Vertex* toVertex;

    Edge(Vertex* from, Vertex* to)
    {
        fromVertex = from;
        toVertex = to;
    }

    public Edge addDirectedEdge(Vertex fromVertex, Vertex toVertex, double weight) {
        // Don't add the same edge twice
        if (hasEdge(fromVertex, toVertex)) {
            return null;
        }

        // Create the Edge object
        Edge newEdge = new Edge(fromVertex, toVertex, weight);

        // Add the edge to the appropriate list in both maps
        fromEdges.get(fromVertex).add(newEdge);
        toEdges.get(toVertex).add(newEdge);

        return newEdge;
    }
}

class Graph {
    private HashMap<Vertex, ArrayList<Edge>> fromEdges;

    private HashMap<Vertex, ArrayList<Edge>> toEdges;

    public Graph() {
        fromEdges = new HashMap<Vertex, ArrayList<Edge>>();
        toEdges = new HashMap<Vertex, ArrayList<Edge>>();
    }

    // Returns a collection of all edges in the graph
    public Collection<Edge> getEdges() {
        HashSet<Edge> edges = new HashSet<Edge>();
        for (ArrayList<Edge> edgeList : fromEdges.values()) {
            edges.addAll(edgeList);
        }
        return edges;
    }

    // Returns the collection of edges with the specified fromVertex
    public Collection<Edge> getEdgesFrom(Vertex fromVertex) {
        return fromEdges.get(fromVertex);
    }

    // Returns the collection of edges with the specified toVertex
    public Collection<Edge> getEdgesTo(Vertex toVertex) {
        return toEdges.get(toVertex);
    }

    // Returns a vertex with a matching label, or null if no such vertex exists
    public Vertex getVertex(String vertexLabel) {
        // Search the collection of vertices for a vertex with a matching label
        for (Vertex vertex : getVertices()) {
            if (vertex.label.equals(vertexLabel)) {
                return vertex;
            }
        }
        return null;
    }

    // Returns the collection of all of this graph's vertices
    public Collection<Vertex> getVertices() {
        return fromEdges.keySet();
    }

    ...
}





public Edge[] addUndirectedEdge(Vertex vertexA, Vertex vertexB, double weight) {
    Edge edge1 = addDirectedEdge(vertexA, vertexB, weight);
    Edge edge2 = addDirectedEdge(vertexB, vertexA, weight);
    Edge[] result = { edge1, edge2 };
    return result;
}

// Returns true if this graph has an edge from fromVertex to toVertex
public boolean hasEdge(Vertex fromVertex, Vertex toVertex) {
    if (!fromEdges.containsKey(fromVertex)) {
        // fromVertex is not in this graph
        return false;
    }

    // Search the list of edges for an edge that goes to toVertex
    ArrayList<Edge> edges = fromEdges.get(fromVertex);
    for (Edge edge : edges) {
        if (edge.toVertex == toVertex) {
            return true;
        }
    }

    return false;
}