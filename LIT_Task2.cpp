#include <iostream>
#include <string>

#define sep '.'

bool syntax(std::string str){
	int dot = 0;
	
	while(!str.empty()){
		char ch = str.back();
		if (ch == sep){
			if (++dot > 3){
				return false;
			}
		}
		else if (ch < '0' || ch > '9'){
			return false;
		}
		str.pop_back();
	}
	
	if (dot < 3)
		return false;
	
	return true;
}

int main()
{
    std::string str1 = "8.1.13.41", str2 = "8.1.009.125";
/*
	do{
		std::cout << "Write 1st version:" << std::endl;
		std::cin >> str1;
	}
	while(!syntax(str1));
	
	do{
		std::cout << "Write 2nd version:" << std::endl;
		std::cin >> str2;
	}
	while(!syntax(str2));
*/	
	bool bigger = false;
	int t1 = str1.length() - 1, t2 = str2.length() - 1;

	while (t1 >= 0 || t2 >= 0) {
		if (str1[t1] == sep && str2[t2] == sep) {
			--t1;
			--t2;
		}
		else if (str1[t1] == sep && str2[t2] != sep) {
			if (str2[t2] > '0')
				bigger = false;
			--t2;
		}
		else if (str1[t1] != sep && str2[t2] == sep) {
			if (str1[t1] > '0')
				bigger = true;
			--t1;
		}
		else if (str1[t1] > str2[t2]) {
			bigger = true;
			--t1;
			--t2;
		}
		else if (str1[t1] < str2[t2]) {
			bigger = false;
			--t1;
			--t2;
		}
		else {
			--t1;
			--t2;
		}
	}

	std::cout << str1 << (bigger ? " > " : " < ") << str2 << std::endl;
}