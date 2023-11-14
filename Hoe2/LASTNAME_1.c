
int power(int base, int pow){
	int result;
	for(result = 1;pow > 0;pow--){
		result *= base;
	}
	return result;
}

int gcdEuclideanAlgorithm(int a, int b){
	int q,r; 
	r = 1;

	if (b > a)
		swap(&a, &b);
	
	while(a % b != 0){
		divisionAlgorithm(a, b, &q, &r);
		a = b;
		b = r;
	}
	
	return b;
}


int findRelativelyPrime(int x){
	int counter = 2;

	for(;gcdEuclideanAlgorithm(x,counter) != 1;counter++);
	
	return counter;
}

int countDigits(int message){
	int counter = 0;
	
	do{
		counter++;
		message /= 10;
	} while (message > 0);
	
	return counter;
}


void printMessage(int message){
	int numOfDigits, scale;

	numOfDigits = countDigits(message);
	scale = power(10, numOfDigits - 1);
	if (numOfDigits % 2 == 0){
		scale /= 10;
	} 
	
	while(message > 0){
		printf("%c", getLetter(message/scale));
		message %= scale;
		scale /= 100;
	}
	
	printf("\n");
}

int encryptDecryptMessage(int p, int q, int msg, int mode){
	
	int numOfDigits = countDigits(msg);
	int scale = power(10, numOfDigits - 1);
	int crypted = 0;
	
	if (numOfDigits % 2 == 0){
		scale /= 10;
	} 
	
	if(mode == 1){
		while(scale > 0){
		crypted += encryptLetter(p, q,msg/scale);
		msg %= scale;
		scale /= 100;
			if(scale > 0)
				crypted *= 100;
		}
		return crypted;
	} else if(mode == -1){
		while(scale > 0){
		crypted += decryptLetter(p, q,msg/scale);
		msg %= scale;
		scale /= 100;
			if(scale > 0)
				crypted *= 100;
		}
		return crypted;
	}
}
