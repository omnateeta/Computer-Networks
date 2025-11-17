//Write a program for error detecting code using CRC - CCIT(16-bits)
#include<stdio.h>

int gp[17] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1}; // Generator polynomial

void divide(int data[], int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		if(data[i] == 1)
		{
			for(j = 0; j < 17; j++)
			{
				data[i + j] ^= gp[j]; // XOR operation
			}
		}
	}
}

int main()
{
	int i;
	int data[200], temp[200], recv[200];
	int len, k, flag = 0;

	printf("\nEnter the length of the data frame: ");
	scanf("%d", &len);

	printf("\nEnter the message bits (space separated 0/1): ");
	for(i = 0; i < len; i++)
		scanf("%d", &data[i]);

	// Append 16 zeros
	for(i = 0; i < 16; i++)
		data[len + i] = 0;

	k = len;

	// Copy original data to temp
	for(i = 0; i < len + 16; i++)
		temp[i] = data[i];

	// Perform division to get remainder (CRC bits)
	divide(data, k);

	// Append CRC bits to original data
	for(i = 0; i < len + 16; i++)
		data[i] ^= temp[i];

	printf("\nTransmitted Frame: ");
	for(i = 0; i < len + 16; i++)
		printf("%d", data[i]);
	printf("\n");

	// Receive frame
	printf("\nEnter received frame: ");
	for(i = 0; i < len + 16; i++)
		scanf("%d", &recv[i]);

	// Divide received frame by generator polynomial
	divide(recv, k);

	// Check if remainder is zero (no error)
	for(i = 0; i < len + 16; i++)
	{
		if(recv[i] != 0)
		{
			flag = 1;
			break;
		}
	}

	if(flag)
		printf("\nError detected!\n");
	else
		printf("\nNo error detected.\n");

	return 0;
}

Out put :
	Enter the length of the data frame : 4
	Enter the message bits (space seperated 0 1 1) : 1 0 1 0
	Transmitted Frame : 10101010000101001010001010

	0 No error detected.
	

