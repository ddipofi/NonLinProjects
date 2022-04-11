#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

unordered_map<int, vector<int>> uMap;
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
    uMap[vertex1].push_back(vertex2);
    uMap[vertex2].push_back(vertex1);
}

void addNewVertex(int vertex) {

    if (uMap.find(vertex) == uMap.end())
    {
        vector<int> vectorr;
        uMap.insert({vertex, vectorr});
    }
}







//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <unordered_map>
//#include <forward_list>
//
//using namespace std;
//
//const string facebookText = "facebook-links.txt";
//
//class graph
//{
//public:
//	unordered_map<int, forward_list<int>>* outerMap;
//
//	graph()
//	{
//		//outer = new vector<int>;
//	}
//
//	void addEdge(int x, int y)
//	{
//		forward_list<int> fList;
//
//		outerMap.emplace(x, fList).first->second = fList;
//		
//		
//
//		outerMap[x] = fList;
//		outer[y].push_back(x);
//	}
//
//	void printAdjList()
//	{
//		for (int i = 1; i < 100; i++)
//		{
//			cout << i << ": [";
//			for (int adj : outer[i])
//			{
//				cout << adj << ",";
//			}
//			cout << "]" << endl;
//		}
//	}
//};
//
//int main()
//{
//	ifstream inFS;
//	inFS.open(facebookText);
//
//	if (!inFS.is_open())
//	{
//		cout << "Could not open file " << facebookText << endl;
//		return EXIT_FAILURE;
//	}
//
//	graph g;
//	int a = 0;
//	int b = 0;
//	string extra = "";
//
//	for (int i = 0; i < 200; i++)
//	{
//		inFS >> a >> b >> extra;
//		if (!inFS.fail())
//		{
//			g.addEdge(a, b);
//		}
//	}
//	inFS.close();
//
//	g.printAdjList();
//
//	return 0;
//}