// hw5.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    string task;
    struct Node* next;
};

struct List{
    struct Node* head;
};

class Graph{
private:
    int V;
    List* array;
public:
    Graph(int V){
        this->V = V;
        array = new List[V];		 
        for (int i = 0; i < V; ++i)
            array[i].head = NULL;  		
    }

    /*
     * Adding Edge to Graph
     */
    void addEdge(int src, int dest){
        Node* newNode = new Node;  
        newNode->task = dest;					
        newNode->next = NULL;		
                                                
        newNode->next = array[src].head;		
        array[src].head = newNode;				

    }
    /*
     * Print the graph
     */
    void printGraph(){
        int v;
        for (v = 0; v < V; ++v){
            Node* tmp = array[v].head;		//tmp has the address of (0,1..)vertex head 
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            while (tmp){
                cout << "-> " << tmp->task;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
};


int main(){
    // Total number of tasks
    int num_task; // task
    int i, operation;
    int first_task, sec_task;

    cout << "Enter number of tasks: ";
    cin >> num_task;

    // Diagraph class D1(num_task);
    auto arr{ new string[num_task] };

    for (i = 0; i < num_task; i++) {
        cout << "Enter the task " << i + 1 << ": ";
        getline(cin >> ws, arr[i]);
    }

    cout << "\nType 1 -> Relation Input\n";
    cout << "Type 2 -> Perform Topological Sort\n";
    cout << "Type 3 -> Adjacency List\n";
    cout << "Type 0 -> Quit\nEnter operation: ";
    cin >> operation;

    while (operation != 0) {
        if (operation == 1) {
            cout << "\nTask entered first precededs the second\n";
            cout << "Enter first task: ";
            cin >> first_task;
            cout << "Enter second task: ";
            cin >> sec_task;
            // Add relation to Diagraph
        }

        else if (operation == 2) {
            // Perform Topological Sort
            cout << "222 sucess\n";
        }

        else {
            // Print the adjacency list
            cout << "33 sucess\n";
        }
        cout << "\nType 1 -> Relation Input\n";
        cout << "Type 2 -> Perform Topological Sort\n";
        cout << "Type 3 -> Adjacency List\n";
        cout << "Type 0 -> Quit\nEnter operation: ";
        cin >> operation;
    }
}
