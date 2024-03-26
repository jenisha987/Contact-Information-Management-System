#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>

// global variables for graphic modes
char p1[10],p2[10],p3[10]; //password
char dteam[7][20]={"Account","Advertisement","Canteen","Developer","Security","Technical"};
char dpost[4][20]={"Manager","Vice-Manager","Staff"};
int no[6];
class File
{
	public:
	
	//--------- Variables for contact information --------
	char team[20];
	char lname[20],fname[20];
	char a[3];
	char con[20];
	char G[2];
	char email[30];
	char add[20];
	char degree[20];
	char post[20];
	char Join[12];
	char Exp[3];
	int ID[4];
	
	//--------- Variables for the counting records --------
//	int no1,no2,no3,no4,no5,no6;
	
	//-------- Name Validation --------
	int namee(int r, int s, char name[20])
	{

		int c=1,d,i;
		       //op:  d=name[k];
         	    //cin>>fname;
 	 	if(name[0]>='A' && name[0]<='Z')
 	   		{
			   for(i=1;i<strlen(name);i++)
 	      		   {  					    
		    			if(name[i]>='a' && name[i]<='z')
		    				{ 
								c=0;
							}				        
		   				else
		   					{	
							   	c=1;
		   					}
          			}
				}
				else
					{ 
						c=1;
					}
		if(c==1)
		{
			outtextxy(r+20, s-20, "Enter Valid Data!");
		}
		return c;
	}

    //-------------Join date-----------------
	int gJoin(int r, int s)
	{
		//Go:
		int d=0;


		for(int i=0;i<strlen(Join);i++)
		{
			if((Join[i]>=48 && Join[i]<=57) || Join[i]=='/')
			{
			}
			else
			{
				outtextxy(r+20, s-20, "Enter Valid Data!");
				//goto Go;
				d=1;
				return d;
			}
		}
			if(i==10)
			{   if( Join[4]=='/' && Join[7]=='/' )
			       {}
			    else
			      {	outtextxy(r+20, s-20, "Enter Valid Data!");
				//goto Go;
					d=1;
					return d;
			       }

			}
			else
			{
				outtextxy(r+20, s-20, "Enter Valid Data!");
				//goto Go;
				d=1;
				return d;

			}
	}


	//-------- Department Validation --------
	int gteam(int r, int s)
	{
		int d=0;
		if(strcmp(dteam[0],team)!=0 && strcmp(dteam[1],team)!=0 && strcmp(dteam[2],team)!=0 && strcmp(dteam[3],team)!=0 && strcmp(dteam[4],team)!=0 && strcmp(dteam[5],team)!=0)
		{
			outtextxy(r-65, s-20, "Enter Valid Data!");
			d=1;
			return d;

		}

	}

	//-------- Age Validation --------
	int age(int r, int s)
	{
		int c;
		int d=1;
		for(int k=0; k<3; k++)
		{
			c=a[k];
			if(c>=48 && c<=57)
			{
				d=0;
			}
	   }
	   	if(strlen(a)>2)
			{ 
			 	d=1;
			}

		if(d==1)
			{
				outtextxy(r+20, s-20, "Enter Valid Data!");
			}
		return d;
	}
	//-------- Gender Validation --------
	int gender(int r, int s)
	{
		int d=0;
		if(G[0]!='M' && G[0]!='F' && G[0]!='O')
		{
			outtextxy(r+20, s-20, "Enter Valid Data!");
			d=1;
			return d;
		}

	}

	//-------- Contact Validation --------
	int contact(int r, int s)
	{
	       //	int count=0;
		int c2=0;
		int c1=0;
		int d=0;
		for(int k=0; k<strlen(con); k++)
		{
			if(con[k]-48>=0 && con[k]-48<=9)
			{
				c2=1;
				if (con[0]-48==9 && (con[1]-48==8 || con[1]-48==7))
				{
					c1=1;
					continue;
				}
			}
			else
			{
				c2=0;
				break;
			}
		}

		if(c2==0 || strlen(con)!=10 || c1==0)
		{
			outtextxy(r+20, s-20, "Enter Valid Data!");
			d=1;
			return d;

		}
	}


	//-------- Email Validating --------
	int eemail(int r, int s)
	{
	    int i=0;
	    int atcount=0,dotcount=0;
	    int at=-1, dot=-1;
	    int d=0;
	    if((email[0]>='a' && email[0]<='z') || (email[0]>='A' && email[0]<='Z'))
	    {
			for(int k=0; k<strlen(email); k++)
	       {
				if(email[k]=='@')
				{
					at=i;
					atcount++;
				}
				if(email[k]=='.')
				{
					dot=i;
					dotcount++;
				}
		   }

		    if(at==-1||dot==-1||atcount>=2||dotcount>=2||dot==strlen(email)-1)
		    {
				outtextxy(r+20, s-20, "Enter Valid Data!");
				d=1;
				return d;
			}

	    }
	    else
	    {
			outtextxy(r+20, s-20, "Enter Valid Data!");
			d=1;
			return d;
		}

   }

   //-------- Address Validating --------
	int addr(int r, int s)
	{
		int d[20];
		int c=0;
		for(int k=0; k<strlen(add); k++)
		{
			d[k]=add[k];
		    if((d[k]>=65 && d[k]<=90) || (d[k]>=97 && d[k]<=122))
		    {
				break;
			}
			else
			{
				outtextxy(r+20, s-20, "Enter Valid Data!");
				c=1;
				return c;

		    }
	    }
	}

	//-------- Post Validation --------
	int poost(int r, int s)
   {
		File f[20];
		ifstream fin;
		//int d,e;
		int d=0;
		int l=0, k=0;
		fin.open("Alldata");
		while(fin)
		{
			fin.read((char*)&f[k],sizeof(File));
			k++;
		}
		fin.close();

		//dub:
	

		if((strcmp(dpost[0],post)==0) || (strcmp(dpost[1],post)==0 ))
		{
			for(l=0;l<k;l++)
			{
				if(strcmp(f[l].post,post)==0)
				{
					if(strcmp(f[l].team,team)==0)
					{
						outtextxy(r+20, s-20, "Enter Valid Data!");
						outtextxy(r+20, s-5, "There is already");
						//goto dub;
						d=1;
						return d;
					}
				}
			}
		}
		else if (strcmp(dpost[2],post)!=0)
		{
			outtextxy(r+20, s-20, "Enter Valid Data!");
			d=1;
			return d;
		} 
   }
   
   
   //-------- Exp Validation --------
    int gExp(int r, int s)
	{
		
		int d=0;
		for(int i=0;i<strlen(Exp);i++)
		{
			if(Exp[i]>=48 && Exp[i]<=57)
			{
			}
			else
			{
				outtextxy(r+20, s-20, "Enter Valid Data!");
			    d=1;
				return d;
				
			}
		}
	}

    void PID()
	{
	    int i,j,k;
		ofstream fout;
		ifstream fin;
		int d[7],id[7];
		d[0]=0,id[0]=3,d[1]=0,id[1]=3,d[2]=0,id[2]=3,d[3]=0,id[3]=3,d[4]=0,id[4]=3,d[5]=0,id[5]=3;
		File F[20];
		
		fin.open("Alldata");
		i=0;
		while(fin)
		{
			fin.read((char*)&F[i],sizeof(File));
			i++;
		}
		for(j=0;j<i;j++)
		{
			for(k=0; k<7; k++)
			{
				if(strcmp(F[j].post,dpost[2])==0)
				{
					if(strcmp(F[j].team,dteam[k])==0)
					id[k]++;
				}
			}
		}
	    
	    for(j=0; j<7; j++)
	    {	    		
		    if(strcmp(team,dteam[j])==0)
			{
				ID[0]=j+1;
	    		ID[1]=j+1;
	    		if(strcmp(post,dpost[0])==0)
	    		{
					ID[2]=d[j];
					ID[3]=1;
	    		}
				else  if(strcmp(post,dpost[1])==0)
	    		{
					ID[2]=d[j];
					ID[3]=2;
		   		}
				else
				{
					ID[2]=d[j];
					ID[3]=id[j];
					id[j]++;
				}
			}
		
	
			else if(id[j]==10)
			{
				id[j]=0;
				d[j]=1;
			}
		}
		
    }


	 

	 
	
	//-------- Idisplay Function --------
	int display(int r, int s, int x, int y)
	{
		int i=5,j=8;
		int re=0;
		char ch;
		do
		{
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, " Profile ");

			//----Output------
		       //	line(0,y-190,50,y-140);line(x-50,0,x,50);

			//----Column 1----
			line(r-305,s-110,r-200,s-110);
			line(r-305,s-15,r-247,s-15);
			gotoxy(i-2,j);
			cout << "Basic Info " ;
			gotoxy(i-2,j+2);
			cout << " Name:" << fname << " " << lname;
			gotoxy(i-2,j+3);
			cout << " Age:" << a ;
			gotoxy(i-2,j+4);
			cout << " Gender:" << G ;
			gotoxy(i-2,j+6);
			cout << "Work "  ;
			gotoxy(i-2,j+8);
			cout << " Department:" << team;
			gotoxy(i-2,j+9);
			cout << " ID:";
			for(int q=0;q<4;q++)
			{cout<<ID[q];
			}
			gotoxy(i-2,j+10);
			cout << " Joined:" << Join;
			gotoxy(i-2,j+11);
			cout << " Experience:"  << Exp <<"yrs";

			//----Column 2----
			line(r-88,s-110,r-30,s-110);
			line(r-88,s-15,r+15,s-15);
			gotoxy(i+24,j);
			cout << " Contact" ;
			gotoxy(i+24,j+2);
			cout << "  Phone no:" << con ;
			gotoxy(i+24,j+3);
			cout << "  Email:" << email ;
			gotoxy(i+24,j+4);
			cout << "  Address:" << add ;
			gotoxy(i+24,j+6);
			cout << " Qualification" ;
			gotoxy(i+24,j+8);
			cout << "  Degree:" << degree ;

			// icon, post, edit and exit
			int rad=15,rad2=27,rad3=40,k;
			for(k=1; k<=2; k++)
			{
			circle(r+250, s-108, rad);
			arc(r+250, s-60, 0, 180, rad2);
			circle(r+250, s-90, rad3);
			rad++;
			rad2++;
			rad3++;
			}
			
			int l=strlen(post)/2;
			gotoxy(72-l,14);
			cout << post;
			gotoxy(70,15);
			cout <<"Post"<<endl;

			settextstyle(0 ,0 ,1);
			outtextxy(r+220, s+20, "1.Edit");
			outtextxy(r+220, s+35, "2.Delete");
			outtextxy(r+250, s+80, "0.Back");



			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			switch(ch)
			{
				case '1':re=1; 
						editf(r,s,x,y);
						cleardevice();
						outtextxy(r-60, s, "Profile Edited");
						delay(1000);
						break;
				case '2':re=2;
						reins();
						cleardevice();
						outtextxy(r-60, s, "Profile Deleted");
						delay(1000);
						ch='0';
						break;
					
				default:break;
			}
			
		}while(ch!='0');
		return re;
	}
	
	//-------- Edit Function --------
	void editf(int r,int s,int x,int y)
	{       
		int i=15,j=6,l;
		char ch;
		do
		{
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, " Edit ");

			//----Column 1----
			gotoxy(i,j);
			cout << "a. First Name:" << fname ;
			gotoxy(i,j+2);
			cout << "b. Last Name:" << lname;
			gotoxy(i,j+4);
			cout << "c. Age:" << a;
			gotoxy(i,j+6);
			cout << "d. Gender:" << G;
			gotoxy(i,j+8);
			cout << "e. Phone no:" << con;
			gotoxy(i,j+10);
			cout << "f. Email:" << email;
			gotoxy(i,j+12);
			cout << "g. Address:" << add;
			gotoxy(i,j+14);
			cout << "h. Degree:" << degree;
			//----Column 2----
			gotoxy(i+30,j);
			cout << "i. Department:" <<team;
			gotoxy(i+30,j+2);
			cout << "j. Post:" << post;
			gotoxy(i+30,j+4);
			cout << "k. Joined:" << Join << endl;
			gotoxy(i+30,j+6);
			cout << "l. Exprs:" << Exp ;

			//----exit----
			settextstyle(0 ,0 ,1);
			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			switch(ch)
			{
				case 'a': //Cursor Point Firstname
						upp:
						int c;
						for(l=0;l<20;l++)
						fname[l]=' ';
						gotoxy(i+14,j);
						cout << ">";
						gotoxy(i+14,j);
						cin >>fname;
						c=namee(r, s, fname);
						if(c==1)
						{
							goto upp;
						}
						break;
			case 'b': //Cursor Point Lastname
					uppp:
					for(l=0;l<20;l++)
					lname[l]=' ';	
					gotoxy(i+13,j+2);
					cout << ">";
					gotoxy(i+13,j+2);
					cin >> lname;
					c=namee(r, s, lname);
					if(c==1)
					{
						goto uppp;
					}
					break;
			case 'c':	//Cursor Point Age
					up1:
					for(l=0;l<3;l++)
					a[l]=' ';
					gotoxy(i+7,j+4);
					cout << ">";
					gotoxy(i+7,j+4);
					cin >>a;
					c=age(r, s);
					if(c==1)
					{
						goto up1;
					}
					break;
			case 'd': //Cursor Point Gender
					up2:
					for(l=0;l<2;l++)
					G[l]=' ';	
					gotoxy(i+10,j+6);
					cout << ">";
					gotoxy(i+10,j+6);
					cin >> G;
					c=gender(r, s);
					if(c==1)
					{
						goto up2;
					}
					break;
			case 'e': //Cursor Point Phone Number
					up3:
					for(l=0;l<20;l++)
					con[l]=' ';	
					gotoxy(i+12,j+8);
					cout << ">";
					gotoxy(i+12,j+8);
					cin >> con;
					c=contact(r, s);
					if(c==1)
					{
						goto up3;
					}
					break;
			case 'f': //Cursor Point Email
					up4:
					for(l=0;l<30;l++)
					email[l]=' ';	
					gotoxy(i+9, j+10);
					cout << ">";
					gotoxy(i+9, j+10);
					cin >> email;
					c=eemail(r, s);
					if(c==1)
					{
						goto up4;
					}
					break;
			case 'g': //Cursor Point Address
					up5:
					for(l=0;l<20;l++)
					add[l]=' ';	
					gotoxy(i+11, j+12);
					cout << ">";
					gotoxy(i+11, j+12);
					cin >> add;
					c=addr(r,s);
					if(c==1)
					{
						goto up5;
					}
					break;
			case 'h': //Cursor Point Degree
			       	for(l=0;l<20;l++)
					degree[l]=' ';
					gotoxy(i+10, j+14);
					cout << ">";
					gotoxy(i+10, j+14);
					cin >> degree;
					break;
			case 'i': //Cursor Point Team
					outtextxy(r, s-20, "Department Cannot be changed!");
					getch();
					break;
			case 'j'://Cursor Point Post
					outtextxy(r+20, s-20, "Post Cannot be changed!");
					getch();
					break;
			case 'k'://Cursor Point Date
					up8:
					for(l=0;l<12;l++)
					Join[l]=' ';	
					gotoxy(i+40, j+4);
					cout << ">";
					gotoxy(i+40, j+4);
					cin >> Join;
					c=gJoin(r, s);
					if(c==1)
					{
						goto up8;
					}
					break;
			case 'l'://Cursor Point Experience
					up9:
					for(l=0;l<3;l++)
					Exp[l]=' ';	
					gotoxy(i+39, j+6);
					cout << ">";
					gotoxy(i+39, j+6);
					cin >> Exp;
					c=gExp(r, s);
					if(c==1)
					{
						goto up9;
					}
					break;
			default: break;
			}

		 }while(ch!='0');
	}
	
	
	//-------- Counting Records --------
	void dispteam()
	{ 
		File f[20];
		char dteam[7][20]={"Account","Advertisement","Canteen","Developer","Security","Technical"};
		int i=0,j=0;
		no[0]=0; no[1]=0; no[2]=0; no[3]=0; no[4]=0; no[5]=0;
		ofstream fout;
		ifstream fin;
		fin.open("Alldata");
		while(fin)
		{
			fin.read((char*)&f[i],sizeof(File));
			i++;
		}
	for(j=0;j<i;j++)
	{
		if(strcmp(f[j].team,dteam[0])==0)
		{       
				no[0]++;
			
			}
			else if(strcmp(f[j].team,dteam[1])==0)
			{
				no[1]++;
		       
			}
			else if(strcmp(f[j].team,dteam[2])==0)
			{
			    no[2]++;
		    
			}
			else if(strcmp(f[j].team,dteam[3])==0)
			{
			    no[3]++;
		    
			}
			else if(strcmp(f[j].team,dteam[4])==0)
			{
			    no[4]++;
		    
			}
			else if(strcmp(f[j].team,dteam[5])==0)
			{
			    no[5]++;
		
	   		}
   	 
	}
}
	
	
	void displayr(int q, int r, int s)

	{

		ifstream fin;  
		File Z[20];
  		int i,j,k,l,m,w,gh;
  		//---------List of Records--------

		// Table head
		settextstyle(0, 0, 1);
		outtextxy(r-265, s-145, " ID ");               // difference between line and text is 10 pixel
		outtextxy(r-100, s-145, " Name ");
		outtextxy(r+190, s-145, " Post ");
		line(r-300, s-135, r+300, s-135);
		outtextxy(r+250, s+80, "0.Back");
                                      
        fin.open("Alldata");
        i=0;
	while(fin)
        {
			fin.read((char*)&Z[i],sizeof(File));
            i++;
		}
		fin.close();

		  gh=8;
		for(j=0;j<i;j++)
		{   
			if(strcmp(Z[j].team,dteam[q])==0)
            { 
				if(strcmp(Z[j].post,dpost[0])==0) 
                {   
					// Table content
					    gh=8;
					
						gotoxy(8,gh);						
						for(w=0;w<4;w++)
						cout<<Z[j].ID[w];
						gotoxy(27,gh);
						cout << Z[j].fname << " " << Z[j].lname;
						gotoxy(62,gh);
						cout << Z[j].post;
						gh++;
					
					goto po;
				}																							
			}
		}
		po:
		for(k=0;k<i;k++)
		{ 
			if((strcmp(Z[k].team,dteam[q])==0) && (strcmp(Z[k].post,dpost[1])==0))
			{ 
				// Table content
				gotoxy(8,gh);
				for(w=0;w<4;w++)
				cout<<Z[k].ID[w];
				gotoxy(27,gh);
				cout << Z[k].fname << " " << Z[k].lname;
				gotoxy(62,gh);
				cout << Z[k].post;
				gh++;
					
				goto op;												    
			}											       
		}
		op:
		for(l=0;l<i;l++)
		{ 
			if((strcmp(Z[l].team,dteam[q])==0) && (l!=j) && (l!=k))														        
		 	{					      			     
				// Table content
				gotoxy(8,gh);
				for(w=0;w<4;w++)
				cout<<Z[l].ID[w];
				gotoxy(27,gh);
				cout << Z[l].fname << " " << Z[l].lname;
				gotoxy(62,gh);
				cout << Z[l].post;
				gh++;
				
					
			}   
													
		} 
													
	}

	//-------- Reinitializing --------
	void reins()
	{	
		int i;
		for(i=0;i<20;i++)
		team[i]=' ';
		
		for(i=0;i<20;i++)
		fname[i]=' ';
		
		for(i=0;i<20;i++)
		lname[i]=' ';
		
		for(i=0;i<30;i++)
		email[i]=' ';
		
		for(i=0;i<20;i++)
		add[i]=' ';
		
		for(i=0;i<20;i++)
		degree[i]=' ';
		
		for(i=0;i<20;i++)
		post[i]=' ';
		
		for(i=0;i<3;i++)
		a[i]=' ';
		
		for(i=0;i<20;i++)
		con[i]=' ';
		
		for(i=0;i<2;i++)
		G[i]=' ';
		
		for(i=0;i<12;i++)
		Join[i]=' ';
		
		for(i=0;i<3;i++)
		Exp[i]=' ';		
		
	}

};

File p,v;
















class graph
{     public:
	char name[26];







	//-------- New 1st function --------
	void newf(int r,int s,int x,int y)
	{
		char ch;
		
		do
		{
			cleardevice();
			p.reins();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, "  ");
			settextstyle(0, 0, 2);
			outtextxy(r-110, s-100, "+ New Contact");

			// icon, post, edit and exit
			int rad=5,rad2=13,rad3=20,k;
			for(k=1; k<=2; k++)
			{
			circle(r, s-150, rad);
			arc(r, s-127, 0, 180, rad2);
			circle(r, s-140, rad3);
			rad++;
			rad2++;
			rad3++;
			}

			settextstyle(0, 0, 1);
			outtextxy(r-95, s-40, "Enter a Department Name!");
			line(r-120, s-65, r+120, s-65);
			line(r-120, s-45, r+120, s-45);
			settextstyle(0,0,1);
			outtextxy(r-125, s-55, "1.");
			arc(r+120, s-55, 270, 90, 10);
			arc(r-120, s-55, 90, 270, 10);

			//eye glass
			circle(r+115, s-55, 5);
			line(r+118, s-52, r+123, s-48);

			//----exit----
			settextstyle(0 ,0 ,1);

			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			if(ch!='1' && ch!='0')
			{
			outtextxy(r-60, s, "Invalid Input!");
			delay(250);






			}

			if(ch=='1')
			{
				up0:
				int c;
				gotoxy(35,12);
				cout<< ">" <<endl;
				gotoxy(35,12);
				cin>>p.team;
				c=p.gteam(r,s);
				if(c==1)
				{
					goto up0;
				}

				newfu(r,s,x,y);
			}


		}while(ch!='0');
	}

	//-------- + New 2nd function --------
	void newfu(int r,int s,int x,int y)
	{
	    int i=15,j=6;
	    int re;
		char ch;
		ofstream fout;
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, " + New Contact ");

			//----Column 1----
			gotoxy(i-3,j);
			cout << "1.  First Name: " ;
			gotoxy(i,j+2);
			cout << " Last Name: " ;
			gotoxy(i,j+4);
			cout << " Age: " ;
			gotoxy(i,j+6);
			cout << " Gender:      (M or F or O)" ;
			gotoxy(i,j+8);
			cout << " Phone no: " ;
			gotoxy(i,j+10);
			cout << " Email: " ;
			gotoxy(i,j+12);
			cout << " Address: " ;
			gotoxy(i,j+14);
			cout << " Degree: " ;

			//----Column 2----
			gotoxy(i+30,j);
			cout << " Department: " ;
			gotoxy(i+30,j+2);
			cout << " Post: " ;
			gotoxy(i+30,j+4);
			cout << " Joined:" <<    "YYYY/MM/DD"  << endl;
			gotoxy(i+30,j+6);
			cout << " Exprs: "  <<" yrs"<< endl;

			//----exit----
			settextstyle(0 ,0 ,1);
			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;
			char name[2];

			switch(ch)
			{
				case '1': //Cursor Point Firstname
					upp:
					int c;
					gotoxy(i+12,j);
					cout << ">";
					gotoxy(i+12,j);
					cin >> p.fname;
					c=p.namee(r, s, p.fname);
					if(c==1)
					{
						goto upp;
					}

					//Cursor Point Lastname
					uppp:
					gotoxy(i+11,j+2);
					cout << ">";
					gotoxy(i+11,j+2);
					cin >> p.lname;
					c=p.namee(r, s, p.lname);
					if(c==1)
					{
						goto uppp;
					}

					//Cursor Point Age
					up1:
					gotoxy(i+5,j+4);
					cout << ">";
					gotoxy(i+5,j+4);
					cin >>p.a;
					c=p.age(r, s);
					if(c==1)
					{
						goto up1;
					}


					//Cursor Point Gender
					up2:
					gotoxy(i+8,j+6);
					cout << ">";
					gotoxy(i+8,j+6);
					cin >> p.G;
					c=p.gender(r, s);
					if(c==1)
					{
						goto up2;
					}

					//Cursor Point Phone Number
					up3:
					gotoxy(i+10,j+8);
					cout << ">";
					gotoxy(i+10,j+8);
					cin >> p.con;
					c=p.contact(r, s);
					if(c==1)
					{
						goto up3;
					}

					//Cursor Point Email
					up4:
					gotoxy(i+7, j+10);
					cout << ">";
					gotoxy(i+7, j+10);
					cin >> p.email;
					c=p.eemail(r, s);
					if(c==1)
					{
						goto up4;
					}


					//Cursor Point Address
					up5:
					gotoxy(i+9, j+12);
					cout << ">";
					gotoxy(i+9, j+12);
					cin >> p.add;
					c=p.addr(r, s);
					if(c==1)
					{
						goto up5;
					}

					//Cursor Point Degree
					gotoxy(i+8, j+14);
					cout << ">";
					gotoxy(i+8, j+14);
					cin >> p.degree;

					//Cursor Point Department
					gotoxy(i+42, j);
					cout << p.team;

					//Cursor Point Post
					up6:
					gotoxy(i+36, j+2);
					cout << ">";
					gotoxy(i+36, j+2);
					cin >> p.post;
					c=p.poost(r, s);
					if(c==1)
					{
						goto up6;
					}

					//Cursor Point Date
					up7:
					gotoxy(i+38, j+4);
					cout << ">";
					gotoxy(i+38, j+4);
					cin >> p.Join;
					c=p.gJoin(r,s);
					if(c==1)
					{
						goto up7;
					}


					//Cursor Point Experience
					up8:
					gotoxy(i+37, j+6);
					cout << ">";
					gotoxy(i+37, j+6);
					cin>> p.Exp;
					c=p.gExp(r, s);
					if(c==1)
					{
						goto up8;
					}

		    		p.PID();

					//done button
					arc(r+240, s+20, 270, 90, 10);
					arc(r+210, s+20, 90, 270, 10);
					line(r+210, s+10, r+240, s+10);
					line(r+210, s+30, r+240, s+30);
					settextstyle(0 ,0 ,1);
					outtextxy(r+211, s+18, "DONE");
					outtextxy(r+185, s+18, "?");
					getch();
					
					re=p.display(r,s,x,y);
					
					if(re==0 || re==1)
					{
						fout.open("Alldata",ios::app);
						fout.write((char*)&p,sizeof(File));
						fout.close();
					}
					
					break;

				default: break;
			}



	}

	//-------- Viewfunction --------
	void viewf(int r, int s, int x, int y, char cr)
	{

		int gd=DETECT, gm;
		initgraph(&gd, &gm,"c:\\turboc3\\bgi");
		char ch[4];
		int chh[4];
		int comp;
		int i=0,re,a,f;
		File F[20];
		ifstream fin;
		ofstream fout;
		do
		{
		cleardevice();
		switch(cr)
		{
		 case 'a':settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Account ");
			  f=0;
			  v.displayr(f,r,s);
			  break;
		 case 'b':settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Advertisement ");
              f=1; 
			  v.displayr(f,r,s);
			  break;
		 case 'c': settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Canteen ");
	      f=2;
			  v.displayr(f,r,s);
			  break;
		 case 'd': settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Developer ");
			  f=3;
			  v.displayr(f,r,s);
			  break;
		 case 'e': settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Security ");
			  f=4;
			  v.displayr(f,r,s);
			  break;
		 case 'f': settextstyle(0, 0, 2);
			  outtextxy(r-300, s-200, " Technical ");
			  f=5;
			  v.displayr(f,r,s);
			  break;
		 default: break;
		 }

         fin.open("Alldata");
		 while(fin) 		 
		 {
		 		fin.read((char*)&F[i],sizeof(File));
		 		i++;
		 }
         fin.close(); 
		  
		//seperation line
		line(0, y-140, x, y-140);
		gotoxy(1,23);
		line(0, y, x, y);
		cout << "Enter the corresponding 'ID' number to select or '0' for exit:" <<endl;
		cout << ">" ;
		gotoxy(1,24);
		cin >> ch;
		

		int c=0;
	   	for(int k=0; k<4; k++)
		{	
			comp=ch[k];
			if(comp>=48 && comp<=57)
			{
				c=0;
			}
			else
			c=1;
		}
		
		if(c==0)
		{
			for(k=0; k<4; k++)
			{
				comp=ch[k];
				chh[k]=comp-48;
				
			}
			
		for(k=0; k<i; k++)
			{   
				if((F[k].ID[0]==chh[0]) && (F[k].ID[1]==chh[1]) && (F[k].ID[2]==chh[2]) && (F[k].ID[3]==chh[3]))
			     	{   a=k;
			     		re=F[k].display(r,s,x,y);
			     		if(re==1)
							{
								fout.open("Alldata");
								for(int l=0;l<i-1;l++)
									{   
										fout.write((char*)&F[l],sizeof(File));
						 			}
								fout.close();
							}
					
						if(re==2)
							{
								fout.open("Alldata");
								for(int l=0;l<i-1;l++)
									{
										if(l!=a)
											{
												fout.write((char*)&F[l],sizeof(File));
											}
									}
								fout.close();
								ch[0]='0';		
							}
						break;
					}
				 			 
			}
			
		}
		
		if(c==1 && ch[0]!='0')
		{
			outtextxy(r-60, s+60, "Invalid Input!");
			delay(250);	
		}
		
		}while(ch[0]!='0');
 	}

		// -------search function--------
	void search(int r, int s, int x, int y)
	{
		
		cleardevice();
		char ch;
		char name[20];
		char cfname[20],clname[20];
		int i, j;
		int re,a;
		ifstream fin;
		ofstream fout;
		File F[20];
		


		do
		{  cleardevice();
		settextstyle(0, 0, 2);
		outtextxy(r-300, s-200, "  ");
		settextstyle(0, 0, 2);
		outtextxy(r-110, s-100, "Search Contact");

		settextstyle(0, 0, 1);
		outtextxy(r-85, s-40, "Enter a person's Name!");
		line(r-120, s-65, r+120, s-65);
		line(r-120, s-45, r+120, s-45);
		settextstyle(0,0,1);
		outtextxy(r-125, s-55, "1.");
		arc(r+120, s-55, 270, 90, 10);
		arc(r-120, s-55, 90, 270, 10);

		//eye glass
		circle(r+115, s-55, 5);
		line(r+118, s-52, r+123, s-48);

		//exit
		settextstyle(0 ,0 ,1);
		outtextxy(r+250, s+80, "0.Back");



		//separtionline
		line(0, y-140, x, y-140);
		gotoxy(1,23);
		line(0, y, x, y);
		cout << "Enter the corresponding number to select:" <<endl;
		gotoxy(1,24);
		cout<<">";
		gotoxy(1,24);
		cin >> ch;
		if(ch=='1')
		{
			gotoxy(27,12);
			cout<< ">" <<endl;
			gotoxy(27,12);
			cin >> cfname;
			cin >> clname;
			
			//reading alldata
			i=0;
			fin.open("Alldata");
			while(fin)
			{
				fin.read((char*)&F[i],sizeof(File));
				i++;
			}
			fin.close();
			
			
			//comparing name to display
			int check=0;
			for(j=0;j<i-1;j++)
			{
				if(strcmp(cfname,F[j].fname)==0 && strcmp(clname,F[j].lname)==0)
				{   a=j;
					check=1;
					re=F[j].display(r,s,x,y);
					
					if(re==1)
					{
						fout.open("Alldata");
						for(int l=0;l<i-1;l++)
						{   
							
						 	fout.write((char*)&F[l],sizeof(File));
						 	
						}
						fout.close();
					}
					
					if(re==2)
					{
						fout.open("Alldata");
						for(int l=0;l<i-1;l++)
						{
							if(l!=a)
							{
								
								fout.write((char*)&F[l],sizeof(File));
							}
						}
						fout.close();		
					}
					break;
				}
			
				
			}
			
			if(check==0)
				{ 	outtextxy(r-70,s," Contact Not Found! ");
					delay(500);
				}
		}

		if(ch!='0' && ch!='1')
		{
			outtextxy(r-60,s," Invalid Input! ");
			delay(500);
		}



		}while(ch!='0');
	}

	//-------- Department --------
	void department(int r, int s, int x, int y)
	{       char ch;
		do
		{       cleardevice();
		    v.dispteam();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, " Departments ");


			//---------List of Records--------

			// Table head
			settextstyle(0, 0, 1);
			outtextxy(r-265, s-145, " SN ");               // difference between line and text is 10 pixel
			outtextxy(r-100, s-145, " Name ");
			outtextxy(r+160, s-145, " Total Records ");
			line(r-300, s-135, r+300, s-135);
			outtextxy(r+250, s+80, "0.Back");

			// Table content

			gotoxy(9,8);
			cout<<" a";
			gotoxy(27,8);
			cout << "Account";
			gotoxy(67,8);
			cout << no[0];

			gotoxy(9,9);
			cout<<" b";
			gotoxy(27,9);
			cout << "Advertisement";
			gotoxy(67,9);
			cout << no[1];

			gotoxy(9,10);
			cout<<" c";
			gotoxy(27,10);
			cout << "Canteen";
			gotoxy(67,10);
			cout << no[2];

			gotoxy(9,11);
			cout<<" d";
			gotoxy(27,11);
			cout << "Developer";
			gotoxy(67,11);
			cout << no[3];

			gotoxy(9,12);
			cout<<" e";
			gotoxy(27,12);
			cout << "Security";
			gotoxy(67,12);
			cout << no[4];

			gotoxy(9,13);
			cout<<" f";
			gotoxy(27,13);
			cout << "Technical";
			gotoxy(67,13);
			cout << no[5];



			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			switch(ch)
			{
				case 'a':viewf(r,s,x,y,ch);
					break;
				case 'b':viewf(r,s,x,y,ch);
					break;
				case 'c':viewf(r,s,x,y,ch);
					break;
				case 'd':viewf(r,s,x,y,ch);
					break;
				case 'e':viewf(r,s,x,y,ch);
					break;
				case 'f':viewf(r,s,x,y,ch);
					break;
				default:break;
			}

		}while(ch!='0');
	}


	//----------------Homepage------------------------
	void homepage(int r, int s, int x, int y)
	{  
		char c;
		
		//title
		settextstyle(0, 0, 2);
		outtextxy(r-300, s-200, " Contact Information Management System ");

		//side menu
		settextstyle(0, 0, 1);
		outtextxy(r-290, s-150, " 1. + New                   |");
		outtextxy(r-290, s-135, " 2. O- Search               |");
		outtextxy(r-290, s-120, " 3. Departments             |");
		outtextxy(r-290, s-105, "  - a. Account              |");
		outtextxy(r-290, s-90,  "  - b. Advertisement        |");
		outtextxy(r-290, s-75,  "  - c. Canteen              |");
		outtextxy(r-290, s-60,  "  - d. Developer            |");
		outtextxy(r-290, s-45,  "  - e. Security             |");
		outtextxy(r-290, s-30,  "  - f. Technical            |");
		outtextxy(r-290, s-15,  " 4. About                   |");
		outtextxy(r-290, s,     " 5. Setting                 |");
		outtextxy(r-290, s+15,  "                            |");
		outtextxy(r-290, s+30,  "                            |");
		outtextxy(r+250, s+80, " 0.Back ");

		//counting records
		v.dispteam();


		//---------List of teams--------

		// Table head
		outtextxy(r-40, s-145, " SN ");               
		outtextxy(r+20, s-145, " Department Name ");
		outtextxy(r+190, s-145, " Total Records ");
		line(r-45 , s-135, x-8, s-135);

		// Table content
		gotoxy(36,8);
		cout << " a       Account ";
		//line(r-45, s-115, x-8, s-115);
		gotoxy(70,8);
		cout << no[0];

		gotoxy(36,9);
		cout << " b       Advertisement  ";
		//line(r-45, s-95, x-8, s-95);
		gotoxy(70,9);
		cout << no[1];

		gotoxy(36,10);
		cout << " c       Canteen  ";
		//line(r-45, s-75, x-8, s-75);
		gotoxy(70,10);
		cout << no[2];
		
		gotoxy(36,11);
		cout << " d       Developer  ";
		//line(r-45, s-55, x-8, s-55);
		gotoxy(70,11);
		cout << no[3];

		gotoxy(36,12);
		cout << " e       Security   ";
		//line(r-45, s-35, x-8, s-35);
		gotoxy(70,12);
		cout << no[4];
	
		gotoxy(36,13);
		cout << " f       Technical  ";
		//line(r-45, s-15, x-8, s-15);
		gotoxy(70,13);
		cout << no[5];

		//separtionline
		line(0, y-140, x, y-140);
		gotoxy(1,23);
		line(0, y, x, y);


	}

	//-------- Password Changing --------
	void pass(int r, int s, int x, int y)
	{
		char ch;
		ofstream fout;
		ifstream fin;
		int c=0;
		do
		{
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, "Change Password");

			//box and password change box
			line(r-120,s-120,r+120,s-120);
			arc(r-120, s-110, 90, 180, 10);
			arc(r+120, s-110, 0, 90, 10);

			gotoxy(33,10);
			cout<<"Current Password";
			line(r-65,s-63,r+65,s-63);
			gotoxy(31,11);
			cout<< "1.";

			gotoxy(33,14);
			cout<< "New Password";
			line(r-65,s+2,r+65,s+2);

			gotoxy(28,17);
			cout<< "Enter 6 character password!";
			line(r-130, s-110, r-130, s+25);
			line(r+130, s-110, r+130, s+25);
			arc(r-120, s+25, 180, 270, 10);
			arc(r+120, s+25, 270, 0, 10);
			line(r-120, s+35, r+120, s+35);
			
			settextstyle(0, 0, 1);
			outtextxy(r+250, s+80, "0.Back");


            char cha;
            int k=0;
			fin.open("password.txt");
   			while(fin)
  				{ 	
				  	fin>>cha;
    				p1[k]=cha;
    				k++;
   				}
   	
   			fin.close();
   			for(int j=0;j<k-1;j++)
   			p3[j]=p1[j];
            
			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;
			if(ch=='1')
			{
				gotoxy(33,11);
				cout<< ">" <<endl;
				gotoxy(38,11);
				cin >> p2;

			    if(strcmp(p3,p2)!=0)
			     	c=1;

				if(c==0)
				{   up:
					gotoxy(33,15);
					cout<< ">";
					gotoxy(38,15);
					cin>>p1;
					if(strlen(p1)!=6)
						{
								gotoxy(33,19);
								cout<<"Password Is Weak" ;
								delay(500);
                                goto up;
						}	
					
					fout.open("password.txt");
					fout<<p1;
					fout.close();
					gotoxy(33,19);
					cout<<"Password Changed" ;
					delay(500);

				}


				if(c==1)
				{
					gotoxy(33,19);
					cout<<"Incorrect Password!" ;
					delay(500);
				}
			}


			if(ch!='0' && ch!='1')
			{
				gotoxy(35,19);
				cout<< "Invalid Input!" ;
				delay(500);
			}

		}while(ch!='0');
	}

	
	

	//-------- About and About Us --------
	void about1(int r, int s, int x, int y)
	{       
		char ch;
		do
		{       
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, "About");
			
			//middle text
			settextstyle(0, 0, 1);
			outtextxy(45,80,  "This is ' Contact Information Management System '. Here are some guides:");
			outtextxy(45,110, "'>'     - It is a cursor in this program. It will show you location of ");
			outtextxy(45,130, "          cursor at the time.");
			outtextxy(45,160, "'1.'    - They are the numbers to select a given option.");
			outtextxy(45,190, "'0'     - Zero is specificly assigned for going back.");
			outtextxy(45,220, "'Posts' - There are only 3 types of posts (Manager, Vice-Manager & Staff).");
			outtextxy(45,250, "Setting     - Here you can find more information about us and can change");
			outtextxy(45,265, "              login password also.");
			outtextxy(45,295, "'Exp'   - System will accept entered experience year as '01', '11','20'");
			
			settextstyle(0 ,0 ,1);
			outtextxy(r+250, s+70, "1.Next");
			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;
			
			if(ch=='1')
			{
				cleardevice();
				settextstyle(0, 0, 2);
				outtextxy(r-300, s-200, "About");
				settextstyle(0, 0, 1);
				outtextxy(45,80,  "More Guides");
				outtextxy(45,110, "'+ New' - It is for creating new contact information records.");
		//		outtextxy(45,130, ".");
				outtextxy(45,160, "'O- Search'   - It is for searching contact information records.");
				outtextxy(45,190, "'Department   - Department will show you number of record of Departments.'");
		/*		outtextxy(45,220, "");
				outtextxy(45,250, "Setting     - Here you can find more information about us and can change");
				outtextxy(45,265, "              login password also.");
				outtextxy(45,295, "'0'     - Zero is specificly assigned for going back.");*/
				line(0, y-140, x, y-140);
				settextstyle(0 ,0 ,1);
				outtextxy(r+230, s+60, "Press Enter.");
				getch();
			}

			if(ch!='0' && ch!='1')
			{       settextstyle(0,0,1);
				outtextxy(r-60,s," Invalid Input! ");
				delay(500);
			}
		}while(ch!='0');
	}
	
	void about2(int r, int s, int x, int y)
	{       
		char ch;
		do
		{       
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, "About Us");
			
			//middle text
			settextstyle(0, 0, 1);
			outtextxy(45,80, "The Topic of out project is ' Contact Information Management System '");
			outtextxy(45,100, "   Group Members are:");
			outtextxy(45,115, "     1. Jenisha Shrestha");
			outtextxy(45,130, "     2. Kritima Shrestha");
			outtextxy(45,145, "     3. Rabin Thimi");
			outtextxy(45,160, "     4. Rajesh Hamal");
			outtextxy(45,180, "This is our Third Semester Project. In this programme user can save ");
			outtextxy(45,195, "contact informations of many persons of an organization. User can add,");
			outtextxy(45,210, "edit, search and delete the informations in it.");
			
			
			settextstyle(0 ,0 ,1);
			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			if(ch!='0')
			{       settextstyle(0,0,1);
				outtextxy(r-60,s," Invalid Input! ");
				delay(500);
			}
		}while(ch!='0');
	}
	
	
	//-------- Setting --------
	void setting(int r, int s, int x, int y)
	{
		char ch;
		do
		{
			cleardevice();
			settextstyle(0, 0, 2);
			outtextxy(r-300, s-200, "Setting");
			settextstyle(0, 0, 1);
			outtextxy(r-250,s-170,"1. Change Password");
			outtextxy(r-250,s-155,"2. About us");	
			settextstyle(0 ,0 ,1);
			outtextxy(r+250, s+80, "0.Back");

			//separtionline
			line(0, y-140, x, y-140);
			gotoxy(1,23);
			line(0, y, x, y);
			cout << "Enter the corresponding number to select:" <<endl;
			gotoxy(1,24);
			cout<<">";
			gotoxy(1,24);
			cin >> ch;

			if(ch=='1')
			{
			       pass(r, s, x, y);
			}
			
			if(ch=='2')
			{
				about2(r, s, x, y);
			}

			if(ch!='0' && ch!='1' && ch!='2')
			{
				outtextxy(r-60,s," Invalid Input! ");
				delay(500);
			}
		}while(ch!='0');
	}
	




};


int main()
{  clrscr();
   ifstream fin;
   ofstream fout;
   int gd=DETECT, gm;
   initgraph(&gd, &gm,"c:\\turboc3\\bgi");
   int x = getmaxx();
   int r = x/2;
   int y = getmaxy();
   int s = y/2;
   char ch;
   graph g;

   do{
   //-----Login------
   cleardevice();

   //title
   settextstyle(0, 0, 2);
   outtextxy(r-300, s-200, " Contact Information Management System ");
   settextstyle(0, 0, 1);
  // outtextxy(r-125, s-55, "1.");
   outtextxy(r-130, s-20, "Enter a Password or ' 0 ' to Exit!");

   //----- Lock Symbol -----
   line(r-15,s-100,r+15,s-100);
   line(r-15,s-80,r-15,s-100);
   line(r+15,s-80,r+15,s-100);
   line(r-15,s-80,r+15,s-80);
   arc(r,s-110,0,180,10);
   arc(r,s-110,0,180,5);
   line(r-10,s-100,r-10,s-110);
   line(r+10,s-100,r+10,s-110);
   line(r-5,s-100,r-5,s-110);
   line(r+5,s-100,r+5,s-110);

   //----- Circle -----
   int rad=30;
   for(int j=0; j<2; j++)
   {
   circle(r,s-100,rad);
   rad++;
   }

   //-----Entry Box-----
   line(r-120, s-50, r+120, s-50);
   line(r-120, s-30, r+120, s-30);
   arc(r+120, s-40, 270, 90, 10);
   arc(r-120, s-40, 90, 270, 10);
   outtextxy(r+250, s+80, "0.Exit");

   //----- Reading Password and Saving in p1 -----
   
   int k=0;
   char cha;
   fin.open("password.txt");
   while(fin)
  { fin>>cha;
    p1[k]=cha;
    k++;
   }
   gotoxy(1,23);
   fin.close();
   for(j=0;j<k-1;j++)
   p3[j]=p1[j];


   //----- Password input and check -----
   gotoxy(38,13);
   cin>>p2;

   int c=1;
   if(strcmp(p2,p3)==0)
   {
   c=0;
   }
    if(p2[0]=='0')
   c=2;
   
   if(c==1)
   {
	outtextxy(r-75, s, "Incorrect Password!");
	delay(1000);
   }


   if(c==0)
   {    cleardevice();
 
 	do
	{	cleardevice();
		g.homepage(r,s,x,y);


		cout<< "Enter the corresponding number to select: " << endl;
		gotoxy(1,24);
		cout<<">";
		gotoxy(1,24);
		cin >> ch;
		switch(ch)
		{
			case '1'://new
				g.newf(r,s,x,y);
				break;
			case '2'://search
				g.search(r,s,x,y);
				break;
			case '3'://department
				g.department(r,s,x,y);
				break;

			case '4'://about us
				g.about1(r,s,x,y);
				break;
			case '5'://setting
				g.setting(r,s,x,y);
				break;
			case 'a'://account
				g.viewf(r,s,x,y,ch);
				break;
			case 'b'://advertisement
				g.viewf(r,s,x,y,ch);
				break;
			case 'c'://canteen
				g.viewf(r,s,x,y,ch);
				break;
			case 'd'://developer
				g.viewf(r,s,x,y,ch);
				break;
			case 'e'://security
				g.viewf(r,s,x,y,ch);
				break;
			case 'f'://technical
				g.viewf(r,s,x,y,ch);
				break;

			default:break;
		 }

	}while(ch!='0');
   }

   }while(p2[0]!='0');

   return 0;
}


