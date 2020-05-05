#include "Graph.h"

Graph::Graph(std::vector<const char*> &v)
	:mNumE(v.size())
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		mArray.insert(std::make_pair(v[i], std::list<std::string>()));
	}
	mVisitInfo.reserve(v.size());

}

void Graph::GraphDestroy()
{
	
}

void Graph::AddEdge(std::string from, std::string to)
{
	auto iter = mArray.find(from);
	if (iter == mArray.end())
	{
		return;
	}

	iter->second.push_back(to);
	iter->second.sort(std::less<std::string>());
}

void Graph::ShowGraphEdgeInfo()
{
	auto iter = mArray.begin();

	for (; iter != mArray.end(); ++iter)
	{
		cout << iter->first;
		auto iterList = iter->second.begin();
		for (;iterList!=iter->second.end();++iterList)
		{
			cout << *iterList;
		}
		cout << endl;
	}
}

int Graph::GetEdge()
{
	return mNumE;
}

void Graph::DFShowGraphVertex(const char* start)
{

}

bool Graph::SortCallback(const std::string& lhs, const std::string& rhs)
{
	return lhs > rhs;
}
