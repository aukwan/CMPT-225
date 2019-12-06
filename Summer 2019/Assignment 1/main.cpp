#include <iostream>
#include "CharList.h"
#include <string>

using namespace std;

int main() {
    string expect = ("abcddcbaabcd");
    CharList* c = new CharList("bcdaaace");
    c->insert('a');
    c->append('d');
    c->insert('d', 'd');
    c->remove('a', 2 );
    c->append('b', 'a' , 3 );
    c->remove('e');
    c->insert('c', 'a', 2);
    c->append('b', 'c', 2);
    string actual = c->toString();
    if (actual.compare(expect) == 0) {
      cout << "passed" << endl;
    } else {
      cout <<"failed" << endl;
      //cout << "Expected Result: " << expect << endl;
      //cout << "Actual Result: "  << actual << endl;
    }
    return 0;
}
