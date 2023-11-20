#!/bin/bash

echo "Tests using tester"
[ ! -d push_swap_tester ] && git clone https://github.com/nafuka11/push_swap_tester.git || echo "already cloned"

cd push_swap_tester
echo -e "\033[31m\033[47m******************引数3のとき******************\033[m\033[m"
python3 push_swap_tester.py -l 3
echo -e "\033[31m\033[47m******************引数5のとき******************\033[m\033[m"
python3 push_swap_tester.py -l 5
echo -e "\033[31m\033[47m******************引数100のとき******************\033[m\033[m"
python3 push_swap_tester.py -l 100
echo -e "\033[31m\033[47m******************引数500のとき******************\033[m\033[m"
python3 push_swap_tester.py -l 500