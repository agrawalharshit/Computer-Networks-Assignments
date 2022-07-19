#include<iostream>
using namespace std;

int main()
{
 int data[11],recv[11];
 
 cout<<"Enter data bit 3: ";
 cin>>data[2];
 cout<<"Enter data bit 5: ";
 cin>>data[4];
 cout<<"Enter data bit 6: ";
 cin>>data[5];
 cout<<"Enter data bit 7: ";
 cin>>data[6];
 cout<<"Enter data bit 9: ";
 cin>>data[8];
 cout<<"Enter data bit 10: ";
 cin>>data[9];
 cout<<"Enter data bit 11: ";
 cin>>data[10];


 
 data[0]=data[2]^data[4]^data[6]^data[8]^data[10];
 data[1]=data[2]^data[5]^data[6]^data[9]^data[10];
 data[3]=data[4]^data[5]^data[6];
 data[7]=data[8]^data[9]^data[10];
 
 cout<<"Thus the parity bits are:\n";
 cout<<"Bit p1:"<<data[0];
 cout<<"\nBit p2:"<<data[1];
 cout<<"\nBit p4:"<<data[3];
cout<<"\nBit p8:"<<data[7];
 
 cout<<"\nHamming code for the given data bits is:";
 for(int i=0;i<11;i++)
 cout<<data[i];
 
 cout<<"\n";
 
 cout<<"Enter the recieved code:\n";
 for(int i=0;i<11;i++)
 {
 	cin>>recv[i];
 }
 int p1=recv[0]^recv[2]^recv[4]^recv[6]^recv[8]^recv[10];
 int p2=recv[1]^recv[2]^recv[5]^recv[6]^recv[9]^recv[10];
 int p4=recv[3]^recv[4]^recv[5]^recv[6];
 int p8=recv[7]^recv[8]^recv[9]^recv[10];
 
 if(p1==0&&p2==0&&p4==0&&p4==0)
 {
 	cout<<"\nRecieved data is correct\n";
 }
 else
 {
 	cout<<"\nRecieved data is incorrect\n";	
 	int pos;
 	pos=(1*p1)+(2*p2)+(4*p4)+(8*p8);
 	cout<<"Error occured at bit: "<<pos;
 	if(recv[pos]==0)
 	{
 	 recv[pos-1]=1;
 	}
 	else
 	{
 	 recv[pos-1]=0;  
 	} 
 	cout<<"\nCorrect data is: ";
 	for(int i=0;i<11;i++)
	cout<<recv[i];
 	cout<<"\n";
 }	
 return 0;
} 