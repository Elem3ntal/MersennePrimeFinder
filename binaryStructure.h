//Structure
using namespace std;
struct binaryLink{
	bool value;
	binaryLink *next; //<- to the left,
	binaryLink *prev; // -> to the right;
};
struct binaryChain{
	binaryLink *first; //to the left!
	binaryLink *last; // to the right!
};
//Declarations
void plusOne(binaryChain *chain);
void checkSpace(binaryChain *chain);
binaryChain* createChain(bool _Value);
binaryChain* createChain(int length);
void printBinaryChain(binaryChain *toPrint);
void addToTheLeft(binaryChain *chain, bool _value);
void addToTheRight(binaryChain *chain, bool _value);
void addBinaryChain(binaryChain *target, binaryChain *toSum);
void subtractBinaryChain(binaryChain *target, binaryChain *toSub);
bool isAmayor(binaryChain *A, binaryChain *B);
bool isEqual(binaryChain *A, binaryChain *B);
void deleteChain(binaryChain *toDelete);
binaryChain *divideBinaryChain(binaryChain* dividend, binaryChain* divisor);
binaryChain *multiplicateBinaryChain(binaryChain* A, binaryChain* B);
////////////////////Functions that are being made.////////////////////

////////////////////Functions already performed.////////////////////
//takes A and B and realize multiplication between those two generating a new binary chain
binaryChain *multiplicateBinaryChain(binaryChain* A, binaryChain* B){
	binaryChain *result = createChain(false);
	binaryChain *tempMulti = createChain(false);
	binaryLink *tempA = A->last;
	while(tempA!=NULL){
		if(tempA->value){
			binaryLink *tempB = B->first;
			binaryLink *temp0 = tempMulti->last;
			binaryChain *auxResult = createChain(false);
			while(tempB!=NULL){
				addToTheRight(auxResult,tempB->value);
				tempB=tempB->prev;
			}
			while(temp0!=NULL){
				addToTheRight(auxResult,false);
				temp0=temp0->next;
			}
			addBinaryChain(result,auxResult);
			deleteChain(auxResult);
			delete auxResult;
			delete tempB;
			delete temp0;
		}
		addToTheRight(tempMulti,false);
		tempA = tempA-> next;
	}
	deleteChain(tempMulti);
	delete tempMulti;
	delete tempA;
	binaryLink *toDelete = result->last;
	result->last->next->prev=NULL;
	result->last = result->last->next;
	delete toDelete;
	return result;
}
binaryChain *divideBinaryChain(binaryChain* dividend, binaryChain *divisor){
	//note: 68/11 = 6	1000100/1011 = 110
	binaryChain *auxDividend = createChain(false); //to create part of the number do divid
	binaryChain *result = createChain(false); //to acumulate the result
	binaryLink *tempDividend = dividend->first;
	binaryLink *tempDivisor = divisor->first;
	while(!tempDividend->value)
		tempDividend = tempDividend->prev;
	while(!tempDivisor->value)
		tempDivisor = tempDivisor->prev;
	while(tempDivisor!= NULL){
		addToTheRight(auxDividend,tempDividend->value);
		tempDividend = tempDividend->prev;
		tempDivisor = tempDivisor->prev;
	}
	if(isAmayor(auxDividend,divisor)){
		addToTheRight(result,true);
		subtractBinaryChain(auxDividend,divisor);
	}
	else if(isEqual(auxDividend,divisor)){
		addToTheRight(result,true);
		deleteChain(auxDividend);
		//subtractBinaryChain(auxDividend,divisor);
		//auxDividend=createChain(false);
	}
	else{
		addToTheRight(result,false);
	}
	while(tempDividend!=NULL){
		//cout << "dentro de la division"; printBinaryChain(result);
		addToTheRight(auxDividend,tempDividend->value);
		if(!isAmayor(divisor,auxDividend)){
			addToTheRight(result,true);
			subtractBinaryChain(auxDividend,divisor);
		}
		else if(isEqual(auxDividend,divisor)){
			addToTheRight(result,true);
			deleteChain(auxDividend);
			//subtractBinaryChain(auxDividend,divisor);
			//auxDividend=createChain(false);
		}
		else{
			addToTheRight(result,false);
		}
		tempDividend = tempDividend->prev;
	}
	deleteChain(auxDividend);
	delete auxDividend->first;
	delete auxDividend;
	return result;
}
void deleteChain(binaryChain *toDelete){
	binaryLink *temp = toDelete->first;
	binaryLink *last = temp;
	while(temp->prev!= NULL){
		last = temp;
		temp = temp->prev;
		delete last;
		//last->value = NULL;
		//last->prev = NULL;
		//last->next = NULL;
		//last->~binaryLink();
	}
	temp->prev = NULL;
	temp->next = NULL;
	temp->value = false;
	toDelete->last = temp;
	toDelete->first = toDelete->last;
}
bool isEqual(binaryChain *A, binaryChain *B){
	binaryLink *targetA = A->last, *targetB = B->last;
	while(targetA!= NULL && targetB!= NULL){
		if(targetA->value!= targetB->value)
			return false;
		targetA = targetA->next;
		targetB = targetB->next;
	}
	binaryLink *notNUll = NULL;
	if (targetA == NULL && targetB == NULL)
		return true;
	else if(targetA!= NULL)
		notNUll = targetA;
	else if(targetB!= NULL)
		notNUll = targetB;
	while(notNUll!= NULL){
		if(notNUll->value)
			return false;
		notNUll = notNUll->next;
	}
	targetA = NULL;
	targetB = NULL;
	notNUll = NULL;
	return true;
}
bool isAmayor(binaryChain *A, binaryChain *B){
	binaryLink *targetA = A->last, *targetB = B->last;
	bool aMayor = true;
	while(targetA!= NULL && targetB!= NULL){
		if(targetA->value==true && targetB->value==false)
			aMayor=true;
		else if(targetA->value==false && targetB->value==true)
			aMayor=false;
		targetA = targetA->next;
		targetB = targetB->next;
	}
	while(targetB!= NULL){
		if(targetB->value)
			aMayor=false;
		targetB=targetB->next;
	}
	while(targetA!= NULL){
		if(targetA->value)
			aMayor=true;
		targetA=targetA->next;
	}
	targetA = NULL;
	targetB = NULL;
	return aMayor;
}
void subtractBinaryChain(binaryChain *target, binaryChain *toSub){
	//takes A and B, and add B to A, that implies that the variable where we want to save the values always must be the first to enter
	binaryLink *a = target->last, *b = toSub->last, *aCarry;
	bool carry = false; //true and true is false, and carry true to the nex one, 1+1 = 10
	while((a!= NULL && b!= NULL) || carry){
		if(carry)
			aCarry = a;
		while(carry){//Two cases possible with carry, the link where the sum goes exists or does not
			//cout <<aCarry->value<<carry<<"pegado en while\n";
			if(aCarry!= NULL){ //if A exist, are two posibilites, A have a False or True
				if(aCarry->value){
					aCarry->value = false;
					carry = false;
				}
				else{
					aCarry->value = true;
					carry = true;
				}
				aCarry = aCarry->next;
			}
			else{ // comes here if a not exist and whe have a carry.
				//cout<<"desbordado\n";
				addToTheLeft(target,true);
				carry = false;
			}
		}
		if(b!= NULL && a!= NULL){
			if(a->value && !b->value)
				a->value = true;
			else if(a->value && b->value)
				a->value = false;
			else if(!a->value && b->value){
				a->value = true;
				carry=true;
			}
		}
		if(a!= NULL){
			a = a->next;
		}
		if(b!= NULL)
			b = b->next;
	}
	target=NULL;
	toSub=NULL;
	a=NULL;
	b = NULL;
}
void addBinaryChain(binaryChain *target, binaryChain *toSum){
	//takes A and B, and add B to A, that implies that the variable where we want to save the values always must be the first to enter
	binaryLink *a = target->last, *b = toSum->last;
	bool carry = false; //true and true is false, and carry true to the nex one, 1+1 = 10
	while((a!= NULL || b!= NULL) || carry){
		if(carry){//Two cases possible with carry, the link where the sum goes exists or does not
			if(a!= NULL){ //if A exist, are two posibilites, A have a False or True
				if(a->value){
					a->value = false;
					carry = true;
				}
				else{
					a->value = true;
					carry = false;
				}
			}
			else{ // comes here if a not exist and whe have a carry.
				addToTheLeft(target,true);
				addToTheLeft(target,false);
				carry = false;
			}
		}
		if(a!= NULL && b!= NULL){
			if(a->value && b->value){
				a->value = false;
				carry = true;
			}
			else if(a->value || b->value){
				a->value = true;
			}
		}
		if(a->next == NULL && b!=NULL && carry == false)
			addToTheLeft(target,false);
		if(a->next == NULL && carry)
			addToTheLeft(target,false);
		if(a!= NULL)
			a = a->next;
		if(b!= NULL)
			b = b->next;
	}
	a = NULL;
	b = NULL;
	carry=NULL;
	target=NULL;
	toSum=NULL;
}
void addToTheLeft(binaryChain *chain, bool _value){
	binaryLink *newOne = new binaryLink;
	newOne->value = _value;
	newOne->next = NULL;
	newOne->prev = chain->first;
	chain->first->next = newOne;
	chain->first = newOne;
}
void addToTheRight(binaryChain *chain, bool _value){
	chain->last->prev = new binaryLink;
	chain->last->prev->value = _value;
	chain->last->prev->next = chain->last;
	chain->last->prev->prev = NULL;
	chain->last = chain->last->prev;
}
binaryChain* createChain(int length){ //create a new chain with a preset value
	binaryChain *newChain = new binaryChain;
	binaryLink *newLink = new binaryLink;
	newChain->last = newLink;
	newChain->first = newLink;
	newLink->value = false;
	newLink->prev = NULL;
	for(int i = 1;i<length;i++){
		binaryLink *newOne = new binaryLink;
		newOne->value = false;
		if(i == 1){
			newLink->next = newOne;
		}
		else{
			newChain->first->next = newOne;
		}
		newOne->next = NULL;
		newOne->prev = newChain->first;
		newChain->first = newOne;
	}
	return newChain;
}
void plusOne(binaryChain *chain){//add one to the chain
	checkSpace(chain);
	binaryLink *tempLink = chain->last;
	while(tempLink!= NULL){
		if(tempLink->value){
			tempLink->value = false;
		}
		else if(tempLink->value == false){
			tempLink->value = true;
			return;
		}
		tempLink = tempLink->next;
	}
	delete chain;
	tempLink=NULL;
	//move from the right to the left, if is true, change to zero and continue, if is zero change to true and end.
	//always check if the first link must be zero
}
void checkSpace(binaryChain *chain){
	if(chain->first->value){
		binaryLink *newOne = new binaryLink;
		newOne->value = false;
		newOne->next = NULL;
		newOne->prev = chain->first;
		chain->first->next = newOne;
		chain->first = newOne;
	}
	chain = NULL;
}

binaryChain* createChain(bool _Value){ //create a new chain with a preset value
	binaryChain *newChain = new binaryChain;
	newChain->first = new binaryLink;
	newChain->first->value = _Value;
	newChain->first->next = NULL;
	newChain->first->prev = NULL;
	newChain->last = newChain->first;
	return newChain;
}
void printBinaryChain(binaryChain *toPrint){ //just print... dah!
	//checkSpace(toPrint);
	binaryLink *temp = toPrint->first;
	while(temp!= NULL){
		cout << temp->value;
		temp = temp->prev;
	}
	cout << endl;
}
