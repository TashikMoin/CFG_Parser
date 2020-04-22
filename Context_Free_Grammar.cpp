#include <string.h>

#include <iostream>
#include <string>
using namespace std;

class tokenNode {
   public:
    string token;
    string type;
    tokenNode *next;

    tokenNode() {
        token = "";
        next = nullptr;
    }

    tokenNode(string __token, string __type, tokenNode *__next = nullptr) {
        this->token = __token;
        this->next = __next;
        this->type = __type;
    }
};

class List {
    tokenNode *head, *tail;

   public:
    List() {
        head = tail = nullptr;
    }

    void Add_To_Tail(string __token, string __type) {
        if (this->head == nullptr) {
            this->head = this->tail = new tokenNode(__token, __type);
        } else {
            this->tail->next = new tokenNode(__token, __type);
            this->tail = this->tail->next;
        }
    }

    void Display() {
        tokenNode *temp = this->head;
        while (temp != nullptr) {
            cout << temp->token << "  " << temp->type << endl;
            temp = temp->next;
        }
    }

    ~List() {
        tokenNode *temp = nullptr;
        while (this->head != nullptr) {
            temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }
};

int Total_Words(string Sentence) {
    int i = 0, Count = 0;
    while (i < Sentence.length()) {
        if (Sentence[i] == ' ') {
            Count++;
        }
        i++;
    }
    return Count;
}

class CFG {
    List Linked_List;

   public:
    CFG() : Linked_List() {}

    void Add_Tokens(string Sentence) {
        char TokenString[Total_Words(Sentence) * 20];
        strcpy(TokenString, Sentence.c_str());
        char *Token = strtok(TokenString, " ");
        string Word[Total_Words(Sentence) + 1];
        int i = 0;
        while (Token != NULL) {
            Word[i] = Token;
            cout << Word[i] << endl;
            Token = strtok(NULL, " ");
            i++;
        }
        cout << endl;
        Linked_List.Add_To_Tail(Word[0], "Pronoun");  // we will call type find function here later.
        Linked_List.Add_To_Tail(Word[1], "Verb");
        Linked_List.Add_To_Tail(Word[2], "Determiner");
        Linked_List.Add_To_Tail(Word[3], "Noun");
        Linked_List.Add_To_Tail(Word[4], "Noun");
        Linked_List.Display();
    }

    bool indexCheck(int *__i) {
        if (*(__i) >= 5) {
            return false;
        }
        return true;
    }

    bool pronoun(string *__words, int *__i) {
        if (indexCheck(__i)) {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "I") {
                (*__i)++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool properNoun(string *__words, int *__i) {
        return false;
    }

    bool determiner(string *__words, int *__i) {
        if (indexCheck(__i)) {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "a") {
                (*__i)++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool nominal(string *__words, int *__i) {
        if (indexCheck(__i)) {
            if (noun(__words, __i)) {
                if (nominal(__words, __i)) {
                    return true;
                } else {
                    (*__i)--;
                }
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool verb(string *__words, int *__i) {
        if (indexCheck(__i)) {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "prefer") {
                (*__i)++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool noun(string *__words, int *__i) {
        if (indexCheck(__i)) {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "morning" || __words[*(__i)] == "flight") {
                (*__i)++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool preposition(string *__words, int *__i) {
        return false;
    }

    bool NP(string *__words, int *__i) {
        if (indexCheck(__i)) {
            if (pronoun(__words, __i)) {
                return true;
            } else if (properNoun(__words, __i)) {
            } else if (determiner(__words, __i) && nominal(__words, __i)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool VP(string *__words, int *__i) {
        if (indexCheck(__i)) {
            if (verb(__words, __i)) {
                if (NP(__words, __i)) {
                    if (PP(__words, __i)) {
                        return true;
                    } else {
                        (*__i)--;
                    }
                    return true;
                } else if (PP(__words, __i)) {
                    return true;
                } else {
                    (*__i)--;
                }
                (*__i)++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool PP(string *__words, int *__i) {
        if (preposition(__words, __i) && NP(__words, __i)) {
        } else {
            return false;
        }
    }

    void sentence() {
        int i = 0;
        string words[] = {
            "I",
            "prefer",
            "a",
            "morning",
            "flight"};

        if (NP(words, &i) && VP(words, &i)) {
            cout << "PERFECT\n";
        } else {
            cout << "INVALID STRUCTURE\n";
        }
    }
};

int main(int argc, char const *argv[]) {
    string Sentence;
    //   getline(cin, Sentence);
    CFG Machine;
    //  Machine.Add_Tokens(Sentence);
    Machine.sentence();
    return 0;
}
