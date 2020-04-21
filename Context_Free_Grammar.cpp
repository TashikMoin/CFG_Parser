#include <iostream>
#include <string>
#include<string.h>
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

    void Add_Tokens( string Sentence ) 
    {
        char TokenString[100] ;
        strcpy( TokenString , Sentence.c_str()) ;
        char *Token = strtok( TokenString , " "); 
        string Word[25] ;
        int i = 0 ;
        while (Token != NULL) 
        { 
           Word[i] = Token ;
           cout<<Word[i]<<endl;
           Token = strtok(NULL, " "); 
           i++ ;
        } 
        cout<<endl;
        Linked_List.Add_To_Tail(Word[0] , "Pronoun") ; // we will call type find function here later.
        Linked_List.Add_To_Tail(Word[1] , "Verb") ;
        Linked_List.Add_To_Tail(Word[2] , "Determiner") ;
        Linked_List.Add_To_Tail(Word[3] , "Noun") ;
        Linked_List.Add_To_Tail(Word[4] , "Noun") ;
        Linked_List.Display() ;
    }
} ;



int main(int argc, char const *argv[]) 
{
    string Sentence ;
    getline(cin , Sentence) ;
    CFG Machine;
    Machine.Add_Tokens( Sentence );
    return 0;
}
