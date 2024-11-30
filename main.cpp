#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
ifstream inAdmin;
ifstream inBook;
ifstream inTicket;
ifstream inUser;
ofstream outAdmin;
ofstream outBook;
ofstream outTicket;
ofstream outUser ;


void setposition( int x, int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void textcolor(int x)
{
	HANDLE color ;
	color  = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color , x);
}

void gotocolor(int x,int y,string s,int color)
{
	setposition(x,y);
	textcolor(color);
	cout << s;
	textcolor(7);
}

void textColor (int x,int y,int color )
{
	setposition(x,y);
	textcolor(color);
	textcolor(7);
}

void write(int x, int y, string z)
{
	setposition(x, y);
	cout << z;
}


template <class DataType>
class LinkedList;

template <class DataType>
class Node {
    friend class LinkedList<DataType>;
public:
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data) : _data(data), _pNext(NULL) {}

    DataType getData() const { return _data; }
    Node* getNext() const { return _pNext; }


    void display() {
        cout << _data << " ";
    }
};

template <class DataType>
class LinkedList {
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;

public:
    LinkedList();
    ~LinkedList();

	Node<DataType>* getHead() const { return _pHead; }
    Node<DataType>* getTail() { return _pTail; }

    void addHead(DataType data);
    void addTail(DataType data);
    void addAfter(DataType q, DataType data);
    void addUnique(DataType data);
    void display();
    void addChar(char c);
    void removeLastChar();

    string setstring(int x, int y, int &iCount);
    void addBook();
    void checkBookCode(string s);
    void deleteBook();
    void bookManagement();
    void informationTicket(int &n);
    void information();
    void borrowBook();
    void returnBook();
    void manageTicket();
    bool menu();
    void removeHead();
    void removeTail();
    void append(const DataType &value);
    void removeAfter(Node<DataType> *data);
    void remove(DataType data);
    void clear();
	int  getSize();
	bool isEmpty();
    void readFromFile(const string& filename);
    void writeToFile(const string& filename);
    Node<DataType> *search(DataType data);
    bool exists(DataType data);

    void saveDataBook();
    void saveDataTicket();
    void login();
    void DATA();
    long inputInteger(int x, int y, int &iCount);
    void menuFunction(int n, int k);
    string inputPassword(int x, int y);
    string input(int x, int y, int &iCount, LinkedList<char>& inputList) {
        char a;
        do {
            a = _getch(); 

            if (inputList.getSize() > 100 && a != 8)  
                continue;

            if (a == 8 && !inputList.isEmpty()) {    
                inputList.removeTail(); 
                setposition(--x, y);    
                cout << " ";            
                setposition(x, y);      
                continue;
            }

            if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ') {  
                setposition(x++, y);    
                cout << a;              
                inputList.addTail(a);   
            }

            if (a == 0x1B) 
                exit(0);

        } while (a != 13); 

        
        string result;
        Node<char>* current = inputList.getHead();
        while (current != NULL) {
            result.push_back(current->_data); 
            current = current->_pNext;
        }

        return result;
    }
    string inputStringAuthor(int x, int y, int &iCount);
    string inputStringBookTitle(int x, int y, int &iCount);
    string inputStringBookCode(int x, int y, int &iCount);
    bool checkUser(string a, string b);
    void run();
    string toString();
    float inputRealNumber(int x, int y, int &iCount);
    void informationBook(int &n);
    void informationUser(int &n);
};

template <class DataType>
LinkedList<DataType>::LinkedList() : _pHead(NULL), _pTail(NULL), _iSize(0) {}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
    clear();
}

template <class DataType>
void LinkedList<DataType>::addChar(char c) {
    Node<DataType>* pAdd = new Node<DataType>(c);
    if (_pHead == NULL) {
        _pHead = _pTail = pAdd;
    } else {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::removeLastChar() {
    if (_pHead == NULL) return;  

    if (_pHead == _pTail) {
        delete _pTail;
        _pHead = _pTail = NULL;
    } else {
        Node<DataType>* temp = _pHead;
        while (temp->_pNext != _pTail) {
            temp = temp->_pNext;
        }
        delete _pTail;
        _pTail = temp;
        _pTail->_pNext = NULL;
    }
    --_iSize;
}

template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (_pHead == NULL) {
        _pHead = _pTail = pAdd;
    } else {
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::addTail(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (_pHead == NULL) {
        _pHead = _pTail = pAdd;
    } else {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::addAfter(DataType q, DataType data) {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        if (pWalker->_data == q) {
            Node<DataType>* pAdd = new Node<DataType>(data);
            pAdd->_pNext = pWalker->_pNext;
            pWalker->_pNext = pAdd;

            if (pWalker == _pTail) {
                _pTail = pAdd;
            }
            ++_iSize;
            return;
        }
        pWalker = pWalker->_pNext;
    }
    cout << "Element " << q << " not found!" << endl;
}

template <class DataType>
void LinkedList<DataType>::addUnique(DataType data) {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        if (pWalker->_data == data) {
            cout << "Element " << data << " already exists!" << endl;
            return;
        }
        pWalker = pWalker->_pNext;
    }
    addTail(data);
}

template <class DataType>
void LinkedList<DataType>::remove(DataType data) {
    if (_pHead == NULL) return;

    if (_pHead->_data == data) {
        Node<DataType>* temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
        --_iSize;
        return;
    }

    Node<DataType>* current = _pHead;
    while (current->_pNext != NULL && current->_pNext->_data != data) {
        current = current->_pNext;
    }

    if (current->_pNext != NULL) {
        Node<DataType>* temp = current->_pNext;
        current->_pNext = temp->_pNext;
        if (temp == _pTail) {
            _pTail = current;
        }
        delete temp;
        --_iSize;
    } else {
        cout << "Element " << data << " not found!" << endl;
    }
}

template <class DataType>
void LinkedList<DataType>::clear() {
    Node<DataType>* current = _pHead;
    while (current != NULL) {
        Node<DataType>* nextNode = current->_pNext;
        delete current;
        current = nextNode;
    }
    _pHead = _pTail = NULL;
    _iSize = 0;
}

template <class DataType>
bool LinkedList<DataType>::isEmpty() {
    return _iSize == 0;
}

template <class DataType>
int LinkedList<DataType>::getSize() {
	return _iSize;
}

template <class DataType>
void LinkedList<DataType>::removeTail() {
    
    if (_pHead == NULL) {
        cout << "Danh sách trống. Không thể xóa phần tử!" << endl;
        return;
    }
    if (_pHead == _pTail) {
        delete _pTail;   
        _pHead = _pTail = NULL;
    } else {
        Node<DataType>* temp = _pHead;
        while (temp->_pNext != _pTail) {
            temp = temp->_pNext;
        }
        delete _pTail;
        _pTail = temp;
        _pTail->_pNext = NULL;
    }
    _iSize--;
}

template <class DataType>
void LinkedList<DataType>::append(const DataType& value) {
    
    Node<DataType>* newNode = new Node<DataType>(value);  
    if (!_pHead) {
        _pHead = newNode;  
    } else {
        Node<DataType>* current = _pHead;
        while (current->_pNext) {  
            current = current->_pNext;
        }
        current->_pNext = newNode;  
    }
    ++_iSize;  
}



template <class DataType>
void LinkedList<DataType>::readFromFile(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    DataType data;
    while (file >> data) {
        addTail(data);
    }

    file.close();
}

template <class DataType>
void LinkedList<DataType>::writeToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        file << pWalker->_data << " ";
        pWalker = pWalker->_pNext;
    }

    file.close();
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType data) {
    Node<DataType>* current = _pHead;
    while (current != NULL) {
        if (current->_data == data) {
            return current;
        }
        current = current->_pNext;
    }
    return NULL; 
}

template <class DataType>
bool LinkedList<DataType>::exists(DataType data) {
    Node<DataType>* current = _pHead;
    while (current != NULL) {
        if (current->_data == data) {
            return true;
        }
        current = current->_pNext;
    }
    return false;
}


class  CBook {
	public:
		string strBookCode ;
		string strBookTitle;
		string strAuthor;
		string strPublisher;
		float fPrice;
		long lYear;
		long lpage;
		string strDate;
		long lBookStatus;
	public:
		void operator = (CBook  s)
		{
			strBookCode =s.strBookCode ;
			strBookTitle=s.strBookTitle;
			strAuthor=s.strAuthor;
			strPublisher=s.strPublisher;
			fPrice=s.fPrice;
			lYear=s.lYear;
			lpage=s.lpage;
			strDate=s.strDate;
			lBookStatus=s.lBookStatus;
		}
		~CBook (){}
		friend istream& operator >> (istream& is,CBook & s)
		{
			getline(is,s.strBookCode );
			getline(is,s.strBookTitle);
			getline(is,s.strAuthor);
			getline(is,s.strPublisher);
			is >> s.fPrice;
			is >> s.lYear;
			is >> s.lpage;
			is.ignore();
			getline(is,s.strDate);
			is >> s.lBookStatus;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,CBook  s)
		{
			os << s.strBookCode  << '\n' << s.strBookTitle << '\n' << s.strAuthor << '\n' << s.strPublisher << '\n' << s.fPrice << '\n' << s.lYear << '\n' << s.lpage << '\n' << s.strDate << '\n' << s.lBookStatus << '\n';
			return os;
		}
		bool operator ==(CBook  s)
		{
			return (strBookCode ==s.strBookCode );
		}
        bool operator !=(CBook s) {
            return !(operator ==(s));  
        }
};
class CTicket{
	public:
		long lNumberTicket;
		string strReaderCode;
		string strBookCode ;
		string strLoanDate;
		string strReturnDate;
		long lPaymentDate;
	public:
		void operator = (CTicket p)
		{
			lNumberTicket=p.lNumberTicket;
			strReaderCode=p.strReaderCode;
			strBookCode =p.strBookCode ;
			strLoanDate=p.strLoanDate;
			lPaymentDate=p.lPaymentDate;
		}
		~CTicket(){}
		friend istream& operator >> (istream& is,CTicket& p)
		{
			is >> p.lNumberTicket;
			is.ignore();
			getline(is,p.strReaderCode);
			getline(is,p.strBookCode );
			getline(is,p.strLoanDate);
			getline(is,p.strReturnDate);
			is >> p.lPaymentDate;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,CTicket p)
		{
			os << p.lNumberTicket << '\n' << p.strReaderCode << '\n' << p.strBookCode  << '\n' << p.strLoanDate << '\n' << p.strReturnDate << '\n' << p.lPaymentDate << '\n';
			return os;
		}
};
class CAdmin{
	string strUser ;
	string strPassWord;
	public:
		string getuser(){return strUser ;}
		string getstrPassWord(){return strPassWord;}
		bool operator == (CAdmin a)
		{
			if (strUser ==a.strUser  && strPassWord==a.strPassWord)
				return true;
			return false;
		}
		void operator = (CAdmin a)
		{
			strUser =a.strUser ;
			strPassWord=a.strPassWord;
		}
		CAdmin(string a, string b)
		{
			strUser = a;
			strPassWord = b;
		}
		~CAdmin(){}
		friend istream& operator >> (istream& is,CAdmin& ad)
		{
			setposition(101,20);is >> ad.strUser ;
			is >> ad.strPassWord;
			return is;
		}
		friend ostream& operator << (ostream& os,CAdmin ad)
		{
			os << ad.strUser  << '\n' << ad.strPassWord;
			return os;
		}
};
class CUser{
	public:
		string strUserCode;
		string strName;
		string strRegistrationDate;
	public:
		void operator = (CUser us)
		{
			strUserCode=us.strUserCode;
			strName=us.strName;
			strRegistrationDate=us.strRegistrationDate;
		}
		~CUser(){}
		friend istream& operator >> (istream& is,CUser& us)
		{
			getline(is,us.strUserCode);
			getline(is,us.strName);
			getline(is,us.strRegistrationDate);
			return is;
		}
};

LinkedList<CAdmin> Ad;
LinkedList<CBook> Sa;
LinkedList<CTicket> Ph;
LinkedList<CUser> Us;

template <class DataType>
void LinkedList<DataType>::saveDataBook() {
    outBook.open("Book.txt", ios_base::out);
    if (!outBook.is_open()) {
        cout << "Error: Cannot open Book.txt for writing!" << endl;
        return;
    }
    Node<CBook>* current = Sa.getHead();
    while (current != NULL) {
        outBook << current->_data; 
        current = current->_pNext; 
    }
    outBook.close();
}

template <class DataType>
void LinkedList<DataType>::saveDataTicket() {
    outTicket.open("Ticket.txt", ios_base::out);
    if (!outTicket.is_open()) {
        cout << "Error: Cannot open Ticket.txt for writing!" << endl;
        return;
    }
    Node<CTicket>* current = Ph.getHead();
    while (current != NULL) {
        outTicket << current->_data; 
        current = current->_pNext; 
    }
    outTicket.close();
}

void login()
{
	textcolor(14);
	setposition(64,16);cout << "* * * * * * * * * * * * * * * * *";
	setposition(64,17); cout << "*";
	textcolor(10);
	setposition(72,17);cout << "DANG NHAP HE THONG";
	textcolor(14);
	setposition(96,17); cout << "*";
	setposition(64,18);cout << "* * * * * * * * * * * * * * * * *";

}

int iCount = 1;
void DATA() {
    CAdmin A({"", ""}); 
    CUser U;
    CBook S;
    CTicket P({0, "", "", "", "", -1}); 

    
    inBook.open("Book.txt", ios_base::in);
    inAdmin.open("Admin.txt", ios_base::in);
    inTicket.open("Ticket.txt", ios_base::in);
    inUser.open("User.txt", ios_base::in);

    
    if (inAdmin.is_open()) {
        while (!inAdmin.eof()) {
            inAdmin >> A;
            if (A.getuser().empty() && A.getstrPassWord().empty()) 
                continue;
            Ad.addTail(A); 
        }
        inAdmin.close();
    }

    
    if (inBook.is_open()) {
        while (!inBook.eof()) {
            inBook >> S;
            if (S.strBookCode.empty()) 
                continue;
            Sa.addTail(S); 
        }
        inBook.close();
    }

    
    if (inTicket.is_open()) {
        while (!inTicket.eof()) {
            inTicket >> P;
            
            if (P.strReaderCode.empty() && P.strBookCode.empty() && P.strReturnDate.empty() && P.lPaymentDate == -1)
                continue;
            iCount++;
            Ph.addTail(P); 
        }
        inTicket.close();
    }

    
    if (inUser.is_open()) {
        while (!inUser.eof()) {
            inUser >> U;
            if (U.strUserCode.empty() && U.strName.empty() && U.strRegistrationDate.empty()) 
                continue;
            Us.addTail(U); 
        }
        inUser.close();
    }
}

template <class DataType>
string LinkedList<DataType>::inputPassword(int x, int y) {
    LinkedList<char> password; 
    char a;
    do {
        a = _getch(); 

        
        if (a == 8 && !password.isEmpty()) {
            password.removeTail(); 
            setposition(--x, y);
            cout << " ";  
            setposition(x, y);
            continue;
        }

        
        if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ') {
            setposition(x++, y);
            cout << "*";           
            password.addTail(a);   
        }

        
        if (a == 0x1B)
            exit(0);

    } while (a != 13); 

    
    string result;
    Node<char>* current = password.getHead();
    while (current != NULL) {
        result.push_back(current->_data); 
        current = current->_pNext;
    }
    return result;
}

template <class DataType>
string LinkedList<DataType>::inputStringAuthor(int x, int y, int& iCount) {
    LinkedList<char> inputList; 
    char a, b;
    int iNumber = 0; 

    do {
        a = _getch(); 

        
        if (a == 8 && !inputList.isEmpty()) {
            b = inputList.getTail()->_data; 
            if (((b >= 65 && b <= 90) || (b >= 97 && b <= 122) || b == ' ')) {
                goto hoi;
            } else {
                iNumber--;
            }

        hoi:
            inputList.removeTail(); 
            setposition(--x, y);    
            cout << " ";            
            setposition(x, y);      
            continue;
        }

        
        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || a == ' ') {
            inputList.addTail(a);   
            setposition(x++, y);    
            cout << a;              
            continue;
        }

        
        else {
            if (a != 13) {          
                if (a == 8)         
                    continue;

                iNumber++;          
                inputList.addTail(a); 
                setposition(x++, y);  
                cout << a;            
            }
        }

    } while (13 != a); 

    
    string result;
    Node<char>* current = inputList.getHead();
    while (current != NULL) {
        result.push_back(current->_data); 
        current = current->_pNext;
    }

    
    iCount += iNumber; 
    if (iNumber == 0)  
        return result;

    return ""; 
}

template <class DataType>
string LinkedList<DataType>::inputStringBookTitle(int x, int y, int& iCount) {
    LinkedList<char> inputList; 
    char a, b;
    int iNumber = 0; 

    do {
        a = _getch(); 

        
        if (inputList.getSize() > 100 && a != 8) 
            continue;

        
        if (a == 8 && !inputList.isEmpty()) {
            b = inputList.getTail()->_data; 
            if (((b >= 65 && b <= 90) || (b >= 97 && b <= 122) || (b >= '0' && b <= '9') || b == ' ' || b == '&' || b == '-'))
                goto hoi;
            else
                iNumber--;

            hoi:
            inputList.removeTail(); 
            setposition(--x, y);    
            cout << " ";            
            setposition(x, y);      
            continue;
        }

        
        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= '0' && a <= '9') || a == ' ' || a == '&' || a == '-') {
            inputList.addTail(a);   
            setposition(x++, y);    
            cout << a;              
            continue;
        }

        
        else {
            if (a != 13) {          
                if (a == 8)         
                    continue;

                iNumber++;          
                inputList.addTail(a); 
                setposition(x++, y);  
                cout << a;            
            }
        }

    } while (13 != a); 

    
    string result;
    Node<char>* current = inputList.getHead();
    while (current != NULL) {
        result.push_back(current->_data); 
        current = current->_pNext;
    }

    
    iCount += iNumber; 
    if (iNumber == 0)  
        return result;

    return ""; 
}

template <class DataType>
string LinkedList<DataType>::inputStringBookCode(int x, int y, int& iCount) {
    LinkedList<char> inputChars;  
    string result = "";
    char a;
    int iNumber = 0;

    do {
        a = _getch();  

        
        if (inputChars.getSize() > 100 && a != 8) {
            continue;
        }

        if (a == 8 && !inputChars.isEmpty()) {  
            inputChars.removeLastChar();  
            iNumber--;
            setposition(x - 1, y);
            cout << " ";  
            x--;
            setposition(x, y);
            continue;
        }

        if (a == ' ') {  
            iNumber++;
            setposition(x, y);
            cout << a;
            inputChars.addChar(a);  
            x++;
            continue;
        }

        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= '0' && a <= '9')) {  
            inputChars.addChar(a);
            setposition(x, y);
            cout << a;
            x++;
            continue;
        }

        if (a != 13) {  
            if (a == 8) continue;
            iNumber++;
            setposition(x, y);
            cout << a;
            inputChars.addChar(a);
            x++;
        }

    } while (a != 13);  

    
    Node<char>* current = inputChars.getHead();
    while (current != NULL) {
        result.push_back(current->_data);
        current = current->_pNext;
    }

    iCount += iNumber;
    if (iNumber == 0)
        return result;  
    return result;
}


template <class DataType>
DataType changeNumber(string tmp)
{
	stringstream ss(tmp);
	DataType k;
	ss >> k;
	return k;
}

template <class DataType>
long LinkedList<DataType>::inputInteger(int x, int y, int& iCount) {
    LinkedList<char> inputList; 
    char a, b;
    int iNumber = 0; 

    do {
        a = _getch(); 

        
        if (inputList.getSize() > 100 && a != 8) 
            continue;

        
        if (a == 8 && !inputList.isEmpty()) {
            b = inputList.getTail()->_data; 
            if (b >= '0' && b <= '9')   
                goto hoi;
            else
                iNumber--;   

            hoi:
            inputList.removeTail(); 
            setposition(--x, y);    
            cout << " ";            
            setposition(x, y);      
            continue;
        }

        
        if (a >= '0' && a <= '9') {
            inputList.addTail(a);   
            setposition(x++, y);    
            cout << a;              
            continue;
        }

        
        else {
            if (a != 13) {          
                if (a == 8)         
                    continue;

                setposition(x++, y);  
                cout << a;            
                inputList.addTail(a); 
                iNumber++;           
            }
        }

    } while (13 != a); 

    
    string result;
    Node<char>* current = inputList.getHead();
    while (current != NULL) {
        result.push_back(current->_data); 
        current = current->_pNext;
    }

    
    long number = changeNumber<long>(result);

    
    iCount += iNumber; 
    if (iNumber == 0 && result.size() <= 10) 
        return number;

    return -1; 
}


template <class DataType>
void LinkedList<DataType>::menuFunction(int n,int k)
{
	textcolor(14);
	setposition(102,k); cout << "<-";
	setposition(103,n); cout << " ";
	int null=0;
	while (true)
	{
		textcolor(11);
		
		gotocolor(105,k,"[BACK]",11);
		
		gotocolor(105,n,"[EXIT]",11);
		textcolor(14);
		system("pause>nul");
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (k!=n)
			{
				setposition(102,k); cout << "  ";
				k++;
				setposition(102,k); cout << "X";
				null++;	
			}
			continue;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (k!=n-1)
			{
				setposition(102,k); cout << "  ";
				k--;
				setposition(102,k); cout << "<-";
				null--;
			}
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			textcolor(7);
			if (null==0)
				return;
			if (null==1)
			{
				system("cls");
				exit(0);
			}
		}
	}
}

template <class DataType>
bool LinkedList<DataType>::checkUser(string a, string b) {
    Node<CAdmin>* current = Ad.getHead(); 
    
    
    while (current != NULL) {
        
        if (a == current->_data.getuser() && b == current->_data.getstrPassWord()) {
            return true;
        }
        current = current->_pNext; 
    }

    return false; 
}

void run()
{
	int iNumber=3;
	int iRun =0;
	while (iNumber!=0)
	{
		int iCount =0;
		string U_ser;
		string P_ass;
		login();
		setposition(60,19);
		if (iRun !=0)
		{
			textcolor(11);
			cout << "User hoac Password sai, Ban con ";
			textcolor(12);
			cout << iNumber;
			textcolor(11);
			cout << " luot nhap";
		}
		textcolor(2);
		setposition(66,21); cout << "User:";
		setposition(66,23); cout << "Password:";
		setposition(72,21); 
		textcolor(15);
        LinkedList<char> inputList;
		U_ser = inputList.input(72,21,iCount,inputList);
		setposition(76,23);
		P_ass = inputList.inputPassword(76,23);
		if (Ad.checkUser(U_ser,P_ass))
			return;
		iRun ++;
		iNumber--;
		system("cls");
	}
	exit(0);
}

template <class DataType>
string LinkedList<DataType>::toString() {
        string result = "";
        Node<DataType>* current = _pHead;
        while (current != NULL) {
            result += current->_data;
            current = current->_pNext;
        }
        return result;
    }

template <class DataType>
float LinkedList<DataType>::inputRealNumber(int x, int y, int& iCount) {
    LinkedList<char> inputList; 
    char a;
    char b;
    int iNumber = 0;
    bool dotEntered = false; 
    
    do {
        a = _getch(); 

        if (inputList.toString().size() > 100 && a != 8) 
            continue;
        
        if (a == 8 && !inputList.toString().empty()) { 
            b = inputList.toString().back();  
            if ((b >= 48 && b <= 57) || b == '.') {
                inputList.append(0);  
                setposition(x - 1, y); cout << char(32);
                x--;
                setposition(x, y);
                continue;
            } else {
                iNumber--;
            }
        }

        if ((a >= 48 && a <= 57) || a == '.') { 
            if (a == '.' && dotEntered) 
                continue;
            if (a == '.') dotEntered = true;
            inputList.append(a); 
            setposition(x, y); cout << a;
            x++;
            continue;
        }

        if (a != 13) { 
            if (a == 8)
                continue;
            inputList.append(a); 
            setposition(x, y); cout << a;
            x++;
            iNumber++;
        }
    } while (13 != a); 
    
    iCount += iNumber;

    
    string inputString = inputList.toString();
    if (iNumber == 0 && inputString.size() <= 10) {
        return changeNumber<float>(inputString); 
    } else {
        return -1; 
    }
}

void printBook(CBook tmp,int n)
{
	textcolor(15);
	setposition(5,n); cout << tmp.strBookCode ;
	setposition(16,n); cout << tmp.strBookTitle;
	setposition(42,n); cout << tmp.strAuthor;
	setposition(60,n); cout << tmp.strPublisher;
	setposition(76,n); cout << tmp.fPrice;
	setposition(89,n); cout << tmp.lYear;
	setposition(106,n); cout << tmp.lpage;
	setposition(120,n); cout << tmp.strDate;
	setposition(137,n); cout << tmp.lBookStatus;
	textcolor(7);
}

template <class DataType>
void LinkedList<DataType>::informationBook(int& n)
{
    textcolor(7);
    gotocolor(5, n, "MA SACH", 14);
    gotocolor(16, n, "TEN SACH", 14);
    gotocolor(42, n, "TAC GIA", 14);
    gotocolor(60, n, "NHA XUAT BAN", 14);
    gotocolor(76, n, "GIA BAN", 14);
    gotocolor(89, n, "NAM PHAT HANH", 14);
    gotocolor(106, n, "SO TRANG", 14);
    gotocolor(120, n, "NGAY NHAP KHO", 14);
    gotocolor(137, n, "TINH TRANG SACH", 14);
    textcolor(3);
    int iNumber = n;

    
    for (int i = 0; i <= Sa.getSize() + 1; i++) {
        if (i == 1) {
            iNumber++;
            continue;
        }
        write(4, iNumber, "|");
        write(15, iNumber, "|");
        write(41, iNumber, "|");
        write(59, iNumber, "|");
        write(75, iNumber, "|");
        write(88, iNumber, "|");
        write(105, iNumber, "|");
        write(119, iNumber, "|");
        write(136, iNumber, "|");
        write(155, iNumber, "|");
        iNumber++;
    }

    int iRun = n - 2;
    
    for (int i = 1; i <= 3; i++) {
        if (i == 3) {
            if (!Sa.isEmpty()) {
                for (int j = 4; j <= 154; j += 2) {
                    write(j, iRun + Sa.getSize() + 1, "--");
                }
            }
            break;
        }
        iRun += i;
        for (int j = 4; j <= 154; j += 2) {
            write(j, iRun, "--");
        }
    }

    n += 2;

    
    Node<CBook>* current = Sa.getHead();
    while (current != NULL) {
        printBook(current->_data, n++);
        current = current->_pNext;
    }

    n += 3;
}

void printUser(int n, CUser us)
{
    textcolor(15);
    setposition(5, n); cout << us.strUserCode;
    setposition(52, n); cout << us.strName;
    setposition(100, n); cout << us.strRegistrationDate;
    textcolor(7);
}

template <class DataType>
void LinkedList<DataType>::informationUser(int& n) {
    textcolor(15);
	gotocolor(5,n,"MA USER",14);
	gotocolor(52,n,"HO TEN",14);
	gotocolor(100,n,"NGAY DANG KY",14);
	textcolor(3);

    
    int iNumber = n;
    for (int i = 0; i <= Us.getSize() + 1; i++) {
        if (i == 1) {
            iNumber++;
            continue;
        }
        write(4, iNumber, "|");
        write(51, iNumber, "|");
        write(99, iNumber, "|");
        write(155, iNumber, "|");
        iNumber++;
    }

    int iRun = n - 2;
    for (int i = 1; i <= 3; i++) {
        if (i == 3) {
            if (!Us.isEmpty()) {
                for (int j = 4; j <= 154; j += 2)
                    write(j, iRun + Us.getSize() + 1, "--");
            }
            break;
        }
        iRun += i;
        for (int j = 4; j <= 154; j += 2)
            write(j, iRun, "--");
    }

    n += 2;

    
    Node<CUser>* pWalker = Us.getHead();
    while (pWalker != NULL) {
        printUser(n++, pWalker->_data);
        pWalker = pWalker->_pNext; 
    }

    n += 3;
}

template <class DataType>
void LinkedList<DataType>::display()
{
	int n = 10;
	system("cls");
	informationBook(n);
	menuFunction(n, n-1);
}

bool checkBook(CBook tmp)
{
    Node<CBook>* current = Sa.getHead();  
    while (current != NULL) {
        if (current->_data == tmp) {
            return true;  
        }
        current = current->_pNext;  
    }
    return false;  
}

template <class DataType>
bool bookEntryError(CBook tmp)
{
	if (tmp.fPrice==-1 || tmp.lYear==-1 || tmp.lpage==-1)
		return true;
	return false;
}

template <class DataType>
string LinkedList<DataType>::setstring(int x, int y, int& iCount) {
    
    LinkedList<char> inputList;
    
    
    string strRun = input(x, y, iCount);
    
    
    string result;
    Node<char>* current = inputList.getHead();
    
    
    while (current != NULL) {
        result.push_back(current->_data);
        current = current->_pNext;
    }

    return result;
}

template <class DataType>
void LinkedList<DataType>::addBook() 
{
    system("cls");
    CBook tmp({"","","","",-1,-1,-1});
    textcolor(15);
    
    setposition(5,7); cout << "MA SACH:";
    setposition(5,8); cout << "TEN SACH:";
    setposition(5,9); cout << "TAC GIA:";
    setposition(5,10); cout << "NHA XUAT BAN:";
    setposition(5,11); cout << "GIA BAN:";
    setposition(5,12); cout << "NAM PHAT HANH:";
    setposition(5,13); cout << "SO TRANG:";
    
    int n = 17;
    textcolor(11);
    setposition(70, n - 2); cout << "THONG TIN SACH";
    informationBook(n);
    textcolor(6);
    
    int iCount = 0;
    setposition(14,7); tmp.strBookCode = inputStringBookCode(14,7,iCount);
    setposition(15,8); tmp.strBookTitle = inputStringBookTitle(15,8,iCount);
    setposition(14,9); tmp.strAuthor = inputStringAuthor(14,9,iCount);
    setposition(19,10); tmp.strPublisher = inputStringAuthor(19,10,iCount);
    setposition(14,11); tmp.fPrice = inputRealNumber(14,11,iCount);
    setposition(20,12); tmp.lYear = inputInteger(20,12,iCount);
    setposition(15,13); tmp.lpage = inputInteger(15,13,iCount);
    
    tmp.lBookStatus = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = ltm->tm_mon + 1; 
    int year = ltm->tm_year + 1900; 
    tmp.strDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    
    textcolor(14);
    if (iCount != 0)
    {
        setposition(100,5);
        cout << "LOI NHAP SAI HE THONG!";
        goto hoi;
    }

    if (checkBook(tmp))
    {
        setposition(100,5);
        cout << "SACH DA TON TAI!";
    }
    else
    {
        setposition(100,5);
        cout << "THEM SACH THANH CONG!";
        
        
        Sa.addTail(tmp);  
        
        saveDataBook();
    }
    hoi:
    menuFunction(n, n-1);
}


template <class DataType>
void LinkedList<DataType>::checkBookCode(string s) 
{
    CBook k;
    textcolor(14);

    
    Node<CBook>* current = Sa.getHead();  

    while (current != NULL) {  
        k = current->_data;  

        if (k.strBookCode == s) {  
            if (k.lBookStatus == 0) {  
                Sa.remove(k);  
                setposition(100, 5);
                cout << "XOA SACH THANH CONG";
                saveDataBook();
                return;
            }
            setposition(100, 5);
            cout << "SACH DANG DUOC MUON";
            return;
        }
        current = current->_pNext;  
    }

    setposition(100, 5);
    cout << "SACH KHONG TON TAI";  
}

template <class DataType>
void LinkedList<DataType>::deleteBook()
{
	system("cls");
	string s;
	textcolor(14);
	setposition(5,7); cout << "NHAP MA SACH CAN XOA:";
	textcolor(11);
	int n=11;
	setposition(5,n-2); cout << "THONG TIN SACH";
	informationBook (n);
	textcolor(6);
	int iCount =0;
	setposition(27,7);s=inputStringBookCode(27,7,iCount );
	if (iCount !=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	checkBookCode(s);
	hoi:
	menuFunction(n,n-1);
}


template <class DataType>
void LinkedList<DataType>::bookManagement()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(64,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(64,16); cout << "->";
		setposition(64,17); cout << " ";
		setposition(64,18); cout << " ";
		setposition(64,19); cout << " ";
		while(true)
		{
			textcolor(15);
			setposition(68,16); cout << "HIEN THI THONG TIN SACH";
			setposition(68,17); cout << "THEM SACH";
			setposition(68,18); cout << "XOA SACH";
			setposition(68,19); cout << "[BACK]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(64,k); cout << "  ";
					k++;
					setposition(64,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(64,k); cout << "  ";
					k--;
					setposition(64,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				textcolor(7);
				if (null==0)
				{
					display();
					break;
				}
				if (null==1)
				{
					addBook();
					break;
				}
				if (null==2)
				{
					deleteBook();
					break;
				}
				if (null==3)
					return;
			}
		}
	}
}


void printTicket(CTicket ph,int n)
{
	setposition(5,n); cout << ph.lNumberTicket;
	setposition(29,n); cout << ph.strReaderCode;
	setposition(52,n); cout << ph.strBookCode ;
	setposition(71,n); cout << ph.strLoanDate;
	setposition(94,n); cout << ph.strReturnDate;
	setposition(120,n); cout << ph.lPaymentDate;
}

template <class DataType>
void LinkedList<DataType>::informationTicket(int& n) 
{
    textcolor(14);
    setposition(5, n); cout << "SO PHIEU MUON";
    setposition(29, n); cout << "MA BAN DOC";
    setposition(52, n); cout << "MA SACH";
    setposition(71, n); cout << "NGAY MUON";
    setposition(94, n); cout << "NGAY PHAI TRA";
    setposition(120, n); cout << "TINH TRANG PHIEU MUON";
    textcolor(9);

    int iNumber = n;
    for (int i = 0; i <= Ph.getSize() + 1; i++)
    {
        if (i == 1)
        {
            iNumber++;
            continue;
        }
        write(4, iNumber, "|");
        write(28, iNumber, "|");
        write(51, iNumber, "|");
        write(70, iNumber, "|");
        write(93, iNumber, "|");
        write(119, iNumber, "|");
        write(155, iNumber, "|");
        iNumber++;
    }

    int iRun = n - 2;
    for (int i = 1; i <= 3; i++)
    {
        if (i == 3)
        {
            if (!Ph.isEmpty())
                for (int j = 4; j <= 154; j += 2)
                    write(j, iRun + Ph.getSize() + 1, "--");
            break;
        }
        iRun += i;

        for (int j = 4; j <= 154; j += 2)
            write(j, iRun, "--");
    }
    n += 2;

    textcolor(15);
    
    
    Node<CTicket>* current = Ph.getHead();
    while (current != NULL)
    {
        printTicket(current->_data, n++);
        current = current->_pNext;
    }
    n += 3;
}

template <class DataType>
void LinkedList<DataType>::information ()
{
	system("cls");
	int n=10;
	informationTicket(n);
	menuFunction(n,n-1);
}

int iNumber = 0;
void checkbook(CBook pp,string a)
{
	if (pp.strBookCode == a)
	{
		if (pp.lBookStatus==0)
			iNumber =1;
		iNumber ++;
	}	
}

bool checkReader(CUser us,string a)
{
	if (us.strUserCode == a)
		return true;
	return false;
}

void trace(CBook &sa, string a) {
    CTicket tmp;
    Node<CUser>* currentUser = Us.getHead(); 
    
    while (currentUser != NULL) {
        CUser& user = currentUser->_data; 
        if (user.strUserCode == a) { 
            iNumber++;
            sa.lBookStatus = iCount;
            tmp.lNumberTicket = iCount;
            tmp.strReaderCode = a;
            tmp.strBookCode = sa.strBookCode;

            
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int day = ltm->tm_mday;
            int month = ltm->tm_mon + 1; 
            int year = ltm->tm_year + 1900;

            
            tmp.strLoanDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

            
            day += 7;
            if (month == 2) { 
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { 
                    if (day > 29) {
                        day -= 29;
                        month++;
                    }
                } else { 
                    if (day > 28) {
                        day -= 28;
                        month++;
                    }
                }
            } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { 
                if (day > 31) {
                    day -= 31;
                    month++;
                    if (month > 12) { 
                        month = 1;
                        year++;
                    }
                }
            } else { 
                if (day > 30) {
                    day -= 30;
                    month++;
                }
            }

            
            tmp.strReturnDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

            tmp.lPaymentDate = 1; 

            iCount++;
            Ph.addTail(tmp); 
            Sa.saveDataBook(); 
            Ph.saveDataTicket(); 
            return;
        }

        currentUser = currentUser->_pNext; 
    }
}

template <class DataType>
void LinkedList<DataType>::borrowBook()
{
    system("cls");
    textcolor(15);
    setposition(5, 5); cout << "MA SACH:";
    setposition(5, 6); cout << "MA BAN DOC:";
    textcolor(6);
    string book = "";
    string bn = "";
    int n = 10;
    textcolor(11);
    setposition(5, n - 2); cout << "THONG TIN SACH";
    informationBook(n);
    textcolor(11);
    n++;
    setposition(5, n - 2); cout << "THONG TIN PHIEU";
    informationTicket(n);
    textcolor(11);
    n++;
    setposition(5, n - 2); cout << "THONG TIN USER";
    informationUser(n);

    int iCount = 0;
    iNumber = 0;
    textcolor(6);
    setposition(14, 5); book = inputStringBookCode(14, 5, iCount);
    setposition(17, 6); bn = inputStringBookCode(17, 6, iCount);
    
    
    if (iCount != 0)
    {
        setposition(100, 5);
        cout << "LOI NHAP SAI HE THONG!";
        
        menuFunction(n, n - 1);
        return; 
    }

    
    Node<CBook>* currentBook = Sa.getHead();
    while (currentBook != NULL) {
        CBook& bookData = currentBook->_data;
        checkbook(bookData, book);

        if (iNumber == 2) {
            trace(bookData, bn);
            break;
        }

        if (iNumber == 1)
            break;

        iNumber = 0;
        currentBook = currentBook->_pNext; 
    }

    
    textcolor(14);
    if (iNumber == 0)
    {
        setposition(100, 5);
        cout << "SACH KHONG TON TAI";
    }
    else if (iNumber == 1)
    {
        setposition(100, 5);
        cout << "SACH DANG DUOC MUON";
    }
    else if (iNumber == 2)
    {
        setposition(100, 5);
        cout << "MA BAN DOC KHONG TON TAI";
    }
    else if (iNumber == 3)
    {
        setposition(100, 5);
        cout << "SACH MUON THANH CONG";
    }

    
    menuFunction(n, n - 1);
}


bool findBook(CBook & tmp,string a)
{
	if (tmp.strBookCode == a)
	{
		tmp.lBookStatus = 0;
		return true;
	}
	return false;
}

template <class DataType>
bool checkTicket(CTicket& tmp, int n) {
    iNumber = 0;

    
    Node<CTicket>* currentTicket = Ph.getHead();
    while (currentTicket != NULL) {
        
        if (currentTicket->_data.lNumberTicket == n) {
            tmp = currentTicket->_data;  
            iNumber = 1;

            
            if (tmp.lPaymentDate != 0) {
                tmp.lPaymentDate = 0;  
                currentTicket->_data = tmp;  

                
                Node<CBook>* currentBook = Sa.getHead();
                while (currentBook != NULL) {
                    if (currentBook->_data.strBookCode == tmp.strBookCode) {
                        currentBook->_data.lBookStatus = 0;  
                        break;  
                    }
                    currentBook = currentBook->_pNext;
                }

                
                Ph.saveDataTicket();
                Sa.saveDataBook();
                iNumber = 2;  
            }
            return true;  
        }
        currentTicket = currentTicket->_pNext;  
    }

    return false;  
}

template <class DataType>
void LinkedList<DataType>::returnBook() {
    system("cls");
    textcolor(15);
    setposition(5, 7);
    cout << "SO PHIEU MUON:";

    textcolor(6);
    string book = "";
    string bn = "";
    int n = 11;
    textcolor(11);
    setposition(5, n - 2);
    cout << "THONG TIN SACH";
    informationBook(n);
    textcolor(11);
    n++;
    setposition(5, n - 2);
    cout << "THONG TIN PHIEU";
    informationTicket(n);

    textcolor(6);
    long tmp;
    int iCount = 0;
    setposition(20, 7);
    tmp = inputInteger(20, 7, iCount);
    
    
    if (iCount != 0) {
        setposition(100, 5);
        cout << "LOI NHAP SAI HE THONG!";
        
        menuFunction(n, n - 1);
        return;  
    }

    
    Node<CTicket>* currentTicket = Ph.getHead();
    bool ticketFound = false;

    while (currentTicket != NULL) {
        if (currentTicket->_data.lNumberTicket == tmp) {
            ticketFound = true;
            CTicket ticket = currentTicket->_data;

            
            if (ticket.lPaymentDate != 0) {
                ticket.lPaymentDate = 0;
                currentTicket->_data = ticket; 

                
                Node<CBook>* currentBook = Sa.getHead();
                while (currentBook != NULL) {
                    if (currentBook->_data.strBookCode == ticket.strBookCode) {
                        currentBook->_data.lBookStatus = 0; 
                        break; 
                    }
                    currentBook = currentBook->_pNext;
                }

                
                Ph.saveDataTicket();
                Sa.saveDataBook();

                
                textcolor(14);
                setposition(100, 5);
                cout << "TRA SACH THANH CONG!";
            }
            else {
                
                textcolor(14);
                setposition(100, 5);
                cout << "KHONG THE TRA SACH!";
            }
            break;  
        }
        currentTicket = currentTicket->_pNext;  
    }

    if (!ticketFound) {
        
        textcolor(14);
        setposition(100, 5);
        cout << "PHIEU MUON KHONG TON TAI!";
    }

    
    menuFunction(n, n - 1);
}


template <class DataType>
void LinkedList<DataType>::manageTicket()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(64,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(64,16); cout << "->";
		setposition(64,17); cout << " ";
		setposition(64,18); cout << " ";
		setposition(64,19); cout << " ";
		while(true)
		{
			textcolor(15);
			setposition(68,16); cout << "THONG TIN PHIEU MUON";
			setposition(68,17); cout << "MUON SACH";
			setposition(68,18); cout << "TRA SACH";
			setposition(68,19); cout << "[BACK]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(64,k); cout << "  ";
					k++;
					setposition(64,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(64,k); cout << "  ";
					k--;
					setposition(64,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (null==0)
				{
					information ();
					break;
				}
				if (null==1)
				{
					borrowBook();
					break;
				}
				if (null==2)
				{
					returnBook();
					break;
				}
				if (null==3)
					return;
			}
		}
	}
}

bool menu()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(64,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(64,16); cout << "->";
		setposition(64,17); cout << " ";
		setposition(64,18); cout << " ";
		setposition(64,19); cout << " ";
		while (true)
		{
		
			textcolor(15);
			setposition(68,16); cout << "QUAN LY SACH";
			setposition(68,17); cout << "QUAN LY PHIEU MUON";
			setposition(68,18); cout << "[Dang Xuat]";
			setposition(68,19); cout << "[EXIT]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(64,k); cout << "  ";
					k++;
					setposition(64,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(64,k); cout << "  ";
					k--;
					setposition(64,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (null==0)
				{
                    LinkedList<CBook> b;
					b.bookManagement();
					break;
				}
				if (null==1)
				{
                    LinkedList<CTicket> t;
					t.manageTicket();
					break;
				}
				if (null==2)
					return false;
				if (null==3)
				{
					system("cls");
					exit(0);
				}
			}
		}
	}
	return true;
}

int main()
{
	DATA();
	for(;;)
	{
		run();
		system("cls");
		if (menu())
			return 0;
		system("cls");
	}
	return 0;
}
