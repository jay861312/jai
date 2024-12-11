#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int seat;
    string id;
    int status;  // 0 - available, 1 - booked
};

class cinemax {
public:
    node* head, *tail, *temp;
    cinemax() {
        head = NULL;
    }
    void create_list();
    void display();
    void book();
    void cancel();
    void avail();
};

void cinemax::create_list() {
    temp = new node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "null";
    tail = head = temp;
    
    for (int i = 2; i <= 70; i++) {
        node* p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "null";
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}

void cinemax::display() {
    int count = 0;
    node* temp = head;
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << " Screen this way \n";
    cout << "------------------------------------------------------------------------------------\n";
    
    do {
        cout << "S" << (temp->seat < 10 ? "0" : "") << temp->seat << " :";
        if (temp->status == 0)
            cout << "|___| ";
        else
            cout << "|_B_| ";
        
        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "\n------------------------------------------------------------------------------------\n";
}

void cinemax::book() {
    int x;
    string y;
label:
    cout << "\nEnter seat number to be booked (1-70): ";
    cin >> x;
    cout << "Enter your ID number: ";
    cin >> y;
    
    if (x < 1 || x > 70) {
        cout << "Enter a correct seat number to book (1-70)\n";
        goto label;
    }
    
    node* temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }

    if (temp->status == 1)
        cout << "Seat already booked!\n";
    else {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked!\n";
    }
}

void cinemax::cancel() {
    int x;
    string y;
label1:
    cout << "Enter seat number to cancel booking (1-70): ";
    cin >> x;
    cout << "Enter your ID: ";
    cin >> y;
    
    if (x < 1 || x > 70) {
        cout << "Enter a correct seat number to cancel (1-70)\n";
        goto label1;
    }
    
    node* temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }
    
    if (temp->status == 0) {
        cout << "Seat not booked yet!!\n";
    } else {
        if (temp->id == y) {
            temp->status = 0;
            cout << "Seat " << x << " booking canceled!\n";
        } else {
            cout << "Wrong User ID! Seat cannot be canceled!\n";
        }
    }
}

void cinemax::avail() {
    int count = 0;
    node* temp = head;
    cout << "\nAvailable Seats:\n";
    do {
        if (temp->status == 0) {
            cout << "S" << (temp->seat < 10 ? "0" : "") << temp->seat << " :|___| ";
            count++;
            if (count % 7 == 0) {
                cout << endl;
            }
        }
        temp = temp->next;
    } while (temp != head);
    cout << "\n------------------------------------------------------------------------------------\n";
}

int main() {
    cinemax obj;
    obj.create_list();
    int ch;
    char c = 'y';
    while (c == 'y') {
        obj.display();
        cout << "\n*********************************************\n";
        cout << " CINEMAX MOVIE THEATRE\n";
        cout << "*********************************************\n";
        cout << "\nEnter Choice\n1. Current Seat Status\n2. Book Seat \n3. Available Seat\n4. Cancel Seat\n";
        cin >> ch;
        switch (ch) {
            case 1: obj.display(); break;
            case 2: obj.book(); break;
            case 3: obj.avail(); break;
            case 4: obj.cancel(); break;
            default: cout << "Wrong choice input\n"; break;
        }
        cout << "\nDo you want to perform any other operation: (y/n)\n";
        cin >> c;
    }
    return 0;
}
