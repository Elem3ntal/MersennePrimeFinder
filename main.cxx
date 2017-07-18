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
#include <stdlib.h>
#include "binaryStructure.h"
#include "digitalcounter.h"

int algorithmTest(int N);
void test(int N);

int main(int argc, char **argv)
{
//	test(1000);
	algorithmTest(31);
	return 0;
}

void test(int N)
{
	binaryChain *seven = createChain(false);
	//two: to increase the divisor
	printBinaryChain(seven);
	for(int i=0;i<N;i++){ //to create max divisor
		addToTheRight(seven,true);
	}
	printBinaryChain(seven);
	int pause;
	cin >> pause;
	deleteChain(seven);
	printBinaryChain(seven);
	cin >> pause;
	seven=createChain(false);
	for(int i=0;i<N;i++){ //to create max divisor
		addToTheRight(seven,true);
	}
	printBinaryChain(seven);
	cin >> pause;
}
int algorithmTest(int N)//amount of "1" to conform the binary
{
	bool flag = false;
	binaryChain *two = createChain(false);
	binaryChain *three = createChain(false);
	binaryChain *five = createChain(false);
	binaryChain *seven = createChain(false);
	binaryChain *Target = createChain(false);
	binaryChain *maxDivisory = NULL;
	binaryChain *auxDivisor1 = createChain(false);
	binaryChain *auxDivisor2 = createChain(false);
	binaryChain *auxDivisor3 = createChain(false);
	binaryChain *divisor = createChain(false);
	binaryChain *aux = NULL;
	//
	//two: to increase the divisor
	addToTheRight(two,true);
	addToTheRight(two,false);
	//three: to split and generate the maxDivisory
	addToTheRight(three,true);
	addToTheRight(three,true);
	addToTheRight(five,true);
	addToTheRight(five,false);
	addToTheRight(five,true);
	addToTheRight(seven,true);
	addToTheRight(seven,true);
	addToTheRight(seven,true);
	//divisor: start in 11...
	addToTheRight(divisor,true);
	addToTheRight(divisor,false);
	addToTheRight(divisor,true);
	addToTheRight(divisor,true);
	//increase the auxDivisors to is start number
	addToTheRight(auxDivisor1,true);
	addToTheRight(auxDivisor2,true);
	addToTheRight(auxDivisor2,true);
	addToTheRight(auxDivisor3,true);
	addToTheRight(auxDivisor3,false);
	//seed to analize
	for(int i=0;i<N;i++){ //to create max divisor
		addToTheRight(Target,true);
	}
	maxDivisory=divideBinaryChain(Target,divisor);
	//----------
	cout << "----------Numbers with work----------" <<endl;
	cout << "Target: "; printBinaryChain(Target);
	cout << "maxDivisory: "; printBinaryChain(maxDivisory);
	cout << "divisor: "; printBinaryChain(divisor);
	cout << "two: "; printBinaryChain(two);
	cout << "three: "; printBinaryChain(three);
	cout << "-------------------------------------" <<endl;
	//----------
	while (!isAmayor(divisor,maxDivisory)){
		//printBinaryChain(divisor);
		//aux=divideBinaryChain(Target,divisor);
		//aux=multiplicateBinaryChain(aux,divisor);
		aux=multiplicateBinaryChain(divideBinaryChain(Target,divisor),divisor);
		if(isEqual(Target,aux)){
			cout << "The number isn't prime\n";
			break;
		}
		//increase the aux divisors
		//flag=true;
		do{
			addBinaryChain(divisor,two);
			flag=false;
			plusOne(auxDivisor1);
			plusOne(auxDivisor2);
			plusOne(auxDivisor3);
			//analize
			if(isEqual(auxDivisor1,three)){
				deleteChain(auxDivisor1);
				auxDivisor1=createChain(false);
				flag=true;
			}
			if(isEqual(auxDivisor2,five)){
				deleteChain(auxDivisor2);
				auxDivisor2=createChain(false);
				flag=true;
			}
			if(isEqual(auxDivisor3,seven)){
				deleteChain(auxDivisor3);
				auxDivisor3=createChain(false);
				flag=true;
			}
		}while(flag);
		deleteChain(aux);
		aux->~binaryChain();
	}
	if(isAmayor(divisor,maxDivisory))
		cout<<"the number is prime\n";
	return 0;
}
