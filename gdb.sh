#!/bin/bash

cat >/tmp/gdb <<EOF
break Sortable_list<char>::insert_heap
run
continue
continue
continue
continue
EOF

# -batch
reset
gdb -q -x /tmp/gdb a.out

rm /tmp/gdb