echo "Enter number: "
read n

sum=0
temp=$n 
zero=0


while [ $n -gt $zero ]
do
    r=$((n%10))
    a=$((r*r*r))
    sum=$((sum+a))
    n=$((n/10))
done

if [ $sum == $temp ]
then
    echo "$temp is a armstrong number"
else
    echo "$temp is not a armstrong number"
fi
