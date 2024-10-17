#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <queue>
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
template< class T >
void setposition( T x, T y)
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
template < class T ,class N >
void gotocolor( T x,T  y, N s,T color )
{
	setposition(x,y);
	textcolor(color );
	cout << s;
	textcolor(7);
}
template< class T >
void textColor (T x,T y,T color )
{
	setposition(x,y);
	textcolor(color );
	textcolor(7);
}
template < class T ,class N >
void write( T x, T y, N z)
{
	setposition(x, y);
	cout << z;
}
template < class T ,class N >
class  CBook {
	public:
		N strBookCode ;
		N strBookTitle;
		N strAuthor;
		N strPublisher;
		T fPrice;
		T lYear;
		T lpage;
		N strDate;
		T lBookStatus;
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
};
template <class T , class N >
class CTicket{
	public:
		T lNumberTicket;
		N strReaderCode;
		N strBookCode ;
		N strLoanDate;
		N strPaymentDate;
		T lPaymentDate;
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
			getline(is,p.strPaymentDate);
			is >> p.lPaymentDate;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,CTicket p)
		{
			os << p.lNumberTicket << '\n' << p.strReaderCode << '\n' << p.strBookCode  << '\n' << p.strLoanDate << '\n' << p.strPaymentDate << '\n' << p.lPaymentDate << '\n';
			return os;
		}
};
template <class N >
class CAdmin{
	N strUser ;
	N strPassWord;
	public:
		N getuser(){return strUser ;}
		N getstrPassWord(){return strPassWord;}
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
		CAdmin( N a, N b)
		{
			strUser =a;
			strPassWord=b;
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
template <class N >
class CUser{
	public:
		N strUserCode;
		N strName;
		N strRegistrationDate;
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
vector<CAdmin> Ad;
list<CBook > Sa;
list<CTicket> Ph;
list<CUser> Us;
void saveDataBook()
{
	outBook.open("Book.txt",ios_base::out);
	for (auto it=Sa.begin();it!=Sa.end();it++)
		outBook << *it;
	outBook.close();
}
void saveDataTicket()
{
	outTicket.open("Ticket.txt",ios_base::out);
	for (auto it=Ph.begin();it!=Ph.end();it++)
		outTicket << *it;
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
int iCount =1;
void DATA()
{
	CAdmin A({"",""});
	CUser U;
	inBook.open("Book .txt",ios_base::in);
	inAdmin.open("Admin.txt",ios_base::in);
	CBook  S;
	inTicket.open("Ticket.txt",ios_base::in);
	inUser.open("User.txt",ios_base::in);
	while(!inAdmin.eof())
	{
		inAdmin >> A;
		Ad.push_back(A);
	}
	while(!inBook.eof())
	{
		inBook >> S;
		if (S.strBookCode =="")
			continue;
		Sa.push_back(S);
	}
	while(!inTicket.eof())
	{
		CTicket P({0,"","","","",-1});
		inTicket >> P;
		if (P.strReaderCode=="" && P.strBookCode =="" && P.strPaymentDate=="" && P.lPaymentDate==-1)
			continue;
		iCount ++;
		Ph.push_back(P);
	}
	while(!inUser.eof())
	{
		inUser >> U;
		Us.push_back(U);
	}
	inAdmin.close();
	inBook.close();
	inTicket.close();
	inUser.close();
}
string inputPassword(int x,int y)
{
	string tmp;
	char a;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (8==a && !tmp.empty())
		{
			tmp.resize(tmp.size()-1);
			setposition(x-1,y);cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ')
		{
			setposition(x,y);cout << "*";
			tmp.push_back(a);
			x++;
		}
		if (a==0x1B)
			exit(0);
		if ('\b'==a && !tmp.empty())
			tmp.resize(tmp.size()-1);
	}
	while (13!=a);
		return tmp;
}
string input(int x,int y,int& iCount )
{
	string tmp;
	char a;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ')
		{
			setposition(x,y);cout << a;
			tmp.push_back(a);
			x++;
		}
		if (a==0x1B)
			exit(0);
	}
	while (13!=a);
		return tmp;
}
string inputStringAuthor(int x,int y,int& iCount )
{
	string tmp="";
	char a;
	char b;
	int iNumber=0;
	do
	{
		a=_getch();
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if (((b>=65 && b<=90) || (b>=97 && b<=122) || b==' '))
				goto hoi;
			else
				iNumber--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || a==' ')
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		else
		{
			if (a!=13)
			{
				if (a==8)
					continue;
				iNumber++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		iCount +=iNumber;
		if (iNumber==0)
			return tmp;
		return "";
	}
}
string inputStringBookTitle(int x,int y,int& iCount )
{
	string tmp="";
	char a;
	char b;
	int iNumber =0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;	
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if (((b>=65 && b<=90) || (b>=97 && b<=122) || (b>='0' && b<='9') || b==' ' || b=='&' || b=='-'))
				goto hoi;
			else
				iNumber --;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || (a>='0' && a<='9') || a==' ' || a=='&' || a=='-')
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		else
		{
			if (a!=13)
			{
				if (a==8)
					continue;
				iNumber++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		iCount += iNumber;
		if (iNumber==0)
			return tmp;
		return "";
	}
}
string inputStringBookCode(int x,int y,int& iCount )
{
	string tmp="";
	char a;
	char b;
	int iNumber=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=65 && b<=90) || (b>=97 && b<=122) || (b>='0' && b<='9'))
				goto hoi;
			iNumber--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if (a==' ')
		{
			iNumber++;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || (a>='0' && a<='9'))
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			iNumber++;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
		}
	}
	while (13!=a);
	{
		iCount +=iNumber;
		if (iNumber==0)
			return tmp;
		return "";
	}
}
template <class T>
T changeNumber(string tmp)
{
	stringstream ss(tmp);
	T k;
	ss >> k;
	return k;
}
float inputRealNumber(int x,int y,int& iCount )
{
	string tmp="";
	char a;
	char b;
	int iNumber=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=48 && b<=57) || b == '.')
				goto hoi;
			else
				iNumber--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=48 && a<=57) || a == '.')
		{
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			iNumber++;
		}
	}
	while (13!=a);
	{
		iCount +=iNumber;
		if (iNumber==0 && tmp.size()<=10)
			return changeNumber<float>(tmp);
		else
			return -1;
	}
}
long inputInteger(int x,int y,int& iCount )
{
	string tmp="";
	char a,b;
	int iNumber=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=48 && b<=57))
				goto hoi;
			else
				iNumber--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=48 && a<=57))
		{
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			iNumber++;
		}
		
	}
	while (13!=a);
	{
		iCount +=iNumber;
		if (iNumber==0 && tmp.size()<=10)
			return changeNumber<long>(tmp);
		else
			return -1;
	}
}

void  function(int n,int k)
{
	textcolor(14);
	setposition(102,k); cout << "<-";
	setposition(103,n); cout << " ";
	int null=0;
	while (true)
	{
		textcolor(11);
		//setposition(105,k); cout << "[BACK]";
		gotocolor(105,k,"[BACK]",11);
		//setposition(105,n); cout << "[EXIT]";
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
bool checkuser(string a,string b)
{
	for (int i=0;i<Ad.size();i++)
		if (a==Ad[i].getuser() && b==Ad[i].getpassword())
			return true;
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
		U_ser=input(72,21,iCount );
		setposition(76,23);
		P_ass=inputPassword(76,23);
		if (checkuser(U_ser,P_ass))
			return;
		iRun ++;
		iNumber--;
		system("cls");
	}
	exit(0);
}
void publishingBook(CBook  tmp,int n)
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
} // nhứt lâm
void informationBook(int& n)
{
	textcolor(7);
	gotocolor(5,n,"MA SACH",14);
	gotocolor(16,n,"TEN SACH",14);
	gotocolor(42,n,"TAC GIA",14);
	gotocolor(60,n,"NHA XUAT BAN",14);
	gotocolor(76,n,"GIA BAN",14);
	gotocolor(89,n,"NAM PHAT HANH",14);
	gotocolor(106,n,"SO TRANG",14);
	gotocolor(120,n,"NGAY NHAP KHO",14);
	gotocolor(137,n,"TINH TRANG SACH",14);
	textcolor(3);
	int iNumber =n;
	for (int i=0;i<=Sa.size()+1;i++)
	{
		if (i==1)
		{
			inumber ++;
			continue;
		}
		write(4,iNumber ,"|");
		write(15,iNumber ,"|");
		write(41,iNumber ,"|");
		write(59,iNumber ,"|");
		write(75,iNumber ,"|");
		write(88,iNumber ,"|");
		write(105,iNumber ,"|");
		write(119,iNumber ,"|");
		write(136,iNumber ,"|");
		write(155,iNumber ,"|");
		iNumber ++;
	}
	int iRun =n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Sa.empty())
				for (int j=4;j<=154;j+=2)
					write(j,iRun +Sa.size()+1,"--");
			break;
		}	
		iRun +=i;
		for (int j=4;j<=154;j+=2)
			write(j,iRun ,"--");
	}
	n+=2;
	for (list<CBook >::iterator it=Sa.begin();it!=Sa.end();it++)
		publishingBook(*it,n++);
	n+=3;
}
void  publishingUser(int n,CUser us)
{
	textcolor(15);
	setposition(5,n); cout << us.strUserCode;
	setposition(52,n); cout << us.strName;
	setposition(100,n); cout << us.strRegistrationDate;
	textcolor(7);
}
void  informationUser (int& n)
{
	textcolor(15);
	gotocolor(5,n,"MA USER",14);
	gotocolor(52,n,"HO TEN",14);
	gotocolor(100,n,"NGAY DANG KY",14);
	textcolor(3);
	int  iNumber =n;
	for (int i=0;i<=Us.size()+1;i++)
	{
		if (i==1)
		{
			 iNumber ++;
			continue;
		}
		write(4, iNumber ,"|");
		write(51, iNumber ,"|");
		write(99, iNumber ,"|");
		write(155, iNumber ,"|");
		 iNumber ++;
	}
	int iRun =n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Us.empty())
				for (int j=4;j<=154;j+=2)
					write(j,iRun +Us.size()+1,"--");
			break;
		}	
		iRun +=i;
		for (int j=4;j<=154;j+=2)
			write(j,iRun ,"--");
	}
	n+=2;
	for (list<CUser>::iterator it=Us.begin();it!=Us.end();it++)
		 publishingUser(n++,*it);
	n+=3;
}
void  display()
{
	int n=10;
	system("cls");
	informationBook(n);
	 function(n,n-1);
}
bool  checkBook(CBook  tmp)
{
	for (list<CBook >::iterator i=Sa.begin();i!=Sa.end();i++)
		if (*i==tmp)
			return true;
	return false;
}
bool  bookEntryError(CBook  tmp)
{
	if (tmp.fPrice==-1 || tmp.lYear==-1 || tmp.lpage==-1)
		return true;
	return false;
}
string setstring(int x,int y,int& iCount )
{
	string strRun=input(x,y,iCount );
	return strRun;
}
void moreBook()
{
	system("cls");
	CBook  tmp({"","","","",-1,-1,-1});
	textcolor(15);
	setposition(5,7); cout << "MA SACH:";
	setposition(5,8); cout << "TEN SACH:";
	setposition(5,9); cout << "TAC GIA:";
	setposition(5,10); cout << "NHA XUAT BAN:";
	setposition(5,11); cout << "GIA BAN:";
	setposition(5,12); cout << "NAM PHAT HANH:";
	setposition(5,13); cout << "SO TRANG:";
	int n=17;
	textcolor(11);
	setposition(70,n-2); cout << "THONG TIN SACH";
	informationBook(n);
	textcolor(6);
	int iCount =0;
	setposition(14,7);tmp.strBookCode =inputStringBookCode(14,7,iCount );
	setposition(15,8);tmp.strBookTitle=inputStringBookTitle(15,8,iCount );
	setposition(14,9);tmp.strAuthor=inputStringAuthor(14,9,iCount );
	setposition(19,10);tmp.strPublisher=inputStringAuthor(19,10,iCount );
	setposition(14,11);tmp.fPrice=inputRealNumber(14,11,iCount );
	setposition(20,12);tmp.lYear=inputInteger(20,12,iCount );
	setposition(15,13);tmp.lpage=inputInteger(15,13,iCount );
	tmp.lBookStatus=0;
	time_t now = time(0);
	tm *ltm=localtime(&now);
	int day=ltm->tm_mday;
	int month=ltm->tm_mon;
	month++;
	int lYear=ltm->tm_year;
	lYear+=1900;
	tmp.strDate=to_string(day)+"/"+to_string(month)+"/"+to_string(lYear);
	textcolor(14);
	if (iCount !=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	if ( checkBook(tmp))
	{
		setposition(100,5);
		cout << "SACH DA TON TAI!";
	}
	else
	{
		setposition(100,5);
		cout << "THEM SACH THANH CONG!";
		Sa.push_back(tmp);
		saveDataBook();
	}
	hoi:
	 function(n,n-1);
}
void checkBookCode(string s)
{
	CBook  k;
	textcolor(14);
	for (auto i=Sa.begin();i!=Sa.end();i++)
	{
		k=*i;
		if (k.strBookCode ==s)
		{
			if (k.lBookStatus==0)
			{
				Sa.erase(i);
				setposition(100,5); cout << "XOA SACH THANH CONG";
				saveDataBook();
				return;
			}
			setposition(100,5); cout << "SACH DANG DUOC MUON";
			return;	
		}
	}	
	setposition(100,5); cout << "SACH KHONG TON TAI";
}
void deleteBook()
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
	 function(n,n-1);
}
void bookManagement()
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
					moreBook();
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

void publishingTicket(CTicket ph,int n)
{
	setposition(5,n); cout << ph.lNumberTicket;
	setposition(29,n); cout << ph.strReaderCode;
	setposition(52,n); cout << ph.strBookCode ;
	setposition(71,n); cout << ph.strLoanDate;
	setposition(94,n); cout << ph.strPaymentDate;
	setposition(120,n); cout << ph.lPaymentDate;
}
void informationTicket(int& n)
{
	textcolor(14);
	setposition(5,n); cout << "SO PHIEU MUON";
	setposition(29,n); cout << "MA BAN DOC";
	setposition(52,n); cout << "MA SACH";
	setposition(71,n); cout << "NGAY MUON";
	setposition(94,n); cout << "NGAY PHAI TRA";
	setposition(120,n); cout << "TINH TRANG PHIEU MUON";
	textcolor(9);
	int iNumber =n;
	for (int i=0;i<=Ph.size()+1;i++)
	{
		if (i==1)
		{
			iNumber ++;
			continue;
		}
		write(4,iNumber ,"|");
		write(28,iNumber ,"|");
		write(51,iNumber ,"|");
		write(70,iNumber ,"|");
		write(93,iNumber ,"|");
		write(119,iNumber ,"|");
		write(155,iNumber ,"|");
		iNumber ++;
	}
	int iRun=n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Ph.empty())
				for (int j=4;j<=154;j+=2)
					write(j,iRun+Ph.size()+1,"--");
			break;
		}
		iRun+=i;
			
		for (int j=4;j<=154;j+=2)
			write(j,iRun,"--");
	}
	n+=2;
	textcolor(15);
	for (list<CTicket>::iterator i=Ph.begin();i!=Ph.end();i++)
		publishingTicket(*i,n++);
	n+=3;
}
void information ()
{
	system("cls");
	int n=10;
	informationTicket(n);
	 function(n,n-1);
}
int iNumber =0;
void checkbook(CBook  pp,string a)
{
	if (pp.strBookCode ==a)
	{
		if (pp.lBookStatus==0)
			iNumber =1;
		iNumber ++;
	}	
}
bool checkReader(CUser us,string a)
{
	if (us.strUserCode==a)
		return true;
	return false;
}
void trace(CBook & sa,string a)
{
	CTicket tmp;
	for (list<CUser>::iterator i=Us.begin();i!=Us.end();i++)
	{
		if (checkReader(*i,a))
		{
			iNumber ++;
			sa.lBookStatus=iCount ;
			tmp.lNumberTicket=iCount ;
			tmp.strReaderCode=a;
			tmp.strBookCode =sa.strBookCode ;
			time_t now = time(0);
			tm *ltm=localtime(&now);
			int day=ltm->tm_mday;
			int month=ltm->tm_mon;
			month++;
			int lYear=ltm->tm_year;
			lYear+=1900;
			tmp.strLoanDate=to_string(day)+"/"+to_string(month)+"/"+to_string(lYear);
			if (month==2)
			{
				if (lYear%4==0 && lYear%400==0)
				{
					day+=7;
					if (day>29)
					{
						day-=29;
						month++;
					}
				}
				else
				{
					day+=7;
					if (day>28)
					{
						day-=28;
						month++;
					}
				}
			}
			else
			{
				if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
				{
					day+=7;
					if (day>31)
					{
						day-=31;
						month++;
						if (month>12)
						{
							lYear++;
							month-=12;
						}
						else
							month++;
					}
				}
				else
				{
					day+=7;
					if (day>30)
					{
						day-=30;
						month++;
					}
				}
			}
			tmp.strPaymentDate=to_string(day)+"/"+to_string(month)+"/"+to_string(lYear);
			tmp.lPaymentDate=1;
			iCount ++;
			Ph.push_back(tmp);
			saveDataTicket();
			saveDataBook();
			return;
		}
	}
}
void borrowBook()
{
	system("cls");
	textcolor(15);
	setposition(5,5); cout << "MA SACH:";
	setposition(5,6); cout << "MA BAN DOC:";
	textcolor(6);
	string book="";
	string bn="";
	int n=10;
	textcolor(11);
	setposition(5,n-2);cout << "THONG TIN SACH";
	informationBook(n);
	textcolor(11);
	n++;
 	setposition(5,n-2);cout << "THONG TIN PHIEU";
	informationTicket(n);
	textcolor(11);
	n++;
	setposition(5,n-2);cout << "THONG TIN USER";
	 informationUser (n);
	int iCount =0;
	iNumber =0;
	textcolor(6);
	setposition(14,5);book=inputStringBookCode(14,5,iCount );
	setposition(17,6);bn=inputStringBookCode(17,6,iCount );
	if (iCount !=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<CBook >::iterator i=Sa.begin();i!=Sa.end();i++)
	{
		checkbook(*i,book);
		if (iNumber ==2)
		{
			trace(*i,bn);
			break;
		}
		if (iNumber ==1)
			break;
		iNumber =0;
	}
	textcolor(14);
	if (iNumber ==0)
	{
		setposition(100,5);
		cout << "SACH KHONG TON TAI";
	}
	if (iNumber ==1)
	{
		setposition(100,5);
		cout << "SACH DANG DUOC MUON";
	}
	if (iNumber ==2)
	{
		setposition(100,5);
		cout << "MA BAN DOC KHONG TON TAI";
	}
	if (iNumber ==3)
	{
		setposition(100,5);
		cout << "SACH MUON THANH CONG";
	}
	hoi:
	 function(n,n-1);
}
bool findBook(CBook & tmp,string a)
{
	if (tmp.strBookCode ==a)
	{
		tmp.lBookStatus=0;
		return true;
	}
	return false;
}
bool checkTitket(CTicket& tmp,int n)
{
	iNumber =0;
	if (n==tmp.lNumberTicket)
	{
		iNumber =1;
		if (tmp.lPaymentDate!=0)
		{
			tmp.lPaymentDate=0;
			for (auto i=Sa.begin();i!=Sa.end();i++)
				if (findBook(*i,tmp.strBookCode ))
				{
					saveDataTicket();
					saveDataBook();
					break;
				}
			iNumber =2;
		}
		return true;	
	}
	return false;
}
void returnBook()
{
	system("cls");
	textcolor(15);
	setposition(5,7); cout << "SO PHIEU MUON:";
	textcolor(6);
	string book="";
	string bn="";
	int n=11;
	textcolor(11);
	setposition(5,n-2);cout << "THONG TIN SACH";
	informationBook(n);
	textcolor(11);
	n++;
 	setposition(5,n-2);cout << "THONG TIN PHIEU";
	informationTicket(n);
	textcolor(6);
	long tmp;
	int iCount =0;
	setposition(20,7);tmp=inputInteger(20,7,iCount );
	if (iCount !=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<CTicket>::iterator i=Ph.begin();i!=Ph.end();i++)
		if (checkTitket(*i,tmp))
			break;
	textcolor(14);
	if (iNumber ==0)
	{
		setposition(100,5);
		cout << "PHIEU MUON KHONG TON TAI!";
	}
	if (iNumber ==1)
	{
		setposition(100,5);
		cout << "KHONG THE TRA SACH!";
	}
	if (iNumber ==2)
	{
		setposition(100,5);
		cout << "TRA SACH THANH CONG!";
	}
	textcolor(14);
	hoi:
	 function(n,n-1);
}
void manageTicket()
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
		//	setposition(90,16); cout << ;
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
					bookManagement();
					break;
				}
				if (null==1)
				{
					manageTicket();
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