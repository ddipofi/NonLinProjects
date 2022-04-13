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
            adjVertexDeg = facebookAdjList.at(j).size();
            if (adjVertexDeg >= 0)
                meanAdjDegree += adjVertexDeg / (double) vertexDeg;
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
