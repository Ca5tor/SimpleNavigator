#ifndef S21_GRAPH_ALGORITHMS_H
# define S21_GRAPH_ALGORITHMS_H

#include <queue>
#include "Graph.h"

class GraphAlgorithms {
	public:
		GraphAlgorithms() {};
		//GraphAlgorithms(const GraphAlgorithms &obj) {};
		virtual	~GraphAlgorithms() {};

		//поиск в ширину в графе от заданной вершины
		std::vector<int> breadthFirstSearch(Graph &graph, int startVertex) {
			Vertex* v = graph.getVertex(startVertex);
			v->used = 1;
			std::vector<int> route;
			route.push_back(v->key + 1);
			std::queue<Vertex *> queue;
			queue.push(v);
			while (!queue.empty()) {
				Vertex *to = queue.front();
				for (Edge edge : to->edges){
					if (!edge.pVrtx->used) {
						edge.pVrtx->used = 1;
						route.push_back(edge.pVrtx->key + 1);
						queue.push(edge.pVrtx);
					}
				}
				queue.pop();
			}
			return route;
		}

		//нерекурентный поиск в глубину в графе от заданной вершины
		void depthFirstSearch(Graph &graph, int startVertex) {};

		//Поиск кратчайших путей в графе
		void getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {};

		//Поиск минимального остовного дерева
		void getLeastSpanningTree(Graph &graph) {};

		//Задача коммивояжера
		void solveTravelingSalesmanProblem(Graph &graph) {};
		void solveTravelingSalesmanProblemV1(Graph &graph) {};
		void solveTravelingSalesmanProblemV2(Graph &graph) {};

};

#endif