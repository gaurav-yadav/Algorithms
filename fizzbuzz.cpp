#include<iostream>
int main(int argc, char const *argv[])
{	
int i=0 ;
for (i=0;i<100;i++){
	if(i%3==0 && i%5==0)
		std::cout<< "Fizz Buzz\n";
	else if (i%3==0)
		std::cout<< "FIzz\n";
	else if(i%5==0)
		std::cout <<"Buzz\n";
	else
		std::cout<< i <<" <- i\n";

}

}