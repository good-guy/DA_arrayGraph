#pragma once

// adjacency matrix representation of a weighted directed graph

#ifndef INCLUDEDH_WDIGRAPH
#define INCLUDEDH_WDIGRAPH

#include <iostream>
#include <sstream>
#include <iterator>
#include "graph.h"
#include "weightedEdge.h"
#include "vertexIterator.h"
#include "make2dArrayNoCatch.h"
#include "delete2dArray.h"
#include "myExceptions.h"
#include "arrayQueue.h"
#include "graphChain.h"
#include "minHeap.h"
#include<vector>

using namespace std;

template <class T>
class adjacencyWDigraph : public graph<T>
{
protected:
	int n;           // number of vertices
	int e;           // number of edges
	vector<vector<int>> *a; // adjacency array
	T noEdge;        // denotes absent edge

public:



#endif