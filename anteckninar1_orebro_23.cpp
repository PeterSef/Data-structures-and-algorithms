// anteckninar1_orebro_23.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;


struct Link {
    int key;
    Link* next;
    Link* prev;
    
};
struct List {
    Link* sentinel;
    List() {
        sentinel = NULL;
    }
    
    };


bool isEmpty(List* L) {
    if (L->sentinel==NULL) {
        cout << "Empty List" << endl;
        return true;
    }
    else {
        cout << "List contains some element" << endl;
        return false;
    }
};

void insert(Link* N, List* L) {
    if (L->sentinel != NULL) {
        Link* temp = new Link;
        temp = L->sentinel;
        while (temp->next != NULL) {
            temp = temp->next;

        }temp->next = N;
        N->prev = temp;
    }else{L->sentinel = N;
    }
};
void print_L(List* L) {
    Link* temp = L->sentinel;
    while (temp != NULL) {
        cout << "The value of the node is" << temp->key << endl;
        temp = temp->next;
    }
}
Link* search(List* L, int k) {
    Link* temp = L->sentinel;
    while (temp != NULL && temp->key != k) {
        temp = temp->next;
    }return temp;
}
Link* maximum(List* L) {
    Link* temp = L->sentinel;
    Link* MaxLink = NULL;
    int max = INT_MIN;
    if (temp == NULL) { return NULL; }
    while (temp != NULL) {
        if (max < temp->key) {
            max = temp->key;
            MaxLink = temp;
        }temp = temp->next;
    } cout << "Largest key of the current analyzed list is " << MaxLink->key<< endl; 
    return MaxLink;
}

Link* minimum(List* L) {
    Link* temp = L->sentinel;
    Link* MaxLink = NULL;
    int min = INT_MAX;
    if (temp == NULL) { return NULL; }
    while (temp != NULL) {
        if (min > temp->key) {
            min = temp->key;
            MaxLink = temp;
        }temp = temp->next;
    } cout << "Smallest key of the current analyzed list is " << MaxLink->key << endl;
    return MaxLink;
}

Link* successor(List* L, Link* N) {
    Link* successorlink = NULL;
    if (N->next == NULL) { return NULL; }
    else {
        Link* temp = new Link;
        temp = L->sentinel;
        while (temp != N) {
            temp = temp->next;
        }successorlink = temp->next; 
        cout << "The sucessor of node with key " << temp->key << " is " << successorlink->key << endl;
    }return successorlink;
}

Link* predecessor(List* L, Link* N) {
    Link* predecessorlink = NULL;
    if (N->prev == NULL) { return NULL; }
    else {
        Link* temp = new Link;
        temp = L->sentinel;
        while (temp != N) {
            temp = temp->next;
        }predecessorlink = temp->prev; 
        cout << "The predecessor of node with key " << temp->key<<" is "<<predecessorlink->key << endl;
    }return predecessorlink;
}

Link* deLete(List* L, Link* N) {
    if (N != NULL) {
        Link* temp = N;
        if (N->prev != NULL) {
            N->prev->next = N->next;
        }
        else {
            L->sentinel = N->next;
        }
        if (N->next != NULL) {
            N->next->prev = N->prev;
        }return temp;
    }
    else { return NULL; 
    }
}
int main()
{
    List* L1 = new List;
    Link* min_link1 = new Link;
    isEmpty(L1);
    min_link1->key = 3;
    min_link1->prev = NULL;
    min_link1->next = NULL;
    
    Link* min_link2 = new Link;
    min_link2->key = 1;
    min_link2->prev = NULL;
    min_link2->next = NULL;
    
    Link* min_link3 = new Link;
    min_link3->key = 5;
    min_link3->prev = NULL;
    min_link3->next = NULL;
    
    Link* min_link4 = new Link;
    min_link4->key = 10;
    min_link4->prev = NULL;
    min_link4->next = NULL;
    
    Link* min_link5 = new Link;
    min_link5->key = 8;
    min_link5->prev = NULL;
    min_link5->next = NULL;

    Link* min_link6 = new Link;
    min_link6->key = 7;
    min_link6->prev = NULL;
    min_link6->next = NULL;

    insert(min_link1, L1);
    isEmpty(L1);
    insert(min_link2, L1);
    insert(min_link3, L1);
    insert(min_link4, L1);
    insert(min_link5, L1);
    insert(min_link6, L1);
    print_L(L1);
    search(L1, 8);
    if (search(L1, 8) != NULL) {
        cout << "Link found" << endl;
    }else{ cout << "Link not found" << endl; };

    if (search(L1, 12) != NULL) {
        cout << "Link found" << endl;
    }
    else { cout << "Link not found" << endl; };
    maximum(L1);
    minimum(L1);
    predecessor(L1, maximum(L1));
    successor(L1, minimum(L1));


    List* L2 = new List;
    Link* min_link1_L2 = new Link;
    isEmpty(L2);
    min_link1_L2->key = 5;
    min_link1_L2->prev = NULL;
    min_link1_L2->next = NULL;

    Link* min_link2_L2 = new Link;
    min_link2_L2->key = 2;
    min_link2_L2->prev = NULL;
    min_link2_L2->next = NULL;

    Link* min_link3_L2 = new Link;
    min_link3_L2->key = 9;
    min_link3_L2->prev = NULL;
    min_link3_L2->next = NULL;

    Link* min_link4_L2 = new Link;
    min_link4_L2->key = 6;
    min_link4_L2->prev = NULL;
    min_link4_L2->next = NULL;

    Link* min_link5_L2 = new Link;
    min_link5_L2->key = 1;
    min_link5_L2->prev = NULL;
    min_link5_L2->next = NULL;

    Link* min_link6_L2 = new Link;
    min_link6_L2->key = 2;
    min_link6_L2->prev = NULL;
    min_link6_L2->next = NULL;

    insert(min_link1_L2, L2);
    isEmpty(L2);
    insert(min_link2_L2, L2);
    insert(min_link3_L2, L2);
    insert(min_link4_L2, L2);
    insert(min_link5_L2, L2);
    insert(min_link6_L2, L2);
    print_L(L2);
    search(L2, 8);
    if (search(L2, 8) != NULL) {
        cout << "Link found" << endl;
    }
    else { cout << "Link not found" << endl; };

    if (search(L2, 9) != NULL) {
        cout << "Link found" << endl;
    }
    else { cout << "Link not found" << endl; };
    maximum(L2);
    minimum(L2);
    predecessor(L2, maximum(L2));
    successor(L2, minimum(L2));
};
        
    
    

    




