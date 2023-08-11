#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
// Structure for singly linear and singly circular
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

//////////////////////////////////////////////////////////////////////////////////////////////
// Structure for doubly linear and doubly circular
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//////////////////////////////////////////////////////////////////////////////////////////////
// Structure for Binary Search Tree
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeB
{
    T data;
    struct NodeB *lchild;
    struct NodeB *rchild;
};

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of singly linear linked list
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> *first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int FirstOccurance(T no);
    int LastOccurance(T no);

    T LargestElement();
    T SmallestElement();
    T DisplayAddition();
    T DisplaySecondMax();

    SinglyLL<int> DisplayPerfect();
    SinglyLL<int> DisplayPrime();
    SinglyLL<int> DisplayEven();
    SinglyLL<int> DisplayOdd();
    SinglyLL<int> AddDigit();

    bool SearchElement(T no);
    int FrequencyOfElement(T no);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T>::Display()
{
    cout<<"Elements of Singly Linear linked list are: "<<"\n";

    NodeS<T> * temp = first;

    while(temp!= NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL <T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL <T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		FirstOccurance
//	Input :				Generic
//	Output :			integer
// 	Description :		Returns first occurance of input element in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL <T>::FirstOccurance(T no)
{
    int iCount = 0, iPos = 0;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == no)
            {
                iPos = iCount;
                break;
            }
            temp = temp->next;
            iCount++;
        }
    }
    if(iPos == 0)
    {
        cout<<"No such element present"<<"\n";
    }   
    return iPos;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		LastOccurance
//	Input :				Generic
//	Output :			integer
// 	Description :		Returns last occurance of input element in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL <T>::LastOccurance(T no)
{
    int iCount = 0, iPos = 0;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == no)
            {
                iPos = iCount;
            }
            temp = temp->next;
            iCount++;
        }
    }
    if(iPos == 0)
    {
        cout<<"No such element present"<<"\n";
    }
    return iPos;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		LargestElement
//	Input :				None
//	Output :			Generic
// 	Description :		Returns largest element from the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL <T>::LargestElement()
{
    T Max;
    struct NodeS<T> *temp = first;

    Max = temp->data;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data > Max)
            {
                Max = temp->data;
            }
            temp = temp->next;
        }
    }
    return Max;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		SmallestElement
//	Input :				None
//	Output :			Generic
// 	Description :		Returns smallest element from the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL <T>::SmallestElement()
{
    T Min = 0;
    struct NodeS<T> *temp = first;

    Min = temp->data;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data < Min)
            {
                Min = temp->data;
            }
            temp = temp->next;
        }
    }
    return Min;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplayAddition
//	Input :				None
//	Output :			Generic
// 	Description :		Returns addition of elements in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL <T>::DisplayAddition()
{
    T Sum;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            Sum = Sum + temp->data;
            temp = temp->next;
        }
    }
    return Sum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplaySecondMax
//	Input :				None
//	Output :			Generic
// 	Description :		Returns second maximum element in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL <T>::DisplaySecondMax()
{
    T Sum, Max1, Max2;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        Max1 = temp->data;
        Max2 = temp->data;

        while(temp != NULL)
        {
            if((temp->data) > Max1)
            {
                Max2 = Max1;
                Max1 = temp->data;
            }
            else if((temp->data) > Max2)
            {
                Max2 = temp->data;
            }
            temp = temp->next;
        }
    }
    return Max2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplayPerfect
//	Input :				None
//	Output :			LinkedList
// 	Description :		Returns linkedlist of perfect numbers.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<int> SinglyLL <T>::DisplayPerfect()
{
    int iCnt = 0;
    struct NodeS<T> *temp = first;
    SinglyLL<int> obj;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
        return obj;
    }
    else
    {
        while(temp != NULL)
        {
            int iSum = 0;
            for(iCnt = 1; iCnt < (temp->data) / 2; iCnt++)
            {
                if((temp->data % iCnt) == 0)
                {
                    iSum = iSum + iCnt;
                }
            }

            if(iSum == (temp->data))
            {
                obj.InsertLast(iSum);
            }
            temp = temp->data;
        }    
    }
    return obj;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplayPrime
//	Input :				None
//	Output :			LinkedList
// 	Description :		Returns linkedlist of prime numbers.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<int> SinglyLL <T>::DisplayPrime()
{
    int iCnt = 0, iNo = 0, iPrime = 0;
    struct NodeS<T> *temp = first;
    SinglyLL<int> obj;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
        return obj;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == 2)
            {
                obj.InsertLast(temp->data);
            }
            for(iCnt = 2; iCnt < iNo / 2; iCnt++)
            {
                iNo = temp->data;
                if(iNo % iCnt == 0)
                {
                    break;
                }
                else
                {
                    iPrime = temp->data;
                }
            }
            if(iPrime != 0)
            {
                obj.InsertLast(iPrime);
            }
            temp = temp->next;
        }
    }
    return obj;    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		AddDigit
//	Input :				None
//	Output :			Linkedlist
// 	Description :		Returns linkedlist where the elements of the linkedlist is the addition of their digits.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<int> SinglyLL <T>::AddDigit()
{
    int iCnt = 0, iSum = 0, iNo = 0;
    struct NodeS<T> *temp = first;
    SinglyLL<int> obj;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
        return obj;
    }
    else
    {
        while(temp != NULL)
        {
            int iDigit = 0;
            iSum = 0;
            iNo = temp->data;
            while(iTemp != 0)
            {
                iDigit = iNo % 10;
                iSum = iSum + iDigit;
                iNo = iNo / 10;
            }
            obj.InsertLast(iSum);
            temp = temp->next;
        }
    }
    return obj;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplayEven
//	Input :				None
//	Output :			LinkedList
// 	Description :		Returns Linkedlist of even elements.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<int> SinglyLL <T>::DisplayEven()
{
    int iCnt = 0;
    bool bFlag = false;
    struct NodeS<T> *temp = first;
    SinglyLL<int> obj;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
        return obj;
    }
    else
    {
        while(temp != NULL)
        {
            if((temp->data) % 2 == 0)
            {
                bFlag = true;
                obj.InsertLast(temp->data);
            }
        }
        if(bFlag == false)
        {
            cout<<"No Even elements found!"<<"\n";
        }
    }
    return obj;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		DisplayOdd
//	Input :				None
//	Output :			integer
// 	Description :		Returns Linkedlist of odd elements.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<int> SinglyLL <T>::DisplayOdd()
{
    int iCnt = 0;
    bool bFlag = false;
    struct NodeS<T> *temp = first;
    SinglyLL<int> obj;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
        return obj;
    }
    else
    {
        while(temp != NULL)
        {
            if((temp->data) % 2 != 0)
            {
                bFlag = true;
                obj.InsertLast(temp->data);
            }
        }
        if(bFlag == false)
        {
            cout<<"No odd elements found!"<<"\n";
        }
    }
    return obj;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		SearchElement
//	Input :				Generic
//	Output :			Boolean
// 	Description :		Returns true if the element is found in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL <T>::SearchElement(T no)
{
    bool bFlag = false;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == no)
            {
                bFlag = true;
                break;
            }
            temp = temp->next;
        }
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		FrequencyOfElement
//	Input :				Generic
//	Output :			integer
// 	Description :		Returns frequency of input element in the linked list.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL <T>::FrequencyOfElement(T no)
{
    int iCount = 0;
    bool bFlag = false;
    struct NodeS<T> *temp = first;

    if(temp == NULL)
    {
        cout<<"No elements present!"<<"\n";
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == no)
            {
                bFlag = true;
                iCount++;
            }
            temp = temp->next;
        }
        if(bFlag == false)
        {
            cout<<"Element not found"<<"\n";
        }
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of singly circular linked list
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL <T>::Display()
{
    cout<<"Elements of Singly circular linked list are: "<<"\n";

    NodeS<T> * temp = first;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int SinglyCL <T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL <T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL <T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
        iCount--;
    }
}

template <class T>
void SinglyCL <T>::DeleteLast()
{
    NodeS<T> * temp = first;

    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        do
        {
            temp = temp->next;
        }while(temp->next != last);

        delete temp->next;
        last = temp;
        last->next = first;
        iCount--;
    }
}

template <class T>
void SinglyCL <T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of doubly linear linked list
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL <T>::Display()
{
    cout<<"Elements of Doubly linear linked list are: "<<"\n";

    NodeD<T> * temp = first;

    cout<<"NULL <=> ";
    while(temp!= NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<" NULL"<<"\n";
}

template <class T>
int DoublyLL <T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL <T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    NodeD<T> * temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL <T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T>::DeleteLast()
{
    NodeD<T> * temp = first;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    { 
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of doubly circular linked list
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL <T>::Display()
{
    cout<<"Elements of Doubly circular linked list are: "<<"\n";

    NodeD<T> * temp = first;

    if((first != NULL) && (last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }while(temp != last->next);
        cout<<"\n";
    }
}

template <class T>
int DoublyCL <T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL <T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++; 
    }  
}

template <class T>
void DoublyCL <T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }
    
    iCount--;
}

template <class T>
void DoublyCL <T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    
    iCount--;
}

template <class T>
void DoublyCL <T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of Stack
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:
        struct NodeS<T> * First;
        int iCount;
        
    public:
        Stack();
        void Push(T);         // InsertLast
        int Pop();                  // DeleteFirst
        void Display();
        int Count();
        
};

template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		Push
//	Input :				Generic
//	Output :			void
// 	Description :		Inserts element in the stack.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack <T>:: Push(T)         // InsertLast
{
    NodeS<T> newn = new NodeS<T>;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		Pop
//	Input :				None
//	Output :			integer
// 	Description :		Removes element from stack.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack <T>:: Pop()
{
    int Value = 0;
    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    return Value;
}

template <class T>
void Stack <T>:: Display()
{
    NodeS<T> temp = First;
    cout<<"Elements of the stack are : \n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Stack <T>:: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class of Queue
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:
        NodeS<T> First;
        int iCount;
        
    public:
        Queue();
        void Enqueue(int iNo);         // InsertLast
        int Dequeue();                  // DeleteFirst
        void Display();
        int Count();
        
};

template <class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		Enqueue
//	Input :				Generic
//	Output :			void
// 	Description :		Inserts element in the queue datastructure.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue <T>:: Enqueue(int iNo)         // InsertLast
{
    NodeS<T> newn = new NodeS<T>;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		Dequeue
//	Input :				None
//	Output :			integer
// 	Description :		Removes element from the queue.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue <T>:: Dequeue()
{
    int Value = 0;
    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        Value = First->data;
        NodeS<T> temp = First;
        First= First->next;
        delete temp;
    }
    iCount--;

    return Value;
}

template <class T>
void Queue <T>:: Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as queue is empty\n";
        return;
    }

    cout<<"Elements of the queue are : \n";

    NodeS<T> temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Queue <T>:: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Class for Linear, Bi-directional and binary search
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SearchAlgo
{
    public:
        T *Arr;
        int iSize;

        SearchAlgo(int);
        ~SearchAlgo();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
};

template <class T>
SearchAlgo<T>::SearchAlgo(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
SearchAlgo<T>::~SearchAlgo()
{
    delete []Arr;
}

template <class T>
void SearchAlgo<T>::Accept()
{
    cout<<"Enter the elements : \n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void SearchAlgo<T>::Display()
{
    cout<<"Elements of array are : \n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		LinearSearch
//	Input :				Generic
//	Output :			Boolean
// 	Description :		Returns true if Number is found.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgo<T>::LinearSearch(T No)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		BidirectionalSearch
//	Input :				Generic
//	Output :			Boolean
// 	Description :		Returns true if Number is found.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgo<T>::BidirectionalSearch(T No)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		BinarySearch
//	Input :				Generic
//	Output :			Boolean
// 	Description :		Returns true if Number is found.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				19/07/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgo<T>::BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

template <class T>
class BinarySearchTree
{
    public:
        struct NodeB * first;

    void Insert(struct NodeB ** first, T no);
    bool Search(struct NodeB * first, T no);
    void Preorder(struct NodeB * first);
    void Postorder(struct NodeB * first);
    void Inorder(struct NodeB * first);
    void Display(struct NodeB * first);
    int CountNodes(struct NodeB * first);
    int CountLeafNodes(struct NodeB * first);
    int CountParentNodes(struct NodeB * first);
};

template <class T>
void BinarySearchTree <T>::Insert(struct NodeB ** first, T no)
{
    struct NodeB * newn = NULL;
    struct NodeB * temp = *first;

    newn = (struct NodeB *)malloc(sizeof(struct NodeB));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : Unable to insert"<<"\n";
                free(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;   
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild; 
            }
        }
    }
}

template <class T>
void BinarySearchTree <T>::Display(struct NodeB * first)
{
    if(first != NULL)
    {
        cout<<first->data<<"\n";
        Display(first->lchild);
        Display(first->rchild);
    } 
}

template <class T>
void BinarySearchTree <T>::Preorder(struct NodeB * first)
{
    if(first != NULL)
    {
        cout<<first->data;
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

template <class T>
void BinarySearchTree <T>::Postorder(struct NodeB * first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data;
    }
}

template <class T>
void BinarySearchTree <T>::Inorder(struct NodeB * first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data;
        Inorder(first->rchild);
    }
}

template <class T>
bool BinarySearchTree <T>::Search(struct NodeB * first, T no)
{
    bool bFlag = false;

    if(first != NULL)
    {
        cout<<"Tree is empty"<<"\n";
        return bFlag;
    }
    
    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }
    return bFlag;   
}

template <class T>
int BinarySearchTree <T>::CountNodes(struct NodeB * first)
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first != NULL)
        {
            iCount++;
            CountNodes(first->lchild);
            CountNodes(first->rchild);
        }
    }
    return iCount;
}

template <class T>
int BinarySearchTree <T>::CountLeafNodes(struct NodeB * first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if((first->lchild == NULL) && (first->rchild == NULL))
        {
            iCount++;
        }
    CountLeafNodes(first->lchild);
    CountLeafNodes(first->rchild);
    }
    return iCount;
}

template <class T>
int BinarySearchTree <T>::CountParentNodes(struct NodeB * first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if((first->lchild != NULL) && (first->rchild != NULL))
        {
            iCount++;
        }
    CountParentNodes(first->lchild);
    CountParentNodes(first->rchild);
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Entry point function
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    return 0;
}