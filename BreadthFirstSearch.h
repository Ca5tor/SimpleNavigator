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
		std::vector<int> depthFirstSearch(Graph &graph, int startVertex) {
			// Vertex* v = graph.getVertex(startVertex);
			// v->used = 1;
			// std::vector<int> route;
			// std::stack<Vertex *> stack;

			// list<int>::iterator i;
  			// for (i = adjList.begin(); i != adjList.end(); ++i)
    		// 	if (v->used != 1;)
			// 		depthFirstSearch(graph, v);
			int dfs = 0;
  			Stack stack;

  			visited[start] = true;
  			dfsnumber[start] = ++dfs;

  			stack.Push(start, 0); // (Вершина, Начальный сосед)

  			while (stack.first)
  			{
   				int v = stack.first->data1;
    			// Текущая вершина

    			int i = stack.first->data2; 
    			// Продолжаем просмотр соседей с соседа `i`

    			for (; i < size; ++i)
      				if (graph[v][i] && !visited[i])
      				{ // Найдена новая вершина
        				visited[i] = true;
        				dfsnumber[i] = ++dfs;

        				stack.first->data2 = i + 1; 
        				// Запомним, что когда мы вернемся в эту вершину, то продолжать 
        				// просмотр надо будет с соседа `i + 1`

        				stack.Push(i, 0);
        				// Новая вершина: (Вершина, Начальный сосед)

        				// Прерываем обработку текущей вершины и немедленно переходим к
       	 				// обработке новой вершины
        				break;
      				}

    			if (i == size)
      			// Все соседи текущей вершины просмотрены и ничего нового больше не
      			// найдено - прощаемся с вершиной и делаем шаг назад
      			stack.Pop();
  			}
		};

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