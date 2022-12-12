echo "Enter a: "
read a;

echo "Enter b: "
read b

if [ $a -gt $b ]
then
    echo "${a} is the greatest"
elif [ $b -gt $a ]
then
    echo "${b} is the greatest"
else
    echo "Both a and b are equal"
fi