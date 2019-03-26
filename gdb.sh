#!/bin/bash

cat >/tmp/gdb <<EOF
break Sortable_list<int>::merge_sort()
run
EOF

# -batch
gdb -q -x /tmp/gdb a.out

rm /tmp/gdb