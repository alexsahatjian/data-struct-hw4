/*
    EECE 4040 Homework 4 Programming Project
    Team: Arunesh Mishra, Alex Sahatjian, Keerthi Sekar
    Purpose: C++ Program implementing the ADT Disgraph
*/

#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

int num_task;

//node class - building block for linked list
class node {
public:
    int data;
    node* next;
};

class List {
public:
    node* head;
    List() {};
    //add node to list
    void Add(int n) {
        node* item = new node;
        item->data = n;
        item->next = head;
        head = item;
    }
    //print out tasks
    void Print(string* arr) {
        node* item = head;
        cout << "Printing Topological Sort: \n";
        while (item != NULL) {
            cout << "Task " << item->data + 1 << ": " << arr[item->data] << endl;
            item = item->next;
        }
        cout << endl;
    }
};

class Graph {
public:
    node* head = new node[num_task];
    int* visit = new int[num_task];
    List list;
    //graph constructor
    Graph(int size) {
        //loop and create new node for parameter size
        for (int i = 0; i < size; i++) {
            node* newnode = new node();
            head[i] = *newnode;
            head[i].data = i;
        }
    }
    //graph destructor
    ~Graph() {
        delete[] head;
    }
    //add edge
    void Add(int source, int dest) {
        //create new empty node
        node* item = new node();
        //list starts at 0 so subtract 1
        item->data = dest - 1;
        node* temp = &head[source - 1];
        //loop through adj. list and add to end
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = item;
    }
    
    bool Delete(int source, int dest) {
        //temp2 moves ahead of temp
        node* temp = head;
        node* temp2 = temp->next;
        int found = 0;
        //loop through adj. list until source and dest match set node to null
        while (temp != NULL) {
            if (temp->next != NULL) {
                if (temp->next->data == dest - 1) {
                    found = 1;
                    temp2 = temp->next;
                    temp->next = temp2->next;
                    temp = NULL;
                }
            }
            temp = temp->next;
        }
        //return bool
        if (found != 0)
            return true;
        else
            return false;
    }
    
    void Visit(int* arr) {
        //intailize input array to zero
        for (int i = 0; i < num_task; i++) {
            arr[i] = 0;
        }
    }
    //sort utilizing DFS
    void Sort() {
        int* r = new int[num_task];
        // initialize vist to 0
        Visit(visit);
        //loop through tasks and peform DFS
        for (int i = 0; i < num_task; i++) {
            if (visit[i] == 0) {
                DFS(i);
            }
        }
    }

    void DFS(int i) {
        //set visit to 1
        visit[i] = 1;
        node* temp = &head[i];
        temp = temp->next;
        //recursivly loop through nodes and check for vist
        while (temp != NULL) {
            if (visit[temp->data] == 0) {
                DFS(temp->data);
            }
            temp = temp->next;
        }
        //push to list
        list.Add(i);
    }
    //check if graph is acyclic or not (cyclic)
    bool AcyclicCheck() {
        int i;
        int* num_in = new int[num_task];
        int* num_out = new int[num_task];
        //intialize * arrays to 0
        Visit(num_in);
        Visit(num_out);
        //loop through tasks and set arrays
        for (i = 0; i < num_task; i++) {
            node* temp = &head[i];
            temp = temp->next;
            while (temp != NULL) {
                num_in[temp->data] = num_in[temp->data] + 1;
                num_out[i] = num_out[i] + 1;
                temp = temp->next;
            }
        }

        bool list_sink = false;
        bool list_source = false;
        //check for source and sink
        for (i = 0; i < num_task; i++) {
            if (num_in[i] == 0 && num_out[i] > 0) list_source = true;
            if (num_in[i] > 0 && num_out[i] == 0) list_sink = true;
        }
        //display arrays
        for (i = 0; i < num_task; i++) {
            cout << i << " " << num_out[i] << " " << num_in[i] << endl;
        }
        if (list_sink && list_source) return true;
        else return false;
    }

    // Printing the adjacency list 
    void Print() {
        int i;
        for (i = 0; i < num_task; i++) {
            // Looping through the head of each list 
            node* temp = &head[i];
            while (temp != NULL) {
                cout << temp->data + 1 << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
     // Declare required local variables for the UI 
    int i, operation;
    int first_task, sec_task;

    // Input all the tasks 
    cout << "Enter number of tasks: ";
    cin >> num_task;

    // Caling Diagraph class (num_task);
    Graph tasks(num_task);
    
    auto arr{ new string[num_task] };

    // Loop to input all the tasks 
    for (i = 0; i < num_task; i++) {
        cout << "Enter the task " << i + 1 << ": ";
        getline(cin >> ws, arr[i]);
    }

    // Ask for instructions to perform on the functions
    cout << "\nType 1 -> Relation Input\n";
    cout << "Type 2 -> Delete Relation\n";
    cout << "Type 3 -> Adjacency List\n";
    cout << "Type 4 -> Perform Topological Sort\n";
    cout << "Type 5 -> Acyclic Check\n";
    cout << "Type 0 -> Quit\nEnter operation: ";
    cin >> operation;

    // Looping through the functions
    while (operation != 0) {
        if (operation == 1) {
            // Enter the preceding task and the following task 
            cout << "\nTask entered first precededs the second\n";
            cout << "Enter first task: ";
            cin >> first_task;
            cout << "Enter second task: ";
            cin >> sec_task;
            // Add the tasks
            tasks.Add(first_task, sec_task);
        }

        else if (operation == 2) {
            int source, dest;
            bool found;
            cout << "Enter Source: ";
            cin >> source;
            cout << "\nEnter Destination: ";
            cin >> dest;
            cout << "\n";
            // Deleting
            found = tasks.Delete(source, dest);
            if (found == true)
                cout << "Edge Deleted\n";
            else
                cout << "Edge Not Found\n";
        }
        else if (operation == 3) {
            // Printing the adjacency list 
            cout << "Printing" << endl;
            tasks.Print();
        }
        
        else if (operation == 4) {
            if (tasks.AcyclicCheck()) {
                // Peforming the topological sort
                tasks.Sort();
                // Printng list 
                tasks.list.Print(arr);
            }
            else
                cout << "Error: Graph is cyclic\n";
        }

        else if(operation == 5){
            // Performing acyclic checks 
            if (tasks.AcyclicCheck()){
                cout << "The Graph is Acyclic" << endl;
            }
            else {
                cout << "The Graph is cyclic"<< endl;
            }
        }

        cout << "\nType 1 -> Relation Input\n";
        cout << "Type 2 -> Delete Relation\n";
        cout << "Type 3 -> Adjacency List\n";
        cout << "Type 4 -> Perform Topological Sort\n";
        cout << "Type 5 -> Acyclic Check\n";
        cout << "Type 0 -> Quit\nEnter operation: ";
        cin >> operation;
    }
}
