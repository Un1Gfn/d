# Report
## Let's go step by step
### Step 1
```
darren@...$ g++ ./main.cpp -std=c++11 -Wall -o ./a.out
darren@...$ ./a.out <sample_in.txt 
in->
  capacity: 23
   item_id:  0  1  2  3
item_wight:  1 11 12 22
out<-      
        id:  0  3
    weight:  1 22

        id:  1  2
    weight: 11 12
darren@...$
```
### Step 2
```
darren@...$ cat sample_in.txt 
23
1 11 12 22
darren@...$
```
  * Input format: Two lines.  
  * First line: Capacity of the pack
  * Second line: weight of each items (<=99kg)
  * I'm lazy, so no input integrity check :smile:
  
### Step 3
Try with other inputs or view main.cpp (with comments) if you are interested.

  
  
  
  
  
  
  