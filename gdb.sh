#!/bin/bash

# cat >/tmp/gdb <<EOF
# break Sortable_list<char>::insert_heap
# run
# continue
# continue
# continue
# continue
# EOF

cat >/tmp/gdb <<EOF
set confirm off
# break Sortable_list<int>::build_heap
break Sortable_list<int>::insert_heap
run
# finish
EOF

# -batch
# reset
gdb -q -x /tmp/gdb a.out

rm /tmp/gdb