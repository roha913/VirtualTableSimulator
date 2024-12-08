#include "HashMap.h"
#include <stdio.h>

int HashMap::hashCode(std::string s){
	int hash = 7;
	int p = 31;
	for(int i = 0; i < s.length(); i++){
		hash = p*hash + s[i];
	}
	return hash;
}

void HashMap::insert(std::string key, std::string value){
	if(size >= capacity){
		rehash();
	}
	int i = hashCode(key);
	std::string function_name = hm[i].first;
	if(function_name == ""){//empty
		hm.insert(hm.begin() + i, std::make_pair(key, value));
	}else{//linear probing
		i = (i + 1)%capacity;
		while(i != hashCode(key) && hm[i].first != ""){
			i = (i + 1)%capacity;
		}
		hm.insert(hm.begin() + i, std::make_pair(key, value));
	}
}

void HashMap::rehash(){
	std::vector<std::pair<std::string, std::string>>  new_hm(2*capacity);
	for(int i = 0; i < capacity; i++){
		new_hm.insert(hm[i]);
	}
	capacity *= 2;
}


