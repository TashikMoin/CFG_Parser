#ifndef QUEUE_H
#define QUEUE_h

#pragma once

#include<iostream>
#include<fstream>
using namespace std ;

class Production
{
	public :
	string Production_Name ;
	string Word ;
	string Type ;

    Production( )
	{
		this->Production_Name = "" ;
		this->Word = "" ;
		this->Type = "" ;
	}

} ;

class Queue
{
	private:
		int Size ;
		int Front ;
		int Rear ;
        Production *Data ;
	public:
		Queue( int Size_ = 10 )
		{
			this->Data = new Production[Size_];
			this->Size = Size_ ;
			this->Front = -1 ;
			this->Rear = -1 ;
		}

		void Enqueue( string _Production_Name , string _Word , string _Type )
		{
			Production Data_ ;
			Data_.Production_Name = _Production_Name ;
			Data_.Type = _Type ;
			Data_.Word = _Word ;
			if( ( this->Rear + 1 ) % this->Size == this->Front )
			{
				cout<<"\nException Thrown : Queue Is Already Full !\n" ;
			}
			else
			{
                this->Rear = ( ( this->Rear + 1 ) % ( this->Size ) ) ;
                this->Data[this->Rear] = Data_ ;
                if( this->Front == -1 )
                {
                    this->Front = 0 ;
                }
			}

		}

		Production Dequeue_From_Front()
		{
			if( this->Rear == this->Front  )
			{
				cout<<"\nException Thrown : Queue Is Empty !\n" ;
                exit(1) ;
			}
			else
			{
                Production Temp = this->Data[ this->Front ] ;
				this->Front = ( ( this->Front + 1 ) % ( this->Size ) ) ;
                return Temp ;
			}
		}

        void Dequeue_From_Rear()
		{
            if( this->Rear != -1 )
            {
                this->Rear--;
            }
		}

		Production Peek()
		{
			return this->Data[ this->Front ] ;
		}

		void Print_Queue( )
        {
			string Output = "" ;
			cout<<endl ;
			cout<<" S\n" ;
			int i = this->Front ;
	        while(i!=this->Rear)
	        {
				if( Output == "" && this->Data[i].Type == "DETERMINER" )
				{
					while( this->Data[i+1].Production_Name == "NOMINAL" )
					{
						cout<<Output<<" "<<this->Data[i].Production_Name<<" VP"<<endl
				            <<Output<<" "<<this->Data[i].Type<<" VP"<<endl ;
					    Output = Output + " " + this->Data[i].Word ;
					    ++i ;
					}
				}
				else if( Output == "" )
				{
					cout<<Output<<" "<<this->Data[i].Production_Name<<" VP"<<endl
				    <<Output<<" "<<this->Data[i].Type<<" VP"<<endl ;
				}
				else
				{
					cout<<Output<<" "<<this->Data[i].Production_Name<<endl
				    <<Output<<" "<<this->Data[i].Type<<" "<<this->Data[i+1].Production_Name<<endl ;
				}

				Output = Output + " " + this->Data[i].Word ;
				++i ;
        	}
				cout<<Output<<" "<<this->Data[i].Production_Name<<endl
				<<Output<<" "<<this->Data[i].Type<<endl ;
				Output = Output + " " + this->Data[i].Word ;
				cout<<Output<<endl ;
        }
} ;

#endif