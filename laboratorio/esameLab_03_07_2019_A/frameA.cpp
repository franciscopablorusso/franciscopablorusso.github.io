srand(111222333);     

	for(int i=0; i<DIM; i++){
		short n=1+rand()%10;
		if(rand()%2==0)
	  		vett[i]= new B(n, rand()%5+1, rand()%11+10, (double) rand()/(RAND_MAX));
		else
	  		vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'), rand()%5+1, rand()%11+10);
   	}
