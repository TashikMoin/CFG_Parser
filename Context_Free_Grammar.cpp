#include <iostream>
#include <string>
using namespace std;

class tokenNode 
{
   public:
    string token;
    string type;
    tokenNode *next;

    tokenNode() 
    {
        token = "";
        next = nullptr;
    }

    tokenNode(string __token , string __type , tokenNode *__next = nullptr) 
    {
        this->token = __token ;
        this->next = __next ;
        this->type = __type ;
    }
};

class List 
{
    tokenNode *head, *tail;

   public:
    List() 
    {
        head = tail = nullptr;
    }

    void Add_To_Tail(string __token  ,  string __type ) 
    {
        if (this->head == nullptr) 
        {
            this->head = this->tail = new tokenNode(__token , __type);
        } 
       else 
       {
            this->tail->next = new tokenNode(__token , __type);
            this->tail = this->tail->next;
       }
    }

    void Display() 
    {
        tokenNode *temp = this->head;
        while (temp != nullptr) 
        {
            cout<< temp->token <<"  " << temp->type << endl;
            temp = temp->next;
        }
    }

    ~List() 
    {
        tokenNode *temp = nullptr;
        while (this->head != nullptr) 
        {
            temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }
   
};

class CFG 
{
    List Linked_List;

   public:
    CFG() : Linked_List() {}

    void Add_Tokens() 
    {
        string array[] = 
        {                
            "I",
            "prefer",
            "a",
            "morning",
            "flight"
        } ;

        Linked_List.Add_To_Tail(array[0] , "Pronoun") ; // we will call type find function here later.
        Linked_List.Add_To_Tail(array[1] , "Verb") ;
        Linked_List.Add_To_Tail(array[2] , "Determiner") ;
        Linked_List.Add_To_Tail(array[3] , "Noun") ;
        Linked_List.Add_To_Tail(array[4] , "Noun") ;
    
        Linked_List.Display() ;
    }
} ;



int main(int argc, char const *argv[]) 
{
    CFG Machine;
    Machine.Add_Tokens();
    return 0;
}
