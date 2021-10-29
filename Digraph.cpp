#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    node *next;
};
class List {
public:
    node* head;
    List();
    void Add(int n){
        node* item = new node;
        item->data = n;
        item->next = head;
        head = item;
    }
    void Print(string *arr){
        node* item = head;
        cout << "Topological Sort: \n";
        while (item != NULL) {
            cout << "Task " << item->data + 1 << ": " << arr[item->data] << endl;
            item = item->next;
        }
        cout << endl;
    }

};

class Graph{
    public:
    node *head = new node[task];
    int* visit = new int[task];
    List list;

    Graph(int size){
        int i; 
        for (i = 0; i < size; i++) {
            node* newnode = new node();
            head[i] = *newnode;
            head[i].data = i;
        }
    }

    void Add(int first, int second){
        node* item = new node();
        item->data = second-1;
        node* temp = &head[first-1];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = item;
    }

    void Visit() {
        int i;
        for (i = 0; i < task; i++) {
            visit[i] = 0;
        }
    }

    void Sort(){
        int* r = new int[task];
        Visit();
        int i;
        for (i = 0; i < task; i++) {
            if (visit[i] == 0) {
                DFS(i);
            }
        }
    }

    void DFS(int i){
        visit[i] = 1;
        node* temp = &head[i];
        temp = temp->next;
        while (temp != NULL) {
            if (visit[temp->data] == 0) {
                DFS(temp->data);
            }
            temp = temp->next;
        }
        list.Add(i);
    }

    void Print(){
        int i;
        for (i = 0; i < task; i++) {
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
    int num_task; // task
    int i, operation; 
    int first_task, sec_task;
    
    cout << "Enter number of tasks: ";
    cin >> num_task;

    // Diagraph class D1(num_task);
    auto arr{ new string[num_task]};

    for (i = 0; i < num_task; i++) {
        cout << "Enter the task " << i + 1 << ": ";
        getline(cin >> ws, arr[i]);
    }
    
    cout << "\nType 1 -> Relation Input\n";
    cout << "Type 2 -> Perform Topological Sort\n";
    cout << "Type 3 -> Adjacency List\n";
    cout << "Type 0 -> Quit\nEnter operation: ";
    cin >> operation;

    while (operation != 0){
        if (operation == 1){
            cout << "\nTask entered first precededs the second\n";
            cout << "Enter first task: ";
            cin >> first_task;
            cout << "Enter second task: ";
            cin >> sec_task;
            // Add relation to Diagraph
        }

        else if (operation == 2){
            // Perform Topological Sort
            cout<< "222 sucess\n";
        }

        else{
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
