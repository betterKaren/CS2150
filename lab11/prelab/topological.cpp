/**
* @author Yu Du, yd2am
* @filename topological.cpp
* @date 2019.11.30
* @details This is the program to find topological sort from a given text file storing edges.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <list>
#include <string>

using namespace std;

/**
* @brief This is the class for vertices in graph.
* @details Each vertex stores a value(string),
*	indegree(int) representing how many edges are going into this vertex,
*	and a list of vertex pointers representing the adjacent vertices.
*/
class Vertex {
public:
	string value;
	int indegree;
	list<Vertex*> adj;

	/**
	* @brief Vertex constructor
	* @param s the value of this vertex.
	*/
	Vertex(string s) {
		value = s;
		indegree = 0;
	}
	/**
	* @brief Vertex constructor
	* @param s the value
	* @param i the indegree of this vertex.
	*/
	Vertex(string s, int i) {
		value = s;
		indegree = i;
	}
	/**
	* @brief Vertex destructor, do as default
	*/
	~Vertex(){}
};


/**
* @brief This is the method to find topological sort of a graph.
* @details Based on the graph, find the vertices with indegree as 0. Start to find topological sort.
* @param vertices The adjacent list of this graph.
* @param myQueue The queue that always storing vertices whose indegree = 0.
*/
void topSort(vector<Vertex*> vertices, queue<Vertex*> myQueue) {
	// push the vertices with indegree=0 into queue, to be sorted
	for(int i=0; i<vertices.size(); i++) {
		if(vertices[i]->indegree == 0)
			myQueue.push(vertices[i]);
	}

	while(myQueue.size() > 0) {
		Vertex* cur = myQueue.front();
		myQueue.pop();
		cout << cur->value << " ";

		list<Vertex*>::iterator iter;
		for(iter = cur->adj.begin(); iter != cur->adj.end(); iter++) {
			Vertex *v = *iter;
			// decrement indegree
			v->indegree--;

			if(v->indegree == 0)
				myQueue.push(v);
		}
	}
	cout << endl;
}


/**
* @brief This is the method to build a graph by setting up an adjacent list.
* @details If one vertex has been visited, then set its position to the previous position.
* But if hasn't been visited, push this vertex into the vector that stores all the vertices in this graph.
* In the end, for simplicity, only push dest into src's adjacent list.
* @param s1 The value of the first vertex (source).
* @param s2 The value of the second vertex (destination).
* @param vertices The adjacent list of this graph.
*/
vector<Vertex*> buildGraph(string s1, string s2, vector<Vertex*> vertices) {
	int pos1 = 0;				// position of vertex1 in the vector
    int pos2 = 0;				// position of vertex2 in the vector
    bool visited1 = false;		// vertex1 is visited or not
    bool visited2 = false;		// vertex2 is visited or not

    // check whether this vertex has been visited
    for(int i=0; i<vertices.size(); i++) {
    	if(vertices[i]->value == s1) {	// if true, the this vertex has been visited
    		visited1 = true;
    		pos1 = i;
    	}

    	if(vertices[i]->value == s2) {	// if true, the this vertex has been visited
    		visited2 = true;
    		pos2 = i;
    		vertices[i]->indegree++;
    	}
    }

    if(!visited1) {
    	pos1 = vertices.size();
    	vertices.push_back(new Vertex(s1));
    }

    if(!visited2) {
    	pos2 = vertices.size();
    	vertices.push_back(new Vertex(s2, 1));		// indegree = 1
    }

    // add v into u's adjacent list
    vertices[pos1]->adj.push_back(vertices[pos2]);

    return vertices;
}

/**
* @brief This is the main method for this topological sort program.
* @details Read in input text file and build graph based on adjacency list implemented by map. Then call topSort().
* Secondly, based on the graph, find the vertices with indegree as 0. Start to find topological sort.
* @param The file representing edges of a graph.
*/
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    vector<Vertex*> vertices;		// all the vertices in the graph
    queue<Vertex*> myQueue; 		// to be used in topological sort
    string s1, s2;
    while (!file.eof()) {
        // read in two strings
	    file >> s1;
	    file >> s2;

	    if(s1 == "0" && s2 == "0")
	    	break;

	    // calling build graph
	    vertices = buildGraph(s1, s2, vertices);
	}

	// calling topological sort
	topSort(vertices, myQueue);

    // close the file before exiting
    file.close();
}
