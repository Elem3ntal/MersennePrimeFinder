//Structure

struct binaryChain{
	bool value;
	binaryChain *next;
	binaryChain *prev;
};
//List of Functions
//hi javier
//Functions
binaryChain* crearCadena(){
	binaryChain *nuevo = new binaryChain;
	nuevo->value = true;
	nuevo->next = NULL;
	nuevo->prev = NULL;
	binaryChain *eslabon = new binaryChain;
	eslabon->value = true;
	nuevo->next = eslabon;
	eslabon->prev = eslabon;
	eslabon->next = NULL;
	return nuevo;
}
