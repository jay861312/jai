#include <iostream> 
using namespace std; 
 
#define MAX 50 
 
template <class T> 
class Data { 
public: 
    T val; 
    int priority; 
 
    bool operator <= (int v) { 
        return v <= priority; 
    } 
}; 
 
template <class T> 
class prQueue { 
    int front = -1, rear = -1; 
    Data<T> queue[MAX]; 
 
public: 
    void enqueue(T d, int priority) { 
        Data<T> D; 
        D.val = d; 
        D.priority = priority; 
 
        if (rear == MAX - 1) { 
            cout << "Queue Overflow" << endl; 
            return; 
        } 
 
        if (front == -1 && rear == -1) { 
            front = rear = 0; 
            queue[rear] = D; 
            return; 
        } else { 
            int i; 
            for (i = rear; i >= front; i--) { 
                if (priority <= queue[i].priority) { 
                    queue[i + 1] = queue[i]; 
                } else { 
                    break; 
                } 
            } 
            queue[i + 1] = D; 
            rear++; 
        } 
    } 
 
    Data<T> dequeue() { 
        Data<T> gar; 
        if (front == -1) { 
            cout << "Queue Underflow" << endl; 
            return gar; 
        } else { 
            gar = queue[front]; 
            if (front == rear) { 
                front = rear = -1; 
            } else { 
                front++; 
            } 
            return gar; 
        } 
    } 
 
    void peek() { 
        if (front == -1) { 
            cout << "Queue is Empty" << endl; 
        } else { 
            cout << "Front element is: " << queue[front].val 
                 << " with priority " << queue[front].priority << endl; 
        } 
    } 
 
    void display() { 
        if (front == -1) { 
            cout << "Queue is Empty" << endl; 
        } else { 
            cout << "Queue elements: " << endl; 
            for (int i = front; i <= rear; i++) { 
                cout << "Value: " << queue[i].val << " with Priority: " << queue[i].priority << endl; 
            } 
        } 
    } 
}; 
 
int main() { 
    prQueue<char> p; 
    int opt, pr; 
    char val; 
    Data<char> G; 
 
    do { 
        cout << "\nMENU\n"; 
        cout << "1) Enqueue\n"; 
        cout << "2) Dequeue\n"; 
        cout << "3) Display\n"; 
        cout << "4) Peek\n"; 
        cout << "5) Exit\n"; 
        cout << "Enter your option: "; 
        cin >> opt; 
 
        switch (opt) { 
            case 1: 
                cout << "Enter Data Value: "; 
                cin >> val; 
                cout << "Enter its Priority: "; 
                cin >> pr; 
                p.enqueue(val, pr); 
                break; 
 
            case 2: 
                G = p.dequeue(); 
                cout << "Dequeued: " << G.val << " with priority " << G.priority << endl; 
                break; 
 
            case 3: 
                p.display(); 
                break; 
 
            case 4: 
                p.peek(); 
                break; 
 
            case 5: 
                break; 
 
            default: 
                cout << "Invalid Option!" << endl; 
        } 
 
    } while (opt != 5); 
 
    return 0; 
} 