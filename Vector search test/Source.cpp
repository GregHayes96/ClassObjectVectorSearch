//This program takes a class object and has the ability to search for a specific item in the class object

#include <cstring>
#include <iostream>
#include <vector>


class Item {
	int num;
	std::string word;
public:
	//constructor
	Item(int num = 12, std::string word = "default") :num(num), word(word) {};

	//getters
	int get_num()const { return num; }
	std::string get_word()const { return word; }

	bool operator==(const Item& rhs) const;
};

//operator overload to compare items to each other
bool Item::operator==(const Item& rhs) const {
	if (this->num == rhs.num && this->word == rhs.word){
		std::cout << "Items match" << std::endl;
		return true;
	}
	else {
		std::cout << "Items do not match" << std::endl;
		return false;
	}
};

//a class that store a vector of class objects for 'item'
//this can be searched for individual objects using the search_vector member function

class Vector_stored {
public:
	void store_object(const Item obj) { list.push_back(obj); }
	void search(const Item& obj);
private:
	std::vector<Item> list{};
};


//use of iterator to search vector
void Vector_stored::search(const Item& obj) {
	std::vector<Item>::iterator it;
	it = find(this->list.begin(), this->list.end(), obj);
	if (it == this->list.end()) throw "item not in vector";
	else
		std::cout << "item in database" << std::endl;
}


int main() {
	try {
		Item It1;
		Item It2(12, "word");
		Item It3(13, "stuff");

		Vector_stored Database;

		Database.store_object(It1);
		Database.store_object(It2);

		Database.search(It1);

	}
	catch (const char* txtException) {
		std::cerr << "Exception: " << txtException;
	}
	catch (...) {
		std::cerr << "Exception - unknown";
	}
}