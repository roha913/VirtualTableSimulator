#include <stdio.h>
#include "HashMap.h"

#ifndef a_CLass_H
#define a_CLass_H
class a_Class{
        public:
                std::string name;
                HashMap* vpointer;
		std::vector<a_Class*> derived_classes;
		~a_Class(){
			 delete vpointer;
			 for(std::vector<a_Class*>::const_iterator it = derived_classes.cbegin(); it != derived_classes.cend(); it++){
				delete *it;
			 }
		}
}

#endif a_CLass_H
