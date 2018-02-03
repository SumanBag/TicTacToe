#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
char mtx[3][4];  //the matrix
int tie();
void katumkutum();
int Win(char ch);
void main()
{ int i,j,k=1,win,R,C,tiee;
  char P1[10],P2[10],c;
  cout<<"\tIt is a funny game!!."<<endl;
  cout<<"\nRules: "<<"You have to enter the Row and Column number,";
  cout<<"\n"<<"       of the box you choose."<<endl;
  cout<<"\nEnter the name of player1:";
  gets(P1);
  cout<<"\nEnter the name of player2:";
  gets(P2);
  cout<<"\nNow it's play time.";
  cout<<"\n"<<P1<<" takes 'X'.";
  cout<<"\n"<<P2<<" takes 'O'.";
  select:
  cout<<"\nPress 'c' to cntinue:";
  cin>>c;
  if(c=='c'||c=='C')
  {clrscr();
  }
  else
  { goto select;
  }
  for(i=0;i<3;i++)    //loop to fill space in matrix
  { for(j=0;j<3;j++)
	 { mtx[i][j]=' ';
	 }
  }
  for(k=1;k>0;k++)
  { for(i=1;i<=2;i++)
	 { katumkutum();
		win=0;
		if(i==1) //player1
		{ cout<<"\n"<<P1<<" your turn:";
		  enter1:
		  cout<<"\nRow:";
		  cin>>R;
		  cout<<"\nColumn:";
		  cin>>C;
		  if(mtx[R][C]!=' ')
		  { cout<<"\nThis place have been used, try again!!";
			 goto enter1;
		  }
		  else  
		  { mtx[R][C]='X';
		  }
		  clrscr();
		  tiee=tie();
		  if(Win('X')||tiee==1)
		  { win++;
			 goto pos;
		  }
		}
		else  //player2
		{ cout<<"\n"<<P2<<" your turn:";
		  enter2:
		  cout<<"\nRow:";
		  cin>>R;
		  cout<<"\nColumn:";
		  cin>>C;
		  if(mtx[R][C]!=' ')
		  { cout<<"\nThis place have been used, try again!!";
			 goto enter2;
		  }
		  else
		  { mtx[R][C]='O';
		  }
		  clrscr();
		  tiee=tie();
		  if(Win('O')||tiee==1)
		  { win++;
			 goto pos;
		  }
		}
		pos:
		if(win==1)
		 break;
	 }
	 if(win==1)
	 { break;
	 }
  }
  if(i==1&&tiee==0)
  { katumkutum();
	 cout<<endl<<P1<<" you won the match!!!";
  }
  else if(tiee==1)
  { katumkutum();
	 cout<<"\nThe match is tie!!!!";
  }
  else
  { katumkutum();
	 cout<<endl<<P2<<" you won the match!!!";
  }
}
void katumkutum()  //function for katumkutum box
{ cout<<"    "<<"0   1   2"<<endl;
  cout<<"0.  "<<mtx[0][0]<<" | "<<mtx[0][1]<<" | "<<mtx[0][2]<<endl;
  cout<<"    "<<"_"<<"___"<<"_"<<"___"<<"_"<<endl;
  cout<<"1.  "<<mtx[1][0]<<" | "<<mtx[1][1]<<" | "<<mtx[1][2]<<endl;
  cout<<"    "<<"_"<<"___"<<"_"<<"___"<<"_"<<endl;
  cout<<"2.  "<<mtx[2][0]<<" | "<<mtx[2][1]<<" | "<<mtx[2][2]<<endl;
}
int Win(char ch) //function to check the winner 
{ int flag,i;
  for(i=0;i<3;i++)  //row
  { flag=0;
	 if(mtx[i][0]==ch&&mtx[i][0]==mtx[i][1]&&mtx[i][1]==mtx[i][2])
	 { flag++;
		break;
	 }
  }
  if(flag!=1) //column
  { for(i=0;i<3;i++)
	 { flag=0;
		if(mtx[0][i]==ch&&mtx[0][i]==mtx[1][i]&&mtx[1][i]==mtx[2][i])
		{ flag++;
		  break;
		}
	 }
  }
  if(flag!=1) //left diagonal
  { flag=0;
	 if(mtx[0][0]==ch&&mtx[0][0]==mtx[1][1]&&mtx[1][1]==mtx[2][2])
	 { flag++;
	 }
  }
  if(flag!=1) //right diagonal
  { flag=0;
	 if(mtx[0][2]==ch&&mtx[0][2]==mtx[1][1]&&mtx[1][1]==mtx[2][0])
	 {flag++;
	 }
  }
  if(flag==1) //chance of win
  { return 1;
  }
  else
  { return 0;
  }
}
int tie()  //function to check for match tie
{ int i,j,k=0;
  for(i=0;i<3;i++)
  { for(j=0;j<3;j++)
	 { if(mtx[i][j]==' ')
		{ k++;
		  break;
		}
	 }
	 if(k==1)
	 break;
  }
  if(k==0)
	return 1;
  else
	return 0;
}