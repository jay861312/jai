#include <iostream> 
#include <string> 
using namespace std; 
 
template<class T> 
class Node { 
public: 
    T val; 
    Node* next; 
 
    Node(T data) { 
        val = data; 
        next = nullptr; 
    } 
}; 
 
template<class T> 
class LinkedList { 
public: 
    Node<T>* head; 
 
    LinkedList() { 
        head = nullptr; 
    } 
 
    void insertAtTail(T val) { 
        Node<T>* new_node = new Node<T>(val); 
        if (head == nullptr) { 
            head = new_node; 
            return; 
        } 
 
        Node<T>* temp = head; 
        while (temp->next != nullptr) { 
            temp = temp->next; 
        } 
        temp->next = new_node; 
    } 
 
    void display() { 
        Node<T>* temp = head; 
        while (temp != nullptr) { 
            cout << temp->val << " "; 
            temp = temp->next; 
        } 
        cout << "NULL" << endl; 
    } 
 
    int count() { 
        Node<T>* temp = head; 
        int c = 0; 
        while (temp != nullptr) { 
            c++; 
            temp = temp->next; 
        } 
        return c; 
    } 
 
    Node<T>* intersection(Node<T>* head1, Node<T>* head2) { 
        LinkedList<T> intersected; 
        Node<T>* ptr1 = head1; 
        Node<T>* ptr2 = head2; 
 
        while (ptr1 != nullptr) { 
            while (ptr2 != nullptr) { 
                if (ptr1->val == ptr2->val) { 
                    intersected.insertAtTail(ptr1->val); 
                } 
                ptr2 = ptr2->next; 
            } 
            ptr2 = head2; 
            ptr1 = ptr1->next; 
        } 
        return intersected.head; 
    } 
 
    Node<T>* unionList(Node<T>* head1, Node<T>* head2) { 
        LinkedList<T> united; 
        Node<T>* ptr1 = head1; 
        Node<T>* ptr2 = head2; 
        int flag; 
 
        while (ptr1 != nullptr) { 
            united.insertAtTail(ptr1->val); 
            ptr1 = ptr1->next; 
        } 
 
        while (ptr2 != nullptr) { 
            flag = 0; 
            ptr1 = head1; 
            while (ptr1 != nullptr) { 
                if (ptr1->val == ptr2->val) { 
                    flag = 1; 
                    break; 
                } 
                ptr1 = ptr1->next; 
            } 
            if (flag == 0) { 
                united.insertAtTail(ptr2->val); 
            } 
            ptr2 = ptr2->next; 
        } 
        return united.head; 
    } 
 
    Node<T>* difference(Node<T>* head1, Node<T>* head2) { 
        LinkedList<T> diff; 
        Node<T>* ptr1 = head1; 
        Node<T>* ptr2 = head2; 
        int flag; 
 
        while (ptr1 != nullptr) { 
            flag = 0; 
            ptr2 = head2; 
            while (ptr2 != nullptr) { 
                if (ptr1->val == ptr2->val) { 
                    flag = 1; 
                    break; 
                } 
                ptr2 = ptr2->next; 
            } 
            if (flag == 0) { 
                diff.insertAtTail(ptr1->val); 
            } 
            ptr1 = ptr1->next; 
        } 
        return diff.head; 
    } 
}; 
 
int main() { 
    int n, v, b; 
    string name; 
 
    LinkedList<string> total; 
    LinkedList<string> vanilla; 
    LinkedList<string> butterscotch; 
 
    cout << "Enter Total Number of Students: "; 
    cin >> n; 
    cout << "Enter Name of Students:\n"; 
    for (int i = 0; i < n; i++) { 
        cin >> name; 
        total.insertAtTail(name); 
    } 
 
    cout << "Enter Number of Students liking Vanilla Ice-cream: "; 
    cin >> v; 
    cout << "Enter Name of Students liking Vanilla:\n"; 
    for (int i = 0; i < v; i++) { 
        cin >> name; 
        vanilla.insertAtTail(name); 
    } 
 
    cout << "Enter Number of Students liking Butterscotch Ice-cream: "; 
    cin >> b; 
    cout << "Enter Name of Students liking Butterscotch:\n"; 
    for (int i = 0; i < b; i++) { 
        cin >> name; 
        butterscotch.insertAtTail(name); 
    } 
 
    cout << "\nTotal Students: "; 
    total.display(); 
    cout << "\nStudents Liking Vanilla: "; 
    vanilla.display(); 
    cout << "\nStudents Liking Butterscotch: "; 
    butterscotch.display(); 
 
    int opt; 
    LinkedList<string> result; 
 
    do { 
        cout << "\n1) Set of students who like both vanilla and butterscotch.\n"; 
        cout << "2) Set of students who like either vanilla or butterscotch but not both.\n"; 
        cout << "3) Number of students who like neither vanilla nor butterscotch.\n"; 
        cout << "4) Exit.\n"; 
        cout << "Choose Operation: "; 
        cin >> opt; 
 
        switch (opt) { 
        case 1: 
            result.head = result.intersection(vanilla.head, butterscotch.head); 
            cout << "Students who like both Vanilla and Butterscotch: "; 
            result.display(); 
            break; 
        case 2: 
            result.head = result.difference(result.unionList(vanilla.head, butterscotch.head), 
                                            result.intersection(vanilla.head, butterscotch.head)); 
            cout << "Students who like either Vanilla or Butterscotch but not both: "; 
            result.display(); 
            break; 
        case 3: 
            result.head = result.difference(total.head, 
                                            result.unionList(vanilla.head, butterscotch.head)); 
            cout << "Students who like neither Vanilla nor Butterscotch: "; 
            result.display(); 
            cout << "Number of students: " << result.count() << endl; 
            break; 
        case 4: 
            break; 
        default: 
cout << "Invalid Option!" << endl; 
} 
} while (opt != 4); 
return 0; 
}