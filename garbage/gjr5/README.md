# algorithm_experiment5

* 吴德润 16340238 教务三班 星期三08:00~09:40数据结构实验课

* You might have a look of the Makefile for details **after** the following steps. Thanks.

```
...$ make clean
rm -f *.svg *.out
...$ make
g++ -std=c++11 -Wall -g ./main.cpp -o ./a.out
...$ make static_test
echo "3 6 5 8 4 2 7" | ./a.out
Please input signed integers between [-9223372036854775808, 9223372036854775807]: 
Each number a line, end with EOF.
Don't give me letters and/or other garbages. Please BE SMART.
Number> Number> Number> Number> Number> Number> Number> Number> 

Original:
  Preorder : 3 2 6 5 4 8 7
  Postorder: 2 4 5 7 8 6 3
  Inorder  : 2 3 4 5 6 7 8

Flipped:
  Preorder : 3 6 8 7 5 4 2
  Postorder: 7 8 4 5 6 2 3
  Inorder  : 8 7 6 5 4 3 2

Bye.

...$ make test
echo `shuf -i 2-8` | ./a.out
Please input signed integers between [-9223372036854775808, 9223372036854775807]: 
Each number a line, end with EOF.
Don't give me letters and/or other garbages. Please BE SMART.
Number> Number> Number> Number> Number> Number> Number> Number> 

Original:
  Preorder : 5 4 2 3 8 6 7
  Postorder: 3 2 4 7 6 8 5
  Inorder  : 2 3 4 5 6 7 8

Flipped:
  Preorder : 5 8 6 7 4 2 3
  Postorder: 7 6 8 3 2 4 5
  Inorder  : 8 7 6 5 4 3 2

Bye.

...$ make test
echo `shuf -i 2-8` | ./a.out
Please input signed integers between [-9223372036854775808, 9223372036854775807]: 
Each number a line, end with EOF.
Don't give me letters and/or other garbages. Please BE SMART.
Number> Number> Number> Number> Number> Number> Number> Number> 

Original:
  Preorder : 7 3 2 6 4 5 8
  Postorder: 2 5 4 6 3 8 7
  Inorder  : 2 3 4 5 6 7 8

Flipped:
  Preorder : 7 8 3 6 4 5 2
  Postorder: 8 5 4 6 2 3 7
  Inorder  : 8 7 6 5 4 3 2

Bye.

...$ 

```


