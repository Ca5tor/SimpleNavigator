#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <list>

struct Vertex;

struct Edge {
	Vertex	*pVrtx;	// ptr to vertex
	int		weight;	// weight this Edges
};

typedef std::list<Edge> ListEdge;

struct Vertex {
	int			key;	   // number vertex
	bool		used;	   // status visit
	int			sizeEdges; // number edges this vertex
	ListEdge	edges;

	Vertex(int num) :
		key(num),
		used(false),
		sizeEdges(0) {}
};

typedef std::list<Vertex *> ListPtrVertex;

class Graph {
public:
	Graph() : _sizeVertexes(0) {}

	~Graph() {
		for (ListPtrVertex::iterator it = _vertexes.begin(); it != _vertexes.end(); it++)
			delete *it;		
	}

	void	loadGraphFromFile(std::string filename) {
		(void) filename;
	}

	void	initGraph(void){
		// для проверки графа на обход https://graphonline.ru/
		const int N = 4;
		int mas[N][N] = {
			// 11
			// {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
			// {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
			// {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
			// {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
			// {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
			// {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
			// {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
			// {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
			// {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
			// {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
			// {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}
			{0, 1, 0, 1},
			{0, 0, 1, 1},
			{0, 1, 0, 0},
			{1, 0, 1, 0}
		};
		for (size_t i = 0; i < N; i++) addVertex(i);

		for (size_t i = 0; i < N; i++) {
			for	(size_t j = 0; j < N; j++) {
				if (mas[i][j] > 0) addEdges(i, j, mas[i][j]);
			}		
		}		
	}

	int		getSize(void) { return _sizeVertexes; }

	Vertex*	getVertex(const int n) {
		//сделать проверку на существование элементов
		ListPtrVertex::iterator it = _vertexes.begin();
		std::advance(it, n);
		return *it;
	}

private:
	ListPtrVertex	_vertexes;			//список вершин с ребрами
	int				_sizeVertexes;		//кол-во вершин
	//bool			_isDirectedGraph;	//граф орентированный true иначе false

	void	addVertex(int key) {
		_vertexes.push_back(new Vertex(key));
		_sizeVertexes++;
	}

	void	addEdges(int v1, int v2, int weight) {
		//сделать проверку на существование элементов

		Vertex* pV1 = getVertex(v1);
		Vertex* pV2 = getVertex(v2);
		Edge edge;

		edge.pVrtx = pV2;
		edge.weight = weight;
		pV1->edges.push_back(edge);
		pV1->sizeEdges++;
	}
};

#endif