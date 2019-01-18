#include "10_SequentialSearch.h"

int Key::comparisons = 0;

Error_code sequential_search(const List< Record > &the_list,const Key &target, int &position)
{
  int s = the_list.size();
  for (position = 0; position < s; position ++) {
    Record data;
    the_list.retrieve(position, data);
    if (data == target) return success;
  }
  return not_present;
}

bool operator == (const Key &x, const Key &y)
{
  Key::comparisons++ ;
  return x.the_key() == y.the_key();
}

void test_search(int searches, List< Record > &the_list)
{
  int list_size = the_list.size();
  if (searches <= 0 || list_size < 0) {
    cout << " Exiting test: " << endl
         << " The number of searches must be positive." << endl
         << " The number of list entries must exceed 0." << endl;
    return;
  }
  int i, target, found_at;
  Key::comparisons = 0;
  Random number;
  Timer clock;
  for (i = 0; i < searches; i ++ ) {
    target = 2 * number.random_integer(0, list_size − 1) + 1;
    if (sequential_search(the_list, target, found_at) == not_present)
    cout << "Error: Failed to find expected target " << target << endl;
    }
    print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);
    Key::comparisons = 0;
    clock.reset();
    for (i = 0; i < searches; i ++ ) {
    target = 2 * number.random_integer(0, list_size);
    if (sequential_search(the_list, target, found_at) == success)
    cout << "Error: Found unexpected target " << target
    << " at " << found_at << endl;
    }
    print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
    }
