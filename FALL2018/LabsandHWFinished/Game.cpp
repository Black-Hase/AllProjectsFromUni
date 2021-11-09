#include <iostream>

using namespace std;

int main()
{
    int count =1;
    int answer=0;
    if(count%3!=0)
    {
        cout << "Room is cold" << endl;
        while(answer!=5 || count !=10)
        {
            cin >> answer;
            switch (answer)
            {
                case 1:
                    cout << "The fire is roaring!" << endl;
                    break;
                case 2:
                    cout << "The fire is out!" << endl;
                    break;
                case 3:
                    cout << "That was an in accuract choose" << endl;
            }
        }
        
    }
return 0;
}