/*  Problem: weather
    
    Name           : Bukuhan. Abram Aki R.
    Section        : S17C
    Room           : 204
    Terminal Number: insane
 */

#include <stdio.h>
#include <math.h>

#define WINTER 'W'
#define SUNNY 'S'
#define RAINY 'R'

#define TEMP_1	1
#define HUMID_1	24

#define TEMP_2	30
#define HUMID_2	40

#define TEMP_3	21
#define HUMID_3	25

/* display() shows the weather data
 */
void displayWeatherData ()
{
	printf ("TEMPERATURE\tHUMIDITY\tWEATHER\n");
	printf ("-----------------------------------------\n");
	printf ("%6d\t\t%5d\t\t%c\n", TEMP_1, HUMID_1, WINTER);
	printf ("%6d\t\t%5d\t\t%c\n", TEMP_2, HUMID_2, SUNNY);
	printf ("%6d\t\t%5d\t\t%c\n", TEMP_3, HUMID_3, RAINY);
}

/* TODO: getSquare() returns the square of a float (i.e., raising a floating point number to
   the power of 2).
 */

float getSquare(float n){
	return n * n;
}


/* TODO: getManhattanDist() returns the manhattan distance between two instances of sample data.
   This function accepts as parameters the temperature and humidity values of each instance.
   
   HINT: for computing the absolute value, use the function fabs() defined in math.h
   FUNCTION PROTOTYPE: double fabs(double x);
 */
float getManhattanDist(float fDataTemp, float fDataHumid, float fInTemp, float fInHumid){
	float fManDist;
	fManDist = fabs(fDataTemp - fInTemp) + fabs(fDataHumid - fInHumid);

	return fManDist;
}

/* TODO: getEuclideanDist() returns the euclidean distance between two instances of weather data.
   This function accepts as parameters the temperature and humidity values of each instance.
   This should use the getSquare() function which you have defined.
   
   HINT: for computing the square root, use the function sqrt() defined in math.h
   FUNCTION PROTOTYPE: double sqrt(double x);
 */
float getEuclideanDist(float fDataTemp, float fDataHumid, float fInTemp, float fInHumid){
	float fEucDist;
	fEucDist = sqrt(getSquare(fDataTemp - fInTemp) + getSquare(fDataHumid - fInHumid));

	return fEucDist;
}


/* This function should return the distance between two instances of weather data.
   It calls the function getManhattanDist() to compute the manhattan distance.
   Otherwise, it calls the function getEuclideanDist() to compute the euclidean distance.
   It has logical bugs.

   TODO: Debug it.
 */
float getDistance (char cMetric, float fDataTemp, float fDataHumid, float fInTemp, float fInHumid)
{
	float fDist;
		
	switch (cMetric)
	{
		case 'M': 
		case 'm':
			fDist = getManhattanDist (fDataTemp, fDataHumid, fInTemp, fInHumid);
			break;
		case 'E':
		case 'e':
			fDist = getEuclideanDist (fDataTemp, fDataHumid, fInTemp, fInHumid);
			break;
	}
	
	return fDist;
}

/* TODO: getWeather() returns a character signifying the predicted weather.
   This function accepts the temperature, humidity, and distance metric provided by the user.
   The function computes the distance of data provided by the user from each weather data,
   displays the distances, then returns the weather which yields the smallest distance.
   This should use the getDistance() function which you have defined.
 */

char getWeather(char cMetric, float fInTemp, float fInHumid){
	char cWeather;
	float fWinter, fSunny, fRainy;

	fWinter = getDistance(cMetric, TEMP_1, HUMID_1, fInTemp, fInHumid);
	fSunny = getDistance(cMetric, TEMP_2, HUMID_2, fInTemp, fInHumid);
	fRainy = getDistance(cMetric, TEMP_3, HUMID_3, fInTemp, fInHumid);
	
	printf("\nDistances:\n");
	printf("Winter: %.2f\n",fWinter);
	printf("Sunny: %.2f\n", fSunny);
	printf("Rainy: %.2f\n", fRainy);

	if(fWinter < fSunny && fWinter < fRainy){
		cWeather = 'W';
	}
	else if(fSunny < fWinter && fSunny < fRainy){
		cWeather = 'S';
	}
	else if(fRainy < fWinter && fRainy < fSunny){
		cWeather = 'R';
	}

	return cWeather;
}

int main ()
{
	float fTemp;
	float fHumid;
	char cMetric;
	char cWeather;
	
	displayWeatherData ();
	
	printf ("\nEnter Temperature: ");
	scanf ("%f", &fTemp);
	
	printf ("Enter Humidity: ");
	scanf ("%f", &fHumid);
	
	printf ("Metric: [M] Manhattan [E] Euclidean: ");
	scanf (" %c", &cMetric);
	
	if (cMetric == 'M' || cMetric == 'm' || cMetric == 'E' || cMetric == 'e')
	{
		
		cWeather = getWeather(cMetric, fTemp, fHumid);
		
		printf ("\nWEATHER PREDICTION: %c", cWeather);
	}
	else
		printf ("Invalid metric.");
	
	return 0;
}
