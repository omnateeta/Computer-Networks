#include<stdio.h>
#include<string.h>
int gcd(int m, int n){
	while(n!=0){
		int r= m % n;
		m = n;
		n = r;
	}
	return m;
}
int main()
{
	int p,q,n,e,d,phi;
	int nums[100], erp[100], drp[100];
	int i,j,nofelem;
	char msg[100];
	
	printf("Enter the message to be encrypted: ");
	fgets(msg, sizeof(msg),stdin);
	
	msg[strcspn(msg, "\n")]=0;
	printf("Enetr value of p & q: ");
	scanf("%d %d",&p,&q);
	n=p*q;
	phi = (p-1)*(q-1);
	
	for(e=2;e<phi;e++)
	{
		if(gcd(e,phi)==1)
		break;
	}
	for(d=2;d<phi;d++)
	{
		if((e*d-1) % phi == 0)
			break;
	}
	for(i=0;i<strlen(msg);i++)
	{
		nums[i] = msg[i] - 96;
	}
	
	nofelem = strlen(msg);
	for(i=0;i<nofelem;i++)
	{
		erp[i]=1;
		for(j=0;j<e;j++)
		{
			erp[i]=(erp[i] * nums[i]%n);
		}
	}
	
	printf("\n Encrypted message: ");
	for(i=0;i<nofelem;i++)
	{
		printf("%d",erp[i]);
		printf("%c",erp[i]+96);
	}
	
	for(i=0;i<nofelem;i++)
	{
		drp[i]=1;
		for(j=0;j<d;j++)
		{
			drp[i] = (drp[i]*erp[i] % n);
		}
	}
	
	printf("\n decrypted message: ");
	for(i=0;i<nofelem;i++)
	{
		printf("%c",(drp[i]+96));
	}
	return 0;
}
