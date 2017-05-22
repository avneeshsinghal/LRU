#include <stdio.h>
#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int tag[8];
int mru[8] = {7,6,5,4,3,2,1,0};

void mruUpdate(int index)
{
    int i;
    // find index in mru
    for (i = 0; i < 8; i++)
        if (mru[i] == index)
            break;
    // move earlier refs one later
    while (i > 0) {
        mru[i] = mru[i-1];
        i--;
    }
    mru[0] = index;
}

int main( )
{
    int addr;
    int i, j, t;
    int hits, accesses;
    FILE *fp;
    
    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    int sel=0,sel1=0;
		char file[10]={0};
    do
	{
		cout<<" Welcome to the Cache Memory program   "<<endl;
		cout<<" What would you like to do? Please make a selection from the menu"<<endl;
		cout<<endl<<" 1) Direct mapping                                     "<<endl;
	
                                cout<<endl<<"##################################################  #####"<<endl<<endl;
		cin>>sel;
	}
	while (sel<1||sel>3);
	switch(sel)
	{
	case 1:
		{
		cout<<"Direct mapping......loading cache"<<endl;
		do
		{
			cout<<"What would you like to do?"<<endl;
			cout<<"1) Begin displaying contents of cache"<<endl;
			cout<<"2) Change input file."<<endl;
			cout<<"3) Display hit/miss ratio"<<endl;
			cout<<"4) Exit"<<endl;
			cin>>sel1;
		}
		while (sel1<1||sel1>4);
		switch (sel1)
		{
		case 1:
			while (fscanf(fp, "%x", &addr) > 0) {
        /* simulate fully associative cache with 8 words */
        accesses += 1;
        printf("%3d: 0x%08x ", accesses, addr);
        for (i = 0; i < 8; i++) {
            if (tag[i] == addr) {
                hits += 1;
                printf("Hit%d ", i);
                mruUpdate(i);
                break;
            }
        }
        if (i == 8) {
            /* allocate entry */
            printf("Miss ");
            i = mru[7];
            tag[i] = addr;
            mruUpdate(i);
        }
        for (i = 0; i < 8; i++)
            printf("0x%08x ", tag[i]);
        for (i = 0; i < 8; i++)
            printf("%d ", mru[i]);
        printf("\n");
    
    case 2:
    	    
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
}
	fclose(fp);
    return 0;
   }
}
}
}

