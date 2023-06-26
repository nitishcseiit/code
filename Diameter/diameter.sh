#! /bin/bash


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
	echo "IIT Dharwad. $i"
	echo "CSE: $rec_column1"
	echo "SP4: $rec_column2"
	#theSetOfAAllVertiecs+=('$rec_column1')
	#theSetOfAAllVertiecs[i]+=$i
	#theSetOfAllVertices
	#theSetOfAllVertices+=('foo')
	A+=('foo')
	array=("Jack Brown")
	value="Jack"


	if [[ ! " ${B[*]} " =~ " ${rec_column1} " ]]; then
    		#
		echo -e "Cornor"
		B+=(`expr $rec_column1`)
	fi
	if [[ ! " ${B[*]} " =~ " ${rec_column2} " ]]; then
    		#
		echo -e "Cornor"
		B+=(`expr $rec_column2`)
	fi


	#if [[ "${IFS}${B[*]}${IFS}" =~ "${IFS}${rec_column1}${IFS}" ]]; then
	#	echo "true"
	#else
	#	echo "false"
	#	B+=(`expr $rec_column1`)
		#i=`expr $i + 1`
	#fi
	#unset IFS # or set back to original IFS if previously set
	
	#if [[ "${IFS}${B[*]}${IFS}" =~ "${IFS}${rec_column2}${IFS}" ]]; then
	#	echo "true"
	#else
	#	echo "false"
	#	B+=(`expr $rec_column2`)
		#i=`expr $i + 1`
	#fi
	#unset IFS # or set back to original IFS if previously set



	#B+=(`expr $rec_column1`)
	#i=`expr $i + 1`
	#echo "Number of elements in the array: ${#theSetOfAllvertices[*]}"
	
	echo ""
done < $1

echo -e "\nHold on: $theSetOfAllvertices[0]"
echo -e "\nHold on: $theSetOfAllvertices[1]"
echo -e "\nHold on: $theSetOfAllvertices[2]"
echo -e "\nHold on: $theSetOfAllvertices[3]"
echo -e "\nHold on: $theSetOfAllvertices[4]"
echo -e "\nHold on: $theSetOfAllvertices[5]"
echo -e "\nHold on: $theSetOfAllvertices[6]"
echo -e "\nHold on: $theSetOfAllvertices[7]"
echo -e "\nHold on: $theSetOfAllvertices[8]"
echo -e "\nHold on: $theSetOfAllvertices[9]"
echo -e "\nHold on: $theSetOfAllvertices[10]"
echo -e "\nHold on: $theSetOfAllvertices[11]"
echo -e "\nHold on: $theSetOfAllvertices[12]"
echo -e "\nHold on: $theSetOfAllvertices[13]"

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

#g++ diameter-2023-05-25-1800.cpp -lz3
#./a.out graph1.txt

g++ Diameter.cpp -lz3

for i in ${B[@]}; 
do 
	./a.out $1 $i	
	#echo -e "\nTest: $i"; 
done

C=()

while IFS="\n" read -r rec_column1 
do
	echo "IIT Dharwad. $i"
	echo "CSE: $rec_column1"
	if [[ ! " ${C[*]} " =~ " ${rec_column1} " ]]; then
    		#
		echo -e "Cornor"
		C+=(`expr $rec_column1`)
	fi
	echo ""
done < allD.txt

echo -e "\nprinting C: "
for i in ${C[@]}; 
do 
	echo -e "\nTest: $i"; 
done

max=${C[0]}
for n in "${C[@]}" ; do
    ((n > max)) && max=$n
done

echo -e "\nThe Diameter is: $max"

