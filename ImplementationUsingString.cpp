#include<iostream>
#include<string>
#include<string.h>
using namespace std ;

int Total_Words( string Sentence )
{
    int i = 0 , Count = 0 ;
    while( i < Sentence.length() )
    {
        if(Sentence[i] == ' ')
        {
            Count++ ;
        }
        i++ ;
    }
    return Count ;
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

int main()
{
    string Sentence ;
    getline( cin , Sentence ) ;
    char TokenString[Total_Words(Sentence) * 20 ] ;
    strcpy( TokenString , Sentence.c_str()) ;
    char *Token = strtok( TokenString , " "); 
    Word_Node Words[ Total_Words(Sentence) + 1 ] ;
    int i = 0 ;
    while (Token != NULL) 
    { 
        Words[i].Word = Token ;
        cout<<Words[i].Word<<endl;
        Token = strtok(NULL, " "); 
        i++ ;
    } 


}