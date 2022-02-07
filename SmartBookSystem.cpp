// Smart Book System in Campus
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Quick Sort function
int partition(string T[], int first, int last)
{
    string pivot, temp;
    int loop, cutPoint, bottom, top;
    pivot = T[first];
    bottom = first;
    top = last;
    loop = 1;
    // always TRUE
    /*cout << "Bottom = " << bottom << ", Top = " << top << ", Pivot = " << pivot << endl;
    for (int i = bottom; i <= top; i++)
    {
        cout << T[i] << ", ";
    }
    cout << endl;*/
    while (loop)
    {

        while (T[top] < pivot)
        {
            top--;
        }
        while (T[bottom] > pivot)
        {
            bottom++;
        }
        if (bottom < top)
        {
            temp = T[bottom];
            T[bottom] = T[top];
            T[top] = temp;
            top--;
        }
        else // switch between if and else and add = to else to avoid ==
        {
            loop = 0;
            cutPoint = top;
        }
        /*cout << "Bottom = " << bottom << ", Top = " << top << ", Pivot = " << pivot << endl;
        for (int i = bottom; i <= top; i++)
        {
            cout << T[i] << ", ";
        }
        cout << endl;*/
    } // end while
    return cutPoint;
}

void quickSort(string T[], int first, int last)
{
    int cut;
    if (first < last)
    {
        cut = partition(T, first, last);
        quickSort(T, first, cut);
        quickSort(T, cut + 1, last);
    }
}

class Book
{
private:
    string name, author, field;
    int id, quantity;
    double price;

public:
    Book *next;
    Book();
    Book(int id, string name, string author, string field, int quantity, double price);
    string getName();
    string getAuthor();
    string getField();
    int getQuantity();
    double getPrice();
    int getId();
    void print();
    void buy();
    void updateStock();
    void updateName();
    void updateAuthor();
    void updateField();
    void updatePrice();
};

Book::Book() : Book(0, "", "", "", 0, 0.0)
{
}

Book::Book(int id, string name, string author, string field, int quantity, double price) : id(id), name(name), author(author), field(field), quantity(quantity), price(price)
{
    next = NULL;
}

string Book::getName()
{
    return name;
}

string Book::getAuthor()
{
    return author;
}

string Book::getField()
{
    return field;
}

int Book::getQuantity()
{
    return quantity;
}

double Book::getPrice()
{
    return price;
}

int Book::getId()
{
    return id;
}

void Book::print()
{
    cout << "-------------------------------------------------" << endl;
    cout << "------------------- BookID: " << id << " -------------------" << endl;
    cout << "-------------------------------------------------" << endl
         << endl;
    cout << "Book Name: " << name << endl
         << endl;
    cout << "Book Author: " << author << endl
         << endl;
    cout << "Author Field: " << field << endl
         << endl;
    cout << "Quantity: " << quantity << endl
         << endl;
    cout << "Price: " << price << endl
         << endl;
    cout << "-------------------------------------------------" << endl
         << endl;
}

void Book::buy()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Do you want to buy " << name << " book? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        int quan;
        cout << "Enter how many copies do you want:- " << endl
             << endl;
        cin >> quan;
        if (quan < 1)
        {
            cout << "Sorry, you entered invalid amount." << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else if (quan > quantity)
        {
            cout << "Sorry, the amount is more than the copies in the stock." << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else
        {
            quantity -= quan;
            cout << "Purchase done correctly for " << name << " book with " << quan << " copies, and " << (price * quan) << " total price and you can get a receipt with books you purchased." << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void Book::updateStock()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Hi Admin, Do you want to update " << name << " book's stock? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        int quan;
        cout << "Enter how many copies do you want to add:- " << endl
             << endl;
        cin >> quan;
        if (quan < 1)
        {
            cout << "Sorry, you entered invalid amount, you can increase the amount only." << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else
        {
            quantity += quan;
            cout << "System updated correctly and now system has " << quantity << " copies for " << name << " book." << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void Book::updateName()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Hi Admin, Do you want to update " << name << " book's name? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        string n;
        cout << "Enter the new name:- " << endl
             << endl;
        cin.ignore();
        getline(cin, n);
        name = n;
        cout << "System updated correctly and now system has " << name << " as a name for the book." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void Book::updateAuthor()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Hi Admin, Do you want to update " << name << " author name? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        string n;
        cout << "Enter the new name:- " << endl
             << endl;
        cin.ignore();
        getline(cin, n);
        name = n;
        cout << "System updated correctly and now system has " << author << " as an author name for " << name << " book." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}
void Book::updateField()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Hi Admin, Do you want to update " << name << " book's field? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        string n;
        cout << "Enter the new field:- " << endl
             << endl;
        cin.ignore();
        getline(cin, n);
        name = n;
        cout << "System updated correctly and now system has " << field << " as an author field for " << name << " book." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void Book::updatePrice()
{
    cout << endl
         << "-------------------------------------------------" << endl;
    string ans;
    cout << "Hi Admin, Do you want to update " << name << " book's price? (y/n)" << endl;
    cin >> ans;
    if (ans == "y")
    {
        double n;
        cout << "Enter the new field:- " << endl
             << endl;
        cin >> n;
        price = n;
        cout << "System updated correctly and now system has " << price << " as a price for " << name << " book." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

class SinglyLinkedList
{
public:
    Book *head;
    int size;

    SinglyLinkedList();
    SinglyLinkedList(Book *n);
    Book *nodeExists(int id);
    void appendNode(Book *n);
    void prependNode(Book *n);
    void insertNodeAfter(int id, Book *n);
    void deleteNodeByKey(int id);
    void updateNodeByKey(int id);
    void dequeue();
    void pop();
};

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
    size = 0;
}

SinglyLinkedList::SinglyLinkedList(Book *n)
{
    head = n;
    size = 1;
}

Book *SinglyLinkedList::nodeExists(int id)
{
    Book *temp = NULL;
    Book *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->getId() == id)
        {
            temp = ptr;
        }
        ptr = ptr->next;
    }
    return temp;
}

void SinglyLinkedList::appendNode(Book *n)
{
    if (nodeExists(n->getId()) != NULL)
    {
        cout << "Node already exists with key value : " << n->getId() << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = n;
            size = 1;
            cout << "Node Appended" << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else
        {
            Book *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            size++;
            cout << "Node Appended" << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
    }
}

void SinglyLinkedList::prependNode(Book *n)
{
    if (nodeExists(n->getId()) != NULL)
    {
        cout << "Node already exists with key value : " << n->getId() << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        n->next = head;
        head = n;
        size++;
        cout << "Node Prepended" << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void SinglyLinkedList::insertNodeAfter(int id, Book *n)
{
    Book *ptr = nodeExists(id);
    if (ptr == NULL)
    {
        cout << "No node exists with key value : " << id << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        if (nodeExists(n->getId()) != NULL)
        {
            cout << "Node already exists with key value : " << n->getId() << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else
        {
            n->next = ptr->next;
            ptr->next = n;
            size++;
            cout << "Node Inserted" << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
    }
}

void SinglyLinkedList::deleteNodeByKey(int id)
{
    if (head == NULL)
    {
        cout << "Singly Linked List already Empty." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        if (head->getId() == id)
        {
            head = head->next;
            size--;
            cout << "Node with key value: " << id << " unlinked from the list" << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        else
        {
            Book *temp = NULL;
            Book *prevptr = head;
            Book *currentptr = head->next;
            while (currentptr != NULL)
            {
                if (currentptr->getId() == id)
                {
                    temp = currentptr;
                    currentptr = NULL;
                }
                else
                {
                    prevptr = prevptr->next;
                    currentptr = currentptr->next;
                }
            }
            if (temp != NULL)
            {
                prevptr->next = temp->next;
                size--;
                cout << "Node with key value: " << id << " unlinked from the list" << endl;
                cout << "-------------------------------------------------" << endl
                     << endl;
            }
            else
            {
                cout << "No node exists with key value : " << id << endl;
                cout << "-------------------------------------------------" << endl
                     << endl;
            }
        }
    }
}

void SinglyLinkedList::updateNodeByKey(int id)
{
    Book *ptr = nodeExists(id);
    if (ptr != NULL)
    {
        int option;
        cout << "\nWhich data do you want to update in the book? Select option number or Enter 0 to exit." << endl;
        cout << "1. Update book name" << endl;
        cout << "2. Update book's author" << endl;
        cout << "3. Update author's field" << endl;
        cout << "4. Update book's price" << endl
             << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            ptr->updateName();
            break;
        case 2:
            ptr->updateAuthor();
            break;
        case 3:
            ptr->updateField();
            break;
        case 4:
            ptr->updatePrice();
            break;
        default:
            cout << "enter proper input" << endl;
            cout << "-------------------------------------------------" << endl
                 << endl;
        }
        cout << "Node Data Updated Successfully" << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        cout << "No node exists with key value : " << id << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void SinglyLinkedList::dequeue()
{
    if (head == NULL)
    {
        cout << "Singly Linked List already Empty." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        Book *temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << endl
             << "Book dequeued successfully." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void SinglyLinkedList::pop()
{
    if (head == NULL)
    {
        cout << "Singly Linked List already Empty." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    else
    {
        Book *prevptr = head;
        Book *currentptr = head->next;
        while (currentptr != NULL)
        {
            prevptr = prevptr->next;
            currentptr = currentptr->next;
        }
        prevptr->next = NULL;
        delete currentptr;
        size--;
        cout << endl
             << "Book popped successfully." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void sortByBook(SinglyLinkedList books, SinglyLinkedList sorted)
{
    string names[books.size];
    Book *temp = books.head;
    sorted.head = NULL;
    for (int i = 0; i < books.size; i++)
    {
        names[i] = temp->getName();
        temp = temp->next;
    }
    quickSort(names, 0, books.size - 1);
    string option;
    cout << endl
         << "Do you want the list in ascending or descending order? (a/d)" << endl;
    cin >> option;
    if (option == "a")
    {
        for (int i = books.size - 1; i >= 0; i--)
        {
            temp = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (names[i] == temp->getName())
                {
                    Book *ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                    sorted.appendNode(ex);
                }
                temp = temp->next;
            }
        }
    }
    else if (option == "d")
    {
        for (int i = 0; i < books.size; i++)
        {
            temp = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (names[i] == temp->getName())
                {
                    Book *ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                    sorted.appendNode(ex);
                }
                temp = temp->next;
            }
        }
    }
    temp = sorted.head;
    for (int i = 0; i < sorted.size; i++)
    {
        temp->print();
        temp = temp->next;
    }
}

void sortByAuthor(SinglyLinkedList books, SinglyLinkedList sorted)
{
    string authors[books.size];
    Book *temp = books.head;
    Book *temp2 = books.head;
    sorted.head = NULL;
    Book *prev = NULL;
    Book *ex = NULL;
    for (int i = 0; i < books.size; i++)
    {
        authors[i] = temp->getAuthor();
        temp = temp->next;
    }
    quickSort(authors, 0, books.size - 1);
    string option;
    cout << endl
         << "Do you want the list in ascending or descending order? (a/d)" << endl;
    cin >> option;
    if (option == "a")
    {
        for (int i = books.size - 1; i >= 0; i--)
        {
            temp = books.head;
            temp2 = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (authors[i] == temp->getAuthor())
                {
                    if (authors[i] != authors[i - 1] || authors[i] != authors[i + 1])
                    {
                        ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                        sorted.appendNode(ex);
                        prev = ex;
                    }
                    else
                    {
                        temp2 = sorted.head;
                        for (int x = 0; x < books.size; x++)
                        {
                            if (temp2->getName() != prev->getName() && temp2->getAuthor() == prev->getAuthor())
                            {
                                ex = new Book(temp2->getId(), temp2->getName(), temp2->getAuthor(), temp2->getField(), temp2->getQuantity(), temp2->getPrice());
                                sorted.appendNode(ex);
                                prev = ex;
                                ++i;
                            }
                            temp2 = temp2->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
    else if (option == "d")
    {
        for (int i = 0; i < books.size; i++)
        {
            temp = books.head;
            temp2 = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (authors[i] == temp->getAuthor())
                {
                    if (authors[i] != authors[i - 1] || authors[i] != authors[i + 1])
                    {
                        ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                        sorted.appendNode(ex);
                        prev = ex;
                    }
                    else
                    {
                        temp2 = sorted.head;
                        for (int x = 0; x < books.size; x++)
                        {
                            if (temp2->getName() != prev->getName() && temp2->getAuthor() == prev->getAuthor())
                            {
                                ex = new Book(temp2->getId(), temp2->getName(), temp2->getAuthor(), temp2->getField(), temp2->getQuantity(), temp2->getPrice());
                                sorted.appendNode(ex);
                                prev = ex;
                                ++i;
                            }
                            temp2 = temp2->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
    temp = sorted.head;
    for (int i = 0; i < sorted.size; i++)
    {
        temp->print();
        temp = temp->next;
    }
}

void sortByField(SinglyLinkedList books, SinglyLinkedList sorted)
{
    string field[books.size];
    Book *temp = books.head;
    Book *temp2 = books.head;
    sorted.head = NULL;
    Book *prev = NULL;
    Book *ex = NULL;
    for (int i = 0; i < books.size; i++)
    {
        field[i] = temp->getField();
        temp = temp->next;
    }
    quickSort(field, 0, books.size - 1);
    string option;
    cout << endl
         << "Do you want the list in ascending or descending order? (a/d)" << endl;
    cin >> option;
    if (option == "a")
    {
        for (int i = books.size - 1; i >= 0; i--)
        {
            temp = books.head;
            temp2 = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (field[i] == temp->getField())
                {
                    if (field[i] != field[i - 1] || field[i] != field[i + 1])
                    {
                        ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                        sorted.appendNode(ex);
                        prev = ex;
                    }
                    else
                    {
                        temp2 = sorted.head;
                        for (int x = 0; x < books.size; x++)
                        {
                            if (temp2->getName() != prev->getName() && temp2->getField() == prev->getField())
                            {
                                ex = new Book(temp2->getId(), temp2->getName(), temp2->getAuthor(), temp2->getField(), temp2->getQuantity(), temp2->getPrice());
                                sorted.appendNode(ex);
                                prev = ex;
                                ++i;
                            }
                            temp2 = temp2->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
    else if (option == "d")
    {
        for (int i = 0; i < books.size; i++)
        {
            temp = books.head;
            temp2 = books.head;
            for (int j = 0; j < books.size; j++)
            {
                if (field[i] == temp->getField())
                {
                    if (field[i] != field[i - 1] || field[i] != field[i + 1])
                    {
                        ex = new Book(temp->getId(), temp->getName(), temp->getAuthor(), temp->getField(), temp->getQuantity(), temp->getPrice());
                        sorted.appendNode(ex);
                        prev = ex;
                    }
                    else
                    {
                        temp2 = sorted.head;
                        for (int x = 0; x < books.size; x++)
                        {
                            if (temp2->getName() != prev->getName() && temp2->getField() == prev->getField())
                            {
                                ex = new Book(temp2->getId(), temp2->getName(), temp2->getAuthor(), temp2->getField(), temp2->getQuantity(), temp2->getPrice());
                                sorted.appendNode(ex);
                                prev = ex;
                                ++i;
                            }
                            temp2 = temp2->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
    temp = sorted.head;
    for (int i = 0; i < sorted.size; i++)
    {
        temp->print();
        temp = temp->next;
    }
}

string StringtoLower(string word)
{
    string newWord = word;
    for (int i = 0; i < word.length(); i++)
    {
        newWord[i] = tolower(word[i]);
    }
    return newWord;
}

void searchByBook(SinglyLinkedList books)
{
    Book *temp = books.head;
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    string name;
    bool found = false;
    cout << "Please enter a part of the book name that you want to get: " << endl;
    cin >> name;
    for (int i = 0; i < books.size; i++)
    {
        if (StringtoLower(temp->getName()).find(StringtoLower(name), 0) != -1)
        {
            temp->print();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << endl
             << "Sorry, this book is not available." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void searchByAuthor(SinglyLinkedList books)
{
    Book *temp = books.head;
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    string name;
    bool found = false;
    cout << "Please enter a part of the author name that you want to get his books: " << endl;
    cin >> name;
    for (int i = 0; i < books.size; i++)
    {
        if (StringtoLower(temp->getAuthor()).find(StringtoLower(name), 0) != -1)
        {
            temp->print();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << endl
             << "Sorry, this author's books are not available." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void searchByField(SinglyLinkedList books)
{
    Book *temp = books.head;
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    string name;
    bool found = false;
    cout << "Please enter a part of the field that you want to get books from: " << endl;
    cin >> name;
    for (int i = 0; i < books.size; i++)
    {
        if (StringtoLower(temp->getField()).find(StringtoLower(name), 0) != -1)
        {
            temp->print();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << endl
             << "Sorry, this field is not available in the campus." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void searchByPrice(SinglyLinkedList books)
{
    Book *temp = books.head;
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    double top, bottom;
    bool found = false;
    cout << "Please enter the range of book prices that you want to get books between them: " << endl;
    cin >> top >> bottom;
    if (bottom > top)
    {
        double temp = bottom;
        bottom = top;
        top = temp;
    }
    for (int i = 0; i < books.size; i++)
    {
        if (bottom <= temp->getPrice() && temp->getPrice() <= top)
        {
            temp->print();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << endl
             << "No book found between " << top << " and " << bottom << "." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void sort(SinglyLinkedList books)
{
    int option;
    SinglyLinkedList sorted;
    cout << "\nWhich sort operation do you want to perform? Select option number or Enter 0 to exit." << endl;
    cout << "1. Sort by book name" << endl;
    cout << "2. Sort by author name" << endl;
    cout << "3. Sort by author field" << endl
         << endl;
    cin >> option;
    switch (option)
    {
    case 0:
        break;
    case 1:
        sortByBook(books, sorted);
        break;
    case 2:
        sortByAuthor(books, sorted);
        break;
    case 3:
        sortByField(books, sorted);
        break;
    default:
        cout << "enter proper input" << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void search(SinglyLinkedList books)
{
    int option;
    cout << "\nWhich search operation do you want to perform? Select option number or Enter 0 to exit." << endl;
    cout << "1. Search by book name" << endl;
    cout << "2. Search by book author" << endl;
    cout << "3. Search by author field" << endl;
    cout << "4. Search by price range" << endl
         << endl;
    cin >> option;
    switch (option)
    {
    case 0:
        break;
    case 1:
        searchByBook(books);
        break;
    case 2:
        searchByAuthor(books);
        break;
    case 3:
        searchByField(books);
        break;
    case 4:
        searchByPrice(books);
        break;
    default:
        cout << "enter proper input" << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
}

void check(SinglyLinkedList books)
{
    Book *temp = books.head;
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    int limit;
    bool found = false;
    cout << "Please enter the limit of book quantities that you want to get books lower than it: " << endl;
    cin >> limit;
    for (int i = 0; i < books.size; i++)
    {
        if (temp->getQuantity() <= limit)
        {
            temp->print();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << endl
             << "No book is lower than the limit." << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

int main()
{
    // get file.txt data and set them in Book array
    ifstream infile;
    SinglyLinkedList books;
    Book *temp = books.head;
    Book *instance;
    infile.open("bookfile.txt", ios::out);
    if (!infile)
    {
        cout << "the file is not working or not exist." << endl;
    }
    else
    {
        string line;
        for (int i = 0; i < 10; i++)
        {
            string name, author, field;
            int id, quantity;
            double price;
            getline(infile, line);
            stringstream linestream(line);
            getline(linestream, name, '/');
            getline(linestream, author, '/');
            getline(linestream, field, '/');
            linestream >> id >> quantity >> price;
            instance = new Book(id, name, author, field, quantity, price);
            books.appendNode(instance);
            // temp->print();
            // temp = temp->next;
            // show data entered in id order
            // arr[i].print();
        }
        infile.close();
    }

    // empty Book array will be used to sort Books details by name, author, field
    SinglyLinkedList sorted;
    int originalQuantities[100];
    temp = books.head;
    for (int i = 0; i < books.size; i++)
    {
        originalQuantities[i] = temp->getQuantity();
        temp = temp->next;
    }
    string role;
    cout << "-------------------------------------------------" << endl;
    cout << "  Welcome to Smart Book System in UTM Campus" << endl;
    cout << "-------------------------------------------------" << endl
         << endl;
    cout << "If you are an admin enter 'a', and if you are a student or a normal customer enter 's'. " << endl;
    cin >> role;
    string name, author, field, op;
    double p;
    int q;
    int option, key, idx;
    double totalPrice = 0;
    if (role == "a")
    {
        do
        {
            bool isFound;
            cout << "\nHi Admin, What operation do you want to perform? Select option number or Enter 0 to exit." << endl;
            cout << "1. Show book list" << endl;
            cout << "2. Check book quantities" << endl;
            cout << "3. Update book quantity" << endl;
            cout << "4. Sort book list" << endl;
            cout << "5. Search" << endl;
            cout << "6. Append new book (Enqueue/Push)" << endl;
            cout << "7. Prepend new book" << endl;
            cout << "8. Insert new book After specific ID" << endl;
            cout << "9. Update book details" << endl;
            cout << "10. Delete a specific book" << endl;
            cout << "11. Dequeue a book" << endl;
            cout << "12. Pop a book" << endl;
            cout << "13. Clear Screan" << endl
                 << endl;

            cin >> option;
            switch (option)
            {
            case 0:
                break;
            case 1:
                temp = books.head;
                for (int i = 0; i < books.size; i++)
                {
                    temp->print();
                    temp = temp->next;
                }
                break;
            case 2:
                check(books);
                break;
            case 3:
                isFound = false;
                cout << "Please enter the book id that you want to update. " << endl;
                cin >> key;
                temp = books.head;
                for (int i = 0; i < books.size; i++)
                {
                    if (key - 1 == i)
                    {
                        temp->updateStock();
                        isFound = true;
                    }
                    temp = temp->next;
                }
                if (!isFound)
                {
                    cout << "Sorry, this book id isn't available." << endl;
                    cout << "-------------------------------------------------" << endl
                         << endl;
                }
                break;
            case 4:
                sort(books);
                break;
            case 5:
                search(books);
                break;
            case 6:
                cout << endl
                     << "------------------Append New Book(Enqueue/Push)---------------------" << endl;
                cout << "Book Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Author's Field: ";
                getline(cin, field);
                cout << "Book Price: ";
                cin >> p;
                cout << "Book Quantity: ";
                cin >> q;
                instance = new Book(books.size + 1, name, author, field, q, p);
                instance->print();
                books.appendNode(instance);
                break;
            case 7:
                cout << endl
                     << "------------------Prepend New Book---------------------" << endl;
                cout << "Book Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Author's Field: ";
                getline(cin, field);
                cout << "Book Price: ";
                cin >> p;
                cout << "Book Quantity: ";
                cin >> q;
                instance = new Book(books.head->getId() - 1, name, author, field, q, p);
                instance->print();
                books.prependNode(instance);
                break;
            case 8:
                cout << endl
                     << "------------------Insert New Book After Specific ID---------------------" << endl;
                cout << "Book ID: ";
                cin >> idx;
                cout << "Book Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Author's Field: ";
                getline(cin, field);
                cout << "Book Price: ";
                cin >> p;
                cout << "Book Quantity: ";
                cin >> q;
                instance = new Book(idx + 1, name, author, field, q, p);
                instance->print();
                books.insertNodeAfter(idx, instance);
                break;
            case 9:
                cout << endl
                     << "Enter the id of the book that you want to update:- " << endl;
                cin >> idx;
                books.updateNodeByKey(idx);
                break;
            case 10:
                cout << endl
                     << "Enter the id of the book that you want to delete:- " << endl;
                cin >> idx;
                books.deleteNodeByKey(idx);
                break;
            case 11:
                cout << endl
                     << "Do you want to dequeue a book from the list? (y/n)" << endl;
                cin >> op;
                if (op == "y")
                {
                    books.dequeue();
                }
                break;
            case 12:
                cout << endl
                     << "Do you want to pop a book from the list? (y/n)" << endl;
                cin >> op;
                if (op == "y")
                {
                    books.pop();
                }
                break;
            case 13:
                system("cls");
                break;
            default:
                cout << "enter proper input" << endl;
                cout << "-------------------------------------------------" << endl
                     << endl;
            }
        } while (option != 0);
    }
    else if (role == "s")
    {
        do
        {
            bool isFound;
            cout << "\nHi Student, What operation do you want to perform? Select option number or Enter 0 to exit." << endl;
            cout << "1. Show book list" << endl;
            cout << "2. Purchase a book" << endl;
            cout << "3. Make a receipt" << endl;
            cout << "4. Sort book list" << endl;
            cout << "5. Search" << endl;
            cout << "6. Clear Screan" << endl
                 << endl;

            cin >> option;
            switch (option)
            {
            case 0:
                break;
            case 1:
                temp = books.head;
                for (int i = 0; i < books.size; i++)
                {
                    temp->print();
                    temp = temp->next;
                }
                break;
            case 2:
                isFound = false;
                cout << "Please enter the book id that you want to purchase. " << endl;
                cin >> key;
                temp = books.head;
                for (int i = 0; i < books.size; i++)
                {
                    if (key - 1 == i)
                    {
                        temp->buy();
                        isFound = true;
                    }
                    temp = temp->next;
                }
                if (!isFound)
                {
                    cout << "Sorry, this book id isn't available." << endl;
                    cout << "-------------------------------------------------" << endl
                         << endl;
                }
                break;
            case 3:
                isFound = false;
                totalPrice = 0;
                cout << "------------ List of Purchased Bookes ------------ " << endl;
                temp = books.head;
                for (int i = 0; i < books.size; i++)
                {
                    if (originalQuantities[i] != temp->getQuantity())
                    {
                        cout << "Book ID    Book Name    Book Author    Author Field    Number of Copies Purchased    Price" << endl;
                        cout << temp->getId() << "    " << temp->getName() << "    " << temp->getAuthor() << "    " << temp->getField() << "    " << originalQuantities[i] - temp->getQuantity() << "    " << temp->getPrice() * (originalQuantities[i] - temp->getQuantity()) << endl;
                        totalPrice += temp->getPrice() * (originalQuantities[i] - temp->getQuantity());
                        isFound = true;
                    }
                    temp = temp->next;
                }
                if (!isFound)
                {
                    cout << "Sorry, you didn't purchase any book." << endl;
                    cout << "-------------------------------------------------" << endl
                         << endl;
                }
                else
                {
                    cout << "Total price" << totalPrice << endl;
                    cout << "Thanks for your visit" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            case 4:
                sort(books);
                break;
            case 5:
                search(books);
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "enter proper input" << endl;
                cout << "-------------------------------------------------" << endl
                     << endl;
            }
        } while (option != 0);
    }
    else
    {
        cout << endl
             << "See you later." << endl;
        cout << "-------------------------------------------------" << endl
             << endl;
    }
    system("pause");
    return 0;
}