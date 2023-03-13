#ifndef TEST_H
#define TEST_H

# include <iostream>
# include <string>
# include <list>
# include <fstream>
# include <vector>

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
#include <sstream>
class Graph {
public:
	Graph() : _sizeVertexes(0) {}

	~Graph() {
		for (ListPtrVertex::iterator it = _vertexes.begin(); it != _vertexes.end(); it++)
			delete *it;		
	}

	bool errorReport(std::string msg) {
		std::cout << "Error: " << msg << std::endl;
		return false;
	}

	void printAllInfoToVertices(void) {
		std::cout << "===Info to Vertex===" << std::endl;
		for (int i = 0; i < _sizeVertexes; i++) {
			Vertex *v = getVertex(i);
			std::cout << "VERTEX: " << i + 1 << std::endl;
			for (Edge edge : v->edges) {
				std::cout << " *key= " << edge.pVrtx->key + 1<<
				" weight= " << edge.weight << std::endl;
			}
		}
	}

	bool errLoadGraph(std::fstream *file, std::string msg) {
		std::cout << "ERROR: " << msg << std::endl;
		file->close();
		return false;
	}

	bool	loadGraphFromFile(std::string filename) {
		std::fstream file(filename);

		if (!file) return errLoadGraph(&file, "ERROR 0"); // Файл нельзя открыть

		std::string	line("");
		int kol = 0, tmpNum;

		// считываем 1ю строку чтобы получить кол-во вершин (строк и колонок матрицы)
		std::getline(file, line);
		for(std::stringstream ss(line); !ss.eof(); ) {
			kol++;
			if (!(ss >> tmpNum && tmpNum > 0) || kol > 1) return errLoadGraph(&file, "ERROR 1"); // в строке больше 1 числа или значения не корректны
		}
		for (int i = 0; i < tmpNum; i++) addVertex(i);

		int str = 0;

		// считываем матрицу смежности и сразу заполняем вершины
		while (std::getline(file, line)) {
			kol = 0;
			if (str == _sizeVertexes) return errLoadGraph(&file, "ERROR 2"); // строк больше чем указано вершин
			for (std::stringstream ss(line); !ss.eof(); ) {
				if (!(ss >> tmpNum)) return errLoadGraph(&file, "ERROR 3"); // некорректные значения (не целое число)
				if (tmpNum > 0) addEdges(str, kol, tmpNum);
				kol++;
			}
			str++;
			if (kol != _sizeVertexes) return errLoadGraph(&file, "ERROR 4"); // в матрице не хватает значений (матрица не выровнена)
		}
		if (str != _sizeVertexes) return errLoadGraph(&file, "ERROR 5"); // строк матрицы меньше (нет значений для вершины)
		file.close();
		return true;
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
		std::cout << "add Vertex: " << key << std::endl;
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