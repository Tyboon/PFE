#! /bin/bash

variators="UCP10P1 UCP10P2 UCP10P3 UCP10P4 UCP10P5 UCP10P6 UCP10P7 UCP20P1 UCP20P2 UCP20P3 UCP20P4 UCP20P5 UCP20P6 UCP20P7"

cd tests ;

for var in $variators ; do
	echo $var >> ../group_eps_wilcoxon.20 ;
	cat $(echo $var)_eps_wilcoxon.20 >> ../group_eps_wilcoxon.20 ;
	echo $var >> ../group_hyp_wilcoxon.20 ;
	cat $(echo $var)_hyp_wilcoxon.20 >> ../group_hyp_wilcoxon.20 ;
	echo $var >> ../group_r_wilcoxon.20 ;
	cat $(echo $var)_r_wilcoxon.20 >> ../group_r_wilcoxon.20 ;
done ;


