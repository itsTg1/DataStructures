class Node {
public:
    int data;
    int key;
    Node* prev;
    Node* next;
    Node(int data, int key) {
        this->data = data;
        this->key = key;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache {
public:
    int capacity;
    map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* todelete) {
        Node* prevNod = todelete->prev;
        Node* nextNod = todelete->next;
        prevNod->next = nextNod;
        nextNod->prev = prevNod;
        todelete->next = NULL;
        todelete->prev = NULL;
    }
    void insertNode(Node* toInsert) {
        Node* nextHead = head->next;
        nextHead->prev = toInsert;
        toInsert->next = nextHead;
        toInsert->prev = head;
        head->next = toInsert;
    }
    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* toGet = mp[key];
        deleteNode(toGet);
        insertNode(toGet);
        return toGet->data;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* toUpdate = mp[key];
            toUpdate->data = value;
            deleteNode(toUpdate);
            insertNode(toUpdate);
        } else if (capacity == 0) {
            // delete at tail
            Node* todelete = tail->prev;
            Node* prevNode = todelete->prev;
            prevNode->next = tail;
            tail->prev = prevNode;
            todelete->prev = NULL;
            todelete->next = NULL;
            mp.erase(todelete->key);
            capacity++;
        }
        if (mp.find(key) == mp.end()) {
            Node* toInsert = new Node(value, key);
            mp[key] = toInsert;
            Node* nextOne = head->next;
            nextOne->prev = toInsert;
            toInsert->next = nextOne;
            toInsert->prev = head;
            head->next = toInsert;
            capacity--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */