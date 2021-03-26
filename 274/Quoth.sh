# Eli Billinger
# CSCI 274
# Quoth.shu
quit = "QUIT"
while true
do
	echo "Pick a quote-sayer from:"
	ls -1 
	echo "... or enter QUIT to exit the script."
	read  directname
	if [[ "$directname" == "QUIT" ]]
	then
	       	exit 0
	elif [[ ! -d "$directname" ]]
	then
	       	exit 7
	else
		echo $directname "said:"
		cat $directname/quote.txt
	fi
done
