#include <stdio.h>

#ifndef HashMap_H
#define HashMap_H


class HashMap{
	public:
		void insert(std::string key, std::string value);//key would be function name, value would be description
	private:
		int size = 0;
		int capacity = 16;
		std::vector<std::pair<std::string, std::string>> hm(capacity);
		int hashCode(std::string key);
		void rehash();
}; 

#endif
