/*
 * MPF.cxx
 *
 * Copyright 2017 Javier Rodriguez Benavente <elem3ntaldmnt@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <iostream>
#include <string.h>
#include "binaryStructure.h"
int algorithmTest(int N);
void test();

int main(int argc, char **argv)
{
	test();
//	algorithmTest(21);
	return 0;
}

void test()
{
	binaryChain *divisor = createChain(false);
	binaryChain *five = createChain(false);
	binaryChain *number = createChain(false);
	//two: to increase the divisor
	addToTheRight(five,true);
	addToTheRight(five,false);
	addToTheRight(five,true);
	//three: to split and generate the maxDivisory
	//divisor: start in 3...
	for(int i=0;i<10;i++){
		cout<<(5*i)<<": ";
		printBinaryChain(number);
		addBinaryChain(number,five);
	}
}
int algorithmTest(int N)//amount of "1" to conform the binary
{
	bool flag = false;
	binaryChain *Target = createChain(false);
	binaryChain *maxDivisory = NULL;
	binaryChain *divisor = createChain(false);
	binaryChain *two = createChain(false);
	binaryChain *three = createChain(false);
	//two: to increase the divisor
	addToTheRight(two,true);
	addToTheRight(two,false);
	//three: to split and generate the maxDivisory
	addToTheRight(three,true);
	addToTheRight(three,true);
	//divisor: start in 3...
	addToTheRight(divisor,true);
	addToTheRight(divisor,true);
	//seed to analize
	for(int i=0;i<N;i++){ //to create max divisor
		addToTheRight(Target,true);
	}
	maxDivisory=divideBinaryChain(Target,three);
	//----------
	cout << "----------Numbers with work----------" <<endl;
	cout << "Target: "; printBinaryChain(Target);
	cout << "maxDivisory: "; printBinaryChain(maxDivisory);
	cout << "divisor: "; printBinaryChain(divisor);
	cout << "two: "; printBinaryChain(two);
	cout << "three: "; printBinaryChain(three);
	cout << "-------------------------------------\n\n" <<endl;
	//----------
	while (!isAmayor(divisor,maxDivisory)){
		binaryChain *aux=divideBinaryChain(Target,divisor);
		aux=multiplicateBinaryChain(aux,divisor);
		flag=isEqual(Target,aux);
		if(flag){
			cout << "The number isn't prime\n";
			break;
		}
		addBinaryChain(divisor,two);
	}
	if(!flag)
		cout<<"the number is prime\n";
	return 0;
}
