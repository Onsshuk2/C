#include <iostream>
using namespace std;

class Pet 
{
protected:
    string name;
public:
	Pet(string petName) :name(petName){}
	
	void display() const
	{
		cout << " Pet Name: " << name << endl;
		
	}
};

class Dog:public Pet
{
	string owner;
public:
	
	Dog(string dogName,string ownerName): Pet(dogName), owner(ownerName){}
	

	void display() const
	{
		cout << " Dog Name: " << name << endl;
		cout << "Dog's owner:  " << owner << endl;

	}
};
class Cat :public Pet
{
	string ownerC;
public:

	Cat (string catName, string ownerCatName) : Pet(catName), ownerC(ownerCatName) {}


	void display() const
	{
		cout << "Cat Name: " << name << endl;
		cout << "Cat's owner:  " << ownerC << endl;

	}
};

class Parrot : public Pet
{
	string ownerP;
public:

	Parrot (string parrotName, string ownerPname) : Pet(parrotName), ownerP(ownerPname) {}


	void display() const
	{
		cout << "Parrot Name: " << name << endl;
		cout << "Parrot's owner:  " << ownerP << endl;

	}
};

class String
{
protected:
	int leng;
	string name, name0;
public:
	String()
	{
		leng = 0;
		name = "my string";
	}
	String(const char* str) 
	{
		leng = strlen(str); 
		name = str; 
	}

	String(const String& other) 
	{
		leng = other.leng;
		name = other.name;
	}

	String operator=(String st)
	{
		leng = st.leng;
		name = st.name;
		return *this;
	}

	int lengString()
	{
		 return name.length();
	}

	void clearString() 
	{
		name.clear();
		leng = 0;
	}
	void show() const 
	{
		cout << "Length: " << leng  << endl;
		cout << "String: " << name << endl;
	}

	String operator +(String st)
	{
		String s;
		s.name = name + st.name;
		s.name0 = name0 + st.name0;
		return s;
	}
	
	bool operator==(const String& other) const {
		return (leng == other.leng) && (name == other.name);
	}
};

class BinaryString:public String 
{
	string content;
public:
	BinaryString() 
	{
		content = "00000";
	}

	BinaryString(const string& str) {
		for (char c : str) {
			if (c != '0' && c != '1') {
				content.clear(); 
				break;
			}
		}
		content = str; 
	}

	void show() const  {
		cout << "Binary String: " << content << endl;
	}

	
	int toInteger() const {
		int result = 0;
		for (char c : content) {
			result <<= 1; 
			result += (c - '0');
		}
		return result;
	}
};

int main()
{
	Pet p1("My Pet");
	p1.display();

	Dog d1("Sharic", "Ira");
	d1.display();

	Cat c1("Murchik", "Olga");
	c1.display();

	Parrot per1("Kesha", "Ann");
	per1.display();

	cout << "*************************" << endl;

	String st1("Hello my word");
	cout << "Length : " << st1.lengString() << endl;
	st1.show();
	st1.clearString();
	st1.show();
	String S1("Hello,");
	String S2(" Teacher");

	String S3;
	S3 = S1 + S2;
	S3.show();

	String s1("Hello");
	String s2("Hello");
	String s3("World");

	if (s1 == s2) {
		cout << "st1 and st2 are equal" << endl;
	}
	else {
		cout << "st1 and st2 are not equal" << endl;
	}

	if (s1 == s3) {
		cout << "st1 and st3 are equal" << endl;
	}
	else {
		cout << "st1 and st3 are not equal" << endl;
	}

	BinaryString bs1("101010"); 
	bs1.show(); 
	cout << "Integer value: " << bs1.toInteger() << endl;  

	BinaryString bs2("1010201"); 
	bs2.show(); 

