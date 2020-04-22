#include<iostream>
#include<string>
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

    public :
    Word_Node *Sentence ;

    Context_Free_Grammar()
    {}

    Context_Free_Grammar( Word_Node *__Sentence )
    {
        this->Sentence = __Sentence ;
    }


    bool Index_Check(int *__i) 
    {
        if (*(__i) >= 5) 
        {
            return false;
        }
        return true;
    }

    bool ProNoun(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "I") 
            {
                (*__i)++;
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool Proper_Noun(string *__words, int *__i) 
    {
        return false;
    }

    bool Determiner(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "a") 
            {
                (*__i)++;
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool Nominal(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            if (Noun(__words, __i)) 
            {
                if (Nominal(__words, __i)) 
                {
                    return true;
                } 
                else 
                {
                    (*__i)--;
                }
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool Verb(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "prefer") 
            {
                (*__i)++;
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool Noun(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            cout << __words[*(__i)] << *(__i) << endl;
            if (__words[*(__i)] == "morning" || __words[*(__i)] == "flight") 
            {
                (*__i)++;
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool Preposition(string *__words, int *__i) 
    {
        return false;
    }

    bool NP(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            if (ProNoun(__words, __i)) 
            {
                return true;
            } 
            else if (Proper_Noun(__words, __i)) 
            {} 
            else if (Determiner(__words, __i) && Nominal(__words, __i)) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool VP(string *__words, int *__i) 
    {
        if (Index_Check(__i)) 
        {
            if (Verb(__words, __i)) 
            {
                if (NP(__words, __i)) 
                {
                    if (PP(__words, __i)) 
                    {
                        return true;
                    } 
                    else 
                    {
                        (*__i)--;
                    }
                    return true;
                } 
                else if (PP(__words, __i)) 
                {
                    return true;
                } 
                else 
                {
                    (*__i)--;
                }
                (*__i)++; 
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return false;
        }
    }

    bool PP(string *__words, int *__i) 
    {
        if (Preposition(__words, __i) && NP(__words, __i)) 
        {} 
        else 
        {
            return false;
        }
    }

    void S() 
    {
        int i = 0;
        string words[] = 
        {
            "I",
            "prefer",
            "a",
            "morning",
            "flight"
        } ;

        if (NP(words, &i) && VP(words, &i)) 
        {
            cout << "PERFECT\n";
        } 
        else 
        {
            cout << "INVALID STRUCTURE\n";
        }
    }

} ;



int main()
{
    string S ;
    getline( cin , S ) ;
    char TokenString[Total_Words(S) * 20 ] ;
    strcpy( TokenString , S.c_str()) ;
    char *Token = strtok( TokenString , " "); 
    Word_Node Words[ Total_Words(S) + 1 ] ;
    int i = 0 ;
    while (Token != NULL) 
    { 
        Words[i].Word = Token ;
        cout<<Words[i].Word<<endl;
        Token = strtok(NULL, " "); 
        i++ ;
    } 
    Context_Free_Grammar *Machine = new Context_Free_Grammar(Words) ;
    


}