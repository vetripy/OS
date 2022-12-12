echo "Enter the size: "
read size

sum=0

while [ $size -gt 0 ]
do 
	sum=$((sum+size))
	size=$((size-1))
done

echo $sum
