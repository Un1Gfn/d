#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
// #include<stdexcept>
using namespace std;
typedef unsigned long weight_t;
typedef vector<weight_t> items_t;
typedef unsigned no_t;
// pair::second is currrent weight sum
typedef pair<vector<no_t>,weight_t> pack_t;
typedef vector<pack_t> result_t;
void great_respect_for_the_PLA(){
	cout<<"I asked Mr. Gjr."<<endl;
	cout<<"And he told me that no one can carry a 100 kg pack"<<endl;
	cout<<"Unless you are a member of the PLA."<<endl;
	exit(1);
}
weight_t get_capacity(istream& is){
	string line;
	getline(is,line);
	weight_t ret=stoul(line);
	if(ret>=100)
		great_respect_for_the_PLA();
	return ret;
}
items_t get_items(istream& is){
	string line;
	items_t ret;
	getline(is,line);
	istringstream iss(line);
	while(1){
		weight_t tmp=0;
		iss>>tmp;
		if(!iss)
			return ret;
		if(tmp>=100)
			great_respect_for_the_PLA();
		ret.push_back(tmp);
	}
}
const weight_t capacity=get_capacity(cin);
const items_t items=get_items(cin);
// contain the id of items
result_t result;
void r(const pack_t p){
	// ditch it
	if(p.second>capacity)
		return;
	// add to result
	if(p.second==capacity){
		result.push_back(p);
		return;
	}
	// call next
	if(p.second<capacity){
		for(no_t id=p.first.back()+1;id!=items.size();++id){
			pack_t q=p;
			q.first.push_back(id);
			q.second+=items[id];
			r(q);
		}
		return;
	}
	return;
}
void r0(pack_t p){
	for(no_t i=0;i!=items.size();++i){
		r(pack_t({i},items[i]));
	}
}
void print(){
	typedef int setw_t; 
	const setw_t width=3;
	cout<<"in->       "<<endl;
	cout<<endl;
	cout<<"  capacity:"<<setw(width)<<capacity<<endl;
	cout<<"   item_id:";
	for(no_t i=0;i!=items.size();++i)
		cout<<setw(width)<<i;
	cout<<endl;
	cout<<"item_wight:";
	for(no_t i=0;i!=items.size();++i)
		cout<<setw(width)<<items[i];
	cout<<endl;
	cout<<endl;
	cout<<"out<-      "<<endl;
	cout<<endl;
	if(result.empty()){
		cout<<"Impossible."<<endl;
		return;
	}
	for(const pack_t& p:result){
		cout<<"        id:";
		for(const no_t no:p.first)
			cout<<setw(width)<<no;
		cout<<endl;
		cout<<"    weight:";
		for(const no_t no:p.first)
			cout<<setw(width)<<items[no];
		cout<<endl;
		cout<<endl;
	}
}
int main(){
	r0(make_pair(vector<no_t>(),0));
	print();
	return 0;
}
