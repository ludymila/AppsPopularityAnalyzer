#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;
int contAux=0;
int tamPopulation = 2264;
unsigned aux;
int mostDownloaded =0; //226415
int numberApps =0; //900
int numberDownloads =0;
int size;
typedef vector <double> record_t;
typedef vector <record_t> data_t;
int attempt=0;
int c[50];
int totalDownloads=0;

//-----------------------------------------------------------------------------
// Let's overload the stream input operator to read a list of CSV fields (which a CSV record).
// Remember, a record is a list of doubles separated by commas ','.
istream& operator >> ( istream& ins, record_t& record )
  {
  // make sure that the returned record contains only the stuff we read now
  record.clear();

  // read the entire line into a string (a CSV record is terminated by a newline)
  string line;
  getline( ins, line );

  // now we'll use a stringstream to separate the fields out of the line
  stringstream ss( line );
  string field;
  int contField=0;
  while (getline( ss, field, ',' ))
    {

	contField++;
	if (contField == 1){
		printf("%s, ",field.c_str());
	}
	if ((contField == 10) && (field.find_first_of('"') ==0)){ //achou o primeiro "
		size = field.size();
		while ((field.c_str()[size-1] != '"') ){
			stringstream fs( field );
			getline( ss, field, ',' );
			size = field.size();
		}
	}
	if (contField == 11){
		puts(field.c_str());	
		numberDownloads = numberDownloads;
		if (mostDownloaded ==0) {
			mostDownloaded = atoi(field.c_str()); 
			mostDownloaded = mostDownloaded;
		}//saving the number of downloads of the most downloaded app		
	}
	
	}
    stringstream fs( field );
	
	/*
    double f = 0.0;  
    fs >> f;

    // add the newly-converted field to the end of the record
    record.push_back( f );
    }
	int i;
	
	numberApps++;*/
	
  // Now we have read a single line, converted into a list of fields, converted the fields
  // from strings to doubles, and stored the results in the argument record, so
  // we just return the argument stream as required for this kind of input overload function.
   // contField=0;
  return ins;
  }

istream& operator >> ( istream& ins, data_t& data )
  {
  // make sure that the returned data only contains the CSV data we read here
  data.clear();
  // For every record we can read from the file, append it to our resulting data
  record_t record;
  while (ins >> record)
    {
    data.push_back( record );
    }

  // Again, return the argument stream as required for this kind of input stream overload.
  return ins;  
  }

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  data_t data;
  // Here is the file containing the data. Read it into data.
  ifstream infile( argv[1] );
  infile >> data;

  // Complain if something went wrong.
  if (!infile.eof())
    {
	printf("Error\n");
    return 1;
    }

  infile.close();
 
  return 0;
}
