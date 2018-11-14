// 270
// 271
// 272
// 274
// 275
// 276

typedef int Key;
typedef int Record;
typedef Key Record;

class Key {
private:
  int key;
public:
  static int comparisons;
  Key (int x = 0);
  int the_key()const;
};

class Record{
public:
  operator Key();
private:
};

bool operator == (const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >= (const Key &x, const Key &y);
bool operator <= (const Key &x, const Key &y);
bool operator != (const Key &x, const Key &y);
