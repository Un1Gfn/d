// 279
// 280
// 281
// 282
// 283
// 284
// 285

#ifndef BINARY_SEARCH
#define BINARY_SEARCH

#include <list>
using namespace std;

enum Error_code{fail,overflow,underflow,success,not_present};

class Key {
private:
  int key;
public:
  Key (int x = 0):key(x){}
  int the_key()const;
};

typedef Key Record;
// class Record{
// public:
//   operator Key();
// private:
// };

class Ordered_list:public list<Record>{
public:
  Error_code retrieve(int position, Record& x) const;
  Ordered_list(){}
  void insert(const Record &data);
  // Error_code insert(int position, const Record &data);
  // Error_code replace(int position, const Record &data);
};

bool operator == (const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >= (const Key &x, const Key &y);
bool operator <= (const Key &x, const Key &y);
bool operator != (const Key &x, const Key &y);

Error_code recursive_binary_1(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position);
Error_code run_recursive_binary_1(const Ordered_list &the_list,const Key &target, int &position);
Error_code binary_search_1(const Ordered_list &the_list,const Key &target, int &position);
Error_code recursive_binary_2(const Ordered_list &the_list, const Key &target,int bottom, int top, int &position);
Error_code run_recursive_binary_2(const Ordered_list &the_list,const Key &target, int &position);
Error_code binary_search_2(const Ordered_list &the_list,const Key &target, int &position);

extern int comparisons;

#endif