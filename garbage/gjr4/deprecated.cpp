// deprecated.cpp
// garbage file
				size_t pos=darren::getnum("Position:");
				char holder='\0';
				if(li.retrieve(pos,holder)!=Error_code::success)
					cout<<"Fail"<<endl;
				else
					cout<<holder<<endl;
	// Error_code retrieve(int position, List_entry &x) const{
	// 	if(position>count-1)
	// 		return Error_code::overflow;
	// 	if(position<0)
	// 		return Error_code::underflow;
	// 	x=entry[position];
	// 	return Error_code::success;
	// }