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

int main(int argc, char **argv)
{
	//number to analize
	binaryChain *chainA = createChain(true);
	binaryChain *chainB = createChain(true);
	binaryChain *two1 = createChain(true);
	binaryChain *two2 = createChain(true);
	for(int i=0;i<2;i++){ //to create the number 3
		plusOne(chainB);
	}
	addToTheRight(two1,false);//to create the number two,
	addToTheRight(two2,false);//to create the number two,
	for(int i=0;i<6;i++){ //create the big chain A
		addToTheRight(chainA,true);
	}
	addToTheLeft(chainA,false);
	printBinaryChain(chainA); //123
	printBinaryChain(chainB); // 16
	printBinaryChain(two1); // 16
	cout << "----------\n";
	while(isAmayor(chainA,chainB)){
		printBinaryChain(chainA);
		subtractBinaryChain(chainA,chainB);
		//printBinaryChain(chainB); // 16
	}
	cout << "----------\n";
	printBinaryChain(chainA);
	subtractBinaryChain(chainA,chainB);
	printBinaryChain(chainA); //123
	printBinaryChain(chainB); // 16
	return 0;
}

