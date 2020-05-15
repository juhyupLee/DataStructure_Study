#pragma once
#include <iostream>
#include <string>
#include <map>

#include <Windows.h>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Graph 
{
private:
	int mNumE; // 간선의 수
	std::map<std::string,std::list<std::string>> mArray;
	std::vector<std::string> mVisitInfo;


public:
	Graph(std::vector<const char*>& v);
	void GraphDestroy();
	void AddEdge(std::string from, std::string to);
	void ShowGraphEdgeInfo();
	int GetEdge();
	void DFShowGraphVertex(std::string start);
	void BFSub(std::queue<std::string>& queue, std::string str);
	void BFShowGraphVertex(std::string start);
	bool SortCallback(const std::string& lhs, const std::string& rhs);
	bool SearchOver(std::stack<std::string>& stack, std::string node);


};

