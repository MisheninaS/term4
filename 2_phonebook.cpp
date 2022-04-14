#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

class Phonebook {
public:
    map<string, string> book;

    Phonebook(): book(){};

    Phonebook(string name, string number){
			book.insert(std::make_pair(name, number));
		};

    void add_person(string name, string number){
        book[name] = number;
    }

    string find_person_by_name(string name){
        map <string, string> :: iterator it;
        it = book.find(name);
        if (it != book.end()) {
            return it->second;
            } else {
                return "no";
                }
    }

     void delete_person(string name){
        map <string, string> :: iterator it;
        it = book.find(name);
        book.erase(it);
    }

    void print_phonebook(){
        map <string, string> :: iterator it = book.begin();
        for (int i = 0; it != book.end(); it++, i++) {
            cout << it->first << " " << it->second << endl;
        }
    }
};

int main() {
    Phonebook phonebook;
    phonebook.add_person("b", "0");
    phonebook.add_person("a", "1");
    phonebook.add_person("c", "2");
    phonebook.print_phonebook();
    phonebook.delete_person("a");
    phonebook.print_phonebook();
    cout << phonebook.find_person_by_name("a");
}
