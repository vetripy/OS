echo "Enter a number: "
read n

f=1
one=1

while [ $n -gt $one ]
do
    f=$((f*n))
    n=$((n-1))
done

echo "factorial: ${f}"