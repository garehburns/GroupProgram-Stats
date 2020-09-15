/*
	  Program 1
	Garrett Burns
   Alexander Bliss
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

//declaring functions before main
vector<int> listmaker();
void menu(vector<int> num_list);

double arithmean(vector<int> num_list);
double geomean(vector<int> num_list);
double harmean(vector<int> num_list);
double pop_variance(vector<int> num_list);
double std_dev(vector<int> num_list);

//function that does all the work
int main()
{
	//declares variable used throughout the program
	vector<int> num_list= {};
	
	cout << "Welcome to my simple stats program!\n";
	
	//creates the list of numbers
	num_list = listmaker();
	
	//call menu using the list we just made
	menu(num_list);
	
	return 0;
}

//creates the list and puts it in main
vector<int> listmaker()
{
	//declare variables
	int list_choice = 0;
	int numAmount = 0;
	vector<int> num_list= {};
	
	//get input from user on what they want to do
	cout << "How would you like to enter your numbers? \n";
	cout << "1.Import from a file\n2.Manually\n";
	cin >> list_choice;
	
	//if the user picks choice 1, this executes
	if(list_choice == 1)
	{
		cout << "What is the name of the text file you would like to import?";
		string file_name = "";
		cin >> file_name;
		ifstream fin;
		fin.open(file_name + ".txt");
		
		cout << "How many numbers are in the file?";
		cin >> numAmount;
		
		for(int i = 0; i < numAmount; i++)
		{
			double num = 0;
			fin >> num;
			num_list.push_back(num);
		}
		fin.close();
		return num_list;
	}
	
	//if the user picks choice 1, this executes
	else if(list_choice == 2)
	{
		cout << "How many numbers will you be entering? ";
		cin >> numAmount;
		
		cout << "Enter your numbers with spaces or newlines between each number\n";
		
		for(int i = 0; i < numAmount; i++)
		{
			double num = 0;
			cin >> num;
			num_list.push_back(num);
		}
		
		return num_list;
	}
	
	else
	{
		cout << "Oops, that's not an option. Please try again.\n\n";
		listmaker();
	}
}

//displays a menu for the different choices and takes the users input for what he/she wants to find
void menu(vector<int> num_list)
{
	//Display choices
	int choice = 0;
	cout << "\n\nWhat do you want to find?\n1. Start Over\n2. Arithmetic Mean\n3. Geometric Mean\n";
	cout << "4. Harmonic Mean\n5. Population Variance\n6. Standard Deviation\n7. Quit.\n";
	cin >> choice;
	
	int answer = 0;
	
	//takes user back to the beginning
	if(choice == 1)
	{
		num_list = listmaker();
		menu(num_list);
	}
	
	//finds arithmetic mean
	else if(choice == 2)
	{
		answer = arithmean(num_list);
		cout << "The arithmetic mean is: " << answer << "\n\n";
		menu(num_list);
	}
	
	//finds geometric mean
	else if(choice == 3)
	{
		cout << "The geometric mean is: " << geomean(num_list) << "\n\n";
		menu(num_list);
	}
	
	//finds harmonic mean
	else if(choice == 4)
	{
		answer = harmean(num_list);
		cout << "The harmonic mean is: " << answer << "\n\n";
		menu(num_list);
	}
	
	//finds population variance
	else if(choice == 5)
	{
		answer = pop_variance(num_list);
		cout << "The population variance is: " << answer << "\n\n";
		menu(num_list);
	}
	
	//finds population standard decviation
	else if(choice == 6)
	{
		answer = std_dev(num_list);
		cout << "The population standard deviation is: " << answer << "\n\n";
		menu(num_list);
	}
	
	//quits program
	else if(choice == 7)
	{
		cout << "Bye :(";
	}
	
	//loop back to the menu if they pick something that isn't listed
	else
	{
		cout << "Oops, that's not an option. Please try again.\n\n";
		menu(num_list);
	}
}

//solves for the arithmetic mean and returns it
double arithmean(vector<int> num_list)
{
	double total = 0;
	for(double i : num_list)
	{
		total = total + i;
	}
	double mean = total / num_list.size();
	
	return mean;
}

//solves for the geometric mean and returns it
double geomean(vector<int> num_list)
{
	double total = 1;
	for(double i : num_list)
	{
		total = total * i;
	}
	
	double power = num_list.size();
	double mean = pow(total, (1.0 / power));
	
	return mean;
}

//solves for the harmonic mean and returns it
double harmean(vector<int> num_list)
{
	double total = 0;
	double new_num = 0;
	double mean = 0;
	for(double i : num_list)
	{
		new_num = 1 / i;
		total = total + new_num;
		
		mean = 1 / (total / num_list.size());
	}
	return mean;
}

//solves for the population variance and returns it
double pop_variance(vector<int> num_list)
{
	double total = 0;
	double variance = 0;
	for(double num : num_list)
	{
		total = total + num;
	}
	
	double mean = total / num_list.size();
	
	double difference = 0;
	total = 0;
	
	for(double num : num_list)
	{
		difference = pow(num - mean, 2);
		total = total + difference;
	}
	
	variance = total / num_list.size();
	
	return variance;
}

//solves for the population standard deviation and returns it
double std_dev(vector<int> num_list)
{
	double variance = pop_variance(num_list);
	double deviation = pow(variance, 0.5);
	
	return deviation;
}
