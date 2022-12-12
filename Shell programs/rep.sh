echo "Enter a string: "
read string

echo "Enter the character to be replaced: "
read rem

echo "Enter character to replace: "
read chr

echo $string | tr $rem $chr
