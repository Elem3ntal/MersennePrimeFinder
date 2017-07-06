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
////////////////////Functions that are being made.////////////////////
binaryChain *divideBinaryChain(binaryChain* dividend, binaryChain *divisor){
	//note: 15/3=5	1111/11=101
	binaryChain *auxDividend = createChain(false);
	binaryChain *result = createChain(false);
	binaryLink *tempDividend = dividend->first;
	binaryLink *tempDivisor=divisor->first;
	while(tempDivisor!=NULL){
		addToTheRight(auxDividend,tempDividend->value);
		tempDividend=tempDividend->prev;
		tempDivisor= tempDivisor->prev;
	}
	printBinaryChain(auxDividend);
	subtractBinaryChain(auxDividend,divisor);
	return auxDividend;
}
////////////////////Functions  already  performed.////////////////////
void deleteChain(binaryChain *toDelete){
	binaryLink *temp=toDelete->first;
	binaryLink *last=toDelete->first;
	while(temp!=NULL){
		last=temp;
		temp=temp->prev;
		if(last!=NULL){
			delete last;
		}
	}
}
bool isEqual(binaryChain *A, binaryChain *B){
	binaryLink *targetA = A->last, *targetB = B->last;
	bool exit = true;
	while(targetA!=NULL && targetB!=NULL){
		if(targetA->value!=targetB->value)
			exit=false;
		targetA = targetA->next;
		targetB = targetB->next;
	}
	binaryLink *notNUll;
	if(targetA!=NULL)
		notNUll=targetA;
	else if(targetB!=NULL)
		notNUll=targetB;
	while(notNUll!=NULL){
		if(notNUll->value)
			exit=false;
		notNUll=notNUll->next;
	}
	return exit;
}
bool isAmayor(binaryChain *A, binaryChain *B){
	binaryLink *targetA = A->last, *targetB = B->last;
	bool same = true;
	bool aMayor = true;
	while(targetA!=NULL && targetB!=NULL){
		if(targetA->value==targetB->value){
		}
		else if(targetB->value==false && targetA->value==true){
			aMayor = true;
			same = false;
		}
		else{
			same = false;
			aMayor = false;
		}
		targetA = targetA->next;
		targetB = targetB->next;
	}
	//cout << "bool state: "<< aMayor << endl;
	if(targetA!=NULL){
		if(targetA->value==true && targetB==NULL)
			aMayor = true;
	}
	if (same==true)
		return false;
	return aMayor;
}
void subtractBinaryChain(binaryChain *target, binaryChain *toSub){
	//takes A and B, and add B to A, that implies that the variable where we want to save the values always must be the first to enter
	binaryLink *a = target->last, *b = toSub->last;
	bool carry = false; //true and true is false, and carry true to the nex one, 1+1=10
	while((a!=NULL && b!=NULL)){
		if(carry){//Two cases possible with carry, the link where the sum goes exists or does not
			if(a!=NULL){ //if A exist, are two posibilites, A have a False or True
				if(a->value)
					a->value=false;
				else{
					a->value=true;
					carry=false;
				}
			}
			else{ // comes here if a not exist and whe have a carry.
				addToTheLeft(target,true);
				carry=false;
			}
		}
		if(b!=NULL && a!=NULL){
			if(a->value && !b->value){
				a->value = false;
				carry = true;
			}
			else if(a->value || !b->value){
				a->value = true;
			}
		}
		if(a!=NULL)
			a=a->next;
		if(b->next==NULL)
			addToTheLeft(toSub,false);
		if(b!=NULL)
			b=b->next;
	}
	//drop the first one
	target->first=target->first->prev;
	plusOne(target);
}
void addBinaryChain(binaryChain *target, binaryChain *toSum){
	//takes A and B, and add B to A, that implies that the variable where we want to save the values always must be the first to enter
	binaryLink *a = target->last, *b = toSum->last;
	bool carry = false; //true and true is false, and carry true to the nex one, 1+1=10
	while((a!=NULL || b!=NULL) || carry){
		if(carry){//Two cases possible with carry, the link where the sum goes exists or does not
			if(a!=NULL){ //if A exist, are two posibilites, A have a False or True
				if(a->value)
					a->value=false;
				else{
					a->value=true;
					carry=false;
				}
			}
			else{ // comes here if a not exist and whe have a carry.
				addToTheLeft(target,true);
				carry=false;
			}
		}
		if(b!=NULL && a!=NULL){
			if(a->value && b->value){
				a->value = false;
				carry = true;
			}
			else if(a->value || b->value){
				a->value = true;
			}
		}
		if(a!=NULL)
			a=a->next;
		if(b!=NULL)
			b=b->next;
	}
}
void addToTheLeft(binaryChain *chain, bool _value){
	binaryLink *newOne = new binaryLink;
	newOne->value=_value;
	newOne->next = NULL;
	newOne->prev = chain->first;
	chain->first->next = newOne;
	chain->first = newOne;
}
void addToTheRight(binaryChain *chain, bool _value){
	binaryLink *newOne = new binaryLink;
	newOne->value=_value;
	newOne->next = chain->last;
	newOne->prev = NULL;
	chain->last->prev = newOne;
	chain->last = newOne;
}
binaryChain* createChain(int length){ //create a new chain with a preset value
	binaryChain *newChain = new binaryChain;
	binaryLink *newLink = new binaryLink;
	newChain->last = newLink;
	newChain->first = newLink;
	newLink->value = false;
	newLink->prev = NULL;
	for(int i=1;i<length;i++){
		binaryLink *newOne = new binaryLink;
		newOne->value=false;
		if(i==1){
			newLink->next = newOne;
		}
		else{
			newChain->first->next=newOne;
		}
		newOne->next=NULL;
		newOne->prev=newChain->first;
		newChain->first=newOne;
	}
	return newChain;
}
void plusOne(binaryChain *chain){//add one to the chain
	checkSpace(chain);
	binaryLink *tempLink = chain->last;
	while(tempLink!=NULL){
		if(tempLink->value){
			tempLink->value=false;
		}
		else if(tempLink->value==false){
			tempLink->value=true;
			return;
		}
		tempLink=tempLink->next;
	}
	//move from the right to the left, if is true, change to zero and continue, if is zero change to true and end.
	//always check if the first link must be zero
}
void checkSpace(binaryChain *chain){
	if(chain->first->value){
		binaryLink *newOne = new binaryLink;
		newOne->value=false;
		newOne->next = NULL;
		newOne->prev = chain->first;
		chain->first->next = newOne;
		chain->first = newOne;
	}
}

binaryChain* createChain(bool _Value){ //create a new chain with a preset value
	binaryChain *newChain = new binaryChain;
	binaryLink *newLink = new binaryLink;
	newLink->value = _Value;
	newLink->next = NULL;
	newLink->prev = NULL;
	newChain->first = newLink;
	newChain->last = newLink;
	return newChain;
}
void printBinaryChain(binaryChain *toPrint){ //just print... dah!
	//checkSpace(toPrint);
	binaryLink *temp=toPrint->first;
	while(temp!=NULL){
		cout << temp->value;
		temp=temp->prev;
	}
	cout << endl;
}
