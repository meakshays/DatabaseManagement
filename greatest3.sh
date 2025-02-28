echo "Enter three integers"
read a b c 
if [ $a -gt $b -a $a -gt $c ]
then
echo "$a is the Greatest integer"
elif [ $b -gt $a -a $b -gt $c ]
then
echo "$b is the Greatest integer"
else
echo "$c is the Greatest integer"
fi
