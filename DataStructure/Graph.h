#pragma once
#include <iostream>
#include <string>
#include <map>

#include <Windows.h>
#include <list>
#include <vector>
using namespace std;
class Graph 
{
private:
	int mNumE; // 간선의 수
	std::map<std::string,std::list<std::string>> mArray;
	std::vector<const char*> mVisitInfo;

public:
	Graph(std::vector<const char*>& v);
	void GraphDestroy();
	void AddEdge(std::string from, std::string to);
	void ShowGraphEdgeInfo();
	int GetEdge();
	void DFShowGraphVertex(const char* start);
	bool SortCallback(const std::string& lhs, const std::string& rhs);

};