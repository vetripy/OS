echo "Enter a string"
read string

temp=$string

rev=""
len=${#string}

for ((i=$len-1;i>=0;i--))
do
	rev="$rev${string:$i:1}"
done
echo "$rev"
