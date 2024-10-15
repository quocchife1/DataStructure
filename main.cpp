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
ifstream inadmin;
ifstream insach;
ifstream inphieu;
ifstream inuser;
ofstream outadmin;
ofstream outsach;
ofstream outphieu;
ofstream outuser;
void setposition(int x, int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void textolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotocolor(int x,int y,string s,int mau)
{
	setposition(x,y);
	textcolor(mau);
	cout << s;
	textcolor(7);
}
void textmau(int x,int y,int mau)
{
	setposition(x,y);
	textcolor(mau);
	textcolor(7);
}
void write(int x, int y, string z)
{
	setposition(x, y);
	cout << z;
}
class Sach{
	public:
		string masach;
		string tensach;
		string tacgia;
		string nhaxuatban;
		float giaban;
		long nam;
		long sotrang;
		string ngaynhap;
		long tinhtrangsach;
	public:
		void operator = (Sach s)
		{
			masach=s.masach;
			tensach=s.tensach;
			tacgia=s.tacgia;
			nhaxuatban=s.nhaxuatban;
			giaban=s.giaban;
			nam=s.nam;
			sotrang=s.sotrang;
			ngaynhap=s.ngaynhap;
			tinhtrangsach=s.tinhtrangsach;
		}
		~Sach(){}
		friend istream& operator >> (istream& is,Sach& s)
		{
			getline(is,s.masach);
			getline(is,s.tensach);
			getline(is,s.tacgia);
			getline(is,s.nhaxuatban);
			is >> s.giaban;
			is >> s.nam;
			is >> s.sotrang;
			is.ignore();
			getline(is,s.ngaynhap);
			is >> s.tinhtrangsach;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,Sach s)
		{
			os << s.masach << '\n' << s.tensach << '\n' << s.tacgia << '\n' << s.nhaxuatban << '\n' << s.giaban << '\n' << s.nam << '\n' << s.sotrang << '\n' << s.ngaynhap << '\n' << s.tinhtrangsach << '\n';
			return os;
		}
		bool operator ==(Sach s)
		{
			return (masach==s.masach);
		}
};
class Phieu{
	public:
		long sophieu;
		string mabandoc;
		string masach;
		string ngaymuon;
		string ngaytra;
		long tinhtrang;
	public:
		void operator = (Phieu p)
		{
			sophieu=p.sophieu;
			mabandoc=p.mabandoc;
			masach=p.masach;
			ngaymuon=p.ngaymuon;
			tinhtrang=p.tinhtrang;
		}
		~Phieu(){}
		friend istream& operator >> (istream& is,Phieu& p)
		{
			is >> p.sophieu;
			is.ignore();
			getline(is,p.mabandoc);
			getline(is,p.masach);
			getline(is,p.ngaymuon);
			getline(is,p.ngaytra);
			is >> p.tinhtrang;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,Phieu p)
		{
			os << p.sophieu << '\n' << p.mabandoc << '\n' << p.masach << '\n' << p.ngaymuon << '\n' << p.ngaytra << '\n' << p.tinhtrang << '\n';
			return os;
		}
};
class Admin{
	string user;
	string password;
	public:
		string getuser(){return user;}
		string getpassword(){return password;}
		bool operator == (Admin a)
		{
			if (user==a.user && password==a.password)
				return true;
			return false;
		}
		void operator = (Admin a)
		{
			user=a.user;
			password=a.password;
		}
		Admin(string a,string b)
		{
			user=a;
			password=b;
		}
		~Admin(){}
		friend istream& operator >> (istream& is,Admin& ad)
		{
			setposition(101,20);is >> ad.user;
			is >> ad.password;
			return is;
		}
		friend ostream& operator << (ostream& os,Admin ad)
		{
			os << ad.user << '\n' << ad.password;
			return os;
		}
};
class User{
	public:
		string ma;
		string hoten;
		string ngaydangky;
	public:
		void operator = (User us)
		{
			ma=us.ma;
			hoten=us.hoten;
			ngaydangky=us.ngaydangky;
		}
		~User(){}
		friend istream& operator >> (istream& is,User& us)
		{
			getline(is,us.ma);
			getline(is,us.hoten);
			getline(is,us.ngaydangky);
			return is;
		}
};
vector<Admin> Ad;
list<Sach> Sa;
list<Phieu> Ph;
list<User> Us;
void savedatasach()
{
	outsach.open("Sach.txt",ios_base::out);
	for (auto it=Sa.begin();it!=Sa.end();it++)
		outsach << *it;
	outsach.close();
}
void savedataphieu()
{
	outphieu.open("PhieuMuon.txt",ios_base::out);
	for (auto it=Ph.begin();it!=Ph.end();it++)
		outphieu << *it;
	outphieu.close();
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
int ddem=1;
void DATA()
{
	Admin A({"",""});
	User U;
	insach.open("Sach.txt",ios_base::in);
	inadmin.open("Admin.txt",ios_base::in);
	Sach S;
	inphieu.open("PhieuMuon.txt",ios_base::in);
	inuser.open("User.txt",ios_base::in);
	while(!inadmin.eof())
	{
		inadmin >> A;
		Ad.push_back(A);
	}
	while(!insach.eof())
	{
		insach >> S;
		if (S.masach=="")
			continue;
		Sa.push_back(S);
	}
	while(!inphieu.eof())
	{
		Phieu P({0,"","","","",-1});
		inphieu >> P;
		if (P.mabandoc=="" && P.masach=="" && P.ngaytra=="" && P.tinhtrang==-1)
			continue;
		ddem++;
		Ph.push_back(P);
	}
	while(!inuser.eof())
	{
		inuser >> U;
		Us.push_back(U);
	}
	inadmin.close();
	insach.close();
	inphieu.close();
	inuser.close();
}
string input_password(int x,int y)
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
string input(int x,int y,int& dem)
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
string inputstringtacgia(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
	do
	{
		a=_getch();
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if (((b>=65 && b<=90) || (b>=97 && b<=122) || b==' '))
				goto hoi;
			else
				so--;
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
				so++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
string inputstringtensach(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
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
				so--;
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
				so++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
string inputstringmasach(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
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
			so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if (a==' ')
		{
			so++;
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
			so++;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
template <class T>
T chuyenso(string tmp)
{
	stringstream ss(tmp);
	T k;
	ss >> k;
	return k;
}
float inputsothuc(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
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
				so--;
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
			so++;
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0 && tmp.size()<=10)
			return chuyenso<float>(tmp);
		else
			return -1;
	}
}
long inputsonguyen(int x,int y,int& dem)
{
	string tmp="";
	char a,b;
	int so=0;
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
				so--;
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
			so++;
		}
		
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0 && tmp.size()<=10)
			return chuyenso<long>(tmp);
		else
			return -1;
	}
}

void ham(int n,int k)
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
	int so=3;
	int chay=0;
	while (so!=0)
	{
		int dem=0;
		string U_ser;
		string P_ass;
		login();
		setposition(60,19);
		if (chay!=0)
		{
			textcolor(11);
			cout << "User hoac Password sai, Ban con ";
			textcolor(12);
			cout << so;
			textcolor(11);
			cout << " luot nhap";
		}
		textcolor(2);
		setposition(66,21); cout << "User:";
		setposition(66,23); cout << "Password:";
		setposition(72,21); 
		textcolor(15);
		U_ser=input(72,21,dem);
		setposition(76,23);
		P_ass=input_password(76,23);
		if (checkuser(U_ser,P_ass))
			return;
		chay++;
		so--;
		system("cls");
	}
	exit(0);
}
void xuatsach(Sach tmp,int n)
{
	textcolor(15);
	setposition(5,n); cout << tmp.masach;
	setposition(16,n); cout << tmp.tensach;
	setposition(42,n); cout << tmp.tacgia;
	setposition(60,n); cout << tmp.nhaxuatban;
	setposition(76,n); cout << tmp.giaban;
	setposition(89,n); cout << tmp.nam;
	setposition(106,n); cout << tmp.sotrang;
	setposition(120,n); cout << tmp.ngaynhap;
	setposition(137,n); cout << tmp.tinhtrangsach;
	textcolor(7);
}
void inforsach(int& n)
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
	int so=n;
	for (int i=0;i<=Sa.size()+1;i++)
	{
		if (i==1)
		{
			so++;
			continue;
		}
		write(4,so,"|");
		write(15,so,"|");
		write(41,so,"|");
		write(59,so,"|");
		write(75,so,"|");
		write(88,so,"|");
		write(105,so,"|");
		write(119,so,"|");
		write(136,so,"|");
		write(155,so,"|");
		so++;
	}
	int chay=n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Sa.empty())
				for (int j=4;j<=154;j+=2)
					write(j,chay+Sa.size()+1,"--");
			break;
		}	
		chay+=i;
		for (int j=4;j<=154;j+=2)
			write(j,chay,"--");
	}
	n+=2;
	for (list<Sach>::iterator it=Sa.begin();it!=Sa.end();it++)
		xuatsach(*it,n++);
	n+=3;
}
void xuatuser(int n,User us)
{
	textcolor(15);
	setposition(5,n); cout << us.ma;
	setposition(52,n); cout << us.hoten;
	setposition(100,n); cout << us.ngaydangky;
	textcolor(7);
}
void inforuser(int& n)
{
	textcolor(15);
	gotocolor(5,n,"MA USER",14);
	gotocolor(52,n,"HO TEN",14);
	gotocolor(100,n,"NGAY DANG KY",14);
	textcolor(3);
	int so=n;
	for (int i=0;i<=Us.size()+1;i++)
	{
		if (i==1)
		{
			so++;
			continue;
		}
		write(4,so,"|");
		write(51,so,"|");
		write(99,so,"|");
		write(155,so,"|");
		so++;
	}
	int chay=n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Us.empty())
				for (int j=4;j<=154;j+=2)
					write(j,chay+Us.size()+1,"--");
			break;
		}	
		chay+=i;
		for (int j=4;j<=154;j+=2)
			write(j,chay,"--");
	}
	n+=2;
	for (list<User>::iterator it=Us.begin();it!=Us.end();it++)
		xuatuser(n++,*it);
	n+=3;
}
void hienthi()
{
	int n=10;
	system("cls");
	inforsach(n);
	ham(n,n-1);
}
bool checksach(Sach tmp)
{
	for (list<Sach>::iterator i=Sa.begin();i!=Sa.end();i++)
		if (*i==tmp)
			return true;
	return false;
}
bool loinhapsach(Sach tmp)
{
	if (tmp.giaban==-1 || tmp.nam==-1 || tmp.sotrang==-1)
		return true;
	return false;
}
string setstring(int x,int y,int& dem)
{
	string chay=input(x,y,dem);
	return chay;
}
void themsach()
{
	system("cls");
	Sach tmp({"","","","",-1,-1,-1});
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
	inforsach(n);
	textcolor(6);
	int dem=0;
	setposition(14,7);tmp.masach=inputstringmasach(14,7,dem);
	setposition(15,8);tmp.tensach=inputstringtensach(15,8,dem);
	setposition(14,9);tmp.tacgia=inputstringtacgia(14,9,dem);
	setposition(19,10);tmp.nhaxuatban=inputstringtacgia(19,10,dem);
	setposition(14,11);tmp.giaban=inputsothuc(14,11,dem);
	setposition(20,12);tmp.nam=inputsonguyen(20,12,dem);
	setposition(15,13);tmp.sotrang=inputsonguyen(15,13,dem);
	tmp.tinhtrangsach=0;
	time_t now = time(0);
	tm *ltm=localtime(&now);
	int day=ltm->tm_mday;
	int month=ltm->tm_mon;
	month++;
	int nam=ltm->tm_year;
	nam+=1900;
	tmp.ngaynhap=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
	textcolor(14);
	if (dem!=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	if (checksach(tmp))
	{
		setposition(100,5);
		cout << "SACH DA TON TAI!";
	}
	else
	{
		setposition(100,5);
		cout << "THEM SACH THANH CONG!";
		Sa.push_back(tmp);
		savedatasach();
	}
	hoi:
	ham(n,n-1);
}
void kiemtramasach(string s)
{
	Sach k;
	textcolor(14);
	for (auto i=Sa.begin();i!=Sa.end();i++)
	{
		k=*i;
		if (k.masach==s)
		{
			if (k.tinhtrangsach==0)
			{
				Sa.erase(i);
				setposition(100,5); cout << "XOA SACH THANH CONG";
				savedatasach();
				return;
			}
			setposition(100,5); cout << "SACH DANG DUOC MUON";
			return;	
		}
	}	
	setposition(100,5); cout << "SACH KHONG TON TAI";
}
void xoasach()
{
	system("cls");
	string s;
	textcolor(14);
	setposition(5,7); cout << "NHAP MA SACH CAN XOA:";
	textcolor(11);
	int n=11;
	setposition(5,n-2); cout << "THONG TIN SACH";
	inforsach(n);
	textcolor(6);
	int dem=0;
	setposition(27,7);s=inputstringmasach(27,7,dem);
	if (dem!=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	kiemtramasach(s);
	hoi:
	ham(n,n-1);
}
void quanlysach()
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
					hienthi();
					break;
				}
				if (null==1)
				{
					themsach();
					break;
				}
				if (null==2)
				{
					xoasach();
					break;
				}
				if (null==3)
					return;
			}
		}
	}
}

void xuatphieu(Phieu ph,int n)
{
	setposition(5,n); cout << ph.sophieu;
	setposition(29,n); cout << ph.mabandoc;
	setposition(52,n); cout << ph.masach;
	setposition(71,n); cout << ph.ngaymuon;
	setposition(94,n); cout << ph.ngaytra;
	setposition(120,n); cout << ph.tinhtrang;
}
void inforphieu(int& n)
{
	textcolor(14);
	setposition(5,n); cout << "SO PHIEU MUON";
	setposition(29,n); cout << "MA BAN DOC";
	setposition(52,n); cout << "MA SACH";
	setposition(71,n); cout << "NGAY MUON";
	setposition(94,n); cout << "NGAY PHAI TRA";
	setposition(120,n); cout << "TINH TRANG PHIEU MUON";
	textcolor(9);
	int so=n;
	for (int i=0;i<=Ph.size()+1;i++)
	{
		if (i==1)
		{
			so++;
			continue;
		}
		write(4,so,"|");
		write(28,so,"|");
		write(51,so,"|");
		write(70,so,"|");
		write(93,so,"|");
		write(119,so,"|");
		write(155,so,"|");
		so++;
	}
	int chay=n-2;
	for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Ph.empty())
				for (int j=4;j<=154;j+=2)
					write(j,chay+Ph.size()+1,"--");
			break;
		}
		chay+=i;
			
		for (int j=4;j<=154;j+=2)
			write(j,chay,"--");
	}
	n+=2;
	textcolor(15);
	for (list<Phieu>::iterator i=Ph.begin();i!=Ph.end();i++)
		xuatphieu(*i,n++);
	n+=3;
}
void thongtin()
{
	system("cls");
	int n=10;
	inforphieu(n);
	ham(n,n-1);
}
int so=0;
void checkbook(Sach pp,string a)
{
	if (pp.masach==a)
	{
		if (pp.tinhtrangsach==0)
			so=1;
		so++;
	}	
}
bool checkbandoc(User us,string a)
{
	if (us.ma==a)
		return true;
	return false;
}
void truyvet(Sach& sa,string a)
{
	Phieu tmp;
	for (list<User>::iterator i=Us.begin();i!=Us.end();i++)
	{
		if (checkbandoc(*i,a))
		{
			so++;
			sa.tinhtrangsach=ddem;
			tmp.sophieu=ddem;
			tmp.mabandoc=a;
			tmp.masach=sa.masach;
			time_t now = time(0);
			tm *ltm=localtime(&now);
			int day=ltm->tm_mday;
			int month=ltm->tm_mon;
			month++;
			int nam=ltm->tm_year;
			nam+=1900;
			tmp.ngaymuon=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
			if (month==2)
			{
				if (nam%4==0 && nam%400==0)
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
							nam++;
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
			tmp.ngaytra=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
			tmp.tinhtrang=1;
			ddem++;
			Ph.push_back(tmp);
			savedataphieu();
			savedatasach();
			return;
		}
	}
}
void muonsach()
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
	inforsach(n);
	textcolor(11);
	n++;
 	setposition(5,n-2);cout << "THONG TIN PHIEU";
	inforphieu(n);
	textcolor(11);
	n++;
	setposition(5,n-2);cout << "THONG TIN USER";
	inforuser(n);
	int dem=0;
	so=0;
	textcolor(6);
	setposition(14,5);book=inputstringmasach(14,5,dem);
	setposition(17,6);bn=inputstringmasach(17,6,dem);
	if (dem!=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<Sach>::iterator i=Sa.begin();i!=Sa.end();i++)
	{
		checkbook(*i,book);
		if (so==2)
		{
			truyvet(*i,bn);
			break;
		}
		if (so==1)
			break;
		so=0;
	}
	textcolor(14);
	if (so==0)
	{
		setposition(100,5);
		cout << "SACH KHONG TON TAI";
	}
	if (so==1)
	{
		setposition(100,5);
		cout << "SACH DANG DUOC MUON";
	}
	if (so==2)
	{
		setposition(100,5);
		cout << "MA BAN DOC KHONG TON TAI";
	}
	if (so==3)
	{
		setposition(100,5);
		cout << "SACH MUON THANH CONG";
	}
	hoi:
	ham(n,n-1);
}
bool timsach(Sach& tmp,string a)
{
	if (tmp.masach==a)
	{
		tmp.tinhtrangsach=0;
		return true;
	}
	return false;
}
bool checkphieumuon(Phieu& tmp,int n)
{
	so=0;
	if (n==tmp.sophieu)
	{
		so=1;
		if (tmp.tinhtrang!=0)
		{
			tmp.tinhtrang=0;
			for (auto i=Sa.begin();i!=Sa.end();i++)
				if (timsach(*i,tmp.masach))
				{
					savedataphieu();
					savedatasach();
					break;
				}
			so=2;
		}
		return true;	
	}
	return false;
}
void trasach()
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
	inforsach(n);
	textcolor(11);
	n++;
 	setposition(5,n-2);cout << "THONG TIN PHIEU";
	inforphieu(n);
	textcolor(6);
	long tmp;
	int dem=0;
	setposition(20,7);tmp=inputsonguyen(20,7,dem);
	if (dem!=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<Phieu>::iterator i=Ph.begin();i!=Ph.end();i++)
		if (checkphieumuon(*i,tmp))
			break;
	textcolor(14);
	if (so==0)
	{
		setposition(100,5);
		cout << "PHIEU MUON KHONG TON TAI!";
	}
	if (so==1)
	{
		setposition(100,5);
		cout << "KHONG THE TRA SACH!";
	}
	if (so==2)
	{
		setposition(100,5);
		cout << "TRA SACH THANH CONG!";
	}
	textcolor(14);
	hoi:
	ham(n,n-1);
}
void quanlyphieumuon()
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
					thongtin();
					break;
				}
				if (null==1)
				{
					muonsach();
					break;
				}
				if (null==2)
				{
					trasach();
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
					quanlysach();
					break;
				}
				if (null==1)
				{
					quanlyphieumuon();
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
