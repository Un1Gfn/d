// 236
// 237
// 238
// 239
// 240

#include <iostream>
#include <list>
using namespace std;

class String {
public:
  String(); // ok
  ~String();
  String(const String &copy);
  String(const char *copy); // ok
  String(/*List*/list<char> &copy); // ok
  void operator=(const String &copy);
  const char *c_str() const; // ok
protected:
  char *entries;
  int length;
};

bool operator==(const String &first, const String &second); // ok
bool operator>(const String &first, const String &second); // ok
bool operator<(const String &first, const String &second); // ok
bool operator>=(const String &first, const String &second); // ok
bool operator<=(const String &first, const String &second); // ok
bool operator!=(const String &first, const String &second); // ok

void strcat(String &add_to, const String &add_on); // ok
// String read_in(istream &input, int &terminator);
String read_in(istream &input); // ok
void write(String &s); // ok
void strcpy(String &copy, const String &original); // unimplemted
void strncpy(String &copy, const String &original, int n); // unimplemted
int strstr(const String &text, const String &target); // unimplemted
