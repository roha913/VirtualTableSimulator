#include <stdio.h>
#include <string>
#include <map>
#include "a_Class.h"
#include "HashMap.h"
#include <iostream>


int main(){
	std::string command;
	std::map<std::string, a_Class*> classes;// map between class name and actual class
	bool doIt = true;
	while(doIt){
		std::cin >> command;
		if(command.length() != 1){
			throw std::runtime_error("command.length() != 1");
		}
		switch(command[0]){// commands are to add a class as a derived class, add a function to a class, or exit
			case 'F'://Add a function to a class
				{
				std::string class_name;
				std::string func_name;
				std::string func_description;
				int isVirtual;
				std::cin >> class_name;
				std::cin >> func_name;
				std::cin >> func_description;
				std::cin >> isVirtual;
				if(class_name.length() == 0 || func_name.length() == 0 || func_description.length() == 0){
					throw std::runtime_error("One of the names has length == 0");
				}
				if(!classes.count(class_name)){
					classes[class_name] = new a_Class(class_name, isVirtual);
				}
				if(isVirtual){
					(classes[class_name]->v_pointer)->insert(func_name, func_description);
				}
				break;
				}
			case 'D'://Add a class as a derived class
				{
				std::string base_name;
				std::cin >> base_name;
				std::string derived_name;
				std::cin >> derived_name;
				(classes[base_name]->derived_classes).insert(new a_Class(derived_name, 0));
				break;
				}
			case 'X'://Exit
				{
				doIt = false;
				break;
				}
			default:
		}
	}
	return 0;
}
