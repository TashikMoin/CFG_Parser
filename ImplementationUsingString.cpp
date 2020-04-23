#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"Queue.h"
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
            Token = strtok(NULL, " "); 
            i++ ;
        } 
        this->Assign_Types() ;
        cout<<endl ;
        Queue Track_Of_Production( this->Sentence_Length + 1 ) ;
        for( int i = 0 ; i < this->Sentence_Length ; ++i )
        {
            i = this->Check_Sentence_Structure_For_NP( i , Track_Of_Production ) ;
            i++ ;
            i = this->Check_Sentence_Structure_For_VP( i , Track_Of_Production ) ;
            i++ ;
            i = this->Check_Sentence_Structure_For_PP( i , Track_Of_Production ) ;
        }
        
    }

    ~Context_Free_Grammar()
    {
        delete[] this->Sentence ;
    }


    string Find_Type( string &__Word )
    {
        fstream Reader ;
        string Word ;
        To_Upper_Case(__Word) ;
        Reader.open("Nouns.txt" , ios::in ) ;
        while( !Reader.eof() )
        {
            getline(Reader , Word ) ;
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

    int Check_Sentence_Structure_For_Nominal( int i , Queue &__Track_Of_Production )
    {
        if( i < this->Sentence_Length )
        {
            string Nominal = "" ;
            if( this->Sentence[i].Type == "NOUN" )
            {
                Nominal += this->Sentence[i].Word ;
                Nominal += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_Nominal( i , __Track_Of_Production ) ;
            }
        }
        i-- ;
        return i ;
    }

    int Check_Sentence_Structure_For_NP( int i , Queue &__Track_Of_Production )
    {
        if( i < this->Sentence_Length )
        {
            string NP = "" ;
            if( this->Sentence[i-1].Type == "PREPOSITION" )
            {
                    NP += this->Sentence[i].Word ;
                    NP += " " ;
                    // Push Into Queue this->Sentence[i].Word & Production Name
                    i++ ;
                    return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;    
            }
            if( this->Sentence[i].Type == "PRONOUN" || this->Sentence[i].Type == "PROPERNOUN" )
            {
                NP += this->Sentence[i].Word ;
                NP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
            }
            if( this->Sentence[i].Type == "DETERMINER" )
            {
                NP += this->Sentence[i].Word ;
                NP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_Nominal( i , __Track_Of_Production ) ;               
            }
        }
        i-- ;
        return i ;
    }


    int Check_Sentence_Structure_For_PP( int i , Queue &__Track_Of_Production )
    {
        if( i < this->Sentence_Length )
        {
            string PP = "" ;
            if( this->Sentence[i].Type == "PREPOSITION" )
            {
                PP += this->Sentence[i].Word ;
                PP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
            }
        }
        i-- ;
        return i ;
    }


    int Check_Sentence_Structure_For_VP( int i , Queue &__Track_Of_Production )
    {
        if( i < this->Sentence_Length )
        {
            string VP = "" ;
            if( this->Sentence[i].Type == "VERB" && i == this->Sentence_Length - 1 )
            {
                VP += this->Sentence[i].Word ;
                VP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                return i ;
            }

            if( this->Sentence[i].Type == "VERB" && this->Sentence[i+1].Type == "PREPOSITION" )
            {
                VP += this->Sentence[i].Word ;
                VP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_PP( i , __Track_Of_Production ) ;
            }

            if( this->Sentence[i].Type == "VERB" )
            {
                VP += this->Sentence[i].Word ;
                VP += " " ;
                // Push Into Queue this->Sentence[i].Word & Production Name
                i++ ;
                return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
            }



        }
        i-- ;
        return i ;
    }




} ;



int main()
{
    Context_Free_Grammar *Machine = new Context_Free_Grammar() ;
}