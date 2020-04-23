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
		
		void Enqueue( Production Data_ )
		{
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
				cout<<"\nException Thrown :Queue Is Empty !\n" ;
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
			cout<<endl ;
	        for( int i = this->Front ; i!=this->Rear + 1 ; i++ )
	        {
		        cout<<this->Data[i].Production_Name<<"  " ;
				cout<<this->Data[i].Word<<"  " ;
				cout<<this->Data[i].Type<<"  " ;
        	}
	        cout<<endl;
        }
} ;
