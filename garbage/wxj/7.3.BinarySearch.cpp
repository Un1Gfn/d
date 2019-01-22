#include "7.3.BinarySearch.h"

int Key::the_key()const
{
  return key;
}

Error_code Ordered_list::retrieve(int position, Record& x)const
{
  auto it=begin();
  if((unsigned)position<0)
    return underflow;
  if((unsigned)position>size()-1)
    return overflow;
  advance(it,position);
  x=*it;
  return success;
}

void Ordered_list::insert(const Record &data)
{
  list<Record>::iterator position;
  for(position=begin(); position != end(); ++position)
    if(data < *position)
      break;
  list<Record>::insert(position, data);
}

// Error_code Ordered_list::insert(int position, const Record &data)
// {
//   Record list_data;
//   if (position > 0) {
//     retrieve(position - 1, list_data);
//     if (data < list_data)
//       return fail;
//   }
//   if (position < size()) {
//     retrieve(position, list_data);
//     if (data > list_data)
//       return fail;
//   }
//   return list<Record>::insert(position, data);
// }

bool operator == (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()==y.the_key();
}
bool operator > (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()>y.the_key();
}
bool operator < (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()<y.the_key();
}
bool operator >= (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()>=y.the_key();
}
bool operator <= (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()<=y.the_key();
}
bool operator != (const Key &x, const Key &y){
  ++comparisons;
  return x.the_key()!=y.the_key();
}

Error_code recursive_binary_1(const Ordered_list &the_list, const Key &target,
int bottom, int top, int &position)
{
  Record data;
  if (bottom < top) {
    int mid = (bottom + top)/2;
    the_list.retrieve(mid, data);
    if (data < target)
      return recursive_binary_1(the_list, target, mid + 1, top, position);
    else
      return recursive_binary_1(the_list, target, bottom, mid, position);
  }
  else if (top < bottom)
    return not_present;
  else {
    position = bottom;
    the_list.retrieve(bottom, data);
    if (data == target) return success;
    else return not_present;
  }
}

Error_code run_recursive_binary_1(const Ordered_list &the_list,const Key &target, int &position)
{
  return recursive_binary_1(the_list, target, 0, the_list.size() - 1, position);
}

Error_code binary_search_1(const Ordered_list &the_list,const Key &target, int &position)
{
  Record data;
  int bottom = 0, top = the_list.size() - 1;
  while (bottom < top) {
    int mid = (bottom + top)/2;
    the_list.retrieve(mid, data);
    if (data < target)
      bottom = mid + 1;
    else
      top = mid;
  }
  if (top < bottom) return not_present;
  else {
    position = bottom;
    the_list.retrieve(bottom, data);
    if (data == target) return success;
    else return not_present;
  }
}

Error_code recursive_binary_2(const Ordered_list &the_list, const Key &target,int bottom, int top, int &position)
{
  Record data;
  if (bottom <= top) {
    int mid = (bottom + top)/2;
    the_list.retrieve(mid, data);
    if (data == target) {
      position = mid;
      return success;
    }
    else if (data < target)
      return recursive_binary_2(the_list, target, mid + 1, top, position);
    else
      return recursive_binary_2(the_list, target, bottom, mid - 1, position);
  }else{
    return not_present;
  }
}

Error_code run_recursive_binary_2(const Ordered_list &the_list,const Key &target, int &position)
{
  return recursive_binary_2(the_list, target, 0, the_list.size() - 1, position);
}

Error_code binary_search_2(const Ordered_list &the_list,const Key &target, int &position)
{
  Record data;
  int bottom = 0, top = the_list.size() - 1;
  while (bottom <= top) {
    position = (bottom + top)/2;
    the_list.retrieve(position, data);
    if (data == target) return success;
    if (data < target) bottom = position + 1;
    else top = position - 1;
  }
  return not_present;
}

int comparisons=0;