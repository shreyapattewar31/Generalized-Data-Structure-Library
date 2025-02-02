#include<iostream>
using namespace std;

template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeSL
// Description:     It is used to store data and maintain connections between elements in a singly linear linked list.
// Author:         Shreya Pattewar 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     SinglyLL
// Description:    It is used to create and manipulate a singly linear linked list
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyLL
{
    private: 
        struct nodeSL<T> * First;
        int iCount;
    public:
        SinglyLL(); 
        
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  SinglyLL
// Description:    Constructor used to initialise the variables
// Author:         Shreya Pattewar
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SinglyLL <T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}


template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of Singly Linear LinkedList
// Input :         None
// Output :        Prints the elements of the linked list to the console
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::Display()
{
    struct nodeSL<T> * temp = First;
    
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of Singly Linear LinkedList
// Input :         None
// Output :        Prints the number of elements of the linked list to the console
// Author:         Shreya Pattewar
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLL <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Description:    It is used to insert element at the First position of Singly Linear LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the beginning
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Description:    It is used to insert element at the Last position of Singly Linear LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the end
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp =NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Description:    It is used to insert element at the given position of Singly Linear LinkedList
// Input :         (int/ float/ char/ double), int
// Output :        Modifies the linked list by adding a new node at the given position
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::InsertAtPos(T No, int iPos)
{
    int i = 0;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSL<T> * newn = NULL;
        struct nodeSL<T> * temp = First;

        newn = new nodeSL<T>;

        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Description:    It is used to delete element at the First position of Singly Linear LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the first position
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"LL is empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
    }
    else
    {
        struct nodeSL<T> * temp = First;

        First = First->next;
        delete temp;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Description:    It is used to delete element at the Last position of Singly Linear LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the last position
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T>::DeleteLast()
{
    if(First == NULL)
    {
        cout<<"LL is empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
    }
    else
    {
        struct nodeSL<T> * temp = First;

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Description:    It is used to delete element at the given position of Singly Linear LinkedList
// Input :         int
// Output :        Modifies the linked list by deleting a existing node at the given position
// Author:         Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL <T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1 = NULL;
    struct nodeSL<T> * temp2 = NULL;

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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}


template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeDL
// Description:     It is used to store data and maintain connections between elements in a linked list.
// Author:          Shreya Pattewar
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     DoublyLL
// Description:    It is used to create and manipulate a linked list
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyLL
{
    public:
        struct nodeDL<T> * First;
        int iCount;

        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DoublyLL
// Description:    Constructor used to initialise the variables
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DoublyLL <T>::DoublyLL()
{
    cout<<"Inside Constructor"<<endl;
    First = NULL;
    iCount = 0;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of LinkedList
// Input :         None
// Output :        Prints the elements of the linked list to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::Display()
{
    struct nodeDL<T> * temp = First;

    cout<<"NULL <=> ";
    while(temp!= NULL)
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of LinkedList
// Input :         None
// Output :        Prints the number of elements of the linked list to the console
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int DoublyLL <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Description:    It is used to insert element at the First position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the beginning
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // $

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Description:    It is used to insert element at the Last position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the end
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // $

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Description:    It is used to insert element at the given position of LinkedList
// Input :         (int/ float/ char/ double), int
// Output :        Modifies the linked list by adding a new node at the given position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::InsertAtPos(T No, int iPos)
{
    int i = 0;

    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        temp->next = newn;
        newn->next->prev = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Description:    It is used to delete element at the First position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the first position
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::DeleteFirst()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
    }
    else
    {
        temp = First;

        First = temp->next;
        temp->next->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Description:    It is used to delete element at the Last position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the last position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
    }
    else
    {
        temp = First;

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Description:    It is used to delete element at the given position of LinkedList
// Input :         int
// Output :        Modifies the linked list by deleting a existing node at the given position
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL <T>::DeleteAtPos(int iPos)
{
    int i = 0;

    struct nodeDL<T> * temp1 = NULL;
    struct nodeDL<T> * temp2 = NULL;

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
        temp1 = First;

        for(i = 1; i < iPos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    iCount--;
}


template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeSCL
// Description:     It is used to store data and maintain connections between elements in a linked list.
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeSCL
{
    T data;
    struct nodeSCL *next;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     SinglyCL
// Description:    It is used to create and manipulate a linked list
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyCL
{
    private:
        struct nodeSCL<T> * First;
        struct nodeSCL<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  SinglyCL
// Description:    Constructor used to initialise the variables
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SinglyCL <T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of LinkedList
// Input :         None
// Output :        Prints the elements of the linked list to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: Display()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    do
    {
        cout<<"| "<<First->data<<" |"<<" -> ";
        First = First->next;
    } while (First != Last->next);
    
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of LinkedList
// Input :         None
// Output :        Prints the number of elements of the linked list to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SinglyCL <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Description:    It is used to insert element at the First position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the beginning
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: InsertFirst(T No)
{
    struct nodeSCL<T> * newn = NULL;

    newn = new nodeSCL<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Description:    It is used to insert element at the Last position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the end
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: InsertLast(T No)
{
    struct nodeSCL<T> * newn = NULL;

    newn = new nodeSCL<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Description:    It is used to insert element at the given position of LinkedList
// Input :         (int/ float/ char/ double), int
// Output :        Modifies the linked list by adding a new node at the given position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: InsertAtPos(T No, int iPos)
{
    int i = 0;

    struct nodeSCL<T> * newn = NULL;
    struct nodeSCL<T> * temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSCL<T>;

        newn->data = No;
        newn->next = NULL;

        temp = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Description:    It is used to delete element at the First position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the first position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        Last = NULL;
    }
    else
    {
        Last->next = First->next;
        delete First;
        First = Last->next;
    }
    iCount--;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Description:    It is used to delete element at the Last position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the last position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: DeleteLast()
{
    struct nodeSCL<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Description:    It is used to delete element at the given position of LinkedList
// Input :         int
// Output :        Modifies the linked list by deleting a existing node at the given position
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL <T>:: DeleteAtPos(int iPos)
{
    int i = 0;

    struct nodeSCL<T> * temp1 = NULL;
    struct nodeSCL<T> * temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}


template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeDCL
// Description:     It is used to store data and maintain connections between elements in a linked list.
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeDCL
{
    T data;
    struct nodeDCL *next;
    struct nodeDCL *prev;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     DoublyCL
// Description:    It is used to create and manipulate a linked list
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyCL
{
    private:
        struct nodeDCL<T> * First;
        struct nodeDCL<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DoublyCL
// Description:    Constructor used to initialise the variables
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DoublyCL <T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of LinkedList
// Input :         None
// Output :        Prints the elements of the linked list to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of LinkedList
// Input :         None
// Output :        Prints the number of elements of the linked list to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int DoublyCL <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Description:    It is used to insert element at the First position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the beginning
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::InsertFirst(T No)
{
    struct nodeDCL<T> * newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Description:    It is used to insert element at the Last position of LinkedList
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node at the end
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::InsertLast(T No)
{
    struct nodeDCL<T> * newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Description:    It is used to insert element at the given position of LinkedList
// Input :         (int/ float/ char/ double), int
// Output :        Modifies the linked list by adding a new node at the given position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::InsertAtPos(T No, int iPos)
{
    struct nodeDCL<T> * temp = NULL;
    struct nodeDCL<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDCL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Description:    It is used to delete element at the First position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the first position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Description:    It is used to delete element at the Last position of LinkedList
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the last position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Description:    It is used to delete element at the given position of LinkedList
// Input :         int
// Output :        Modifies the linked list by deleting a existing node at the given position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL <T>::DeleteAtPos(int iPos)
{
    struct nodeDCL<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
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
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}


template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeQ
// Description:     It is used to store data and maintain connections between elements in a stack
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     Stack
// Description:    It is used to create and manipulate a stack
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        T Pop();   // DeleteFirst()
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Stack
// Description:    Constructor used to initialise the variables
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of Stack
// Input :         None
// Output :        Prints the elements of the stack to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack <T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of Stack
// Input :         None
// Output :        Prints the number of elements of the stack to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Push
// Description:    It is used to insert element into the Stack
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack <T>::Push(T No)
{
    struct nodeS<T> * newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Pop
// Description:    It is used to delete element from the Stack
// Input :         None
// Output :        Returns the removed element
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

T Stack <T>::Pop()
{
    T iValue = 0;
    struct nodeS<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}


template <class T>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure name:  nodeQ
// Description:     It is used to store data and maintain connections between elements in a Queue
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class name:     Queue
// Description:    It is used to create and manipulate a Queue
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        T DeQueue();   // DeleteFirst()
};

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Queue
// Description:    Constructor used to initialise the variables
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Description:    It is used to display elements of Stack
// Input :         None
// Output :        Prints the elements of the stack to the console
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Queue <T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Description:    It is used to Count the elements of Stack
// Input :         None
// Output :        Prints the number of elements of the stack to the console
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Queue <T>::Count()
{
    return iCount;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Enqueue
// Description:    It is used to insert element into the Queue
// Input :         (int/ float/ char/ double)
// Output :        Modifies the linked list by adding a new node 
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Queue <T>::EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name:  Dequeue
// Description:    It is used to delete element from the Queue
// Input :         None
// Output :        Modifies the linked list by deleting a existing node at the first position
// 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

T Queue <T>::DeQueue()
{
    T iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function name:  Main
// Description:    Its entry point function
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<endl<<"------------------IMPLEMENTATION OF SINGLY LINEAR LINKEDLIST------------------"<<endl;

    SinglyLL<int> *iobj = new SinglyLL<int>();

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;

    iobj->InsertFirst(1);
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;

    iobj->InsertLast(151);
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;
    
    iobj->DeleteFirst();
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;

    iobj->DeleteLast();
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;
    
    iobj->InsertAtPos(105, 5);
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    cout<<"Number of elements are: "<<iobj->Count()<<endl;


    cout<<endl<<"------------------IMPLEMENTATION OF DOUBLY LINEAR LINKEDLIST------------------"<<endl;

    DoublyLL<double> *dobj = new DoublyLL<double>();

    dobj->InsertFirst(51.4554);
    dobj->InsertFirst(21.4554);
    dobj->InsertFirst(11.4554);

    dobj->InsertLast(101.4554);
    dobj->InsertLast(111.4554);
    dobj->InsertLast(121.4554);

    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->InsertFirst(1.4554);
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->InsertLast(151.4554);
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->InsertAtPos(105.4554, 5);
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    cout<<"Number of elements: "<<dobj->Count()<<endl;


    cout<<endl<<"------------------IMPLEMENTATION OF SINGLY CIRCULAR LINKEDLIST------------------"<<endl;

    SinglyCL<char> *cobj = new SinglyCL<char>();

    cobj->InsertFirst('c');
    cobj->InsertFirst('b');
    cobj->InsertFirst('a');

    cobj->InsertLast('d');
    cobj->InsertLast('e');
    cobj->InsertLast('f');

    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;

    cobj->InsertFirst('p');
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;

    cobj->InsertLast('q');
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;
    
    cobj->DeleteFirst();
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;

    cobj->DeleteLast();
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;
    
    cobj->InsertAtPos('x', 5);
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    cout<<"Number of elements are: "<<cobj->Count()<<endl;


    cout<<endl<<"------------------IMPLEMENTATION OF DOUBLY CIRCULAR LINKEDLIST------------------"<<endl;

    DoublyCL<float> *fobj = new DoublyCL<float>();

    fobj->InsertFirst(51.18f);
    fobj->InsertFirst(21.18f);
    fobj->InsertFirst(11.18f);

    fobj->InsertLast(101.18f);
    fobj->InsertLast(111.18f);
    fobj->InsertLast(121.18f);

    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->InsertFirst(1.18f);
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->InsertLast(151.18f);
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->DeleteFirst();
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->DeleteLast();
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->InsertAtPos(105.18f, 5);
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    cout<<"\nNumber of elements: "<<fobj->Count()<<endl;


    cout<<endl<<"------------------IMPLEMENTATION OF STACK------------------"<<endl;

    Stack<char> *sobj = new Stack<char>();

    sobj->Push('a');
    sobj->Push('b');
    sobj->Push('c');
    sobj->Push('d');

    sobj->Display();
    cout<<"Number of elements in the Stack are : "<<sobj->Count()<<"\n";
    
    char cRet1 = sobj->Pop();
    cout<<"Removed element is : "<<cRet1<<"\n";
    char cRet2 = sobj->Pop();
    cout<<"Removed element is : "<<cRet2<<"\n";
    sobj->Display();
    cout<<"Number of elements in the Stack are : "<<sobj->Count()<<"\n";

    sobj->Push('x');
    sobj->Display();
    cout<<"Number of elements in the Stack are : "<<sobj->Count()<<"\n";


    cout<<endl<<"------------------IMPLEMENTATION OF QUEUE------------------"<<endl;

    Queue<int> *qobj = new Queue<int>();

    qobj->EnQueue(10);
    qobj->EnQueue(20);
    qobj->EnQueue(30);
    qobj->EnQueue(40);

    qobj->Display();
    cout<<"Number of elements in the Queue are : "<<qobj->Count()<<"\n";
    
    int iRet1 = qobj->DeQueue();
    cout<<"Removed element is : "<<iRet1<<"\n";
    int iRet2 = qobj->DeQueue();
    cout<<"Removed element is : "<<iRet2<<"\n";
    qobj->Display();
    cout<<"Number of elements in the Queue are : "<<qobj->Count()<<"\n";

    qobj->EnQueue(50);
    qobj->Display();
    cout<<"Number of elements in the Queue are : "<<qobj->Count()<<"\n";
    
    cout<<endl<<"---------------------------------------------------------------"<<endl;
 
    return 0;
}
