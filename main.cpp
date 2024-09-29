#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    int program;
    int switchCase,elementsToAdd;
    int data;
    cout<<"                 WELCOME TO ASSIGNMENT 6\n\n";
    cout<<"Enter:\n 1 for Stack functionality\n"<<" 2 for Queue functionality\n";
    cin>>switchCase;
    switch(switchCase)
    {
        case 1:
        {
            Stack stack;
            stack.stackMain();
            cout<<"\nEnter: \n 1 to return to main page\n"<<" Any other number to terminate program\n";
            cin>>program;
            if(program == 1)
            {
                main();
            }
            else
            {
                cout<<"\n    Thanks for coming:)\n";
            }
            break;
        }
        case 2:
        {
            Queue queue;
            queue.queueMain();
            cout<<"\nEnter: \n 1 to return to main page\n"<<" Any other number to terminate program\n";
            cin>>program;
            if(program == 1)
            {
                main();
            }
            else
            {
                cout<<"\n    Thanks for coming:)\n";
            }
            break;
        }
    }
    return 0;
}
