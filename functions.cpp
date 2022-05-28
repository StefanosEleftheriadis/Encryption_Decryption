#include "classes.h"

//encryption class
encryption::encryption()
{
	key="";
 	message="";
	code_message="";
	temp_key="";
	rowcount=0;
	colcount=0;
	for(int i=0; i<MaxRow;i++)
	{
		for(int j=0; j<MaxCol;j++)
		{
			code[i][j]=' ';
		}
	}
}

void encryption::input()
{
	key="";
 	message="";
	code_message="";
	temp_key="";
	rowcount=0;
	colcount=0;
	for(int i=0; i<MaxRow;i++)
	{
		for(int j=0; j<MaxCol;j++)
		{
			code[i][j]=' ';
		}
	}
	
	string temp_str="";
	bool correct;
	
	fflush(stdin);
	cout<<"Please enter your message: ";
	getline(cin,message);
	
	//remove numbers,spaces,special characters
    for(int counter = 0; counter< message.length(); counter++)
	{
		if(((message[counter]>=65 && message[counter]<=90) || (message[counter]>=97 && message[counter]<=122)))
		{
			temp_str+=message[counter];
		}
    }
    
    message=temp_str;
    
    for(int counter = 0; counter< message.length(); counter++)
	{
		if(!isupper(message[counter]))
		{
			message[counter]=toupper(message[counter]);
		}
    }
    
    do{
    	correct=true;
    	fflush(stdin);
    	cout<<"Please enter your keyword: ";
		cin>>key;
		
		//Checking for numbers and special characters
		for(int charcount=0;charcount<key.length();charcount++)
		{
			if(key[charcount]<65 || key[charcount]>90 && key[charcount]<97 || key[charcount]>122)
			{
				correct=false;
			}
		}
		
		//Checking for dublicates
		for(int charcount=0;charcount<key.length()-1;charcount++)
		{
			for(int counter=charcount+1;counter<key.length();counter++)
			{
				if(key[charcount]==key[counter])
				{
					correct=false;
				}
			}
		}
		
	}while(!correct);
	
	cout<<message<<endl;
    
    
}

void encryption::codemessage()
{	
	for(int counter=0;counter<message.length();counter++)
	{
		switch(message[counter])
		{
			case 'A':
				code_message+="00";
				break;
			case 'B':
				code_message+="01";
				break;
			case 'C':
				code_message+="02";
				break;
			case 'D':
				code_message+="03";
				break;
			case 'E':
				code_message+="04";
				break;
			case 'F':
				code_message+="10";
				break;
			case 'G':
				code_message+="11";
				break;
			case 'H':
				code_message+="12";
				break;
			case 'I':
				code_message+="13";
				break;
			case 'J':
				code_message+="14";
				break;
			case 'K':
				code_message+="20";
				break;
			case 'L':
				code_message+="21";
				break;
			case 'M':
				code_message+="22";
				break;
			case 'N':
				code_message+="23";
				break;
			case 'O':
				code_message+="24";
				break;
			case 'P':
				code_message+="30";
				break;
			case 'Q':
				code_message+="31";
				break;
			case 'R':
				code_message+="32";
				break;
			case 'S':
				code_message+="33";
				break;
			case 'T':
				code_message+="34";
				break;
			case 'U':
				code_message+="40";
				break;
			case 'V':
				code_message+="41";
				break;
			case 'W':
				code_message+="42";
				break;
			case 'X':
				code_message+="43";
				break;
			case 'Y':
				code_message+="44";
				break;
			case 'Z':
				code_message+="50";
				break;
			
		}
	}
	
	cout<<code_message<<endl;
	
	//Write key with caps
	for(int counter=0; counter<key.length(); counter++)
	{
		temp_key+=toupper(key[counter]);
	}
	
	for(int counter=0; counter<temp_key.length(); counter++)
	{
		cout<<left<<setw(2)<<temp_key[counter];
	}
	cout<<endl;
	
	//fill the code table
	colcount=key.length();
	
	rowcount=code_message.length()/key.length();
	if(code_message.length()%key.length()!=0)
	{
		rowcount++;
	}
	
	int char_count=0;
	for(int icount=0; icount<rowcount; icount++)
	{
		for(int jcount=0; jcount<colcount; jcount++)
		{
			if(code_message[char_count]=='\0')
				break;
			code[icount][jcount]=code_message[char_count++];
			cout<<left<<setw(2)<<code[icount][jcount];
		}
		cout<<endl;
	}
		
}

void encryption::sort()
{
	char temp_char;
	string sortkey;
	sortkey=temp_key;
	
	cout<<endl<<endl;
	
	for(int counterout=0;counterout<sortkey.length()-1;counterout++)
	{
		for(int counterin=0;counterin<sortkey.length()-counterout-1;counterin++)
		{
			if(sortkey[counterin]>sortkey[counterin+1])
			{
				temp_char=sortkey[counterin];
				sortkey[counterin]=sortkey[counterin+1];
				sortkey[counterin+1]=temp_char;
				for(int counter=0; counter<rowcount;counter++)
				{
					temp_char=code[counter][counterin];
					code[counter][counterin]=code[counter][counterin+1];
					code[counter][counterin+1]=temp_char;
				}
			}
		}
	}
	
	
	for(int counter=0; counter<sortkey.length(); counter++)
	{
		cout<<left<<setw(2)<<sortkey[counter];
	}	
	cout<<endl;
	
	for(int icount=0; icount<rowcount; icount++)
	{
		for(int jcount=0; jcount<colcount; jcount++)
		{
			cout<<left<<setw(2)<<code[icount][jcount];
		}
		cout<<endl;
	}
	
}

void encryption::print()
{
	cout<<"Encoded message is:"<<endl;
	
	for(int counterout=0;counterout<colcount;counterout++)
	{
		for(int counterin=0;counterin<rowcount;counterin++)
		{
			if(code[counterin][counterout]==' ')
				continue;
			cout<<code[counterin][counterout];
		}
		cout<<" ";
	}
	cout<<endl;
}

//decryption class
decryption::decryption()
{
	key="";
 	enc_message="";
	temp_key="";
	dec_message="";
	sort_key="";
	rowcount=0;
	colcount=0;
	for(int i=0; i<MaxRow;i++)
	{
		for(int j=0; j<MaxCol;j++)
		{
			code[i][j]=' ';
			decode[i][j]=' ';
		}
	}	
}

void decryption::input()
{
	key="";
 	enc_message="";
	temp_key="";
	dec_message="";
	sort_key="";
	rowcount=0;
	colcount=0;
	for(int i=0; i<MaxRow;i++)
	{
		for(int j=0; j<MaxCol;j++)
		{
			code[i][j]=' ';
			decode[i][j]=' ';
		}
	}	
	
	string temp_str="";
	bool correct;
	
	do{
		correct=true;
		fflush(stdin);
		cout<<"Please enter your encrypted message: ";
		getline(cin,enc_message);
		for(int charcount=0;charcount<enc_message.length();charcount++)
		{
			if(enc_message[charcount]!=32 && enc_message[charcount]<48 || enc_message[charcount]>53)
			{
				correct=false;
			}
		}
		
	}while(!correct);
	
	
	//remove numbers,spaces,special characters
    
    do{
    	correct=true;
    	fflush(stdin);
    	cout<<"Please enter your keyword: ";
		cin>>key;
		
		//Checking for numbers and special characters
		for(int charcount=0;charcount<key.length();charcount++)
		{
			if(key[charcount]<65 || key[charcount]>90 && key[charcount]<97 || key[charcount]>122)
			{
				correct=false;
			}
		}
		
		//Checking for dublicates
		for(int charcount=0;charcount<key.length()-1;charcount++)
		{
			for(int counter=charcount+1;counter<key.length();counter++)
			{
				if(key[charcount]==key[counter])
				{
					correct=false;
				}
			}
		}
		
	}while(!correct);
    
}

void decryption::decodemessage()
{
	char temp_char;
	string sortkey=key;
	
	for(int counter=0; counter<sortkey.length();counter++)
	{
		sortkey[counter]=toupper(sortkey[counter]);
	}
	
	for(int counterout=0;counterout<sortkey.length()-1;counterout++)
	{
		for(int counterin=0;counterin<sortkey.length()-counterout-1;counterin++)
		{
			if(sortkey[counterin]>sortkey[counterin+1])
			{
				temp_char=sortkey[counterin];
				sortkey[counterin]=sortkey[counterin+1];
				sortkey[counterin+1]=temp_char;
			}
		}
	}
	
	
	//fill decode table
	colcount=sortkey.length();
	
	rowcount=enc_message.length()/sortkey.length();
	
	int char_count=0;
	for(int icount=0; icount<colcount; icount++)
	{
		int jcount=0;
		while(jcount<rowcount)
		{
			if(enc_message[char_count]!=' ')
			{
				code[jcount][icount]=enc_message[char_count];
				jcount++;
			}
			if(jcount==rowcount-1 && enc_message[char_count]==' ')
			{
				code[jcount][icount]=' ';
				jcount++;
			}
			char_count++;
		}
	}
	temp_key=sortkey;

}

void decryption::desort()
{
	char temp_char;
	
	sort_key=temp_key;
	
	for(int icount=0; icount<rowcount; icount++)
	{
		for(int jcount=0; jcount<colcount; jcount++)
		{
			decode[icount][jcount]=code[icount][jcount];
		}
	}
	
	for(int counter=0; counter<key.length();counter++)
	{
		key[counter]=toupper(key[counter]);
	}
	
	for(int icount=0; icount<temp_key.length(); icount++)
	{
		for(int jcount=0; jcount<temp_key.length(); jcount++)
		{
			if(temp_key[jcount]==key[icount])
			{
				temp_char=temp_key[jcount];
				temp_key[jcount]=temp_key[icount];
				temp_key[icount]=temp_char;
				
				for(int counter=0; counter<rowcount;counter++)
				{
					temp_char=decode[counter][jcount];
					decode[counter][jcount]=decode[counter][icount];
					decode[counter][icount]=temp_char;
				}
			}
		}
	}
	
}

void decryption::print()
{
	bool wrong_input=false;
	enc_message="";
	int row,col;
	
	int char_count=0;
	for(int icount=0; icount<rowcount; icount++)
	{
		for(int jcount=0; jcount<colcount; jcount++)
		{
			if(decode[icount][jcount]==' ')
				continue;
			enc_message+=decode[icount][jcount];
		}
	}
	
	for(int counter=0; counter<enc_message.length()-1;counter+=2)
	{
		row=decryption::convert_chr_int(enc_message[counter]);
		col=decryption::convert_chr_int(enc_message[counter+1]);
		
		dec_message+=table[row][col];
	}
	
	for(int counter=0; counter<dec_message.length();counter++)
	{
		if(dec_message[counter]=='*')
		{
			wrong_input=true;
		}
		
	}
	
	if(!wrong_input)
	{
		cout<<endl;
		
		//sorted message
		for(int counter=0; counter<sort_key.length(); counter++)
		{
			cout<<left<<setw(2)<<sort_key[counter];
		}
		cout<<endl;
		for(int icount=0; icount<rowcount; icount++)
		{
			for(int jcount=0; jcount<colcount; jcount++)
			{
				cout<<setw(2)<<code[icount][jcount];
			}
			cout<<endl;
		}
		cout<<endl;
		
		//unsorted message
		for(int counter=0; counter<temp_key.length(); counter++)
		{
			cout<<left<<setw(2)<<temp_key[counter];
		}
		cout<<endl;
		for(int icount=0; icount<rowcount; icount++)
		{
			for(int jcount=0; jcount<colcount; jcount++)
			{
				cout<<setw(2)<<decode[icount][jcount];
			}
			cout<<endl;
		}
		cout<<endl;
		
		//Coded message
		cout<<enc_message;
		cout<<endl;
		
		//Decoded message
		cout<<"Decoded message is:"<<endl;
		cout<<dec_message<<endl;
	}
	else{
		cout<<"The encrypted code is wrong!"<<endl;
		decryption::input();
		decryption::decodemessage();
		decryption::desort();
		decryption::print();
	}

}

int decryption::convert_chr_int(char chara)
{
	int num;
	switch(chara)
	{
		case '0':
			num=0;
			break;
		case '1':
			num=1;
			break;
		case '2':
			num=2;
			break;
		case '3':
			num=3;
			break;
		case '4':
			num=4;
			break;
		case '5':
			num=5;
			break;
	}
	
	return num;
}
