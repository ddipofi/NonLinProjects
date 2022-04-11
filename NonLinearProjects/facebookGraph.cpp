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

    printList(uMap);

    return 0;
}

void printList(unordered_map<int, vector<int>> const& m)
{
    for (auto const& pair : m) {
        int i = 0;
        cout << "{" << pair.first << ": ";
        for (i = 0; i < pair.second.size() - 1; i++)
        {
            cout << pair.second.at(i) << ", ";
        }
        cout << pair.second.at(i) << "}\n";
    }
}

void addEdge(int vertex1, int vertex2)
{
    if (find(edgeValues.begin(), edgeValues.end(), to_string(vertex1) + ":" + (to_string(vertex2))) == edgeValues.end() && find(edgeValues.begin(), edgeValues.end(), to_string(vertex2) + ":" + (to_string(vertex1))) == edgeValues.end())
    {
        uMap[vertex1].push_back(vertex2);
        uMap[vertex2].push_back(vertex1);
        edgeValues.push_back(to_string(vertex1) + ":" + (to_string(vertex2)));
        edgeValues.push_back(to_string(vertex2) + ":" + (to_string(vertex1)));
    }
}

void addNewVertex(int vertex)
{
    if (uMap.find(vertex) == uMap.end())
    {
        vector<int> vectorr;
        uMap.insert({vertex, vectorr});
    }
}