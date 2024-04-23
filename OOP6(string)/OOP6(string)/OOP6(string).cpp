#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	//1
	string str1;
	string str = "Hello word";
	cout << "#1:" << str << endl;
	//2
	cout << "size:" << str.size() << endl;
	cout << "size:" << str.length() << endl;
	//3
	cout << "One char: " << str[0] << endl;
	//4
	str[6] = 'p';
	str[7] = 'l';
	str[8] = 'a';
	str[9] = 'n';
	str += "et";
	cout << "New string: " << str << endl;
	//5
	str += ",how are you?";
	cout << "New string_2.0: " << str << endl;
	//6
	str1 = "Hello word";
	bool res = str < str1;
	cout <<"#6: "<< res << endl;
	//7
	string str0;
	str0=str.substr(6, 6);
	cout <<"one word: "<< str0 << endl;
	//8
	string pos;
	pos = str.find(str0);//мабуть позиція звязана з аскі тейбл
	cout <<"Position: " << pos << endl;
	//9
	string str9;
	str9 = str.substr(13, 7);
	cout << "#9: " << str9 << endl;
	//10
	string str2 = "big ";
	str.insert( 6, str2 );
	cout << "New string: " << str << endl;
	//11
	reverse(str.begin(), str.end());
	cout <<" Reverse: " << str << endl;
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str << endl;
	//12
	string str00 = "Hello my word, I love very match ";
	string subStr = "ve";
	int count = 0;
	size_t pos00 = 0;
	while ((pos00 = str00.find(subStr, pos00)) < str00.length()) {
		count++;
		pos00 += subStr.length();
	}
	cout << " The number: " << subStr << "in string: " << count << endl;
	// 13
	char strU[] = "Hello my word!";
	_strupr_s(strU);
	cout << "#13 " << strU << endl;
	//15
	string sentence = "Hello my friend";
	istringstream i(sentence);
	string word;

	while (i >> word) 
	{
		string arr[10]{ word };
		cout << "Arr words: "<<*arr << endl;
	}
	
	
	//16
	string str12 = "It's very, very interesting";
	string str13 = "extremely";
	str12.replace(5, 10, str13);
	cout << "#16: "  << str12<<endl;
	// 17
	string strP = "Hello word!";  

	string reversedStr = strP; 
	reverse(reversedStr.begin(), reversedStr.end());  
	if (strP == reversedStr) {
		cout << "String: " << strP << " is palindrom" << endl;
	}
	else {
		cout << "String: " << strP << "isn't palindrom." << endl;
	}
	// 18
	sort(str.begin(), str.end()); 
    cout << "#18: " << str << endl;
	//19//
	string strX = "Today 2024-04-22";
	strX.replace(6, 16, "X");
	cout << strX << endl;
	//20
    str2 += str1; 
    cout << " str2: " << str2 << endl;

}
	


