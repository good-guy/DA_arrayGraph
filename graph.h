#pragma once

#ifndef INCLUDEDH_GRAPH
#define INCLUDEDH_GRAPH

#include "edge.h"
#include "vertexIterator.h"
#include "arrayQueue.h"
#include "arrayStack.h"
#include "myExceptions.h"
#include "binNode.h"
#include "weightedEdge.h"
#include "minHeap.h"
#include "fastUnionFind.h"
#include "arrayListWithIterator.h"

using namespace std;

template<class T>
class graph
{
public:
	virtual ~graph() {}
	virtual int numberOfVertices() const = 0;
	virtual int numberOfEdges() const = 0;
	virtual bool existsEdge(int, int) const = 0;
	virtual void insertEdge(edge<T>*) = 0;
	virtual void eraseEdge(int, int) = 0;
	virtual int degree(int) const = 0;
	virtual int inDegree(int) const = 0;
	virtual int outDegree(int) const = 0;
	virtual bool directed() const = 0;
	virtual bool weighted() const = 0;
	virtual vertexIterator<T>* iterator(int) = 0;
	virtual void output(ostream&) const = 0;
	virtual bool prim(arrayList<T> *, arrayList<weightedEdge<T>> *, T) = 0;

	int* findPath(int theSource, int theDestination)
	{
		int n = numberOfVertices();
		path = new int[n + 1];
		path[1] = theSource;
		reach = new int[n + 1];
		length = 1;//cause theSource
		//reach[1] = theSource;
		destination = theDestination;
		for (int i = 1; i < n + 1; i++)
		{
			reach[i] = 0;
		}
		if (theSource == theDestination || rFindPath(theSource))
		{
			path[0] = length-1;//length=numberOfVertices-1;
			return path;
		}
		else
		{
			delete []path;
			path = nullptr;
			//return path; opti
		}
		delete[]reach;
		return path;
	}

protected:
	static int *reach;//marking 0/1 to judge if a vertex has been reached
	static int *path;
	static int label;
	static int length;//the length of path
	static int destination;
	static int* bin;   // pointer to first node in bin
	static binNode* node;


	bool rFindPath(int s)
	{
		reach[s] = 1;
		//path[1] = s;
		vertexIterator<T> *is = iterator(s);
		int u;//current vertex
		while ((u=is->next())!=0)
		{
			if (reach[u] == 0)
			{
				path[++length] = u;
				//reach[u] = 1;it seems not neccessary
				if (u == destination || rFindPath(u))
				{
					return true;
				}
				else//
				{
					//path[length--] = 0;
					--length;//it's not neccessary to reset the path,it'll be covered by new vertex
					//return false;WRONG the next of u may be true
				}
			}
			//else	ignore the reached node
		}
		delete is;
		return false;
	}
	bool topologicalOrder(int *theOrder)
	{
		
		int n = numberOfVertices();
		theOrder = new int[n];

		if (!directed())
		{
			cout << "无向图没有拓扑序列" << endl;
			return false;
		}

		else
		{
			int j = 0;
			int *inDegree = new int[n+1];
			for (int i = 1; i <= numberOfEdges(); i++)
			{
				inDegree[i] == 0;
			}
			for (int i = 1; i <= n; i++)
			{
				vertexIterator<T> *ii = iterator(i);
				int u = 0;
				while ((u=ii->next())!=0)
				{
					inDegree[u]++;
				}
			}
			arrayStack<T> tempVertex;
			//不同在于a 进栈1遍历全部2检查从改变的点;b1一个一个入列2一齐入列
			//while (true)
			//{
			//	for (int i = 1; i <= n; i++)//push to stack
			//	{
			//		if (inDegree[i] == 0)
			//		{
			//			tempVertex.push(i);
			//			vertexIterator<T> *ii = iterator(i);
			//			int u = ii;
			//			do {
			//				--inDegree[u];
			//			} while ((u = ik->next()) != 0)
			//		}
			//		
			//	}
			//	while(!tempVertex.empty())
			//	{
			//		theOrder[j++] = tempVertex.top();
			//		tempVertex.pop();
			//	}
			//	
			//}
			for (int i = 1; i <= n; i++)//push to stack
			{
				if (inDegree[i] == 0)
				{
					tempVertex.push(i);
				}
			}
			while (!tempVertex.empty())
			{
				int nextVertex = tempVertex.top();
				inOrder[j++] = nextVertex;
				tempVertex.pop();
				vertexIterator<T> *inextVertex = iterator(nextVertex);
				int u = 0;
				while ((u = inextVertex->next()) != 0)
				{
					if ((--inDegree[u] == 0)
					{
						tempVertex.push(u);
					}
				}

			}
		}
		return (j == n);
	}

};

int* graph<bool>::reach;
int graph<bool>::label;
int* graph<bool>::path;
int graph<bool>::length;
int graph<bool>::destination;
int* graph<bool>::bin;
binNode* graph<bool>::node;
int* graph<int>::reach;
int graph<int>::label;
int* graph<int>::path;
int graph<int>::length;
int graph<int>::destination;
int* graph<int>::bin;
binNode* graph<int>::node;
int* graph<float>::reach;
int graph<float>::label;
int* graph<float>::path;
int graph<float>::length;
int graph<float>::destination;
int* graph<float>::bin;
binNode* graph<float>::node;
int* graph<double>::reach;
int graph<double>::label;
int* graph<double>::path;
int graph<double>::length;
int graph<double>::destination;
int* graph<double>::bin;
binNode* graph<double>::node;

#endif