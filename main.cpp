#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>  
#include <algorithm>


using namespace std;

void calc(int);

main()
{
	cout<<"Feladat: \n"<<"Tekintsunk egy tetszolegesen hosszu bitsorozatot. A bitsorozaton egyetlen muveletet tudunk vegezni: az egymas mellett allo azonos bitek kihuzhatoak (ketto vagy akar tobb darab is). Eldontendo, hogy a bitsorozat dosszes bitje eliminalhato-e ezzel a muvelettel. A bitsorozatot standard input-rol kell beolvasni, az eredmenyt a standard output-ra kell kiirni.\n";
	cout<<"Kilepes '9' - cel\n\n";

	int bin;

	while(bin !=9)
	{
		cout<<"\n \nKerem a bitsorozatot: ";
		cin>> bin;
		if(bin !=9) calc(bin);
	}


//	return 0;
}



void calc(int bin)
{

	std::vector<int> v;
	while(bin > 0)
	{
		v.push_back(bin%10);
		bin /=10;
	}

	reverse(v.begin(), v.end());

	/*************************************/	
		/***//*
		cout<<"Megadott sorozat: ";
		for(int j=0; j<v.size(); ++j)
		{
			cout<<v[j]<<" ";
		}*/
		/***/

	int nr = 0;
	int first,last,i;
	
	i = 0;
	//cout<<"v: "<< v.size();
	while((i<v.size()) && (nr<2))
	{
		if((nr == 0) && (v[i] == 0))
		{
			nr = 1;
			first = i;
		}

		if((nr == 1) && (v[i] == 1))
		{
			nr = 2;
			last = i;

			v.erase (v.begin()+first,v.begin()+last);
		}	

		/***/
/*		cout<<"\n nr: "<<nr<<"\n Aktualis sor: ";
		for(int j=0; j<v.size(); ++j)
		{
			cout<<v[j]<<" ";
		}*/
		/***/

		++i;
	}

	/*************************************/

	cout<<"\n \n";
	bool l = true;
	i = 0;
	//for(int i=0; i<v.size(); ++i)
	while((l == true) && (i<v.size()))
	{
		//cout<<v[i]<<" ";
		if (v[i] == 0) l = false;
		++i;
	}

	cout<<"\n *** \n v.size(): "<<v.size();
	cout<<"\n i:"<<i;
	cout<<"\n l: "<<l<<"\n *** \n";

	if (l == false) 
	{
		 cout<<"Nem eliminalhato\n";
	}else{
		 cout<<"Eliminalhato\n";
	}
}