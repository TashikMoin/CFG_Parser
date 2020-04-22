#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std ;

int Total_Words( string S )
{
    int i = 0 , Count = 0 ;
    while( i < S.length() )
    {
        if(S[i] == ' ')
        {
            Count++ ;
        }
        i++ ;
    }
    return Count ;
}

void To_Upper_Case( string &Word )
{
    for( int i = 0 ; i < Word.length() ; ++i )
    {
        if( Word[i] >= 'a' && Word[i] <= 'z' )
        {
            Word[i] -= 32 ;
        }
    }
}


class Word_Node
{
    public :
    string Word ;
    string Type ;

    Word_Node()
    {}

    Word_Node( string _Word , string _Type )
    {
        Word = _Word ;
        Type = _Type ;
    }

} ;


class Context_Free_Grammar
{
    private :

    protected :

    public :
    Word_Node *Sentence ;
    int Sentence_Length ;

    bool Index_Check(int i) 
    {
        if ( i >= this->Sentence_Length ) 
        {
            return false;
        }
        return true;
    }

    string Find_Type( string __Word )
    {
        fstream Reader ;
        string Word ;
        cout<<"\nBefore Upper Case : "<<__Word ;
        To_Upper_Case(__Word) ;
        cout<<"\nAfter Upper Case : "<<__Word ;
        Reader.open("Nouns.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            cout<<"\nWord Read = "<<Word ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Noun" ;
            }
        }
        Reader.close() ;
        Reader.open("Pronouns.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Pronoun" ;
            }
        }
        Reader.close() ;
        Reader.open("Verbs.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Verb" ;
            }
        }
        Reader.close() ;
        Reader.open("Propernouns.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Propernoun" ;
            }
        }
        Reader.close() ;
        Reader.open("Prepositions.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Preposition" ;
            }
        }
        Reader.close() ;
        Reader.open("Adjectives.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Adjective" ;
            }
        }
        Reader.close() ;
        Reader.open("Determiners.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word) ;
            if( Word == __Word )
            {
                Reader.close() ;
                return "Determiner" ;
            }
        }
        Reader.close() ;
        Reader.open("Conjunctions.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
            To_Upper_Case(Word);
            if( Word == __Word )
            {
                Reader.close() ;
                return "Conjunction" ;
            }
        }
        Reader.close() ;
        system("cls") ;
        cout<< " Invalid Word Type " ;
        exit(1) ;
    }

    void Assign_Types()
    {
        string __Type ;
        for( int i = 0 ; i < this->Sentence_Length ; ++i )
        {
            __Type = Find_Type( this->Sentence[i].Word ) ;
            To_Upper_Case(__Type) ;
            this->Sentence[i].Type = __Type ;
        }
    }

    Context_Free_Grammar()
    {
        string _Sentence ;
        getline( cin , _Sentence ) ;
        this->Sentence_Length = Total_Words(_Sentence) + 1 ;
        char TokenString[this->Sentence_Length * 20 ] ;
        strcpy( TokenString , _Sentence.c_str()) ;
        char *Token = strtok( TokenString , " "); 
        this->Sentence = new Word_Node[this->Sentence_Length] ;
        int i = 0 ;
        while (Token != NULL) 
        { 
            this->Sentence[i].Word = Token ;
            cout<<this->Sentence[i].Word<<endl;
            Token = strtok(NULL, " "); 
            i++ ;
        } 
        this->Assign_Types() ;
        cout<<endl ;
        for( int i = 0 ; i < this->Sentence_Length ; ++i )
        {
            cout<<"Word  =  "<<this->Sentence[i].Word<<"    Type  =  "<<this->Sentence[i].Type<<endl ;
        }
    }

    ~Context_Free_Grammar()
    {
        delete[] this->Sentence ;
    }


} ;



int main()
{
    Context_Free_Grammar *Machine = new Context_Free_Grammar() ;
}