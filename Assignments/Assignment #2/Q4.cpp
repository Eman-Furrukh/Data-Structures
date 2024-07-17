// Eman_Furrukh_21i1726
// Assignment #2 
// Question #4

// TEXT FOR STRING MANIPULATION
/*Most of the people of our country are farmers, workers, and day labourers who live below the poverty line.
But the price of essential commodities is soaring higher and higher. It has now become impossible for them to make 
both ends meet. It has severely hit the day labourers, the lower and middle-class families, and the salaried class too.
The prices of rice, vegetables, clothes, mustard oil, medicine, and other essential commodities are also increasing by
leaps and bounds. In most cases, hoarding and black marketing are responsible for such a situation. All these have made
the life of the common man miserable. The government should set up more and more fair price distribution channels for 
selling essential commodities. The Consumers’ Forum should also be more active to check such unreasonable hikes.*/

#include<iostream>
using namespace std;
//Recursive function

class StringList {
public:

	char alphabet;
	StringList* next;
	StringList(char data) {
		this->alphabet = data;
		this->next = NULL;

	}
};

int find_Length(StringList* s, int counter) //counter will start from zero initially
{

}
class String_Manipulation {
public:
	void createList(StringList*& head)
	{
		//read text from file and make the list here
	}
	int Calculate_length(StringList* head)
	{
		int length;
		//call a recursive funcaiton to find string length
		//add your code
		/*
		The function should get a string as input and return the length of the string.
		The length should be measured with the help of a recursive function.
		*/
		return length;
	}
	bool substring(StringList* head, string str)
	{
		bool status;
		//add your code

		return status;
	}
	int substring_position(StringList* head, string str)
	{
		int index = -1;
		//add your code
		/*
			"I am taking DS course"
			Str = "taking"
			The function will return 5 as substring exist and starts at 5th index of main string. In case the substring does not exist, you will return -1.

		*/
		return index;
	}
	void replaceString(StringList*& head, string find, string replace)
	{
		////add your code
	}
	void appendText(StringList*& head, string appends, int index)
	{
		////add your code
	}
	void deleteText(StringList*& head, string delText)
	{

	}
};

int main() {
	StringList* head;
	String_Manipulation obj;
	obj.createList(head);

	//add your code
}