#include<iostream> 
using namespace std; 
 
class Queue { 
public: 
    const static int size = 10; 
    int front = -1; 
    int rear = -1; 
    string queue[size]; 
 
    void enqueue(string job) { 
        if (rear == size - 1) { 
            cout << "Overflow!!! (Queue is Full)" << endl; 
        } 
        else { 
            if (front == -1) { 
                front = 0; 
            } 
            rear++; 
            queue[rear] = job; 
            cout << "Job \"" << job << "\" added to the queue." << endl; 
        } 
    } 
 
    void dequeue() { 
        if (front == -1 || front > rear) { 
            cout << "Underflow!!! (Queue is Empty)" << endl; 
        } 
        else { 
            cout << "The Deleted Job: \"" << queue[front] << "\"" << endl; 
            front++; 
        } 
    } 
 
    void display() { 
        if (front == -1 || front > rear) { 
            cout << "Queue is Empty!" << endl; 
        } 
        else { 
            cout << "Jobs in the Queue: "; 
            for (int i = front; i <= rear; i++) { 
                cout << "\"" << queue[i] << "\" "; 
            } 
            cout << endl; 
        } 
    } 
}; 
 
int main() { 
    Queue jobQueue; 
    int choice; 
    string job; 
 
    do { 
        cout << "\nEnter the option number to perform the operations:" << endl; 
        cout << "1. To Add Job" << endl; 
        cout << "2. To Delete Job" << endl; 
        cout << "3. To Display Queue" << endl; 
        cout << "4. Exit" << endl; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter Job Name to Add: "; 
            cin.ignore(); 
            getline(cin, job); 
            jobQueue.enqueue(job); 
            break; 
        case 2: 
            jobQueue.dequeue(); 
            break; 
        case 3: 
            jobQueue.display(); 
            break; 
        case 4: 
            cout << "Exiting program." << endl; 
            break; 
        default: 
            cout << "Invalid option! Please enter a valid option." << endl; 
        } 
    } while (choice != 4); 
 
    return 0; 
} 
