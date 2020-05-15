#include "Graph.h"

Graph::Graph(std::vector<const char*>& v)
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
	auto iter_From = mArray.find(from);
	auto iter_To = mArray.find(to);

	if (iter_From == mArray.end())
	{
		return;
	}
	if (iter_To == mArray.end())
	{
		return;
	}

	iter_From->second.push_back(to);
	iter_From->second.sort(std::less<std::string>());

	iter_To->second.push_back(from);
	iter_To->second.sort(std::less<std::string>());
}

void Graph::ShowGraphEdgeInfo()
{
	auto iter = mArray.begin();

	for (; iter != mArray.end(); ++iter)
	{
		cout << iter->first;
		auto iterList = iter->second.begin();
		for (; iterList != iter->second.end(); ++iterList)
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

void Graph::DFShowGraphVertex(std::string start)
{
	auto iter = mArray.find(start);

	if (iter == mArray.end())
	{
		return;
	}
	mVisitInfo.clear();
	mVisitInfo.push_back(start);
	std::stack<std::string> stack;
	if (!SearchOver(stack, start))
	{
		return;
	}

	std::string lastNode = mVisitInfo[mVisitInfo.size() - 1];
	while (!stack.empty())
	{
		
		if (SearchOver(stack,lastNode))
		{
			lastNode = mVisitInfo[mVisitInfo.size() - 1];
		}
		else
		{
			lastNode = stack.top();
			stack.pop();
		}
	}

	for (size_t i = 0; i < mVisitInfo.size(); ++i)
	{
		cout << mVisitInfo[i] << " ";
	}
	cout << endl;

}


void Graph::BFSub(std::queue<std::string>& queue,std::string str)
{
	auto map = mArray.find(str);
	auto list = map->second.begin();
	std::queue<std::string> tempQueue = queue;
	std::vector<std::string> tempVector;

	while (!tempQueue.empty())
	{
		tempVector.push_back(tempQueue.front());
		tempQueue.pop();
	}

	bool bVisit = false;
	for (; list != map->second.end(); ++list)
	{
		bVisit = false;
		for (int i = 0; i<mVisitInfo.size(); ++i)
		{
			if (*list == mVisitInfo[i])
			{
				bVisit = true;
				break;
			}
		}
		if (!bVisit)
		{
			
			queue.push(*list);
		}
	}
}
void Graph::BFShowGraphVertex(std::string start)
{
	auto iter = mArray.find(start);
	if (iter == mArray.end())
	{
		return;
	}
	mVisitInfo.clear();
	std::queue<std::string> queue;
	// 처음에 start 넣고 봄.
	queue.push(start);
	while (!queue.empty())
	{
		std::string  dequeStr = queue.front();
		queue.pop();
		mVisitInfo.push_back(dequeStr);
		BFSub(queue, dequeStr);
	}
	for (size_t i = 0; i < mVisitInfo.size(); ++i)
	{
		cout << mVisitInfo[i] << " ";
	}
	cout << endl;
}

bool Graph::SearchOver(std::stack<std::string> & stack,std::string node)
{
	auto iter = mArray.find(node);

	auto list = iter->second.begin();
	bool bVisited ;

	for (; list != iter->second.end(); ++list)
	{
		bVisited = false;
		for (size_t i = 0; i < mVisitInfo.size(); ++i)
		{
			if (mVisitInfo[i] == *list)
			{
				bVisited = true;
				break;
			}
		}
		if (!bVisited)
		{
			mVisitInfo.push_back(*list);
			stack.push(node);
			return true;
		}

	}
	return false;
}

bool Graph::SortCallback(const std::string& lhs, const std::string& rhs)
{
	return lhs > rhs;
}
