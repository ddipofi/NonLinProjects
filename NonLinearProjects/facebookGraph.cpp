// facebookGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

const std::string FACEBOOK_FILENAME = "facebook-links.txt";

void addEdge(std::vector<std::unordered_set<int>>& adjList, int u, int v);

int main()
{
    std::ifstream inFS;
    std::cout << "Opening file " << FACEBOOK_FILENAME << std::endl;
    inFS.open(FACEBOOK_FILENAME);
    if (!inFS.is_open()) {
        std::cout << "Could not open file " << FACEBOOK_FILENAME << std::endl;
        return 1;
    }

    // Read in edge line by line and add edges
    std::vector<std::unordered_set<int>> facebookAdjList;
    int u, v, lineNum = 0;
    std::string timestamp;
    while (!inFS.eof()) {
        lineNum++;
        if (lineNum % 100000 == 0)
            std::cout << "Reading line " << lineNum << std::endl;

        inFS >> u >> v >> timestamp;
        if (!inFS.fail())
            addEdge(facebookAdjList, u, v);
    }
    inFS.close();

    // Compute degree statistics over all vertices
    int numVertices = facebookAdjList.size();
    double meanDegree = 0;
    double meanAdjDegree = 0;
    for (int i = 0; i < facebookAdjList.size(); i++) {
        int vertexDeg = facebookAdjList.at(i).size();
        int adjVertexDeg = 0;
        if (vertexDeg >= 0)
            meanDegree += vertexDeg / (double) numVertices;
        for (int j = 0; j < facebookAdjList.at(i).size(); j++)
        {
            adjVertexDegree = facebookAdjList.at(j).size();
            if (adjVertexDeg >= 0)
                meanAdjDegree += adjVertexDegree / (double) vertexDeg;
        }
        //std::cout << "Vertex " << i << " has degree " << vertexDeg << std::endl;
    }
    meanAdjDegree /= numVertices;
    
    std::cout << "Mean degree: " << meanDegree << std::endl;
    std::cout << "Mean adjacent degree: " << meanAdjDegree << std::endl;

    return 0;
}

void addEdge(std::vector<std::unordered_set<int>>& adjList, int u, int v) {
    // If either node is not already in the outer list, then add it
    if (std::max(u, v) >= adjList.size())
        adjList.resize(std::max(u, v) + 1);

    // Check if v is already in the inner set for node u, and if not, add it,
    // and vice versa
    if (adjList.at(u).count(v) == 0)
        adjList.at(u).insert(v);
    if (adjList.at(v).count(u) == 0)
        adjList.at(v).insert(u);
}











/*
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

unordered_map<int, vector<int>> uMap;
vector<string> edgeValues;
void addEdge(int vertex1, int vertex2);
void addNewVertex(int vertex);
void printList(unordered_map<int, vector<int>> const& m);

int main()
{
    const string facebookText = "facebook-links.txt";

    ifstream inFS;
    inFS.open(facebookText);
    
    if (!inFS.is_open())
    {
    	cout << "Could not open file " << facebookText << endl;
    	return EXIT_FAILURE;
    }
    
    int a = 0;
    int b = 0;
    string extra = "";

    while (!inFS.eof())
    {
    	inFS >> a >> b >> extra;
    	if (!inFS.fail())
    	{
    		addNewVertex(a);
            addNewVertex(b);
            addEdge(a, b);
    	}
    }

    inFS.close();

    cout << "hello" << endl;
    printList(uMap);

    return 0;
}

void printList(unordered_map<int, vector<int>> const& m)
{
    int num100plus = 0;
    int top = 0;
    int bot = 0;

    for (auto const& pair : m)
    {
        bot++;
        top += pair.second.size();

        if (pair.second.size() >= 100)
        {
            num100plus++;
        }
    }

    cout << "The average degree over all vertices in the graph is " << (top / bot) << "\nThe number of vertices with degree greater than or equal to 100 is " << num100plus;
}

void addEdge(int vertex1, int vertex2)
{
    /*if (find(edgeValues.begin(), edgeValues.end(), to_string(vertex1) + ":" + (to_string(vertex2))) == edgeValues.end() && find(edgeValues.begin(), edgeValues.end(), to_string(vertex2) + ":" + (to_string(vertex1))) == edgeValues.end())
    {
        uMap[vertex1].push_back(vertex2);
        uMap[vertex2].push_back(vertex1);
        edgeValues.push_back(to_string(vertex1) + ":" + (to_string(vertex2)));
        edgeValues.push_back(to_string(vertex2) + ":" + (to_string(vertex1)));
    }*/

    uMap[vertex1].push_back(vertex2);
    uMap[vertex2].push_back(vertex1);
}

void addNewVertex(int vertex)
{
    if (uMap.find(vertex) == uMap.end())
    {
        vector<int> vectorr;
        uMap.insert({vertex, vectorr});
    }
}
*/
