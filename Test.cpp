#include<iostream>
using namespace std ;
int main()
{
    string x = "" ;
    x = x + " " + " Hello " + " Tashik " ;
    for( int i = 0 ; i < 5 ; ++i )
    {
        x += "   " ;
    }
    for( int i = 0 ; i < 5 ; ++i )
    {
        x += "---" ;
    }
    cout<<x ;
}