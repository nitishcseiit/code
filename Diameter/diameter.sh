#! /bin/bash
# copyright(C)
# Authors : Nitish Kumar
#IIT Dharwad 2023

rm allD.txt
touch allD.txt
echo -e "1. Read input file\n"
#declare -a theSetOfAllVertices=()

A=()
B=()
theSetOfAllVertices=()
i=0
while IFS=" " read -r rec_column1 rec_column2
do
	
	A+=('foo')
	array=("Jack Brown")
	value="Jack"


	if [[ ! " ${B[*]} " =~ " ${rec_column1} " ]]; then
    		#
		#echo -e "Cornor"
		B+=(`expr $rec_column1`)
	fi
	if [[ ! " ${B[*]} " =~ " ${rec_column2} " ]]; then
    		#
		#echo -e "Cornor"
		B+=(`expr $rec_column2`)
	fi


	echo ""
done < $1

#print all vertices

printf '%s\n' "${theSetOfAllvertices[@]}"

echo -e "\nprinting A: "

for i in ${A[@]}; 
do
	echo -e "\nHello: $i"; 
done

echo -e "\nprinting B: "
for i in ${B[@]}; 
do 
	echo -e "\nTest: $i"; 
done


echo -e "\n1111111111111111111111111"

echo "${#theSetOfAllvertices[*]}"

echo -e "\n22222222222222222222"


ARRAY=()
ARRAY+=('foo')
ARRAY+=('bar')

for i in ${ARRAY[@]}; do echo $i; done



#call diameter.cpp 

g++ diameter.cpp -lz3

#store output of diameter.cpp

for i in ${B[@]}; 
do 
	./a.out $1 $i	
	#echo -e "\nTest: $i"; 
done

C=()

while IFS="\n" read -r rec_column1 
do
	#echo "IIT Dharwad. $i"
	#echo "CSE: $rec_column1"
	if [[ ! " ${C[*]} " =~ " ${rec_column1} " ]]; then
    		#
		#echo -e "Cornor"
		C+=(`expr $rec_column1`)
	fi
	echo ""
done < allD.txt

#echo -e "\nprinting C: "
for i in ${C[@]}; 
do 
	echo -e "\nTest: $i"; 
done
#find max 
max=${C[0]}
for n in "${C[@]}" ; do
    ((n > max)) && max=$n
done

echo -e "\nThe Diameter is: $max"

