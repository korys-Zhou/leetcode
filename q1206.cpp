struct Node {
    int val;
    Node* right, * down;
    Node(int i) :val(i), right(nullptr), down(nullptr) {}
};

class Skiplist {
public:
    Skiplist() :MAX_LEVEL(32), S(0xFFFF) {
        head = new Node(-1);
        Node* cur = head;
        for (int i = 1; i < MAX_LEVEL; ++i) {
            cur->down = new Node(-1);
            cur = cur->down;
        }
    }

    bool search(int target) {
        Node* cur = head;
        int lv = MAX_LEVEL;
        while (lv > 0) {
            if (cur->val == target) return true;
            if (cur->right && cur->right->val <= target) cur = cur->right;
            else {
                if (--lv > 0) cur = cur->down;
                else return false;
            }
        }
        return false;
    }

    void add(int num) {
        vector<Node*> to_add(MAX_LEVEL);
        int lv = MAX_LEVEL;
        Node* cur = head;
        while (lv > 0) {
            if (cur->right && cur->right->val <= num) cur = cur->right;
            else {
                to_add[--lv] = cur;
                cur = cur->down;
            }
        }
        int n = randomLevel();
        for (int i = 0; i < n; ++i) {
            Node* next = to_add[i]->right;
            to_add[i]->right = new Node(num);
            to_add[i]->right->right = next;
            if (i > 0) to_add[i]->right->down = to_add[i - 1]->right;
        }
    }

    bool erase(int num) {
        vector<Node*> to_del;
        int lv = MAX_LEVEL;
        Node* cur = head;
        while (lv > 0) {
            if (cur->right) {
                if (cur->right->val < num) cur = cur->right;
                else {
                    if (cur->right->val == num) to_del.emplace_back(cur);
                    cur = cur->down;
                    --lv;
                }
            }
            else {
                cur = cur->down;
                --lv;
            }
        }
        for (auto p : to_del) {
            Node* temp = p->right;
            p->right = p->right->right;
            delete temp;
        }
        return !to_del.empty();
    }

private:
    const int MAX_LEVEL, S;
    Node* head;

    int randomLevel() {
        int lv = 1;
        while ((rand() & S) < (S >> 2)) ++lv;
        return min(MAX_LEVEL, lv);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */