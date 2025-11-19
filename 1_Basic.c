/*1. WAP to read the elements from user and store in a list and print the list.
  2. Find the sum and average of the elements.
  3. Find smallest and largest Element in the list.
  4. Search an element which is present or not.
  */
// Ans 1)
# include<iostream>
using namespace std;
int main()
{
    int list[5];
    printf("Enter Five numbers to be added to the list.\n");
    for(int i=0;i<5;i++)
    {
        cout << "Enter " << i << "th element : "; 
        cin >> list[i];
    }

    printf("List: ");
    for(int i=0;i<5;i++)
    {
        cout << list[i] << " ";
    }

//Ans) 2
float sum = 0;
float avg = 0.0;
    for(int i=0;i<5;i++)
    {
        sum = sum + list[i];
    }
    cout << "\nSum: " << sum << endl;
    avg = sum/5;
    cout << "Average: " << avg << endl;

//Ans) 3
int smallest = list[0];
int largest = list[0];
    for(int i=0;i<5;i++)
    {
        if(list[i]<smallest)
            smallest = list[i];
    }
    for(int i=0;i<5;i++)
    {
        if(list[i]>largest)
            largest = list[i];
    }
    cout << "Smallest No.: " << smallest << endl;
    cout << "Largest No. : " << largest << endl;

//Ans) 4
int n;
cout << "Enter a number you want to see if present in the list: ";
cin >> n;
int times_no_is_present = 0; 
for(int i;i<5;i++)
{
    if(list[i] == n)
        {
            cout << n << " is present." << endl;
            times_no_is_present++;
            continue;
        }
    else
        {
            cout << n << " is not present in the list." << endl;
            continue;
        }
}
    cout << "The no. of times " << n << " was present: " << times_no_is_present << endl;
}



