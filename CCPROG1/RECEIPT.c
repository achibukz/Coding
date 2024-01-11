#include<stdio.h>
#define AMOUNT 99.00
#define TAX 0.12
#define TIP1 0.15
#define TIP2 0.18
#define TIP3 0.20

float computeTotal(int nOrder){
	float fTotal;
	fTotal = nOrder * AMOUNT;
	
	return fTotal;
}


float computeGross(float fTotal){
	
	float fGross;
	fGross = fTotal / (1 + TAX);
	
	return fGross;
}

float computeTax(float fGross){
		float fTax;
		
		fTax = fGross * TAX;
		
		return fTax;
}

void currentDate(int Date){
	int mm, dd, yyyy;
	
	yyyy = Date % 10000;
	mm = Date / 10000 % 100;
	dd = Date / 1000000;
	
	printf("Date: %d/%d/%d\n", mm, dd, yyyy);
	
}

void displayDivider(){
	
	printf("%s%s%s%s\n", "----------", "----------", "----------", "----------");
	
}

void displayHeader(){
	
	printf("%24s\n", "MyKitchen");
	printf("%29s\n", "Taft Avenue, Manila");
	printf("%25s\n", "Your Receipt");	
}

int main(){
	
	int nDate;
	int nOrders;
	float fPrice;
		
	printf("Date:  ");
	scanf("%d", &nDate);
	
	printf("Number of Orders:  ");
	scanf("%d", &nOrders);
	
	displayHeader();
	displayDivider();
	currentDate(nDate);
	displayDivider();
	printf("Number of Orders: %d\n", nOrders);

	fPrice = computeTotal(nOrders);
	printf("Total Price = %.2f\n", fPrice);
	
	float fGross = computeGross(fPrice);
	printf("Gross Total= %.2f\n", fGross);
	
	float fTax = computeTax(fGross);
	printf("Tax = %.2f\n", fTax);
		
	return 0;
}

// Year = date % 10000
// Month = date / 10000 % 100
// Day = date / 1000000
// 					25.2f