echo "Enter n: "
read n

f=0
s=1

for(( i=1;i<=n;i++ ))
{
	t=$((f+s))
	echo $t
	f=$s
	s=$t 
}