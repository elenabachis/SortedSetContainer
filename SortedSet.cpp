
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) { //ich erstelle ein neues Set
    this->r = r;
    length = 0;
    head = tail = nullptr;
    ///Komplexitat:O(1)
}

bool SortedSet::add(TComp elem) {
    ///die Komplexitat:O(length) , best case:theta(1) wenn ich am Anfang elem einfuge und worst case:theta(length) wenn ich am Ende elem einfuge
    if (search(elem)) {
        return false;
    }

    Node *newNode = new Node; //es allokiert Speicherplatz fur das neue Node
    newNode->info = elem;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    Node *current = head;
    while (current != nullptr && r(current->info, elem)) { //wenn die Relation nicht stimmt ,dort wird elem eingefugt, um die Reihenfolge zu halten
        current = current->next;
    }

    if (current == head) { //in diesem Fall soll man am Anfang des Sets elem einfugen
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    } else if (current == nullptr) { //in diesem Fall soll man am Ende des Sets elem einfugen
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    } else {
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    length++;
    return true;
}

bool SortedSet::remove(TComp elem) {
    ///die Komplexitat:O(length) , best case:theta(1) wenn ich am Anfang elem losche und worst case:theta(length) wenn ich am Ende elem losche
    if (length == 0) { //wenn es kein Element gibt
        return false;
    }

    Node *current = head;
    while (current != nullptr && current->info != elem) {
        current = current->next;
    }

    if (current == nullptr) { //das Element war nicht gefunden
        return false;
    }

    if (current == head && current == tail) { //wenn es nur ein Element gibt wobei elem=Element
        head = tail = nullptr;
    } else if (current == head) { //wenn elem das erste Element des Sets ist
        head = current->next;
        head->prev = nullptr;
    } else if (current == tail) { //wenn elem am Ende des Sets ist
        tail = current->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    length--;
    return true;
}

bool SortedSet::search(TComp elem) const {
    ///die Komplexitat:O(length) , best case:theta(1) wenn ich am Anfang elem finde und worst case:theta(length) wenn ich am Ende elem finde
    Node *current = head;
    while (current != nullptr && r(current->info,elem)) {
        if (current->info == elem) {
            return true;
        }
        current = current->next;
    }
    return (current != nullptr && current->info == elem);
}

int SortedSet::size() const {
    return length;
}

bool SortedSet::isEmpty() const {
    return length == 0;
}

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}

