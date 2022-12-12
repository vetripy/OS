echo "Enter a string: "
read str

len=${#str}

count=0

for((i=0;i<len;i++))
do
	if [ ${str:$i:1} == 'a' -o ${str:$i:1} == 'e' -o ${str:$i:1} == 'i' -o ${str:$i:1} == 'o' -o ${str:$i:1} == 'u' ] 
	then
	count=$((count+1))
	fi
done

echo $count
