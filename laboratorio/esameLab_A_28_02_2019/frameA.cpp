    srand(111222333);

    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
		short n=1+rand()%10;
		switch(rand()%3) {
	  	case 0: 
	    	vett[i]= new C(n, rand()%10 + 1);
	   	break;
	  	case 1:
	    	vett[i]= new B<string>(n, rand()%('z' - 'a' + 1) + 'a');
	    break;
	  	case 2: 
	    	vett[i]= new B<char>(n, rand()%('z' - 'a' + 1) + 'a');
		}
    }
