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
	binaryChain *chain1 = createChain(5);
	binaryChain *chain2 = createChain(false);
	for(int i=0;i<16;i++){
		cout << i << ") ";
		printBinaryChain(chain1);
		plusOne(chain1);
	}
	for(int i=0;i<16;i++){
		cout << i << ") ";
		printBinaryChain(chain2);
		plusOne(chain2);
	}
	return 0;
}

