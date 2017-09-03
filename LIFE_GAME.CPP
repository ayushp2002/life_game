/*
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	$$$$$$$$$$$$$$$$Programmed by$$$$$$$$$$$$$$$
	$$$$$$$$$$$$$$$$ AYUSH KUMAR $$$$$$$$$$$$$$$
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

			-------------
	****************| LIFE GAME |***************
			-------------
			     V.2

		---Basic Units---
	Cash = main currency
	Energy = needed to do tasks
	Food = needed to restore the energy lost in doing tasks
	Bits = special currency, 1 bit = 10000 cash


		---Activities---
	1> Do Job
		[Energy -2
		[Cash +5 (upgradeable)
	2> Buy Food
		[Cash -2
		[Energy -1
		[Food +1
	3> Buy Bits
		[Energy -1
		[Cash -10000
		[Bits +1
	4> Eat Food
		[Food -1
		[Energy +5
	5> Buy Cash
		[Cash +10000
		[Bits -1
	6> Help
		[See help for any activity
	7> Show Stats
		[See your stats
		[Energy, Cash, Food, Bits
	8> Go to Shop
		[Menu to buy or upgrade assets
		[===Menu===
			[1> Upgrade money earned on doing job
			[2> Upgrade maximum Energy Storage
			[3> Upgrade maximum Cash Storage
			[4> Upgrade maximum Food Storage
	9> Exit
		[Exit the game
*/
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<process.h>
void main()
{
	//declaration of variables start
	/*
			       ___Variables___

			---long int---
		c=cash		cmax=maximum cash limit(default=2000)(upgradeable)
		e=energy	emax=maximum energy limit(default=200)(upgradeable)
		b=bits
		f=food		fmax=maximum food limit(default=200)(upgradeable)
		rc=count of remaining cash required to buy an asset
		amt=number to times you want to do any activity(used multiple)
		chk=for checking the condition of insufficient resources(energy/cash/bits/food)(used multiple)
		chk1=for checking the condition of insufficient resources(energy/cash/bits/food)(used multiple)(for checking secondary)
		earn=amount of money earned by doing job (default=5)(upgradeable)

			---int---
		cmd=command input
		hc=help command input
		sc=shop command input
		v=version of app

			---char---
		conf=confirmation[y/n]
	*/
	long int c=1000, cmax=2000, e=200, emax=200, b=0, f=100, fmax=200, rc=0, amt=0, chk=0, chk1=0, earn=5;
	int cmd=0, hc=0, sc=0, v=2;
	char conf;
	//main body start
	clrscr();
	cout<<setw(124)<<"***LIFE GAME v."<<v<<"***"<<endl;
	//menu
	cout<<setw(100)<<"----MENU----"<<endl;
	cout<<"\t| 1> Do Job\n"<<"\t| 2> Eat Food\n"<<"\t| 3> Help\n"<<"\t| 4> Show Stats\n"<<"\t| 5> Go to Shop\n"<<"\t| 6> Exit\n"<<"\t------------\n";
	//program start
	do
	{
		cmd=0;
		cout<<"\n>> ";
		cin>>cmd;
		//conditions
		if (cmd>0 && cmd<10)
		{
			switch(cmd){
				case 1:{		//Do Job
					cout<<"^^^DOING JOB^^^\n";
					cout<<"How many times you want to do job?";
					cin>>amt;
					chk=e-(2*amt);	//if energy is less than required
					if (chk<0)
					{
						cout<<"Insufficient Energy!";
					}
					else
					{
						if (c<=(cmax-(earn*amt)))
						{
							e-=(2*amt);
							c+=(earn*amt);
						}
						else
						{
							cout<<"Please upgrade your maximum cash storage from the shop(8)";
						}
					}
					break;
				}
				case 2:{		//Eat Food
					cout<<"^^^EATING FOOD^^^\n";
					cout<<"How much food you want to eat?";
					cin>>amt;
					chk=f-amt;
					if (chk<0)
					{
						cout<<"Insufficient Food!";
					}
					else
					{
						if (e<=(emax-5))
						{
							f-=amt;
							e+=(5*amt);
						}
						else
						{
							cout<<"Please upgrade your maximum energy storage from the shop(8)";
						}
					}
					break;
				}
				case 3:{    //Help
					cout<<setw(45)<<"### LIFE Game Help ###\n";
					cout<<setw(100)<<"----MENU----"<<endl;
					cout<<"\t| 1> Do Job\n"<<"\t| 2> Eat Food\n"<<"\t| 3> Help\n"<<"\t| 4> Show Stats\n"<<"\t| 5> Go to Shop\n"<<"\t| 6> Exit\n"<<"\t------------\n";
					cout<<"Enter the number of option you want to know about, or 0 to exit help.\n";
					cin>>hc;
					switch (hc){
						case 0:{                //EXIT HELP
							cout<<"^^^EXITING HELP^^^";
							break;
						}
						case 1:{		//help - Do Job
							cout<<"Help (Do Job)\n";
							cout<<"Cash: +5\nEnergy: -2\nFood: --\nBits: --\n";
							break;
						}
						case 2:{		//help - Eat Food
							cout<<"Help (Eat Food)\n";
							cout<<"Cash: --\nEnergy: +5\nFood: -1\nBits: --\n";
							break;
						}
						case 3:{		//help - Help
							cout<<"Help (Help)\n";
							cout<<"Cash: --\nEnergy: --\nFood: --\nBits: --\n";
							cout<<"See BU Terminal help.";
							break;
						}
						case 4:{		//help - Show Stats
							cout<<"Help (Show Stats)\n";
							cout<<"Cash: --\nEnergy: --\nFood: --\nBits: --\n";
							cout<<"See your Stats.";
							break;
						}
						case 5:{		//help - Go to Shop
							cout<<"Help (Go to Shop)\n";
							cout<<"Cash: --\nEnergy: --\nFood: --\nBits: --\n";
							cout<<"View the list of items to buy in the shop.";
							break;
						}
						case 6:{		//help - Exit
							cout<<"Help (Exit)\n";
							cout<<"Cash: --\nEnergy: --\nFood: --\nBits: --\n";
							cout<<"Exit the Terminal.";
							break;
						}
						default:{
							cout<<"Wrong option.";
							break;
						}

					}
					break;
				}
				case 4:{		//Show Stats
					cout<<"\n------STATS------"<<"\n| Cash: "<<c<<"/"<<cmax<<"\n| Energy: "<<e<<"/"<<emax<<"\n| Food: "<<f<<"/"<<fmax<<"\n| Bits: "<<b<<"\n------------------\n";
					break;
				}
				case 5:{		//Go to Shop
					cout<<"\t-----SHOP MENU-----\n";
					cout<<"\t| 1>Upgrades\n"<<"\t| 2>Assets\n"<<"\t------------------------\n"<<"What do you want to buy?";
					cin>>sc;
					switch (sc)
					{
						case 1:{	//Upgrades
							sc=0;
							cout<<"\t\t---UPGRADES---------------------------------\n";
							cout<<"\t\t| 1>Money earned by Job \n"<<"\t\t| 2>Maximum Energy \n"<<"\t\t| 3>Maximum Cash \n"<<"\t\t| 4>Maximum Food \n"<<"\t\t--------------------------------------------\n";
							cout<<"What do you want to upgrade?";
							cin>>sc;
							conf='0';
							switch(sc)
							{
								case 1:{
									cout<<"Are you sure you want to upgrade?[y/n]";
									cin>>conf;
									if (conf=='y')
									{
										earn++;
										c-+1000;
									}
									else
									{
										cout<<"Upgrading cancelled.";
									}
									break;
								}
								case 2:{
									cout<<"Are you sure you want to upgrade maximum energy storage?[y/n]";
									cin>>conf;
									if (conf=='y')
									{
										emax+=50;
										c-=250;
									}
									else
									{
										cout<<"Upgrading cancelled.";
									}
									break;
								}
								case 3:{
									cout<<"Are you sure you want to upgrade maximum cash storage?[y/n]";
									cin>>conf;
									if (conf=='y')
									{
										cmax+=500;
										c-=600;
									}
									else
									{
										cout<<"Upgrading cancelled.";
									}
									break;
								}
								case 4:{
									cout<<"Are you sure you want to upgrade maximum food storage?[y/n]";
									cin>>conf;
									if (conf=='y')
									{
										fmax+=50;
										c-=250;
									}
									else
									{
										cout<<"Upgrading cancelled.";
									}
									break;
								}
							}
							break;
						}
						case 2:{ 	//Assets
							sc=0;
							cout<<"\t\t---ASSETS---------------------------------\n";
							cout<<"\t\t| 1> Buy Food\n"<<"\t\t| 2> Buy Bits\n"<<"\t\t| 3> Buy Cash\n"<<"\t\t--------------------------------------------\n";;
							cout<<"What do you want to upgrade?";
							cin >>sc;
							switch(sc)
							{
								case 1:{    //Buy food
									cout<<"^^^BUYING FOOD^^^\n";
									cout<<"How much Food do you want to buy?";
									cin>>amt;
									chk=c-(2*amt);	//if cash is less than required
									chk1=e-amt;     //if energy is less than required
									if (chk<0 || chk1<0)
									{
										cout<<"Insufficient Energy or Cash!";
									}
									else
									{
										if (f<=(fmax-amt))
										{
											c-=(2*amt);
											e-=amt;
											f+=amt;
										}
										else
										{
											cout<<"Please upgrade your maximum food storage from the shop(8)";
										}
									}
									break;
								}
								case 2:{    //Buy Bits
									cout<<"^^^BUYING BITS^^^\n";
									cout<<"How many Bits you want to buy?";
									cin>>amt;
									chk=c-(10000*amt);
									chk1=e-amt;
									if (chk<0 || chk1<0)
									{

										rc=10000-c;
										cout<<"Insufficient cash or energy!";
										cout<<rc<<" more Cash needed.";
									}
									else
									{
										c-=(10000*amt);
										e-=amt;
										b+=amt;
									}
									break;
								}
								case 3:{		//Buy Cash
									cout<<"^^^BUYING CASH^^^\n";
									if (cmax>=10000)
									{
										if (b>=1)
										{
											c+=10000;
											b--;
										}
										else
										{
											cout<<"Not enough Bits!\nMinimum 1 bit required.";
										}
									}
									else
										{
											cout<<"Please upgrade your maximum cash storage from the shop(8)";
										}
									break;
								}
							}
							break;
						}
					}
					break;
				}
				case 6:{    //Exit
					cout<<"^^^EXITING^^^\n";
					cout<<"Are you sure you want to exit?[y/n]";
					cin>>conf;
					if (conf=='y')
					{
						cout<<"Press any key to exit...";
						break;
					}
					else if (conf=='n')
					{
						cout<<"Exiting cancelled.";
						cmd=0;
						break;
					}
					else
					{
						cout<<"Wrong option chosen.";
						cmd=0;
						break;
					}
				}
			}
		}
		else
		{
			cout<<"Wrong input...\nTry again...\nPress 6 for help...";
		}
	}while(cmd!=6);
	getch();
}
