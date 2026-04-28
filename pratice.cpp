#include<iostream>
#include<cmath> 

using namespace std; 

int sumOfdigits (int num) { 
    int sum = 0;
    while ( num > 0 ) { 
        
    int last = num % 10; 
    sum += last; 
    num = num / 10;
    }
    return sum; 
}


int main() { 

// getting an inut and then adding the numbers 
    
int numInput; 
cout << "Enter a number " << endl; 
cin >> numInput; 

int s=sumOfdigits(numInput);
cout<<s;






// pr

return 0;
} 