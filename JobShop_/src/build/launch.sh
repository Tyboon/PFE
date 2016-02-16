#!/bin/bash
output="output/NSGA100Point/NSGA100Point_C$1.20";
for i in {1..20};
do ./JobShopEA -A$2 -C$1 -I../../DataOneMachine/bky100/bky100_1.txt -P100 >> $output
	echo $i
done;

