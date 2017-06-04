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

////////////////////Functions that are being made.////////////////////

////////////////////Functions  already  performed.////////////////////
void addToTheLeft(binaryChain *chain, bool _value){
	binaryLink *tempLink = chain->first;
	if(tempLink->value){
		binaryLink *newOne = new binaryLink;
		newOne->value=_value;
		newOne->next = NULL;
		newOne->prev = tempLink;
		tempLink->next = newOne;
		chain->first = newOne;
	}
}
void addToTheRight(binaryChain *chain, bool _value){
	binaryLink *tempLink = chain->last;
	if(tempLink->value){
		binaryLink *newOne = new binaryLink;
		newOne->value=_value;
		newOne->next = tempLink;
		newOne->prev = NULL;
		tempLink->prev = newOne;
		chain->last = newOne;
	}
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
	binaryChain *tempChain = chain;
	binaryLink *tempLink = tempChain->first;
	if(tempLink->value){
		binaryLink *newOne = new binaryLink;
		newOne->value=false;
		newOne->next = NULL;
		newOne->prev = tempLink;
		tempLink->next = newOne;
		tempChain->first = newOne;
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
