#!/bin/bash
#
CAT()
{
	cat /etc/passwd | head -$line
}
limit=6
line=2
if [ $limit -gt $line ]
then
	while [ -n $line ]
		do
			CAT
			break 2
		done
#
	echo
	let line=line+1
	CAT
fi
exit 0		
