#!/bin/bash
#
# run.ksh: UNIX/LINUX complement to run.bat
#
# Eckart Zitzler, ETH Zurich, Feb 18, 2005

# to be edited by the user

#selectors="dmls11n dmls1kn_5 dmls1kn_10 dmls11i dmls11im dmls11id"
#selectors="dmls11im dmls11id"
#selectors="dmls1kn_20 dmls1kn_50 dmls11im dmls11id"
#selectors="IBEAP1 IBEAP2 IBEAP3 IBEAP4 IBEAP5 IBEAP6 IBEAP7 NSGAP1 NSGAP2 NSGAP3 NSGAP4 NSGAP5 NSGAP6 NSGAP7"
#variators="UCP10P1 UCP10P2 UCP10P3 UCP10P4 UCP10P5 UCP10P6 UCP10P7 UCP20P1 UCP20P2 UCP20P3 UCP20P4 UCP20P5 UCP20P6 UCP20P7"
selectors="C1 C2 C3 C4 C5 C6 C7 C8 C9 C10"
variators="JS"
#variators=""
#for i in {01..05}
#do
 #   variators="$variators 100_10_""$i""_2o"
#    variators="$variators 100_10_""$i""_3o"
#    variators="$variators 100_20_""$i""_2o"
#    variators="$variators 100_20_""$i""_3o"
#done
os="c_source"

#=================================================
#for gen in {0360..7200..360}; do
#    echo Generation $gen
#    for var in $variators; do
#        . ./compute.ksh bounds dummy $var $gen
#    done
#    for sel in $selectors; do
#        for var in $variators; do
#	    . ./compute.ksh indicators $sel $var $gen
#        done
#    done
#done

#exit
#=================================================

#generation=0600
generation=20
#=================================================
# DO NOT MAKE ANY CHANGES BELOW THIS LINE
#=================================================

export os


 if [[ $1 != "compare" ]] ; then
     for sel in $selectors ; do
 	for var in $variators ; do
 	    . ./compute.ksh run $sel $var $generation
 	done ;
     done ;
fi

echo BOUNDS
for var in $variators ; do
    . ./compute.ksh bounds dummy $var $generation
done ;

echo INDICATORS
for sel in $selectors ; do
   for var in $variators ; do
	. ./compute.ksh indicators $sel $var $generation
    done ;
done ;

 echo TESTS
 for var in $variators ; do
     . ./compute.ksh tests dummy $var $generation
 done ;

# for sel in $selectors ; do
#     for var in $variators ; do
# 	. ./compute.ksh eafs $sel $var $generation
#     done ;
# done ;

# for sela in $selectors ; do
#     for selb in $selectors ; do
#         for var in $variators ; do
# 	    . ./compute.ksh eaftests $sela $selb $var $generation
# 	done ;
#     done ;
# done ;

# for sela in $selectors ; do
#     for selb in $selectors ; do
#         for var in $variators ; do
# 	    . ./compute.ksh ranktests $sela $selb $var $generation
# 	done ;
#     done ;
# done ;
