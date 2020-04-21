#include <iostream>
#include <string>
using namespace std;

class tokenNode {
   public:
    string token;
    tokenNode *next;

    tokenNode() {
        token = "";
        next = nullptr;
    }

    tokenNode(string __token, tokenNode *__next = nullptr) {
        this->token = __token;
        this->next = __next;
    }
};

class list {
    tokenNode *head, *tail;

   public:
    list() {
        head = tail = nullptr;
    }

    void addToTail(string __token) {
        if (this->head == nullptr) {
            this->head = this->tail = new tokenNode(__token);
        } else {
            this->tail->next = new tokenNode(__token);
            this->tail = this->tail->next;
        }
    }

    void display() {
        tokenNode *temp = this->head;
        while (temp != nullptr) {
            cout << "TOKEN: " << temp->token << endl;
            temp = temp->next;
        }
    }

    ~list() {
        tokenNode *temp = nullptr;
        while (this->head != nullptr) {
            temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }
};

class CFG {
    list llist;

   public:
    CFG() : llist() {}

    void addTokens() {
        string array[] = {"I",
                          "prefer",
                          "a",
                          "morning",
                          "flight"};
        for (int i = 0; i < 5; i++) {
            llist.addToTail(array[i]);
        }
        llist.display();
    }
};

int main(int argc, char const *argv[]) {
    CFG machine;
    machine.addTokens();
    return 0;
}
