/*
Members:
Syeda Hajra 21k-3310
Hafiza Aqsa 21k-4511
Fatima Ashraf 21k-3455
*/
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void games();
void intro(FILE *);
void work(FILE *);
int rockpaperscissor(char,char);
char comppick ();
int main ()
{
	FILE *chatbot;
	char cont[6];
	struct tm *ttime;
	time_t t;
	t=time(NULL);
	ttime=localtime(&t);
	chatbot=fopen("chatbot.txt","a+");
	fprintf(chatbot,"[%d:%d]Hi! I am Chatty the Chatbot.\n",ttime->tm_hour,ttime->tm_min);
	printf("\t\t\t\t\tWELCOME TO WORLD OF AI\n");
	printf("\t\t\t\t    Hi! I am 'Chatty' the Chatbot.\n");
	printf("\t-------------------------------------------------------------------------------------------\n");
	do{
	printf("\t | If you want to continue the conversation enter any key or if you wish to exit enter Exit|\n");
	printf("\t-------------------------------------------------------------------------------------------\n");
	gets(cont);
	system("cls");
	if(strcmp(cont,"exit")==0||strcmp(cont,"Exit")==0||strcmp(cont,"EXIT")==0){
		printf("Bye! Talk to you later. %c",1);
		fprintf(chatbot,"\n[%d:%d]Chatbot: Bye! Talk to you later. %c",ttime->tm_hour,ttime->tm_min,1);}
	else{
			int ans;
			printf("\n\t\t\t\t     HEY, DO YOU WANT A SMALL INTRO !\n\n\t\t\t\t\t    (chat enter '1')\n\t\t\t     (if you want to straight get to work enter '2') \n \t\t\t\t\t   (to exit enter 3?)");
			scanf("%d",&ans);
			switch(ans){
				case 1:
					intro(chatbot);
					break;
				case 2:
					work(chatbot);
					break;
				case 3:
					fprintf(chatbot,"\n[%d:%d]Chatbot: Thank you for using chatty the chatbot!",ttime->tm_hour,ttime->tm_min); 
					printf("Thank you for using chatty the chatbot!");
					strcpy(cont, "exit");
					break;
				default:
					printf("Enter required number!");
			}
		}fclose(chatbot);
    }while(strcmp(cont,"exit")!=0);
}

void intro(FILE *chatbot)
{ 
	char name[15];
	int age,i;
	struct tm *ttime;
	float weath;
	time_t t;
	t=time(NULL);
	ttime=localtime(&t);
	fprintf(chatbot,"[%d:%d]Chatbot: WHAT IS YOUR NAME?",ttime->tm_hour,ttime->tm_min);
	printf("\n\n\t\t\tWhat's your name?");
	fflush(stdin);
	gets(name);
	fprintf(chatbot,"\n[%d:%d]User: %s",ttime->tm_hour,ttime->tm_min,name);
	fprintf(chatbot,"\n[%d:%d]Chatbot: %s, what's your age? ",ttime->tm_hour,ttime->tm_min,name);
	printf("\n\n\t\t\t%s,\n\n\t\t\twhat's your age?",name);
	scanf("%d",&age);
	fprintf(chatbot,"\n[%d:%d]User: %d",ttime->tm_hour,ttime->tm_min,age);
	if(age>=1)
	{
		printf("\t\t\tOh you are older than me! I'm %d days old,I was built on 16th of December.",(ttime->tm_mday-16+31));
		fprintf(chatbot,"\n[%d:%d]Chatbot: Oh you are older than me! I'm %d days old, I was built on 16th of December.",ttime->tm_hour,ttime->tm_min,(ttime->tm_mday-16));
	}
	else{
	    fprintf(chatbot,"\n[%d:%d]Chatbot: Strange, you are younger than me although I'm %d days old!",ttime->tm_hour,ttime->tm_min,(ttime->tm_mday-16));
		printf("Strange, you are younger than me although I'm %d days old!",(ttime->tm_mday-16));
	}
	fprintf(chatbot,"\n[%d:%d]Chatbot: What's the weather there?",ttime->tm_hour,ttime->tm_min);
	printf("\n\t\t\tWhat's the weather there in Centigrade?");
	scanf("%f",&weath);
	fprintf(chatbot,"\n[%d:%d]User: %.2f",ttime->tm_hour,ttime->tm_min,weath);
	if(weath<0)
	{
		fprintf(chatbot,"\n[%d:%d]Chatbot: It's freezing cold. Dont forget to wear your warm jackets and turn on your heaters!",ttime->tm_hour,ttime->tm_min);
		printf("\t\tIt's freezing cold. Dont forget to wear your warm jackets and turn on your heaters!");
	}
	else if(weath>=0 && weath<21)
	{
		fprintf(chatbot,"\n[%d:%d]Chatbot: It's cold. Dont forget to wear your jackets!",ttime->tm_hour,ttime->tm_min);
		printf("\n\t\t\tIt's cold. Dont forget to wear your jackets!");
	}
	else if(weath>=21 && weath<28)
	{
		fprintf(chatbot,"\n[%d:%d]Chatbot: The weather is moderate.",ttime->tm_hour,ttime->tm_min);
		printf("\n\t\t\tThe weather is moderate.");
	}
	else if(weath>=28 && weath<40)
	{
		fprintf(chatbot,"\n[%d:%d]Chatbot: Its hot outside.",ttime->tm_hour,ttime->tm_min);
		printf("\n\t\t\tIts hot outside.");
	}
	else{
		fprintf(chatbot,"\n[%d:%d]Chatbot: Its really warm outside. Dont forget to turn on your AC.",ttime->tm_hour,ttime->tm_min);
	    printf("\n\t\t\tIts really warm outside. Dont forget to turn on your AC.");
	}
	char ans[4];
	do{	
	fprintf(chatbot,"\n[%d:%d]Chatbot: Are you stressed out? Enter yes or no .\n",ttime->tm_hour,ttime->tm_min);
	printf("\n\t\t\tAre you stressed out? Enter yes or no.\n");
	fflush(stdin);
	gets(ans);
	fprintf(chatbot,"\n[%d:%d]User: %s",ttime->tm_hour,ttime->tm_min,ans);
	for(i=0; ans[i]!='\0'; i++)
		ans[i]=tolower(ans[i]);
	if(strcmp(ans,"yes")==0)
	{
		do{
			fprintf(chatbot,"\n[%d:%d]Chatbot: Do you want me to help? Enter yes or no \n.",ttime->tm_hour,ttime->tm_min);
			printf("\n\t\t\tDo you want me to help? Enter yes or no\n.");
			fflush(stdin);
			gets(ans);
			fprintf(chatbot,"\n[%d:%d]User: %s",ttime->tm_hour,ttime->tm_min,ans);
			for(i=0; ans[i]!='\0'; i++)
				ans[i]=tolower(ans[i]);
			if(strcmp(ans,"yes")==0)
			{
				fprintf(chatbot,"\n[%d:%d]Chatbot: Starting relaxing video.",ttime->tm_hour,ttime->tm_min);
				printf("\n\t\t\tStarting relaxing video.");
				system("start https://youtu.be/V1RPi2MYptM");
			}
			printf("Okay. %c\n",1);
		}while(strcmp(ans,"no")!=0);
	  }
	}while(strcmp(ans,"no")!=0);
	
	do{
		fprintf(chatbot,"\n[%d:%d]Chatbot: Are you bored? Enter yes or no.\n",ttime->tm_hour,ttime->tm_min);
		printf("\n\t\t\tAre you bored? Enter yes or no .");
		fflush(stdin);
		gets(ans);
		fprintf(chatbot,"\n[%d:%d]User: %s",ttime->tm_hour,ttime->tm_min,ans);
		for(i=0; ans[i]!='\0'; i++)
			ans[i]=tolower(ans[i]);
		if(strcmp(ans,"yes")==0)
		{
				do{
				fprintf(chatbot,"\n[%d:%d]Chatbot: Do you want me to suggest a few things to fight your boredom? Enter yes or no.\n",ttime->tm_hour,ttime->tm_min);
				printf("\t\t\tDo you want me to suggest a few things to fight your boredom? Enter yes or no.\n");
				fflush(stdin);
				gets(ans);
				fprintf(chatbot,"\n[%d:%d]User: %s",ttime->tm_hour,ttime->tm_min,ans);
				for(i=0; ans[i]!='\0'; i++)
					ans[i]=tolower(ans[i]);
				if(strcmp(ans,"yes")==0)
				{
					fprintf(chatbot,"\n[%d:%d]Chatbot: There are a few things that I can suggest:\nEnter\n1 to watch painting videos\n2 to get recipes\n3 to play games\n4 to watch netflix\n5 to exit: ",ttime->tm_hour,ttime->tm_min);
					printf("\t\t\tThere are a few things that I can suggest:\nEnter\n1 to watch painting videos\n2 to get recipes\n3 to play games\n4 to watch netflix\n5 to exit: ");
					int bore;
					do{
						scanf("%d",&bore);
						fprintf(chatbot,"\n[%d:%d]User: %d",ttime->tm_hour,ttime->tm_min,bore);
						switch(bore)
						{
							case 1:
								fprintf(chatbot,"\n[%d:%d]Chatbot: Pleas wait, playing video.",ttime->tm_hour,ttime->tm_min);
								printf("\t\t\tPlease wait, playing video.");
								system("start https://youtu.be/nTitQlI84po");
								break;
							case 2:
								fprintf(chatbot,"\n[%d:%d]Chatbot: Please wait, opening recipes.",ttime->tm_hour,ttime->tm_min);
								printf("\t\t\tPlease wait, opening recipes.");
								system("start https://www.allrecipes.com/recipes/");
								break;
							case 3:
								fprintf(chatbot,"\n[%d:%d]Chatbot: Please wait, opening games.",ttime->tm_hour,ttime->tm_min);
								printf("\t\t\tPlease wait, opening games.");
								games();
								break;
							case 4:
								fprintf(chatbot,"\n[%d:%d]Chatbot: Please wait, opening netflix.",ttime->tm_hour,ttime->tm_min);
								printf("\t\t\tPlease wait, opening netflix.");
								system("start https://www.netflix.com/pk/");
								break;
							case 5:
								fprintf(chatbot,"\n[%d:%d]Chatbot: Exiting.",ttime->tm_hour,ttime->tm_min);
								fflush(stdin);
								printf("Exiting.\n");
								break;
							default:
								printf("\t\t\tEnter required number!");
								break;
						}
					}while(bore!=5);
				}	
					fprintf(chatbot,"\n[%d:%d]Chatbot: Okay.%c",ttime->tm_hour,ttime->tm_min,1);
					printf("Okay.%c\n",1);
			}while(strcmp(ans,"no")!=0);
		}
		else if(strcmp(ans,"no")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: Okay.%c",ttime->tm_hour,ttime->tm_min,1); 
			printf("Okay. %c\n",1);
		}
	}while(strcmp(ans,"no")!=0);
}

void work(FILE *chatbot)
{
	struct tm *ttime;
	time_t t;
	t=time(NULL);
	ttime=localtime(&t);
	printf("\n\nChrome==>TO OPEN GOOGLE CHROME.\nNotepad==>TO OPEN NOTEPAD.\nTime==>TO SHOW DAY,DATE AND TIME.\nExplorer==>TO OPEN FILE EXPLORER.\nCalculator==>TO OPEN THE CALCULATOR.\n6.Youtube==>TO OPEN YOUTUBE.\n7.Gmail==>TO OPEN GMAIL.\n8.Games==>TO PLAY GAMES.\n");
	fprintf(chatbot,"\n[%d:%d]Chatbot: Chrome==>TO OPEN GOOGLE CHROME.\nNotepad==>TO OPEN NOTEPAD.\nTime==>TO SHOW DAY,DATE AND TIME.\nExplorer==>TO OPEN FILE EXPLORER.\nCalculator==>TO OPEN THE CALCULATOR.\n6.Youtube==>TO OPEN YOUTUBE.\n7.Gmail==>TO OPEN GMAIL.\n8.Games==>TO PLAY GAMES.\n",ttime->tm_hour,ttime->tm_min);
	char input2[20];
	fflush(stdin);
	gets(input2);
	fprintf(chatbot,"\n[%d:%d]User: %s",input2);
	int i=0;
	for(i=0; input2[i]!='\0'; i++)
		input2[i]=tolower(input2[i]);
		if(strcmp(input2,"chrome")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. CHROME IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. CHROME IS OPENNING.\n");
			system("start chrome");
		}
		else if(strcmp(input2,"notepad")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. NOTEPAD IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. NOTEPAD IS OPENNING.\n");
			system("start Notepad");
		}
		else if(strcmp(input2,"time")==0)
		{
			time_t t;   
    		time(&t);
    		fprintf(chatbot,"\n[%d:%d]Chatbot: THE CURRENT DAY, DATE AND TIME IS: %s \n",ttime->tm_hour,ttime->tm_min,ctime(&t));
			printf("\n\t\t\tTHE CURRENT DAY, DATE AND TIME IS: %s \n",ctime(&t));
		}
		else if(strcmp(input2,"file explorer")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. FILE EXPLORER IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. FILE EXPLORER IS OPENNING.\n");
			system("start explorer");
		}
		else if(strcmp(input2,"calculator")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. CALCULATOR IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. CALCULATOR IS OPENNING.\n");
			system("start calc");
		}
		else if(strcmp(input2,"youtube")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. YOUTUBE IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. YOUTUBE IS OPENNING.\n");
			system("start https://www.youtube.com/");
		}
		else if(strcmp(input2,"gmail")==0)
		{
			fprintf(chatbot,"\n[%d:%d]Chatbot: PLEASE WAIT. GAMIL IS OPENNING.",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tPLEASE WAIT. GMAIL IS OPENNING.\n");
			system("start https://accounts.google.com/b/0/AddMailService");
		}
		else if(strcmp(input2,"games")==0)
		{
			games();	
		}
		else{
			fprintf(chatbot,"\n[%d:%d]Chatbot: WINDOWS CANNOT FIND THE WORD MAKE SURE YOU TYPED CORRECTLY.\n",ttime->tm_hour,ttime->tm_min);
			printf("\t\t\tWINDOWS CANNOT FIND THE WORD MAKE SURE YOU TYPED CORRECTLY.\n");
		}
}

void games()
{
	char ans[40],you,comp;
	int n,i=0;
	printf("\t\t\tPLEASE ENTER WHICH GAME YOU WANT TO PLAY.\n");
	printf("ENTER\n1.==>KNOWLEDGE IS POWER.\n2.==>404 ERROR.\n3.==>LOVE AT FIRST BITE.\n4.==>Rock Paper Scissor\n5.==>Guess the Number");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\t\t\t=============KNOWLEDGE IS POWER.=============\n");
	    	printf("\t\t\t5 POINTS ON RIGHT ANSWERS\n-3 ON WRONG ANSWERS.\n");
			printf("\t\t\t1.Which is the smallest continent.\n");
			fflush(stdin);
			gets(ans);
			if(strcmp(ans,"Austrailia")==0||strcmp(ans,"austrailia")==0)
				i+=5;
			else
				i-=3;
			printf("\t\t\t2.What is the national game of USA.\n");
			fflush(stdin);
			gets(ans);
			if(strcmp(ans,"Baseball")==0||strcmp(ans,"baseball")==0)
				i+=5;
			else
				i-=3;
				printf("\t\t\t3.Which animal has three hearts.\n");
				fflush(stdin);
				gets(ans);
				if(strcmp(ans,"Octopus")==0||strcmp(ans,"octopus")==0)
					i+=5;
				else
					i-=3;
				if(i>10)
				{
				 printf("\t\t\tCONGRAGULATIONS.YOU WON.\n");
				 printf("\t\t\tYOUR SCOREE IS: %d\n",i);
				}
				else
				{
				 printf("\t\t\tSORRY BETTER LUCK NEXT TIME.\n");
			 	 printf("\t\t\tYOUR SCORE IS:%d\n",i);
			    }
			break;
				
		case 2:
			printf("\t\t\t=============404 ERROR.=============\n");
			printf("\t\t\t5 POINTS ON RIGHT ANSWERS\n-3 ON WRONG ANSWERS.\n");
			printf("\t\t\t1.RAM stands for.\n");
			fflush(stdin);
			gets(ans);
			if(strcmp(ans,"Random Access Memory")==0||strcmp(ans,"random access memory")==0)
				i+=5;
			else
				i-=3;
				printf("\t\t\t2.one kilo byte is equals to\n");
				int ans2;
				scanf("%d",&ans2);
			if(ans2==1024)
				i+=5;
			else
				i-=3;
			printf("\t\t\t3.Which is the first calculatinf davice.\n");
			fflush(stdin);
			gets(ans);
			if(strcmp(ans,"Abacus")==0||strcmp(ans,"abacus")==0)
				i+=5;
			else
				i-=3;
			if(i>10)
			{
			 printf("\t\t\tCONGRAGULATIONS.YOU WON.\n");
			 printf("\t\t\tYOUR SCOREE IS: %d\n",i);
			}
			else
			{
			 printf("\t\t\tSORRY BETTER LUCK NEXT TIME.\n");
			 printf("\t\t\tYOUR SCORE IS:%d\n",i);
			}
			break;
					
			case 3:
				printf("\t\t\t=============LOVE AT FIRST BITE.=============\n");
				printf("\t\t\t5 POINTS ON RIGHT ANSWERS\n-3 ON WRONG ANSWERS.\n");
				printf("\n\t\t\t1.The national fruit of USA is.\n");
				fflush(stdin);
				gets(ans);
				if(strcmp(ans,"Blueberry")==0||strcmp(ans,"blueberry")==0)
					i+=5;
				else
					i-=3;
				printf("\n2.I am a seed with three letters in my name. Take away the last two and I would stay the same. What am I?.\n");
				fflush(stdin);
				gets(ans);
				if(strcmp(ans,"Pea")==0||strcmp(ans,"pea")==0)
					i+=5;
				else
					i-=3;
				printf("\n3.What kind of cheeze is made backwards.\n");
				fflush(stdin);
				gets(ans);
				if(strcmp(ans,"Edam")==0||strcmp(ans,"edam")==0)
					i+=5;
				else
					i-=3;
				if(i>10)
				{
				  printf("\nCONGRAGULATIONS.YOU WON.\n");
				  printf("\nYOUR SCOREE IS: %d\n",i);
				}
				else
				{
				 printf("\nSORRY BETTER LUCK NEXT TIME.\n");
				 printf("\nYOUR SCORE IS:%d\n",i);
				}
				break;
			
			case 4:
				printf("\nWelcome to a game of rock, paper, scissors!\nEnter 'r' for rock, 's' for scissors, 'p' for paper\n");
				scanf(" %c",&you);
				comp = comppick();
				int result= rockpaperscissor(you, comp);
				printf("You chose %c and computer chose %c.",you,comp);
				if(result==0)
					printf("Game Draw\n");
				else if(result==1)
					printf("You Win\n");
				else
					printf("You Lose\n");
				break;
		  
			case 5:
				printf("This is goint to be fun!*\n");
                printf("The computer will generate random numbers and will ask the player to guess it.If player's guess is higher than actual number,the program displays:\nlower number please.\nSimilarly if the user guess it too low.The program prints:\nhigher number please");
	            int number,guess,nguesses=1;
	            srand(time(0));
				number=rand()%100+1;
				do{
						printf("\nGuess the number between 1 to 100\n");
					scanf("%d",&guess);
					if(guess>number)
						printf("lower number please\n");			
					else if(guess<number)
						printf("greater number please\n");
					nguesses++;
				}while(guess!=number);
				
				printf("you guessed it in %d attempts",nguesses);
				break;
			
			default:
				printf("Enter required number!");	
}
}
char comppick()
{
	srand(time(0));
	int pick = rand()%3;
	if(pick==0)
		return 'r';
	else if(pick==1)
		return 'p';
	else
		return 's';
}
int rockpaperscissor(char you,char comp){
	//returns 1 if you win,-1 if you lose, and 0 if you draw
	//condition for draw
	//cases covered
	//ss
	//gg
	//ww
	if(you==comp)
		return 0;
	else if((you=='r'&&comp=='s') || (you=='p'&&comp=='r') || (you=='s'&&comp=='p'))
		return 1;
	else
		return -1;
}
