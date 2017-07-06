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
	return 0;
}

void test()
{
	binaryChain *N2=createChain(true);
	binaryChain *N1=createChain(true);
	addToTheRight(N1,true);
	addToTheRight(N1,true);
	addToTheRight(N1,false);
	addToTheRight(N1,true);
	addToTheRight(N1,false);
	addToTheRight(N1,true);
	addToTheRight(N2,false);
	addToTheRight(N2,true);
	printBinaryChain(N1);
	cout<<"------------"<<endl;
	printBinaryChain(N2);
	cout<<"------------"<<endl;
	printBinaryChain(divideBinaryChain(N1,N2));
	
}
int algorithmTest(int N)//amount of "1" to conform the binary
{
	bool flag = false;
	binaryChain *Target;
	binaryChain *maxDivisory = createChain(true);
	binaryChain *divisor = createChain(true);
	binaryChain *two = createChain(true);
	//every number has to had a cero in the left
	addToTheLeft(maxDivisory,false);
	addToTheLeft(divisor,false);
	addToTheLeft(two,false);
	//cycles for to create the two, divisor and maxDivisor
	addToTheRight(two,false);//to create the number two
	addToTheRight(divisor,true);//to create first divisor
	for(int i=0;i<N-2;i++){ //to create max divisor
		addToTheRight(maxDivisory,true);
	}
	while (!isAmayor(divisor,maxDivisory)){
		Target = createChain(true);
		addToTheLeft(Target,false);
		for(int i=0;i<N-1;i++){
			addToTheRight(Target,true);
		}
		while(!isAmayor(divisor,Target) && !isEqual(divisor,Target)){
			subtractBinaryChain(Target,divisor);
		}
		flag=isEqual(Target,divisor);
		deleteChain(Target);
		delete Target;
		if(flag){
			cout << "The number isn't prime\n";
			break;
		}
		addBinaryChain(divisor,two);
		cout << "---------\n";
	}
	if(!flag)
		cout<<"the number is prime\n";
	return 0;
}
