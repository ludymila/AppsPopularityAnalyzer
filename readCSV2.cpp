#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*
int **matrix;

 matrix = (int**) malloc (sizeof(int*) * lin); 
 for (i=0; i<lin; i++) 
    matrix[i] = (int*) malloc (sizeof(int) * col);
*/
int tamPopulation = 2264;
int aux;
int mostDownloaded =0; //226415
int numberApps =0; //900
int numberDownloads =0;
//char teste[260000][260000];
typedef vector <double> record_t;
typedef vector <record_t> data_t;

typedef vector <unsigned int> tMatrix;
typedef vector <tMatrix> matrix;

//vector <vector<int> > vec(200000, vector<int>(200000));
//int **matrix;
matrix mat;

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
    // for each field we wish to convert it to a double
    // (since we require that the CSV contains nothing but floating-point values)
    stringstream fs( field );
	
	if (contField == 12){
		cout << "\ncampo:" << field;
		numberDownloads = atoi(field.c_str()); //saving in this variable the number of downloads of one app
		cout << "\nnum down:" << numberDownloads; getchar();
		if (mostDownloaded ==0) {
				mostDownloaded = atoi(field.c_str()); 
				//matrix = (int**) malloc (sizeof(int*) * mostDownloaded); 
		}//saving the number of downloads of the most downloaded app		
	}
    double f = 0.0;  // (default value is 0.0)
    fs >> f;

    // add the newly-converted field to the end of the record
    record.push_back( f );
    }
	int i;
	 //matrix[numberApps] = (int*) malloc (sizeof(int) * mostDownloaded); 
	 //getchar();
	 mat[numberApps].resize(tamPopulation);
	 for (i=0; i< int(numberDownloads/100); i++){ //number of Download = number of users that downloaded, to distribute randomly
		//cout << "\ntogernado:";
		//cout << "\nnum down:" << numberApps;
		aux = rand() %(tamPopulation);
		
		//if (aux > 90000) getchar();
		//cout << "\nnum randomico:" << aux;
		while (mat[numberApps].at(aux)==1){
			aux = rand() %(tamPopulation);
		}		
		mat[numberApps].at(aux) = 1;
		//matrix[numberApps][aux] = 1;
	}
	cout << "\ni" << i;
	numberApps++;
	
  // Now we have read a single line, converted into a list of fields, converted the fields
  // from strings to doubles, and stored the results in the argument record, so
  // we just return the argument stream as required for this kind of input overload function.
    contField=0;
  return ins;
  }


//-----------------------------------------------------------------------------
// Let's likewise overload the stream input operator to read a list of CSV records.
// This time it is a little easier, just because we only need to worry about reading
// records, and not fields.
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
// Now to put it all to use.
int main()
  {
  // Here is the data we want.
  data_t data;
mat.resize(6); //srand48(time(NULL));
	srand(time(NULL));
  // Here is the file containing the data. Read it into data.
  //ifstream infile( "App_Annie_Intelligence_Top_Unified_Apps_Charts_google-play_Argentina_Overall_2013-10-06-2013-10-12.csv" );
  ifstream infile( "apps.csv" );
  infile >> data;

  // Complain if something went wrong.
  if (!infile.eof())
    {
    cout << "Fooey!\n";
    return 1;
    }

  infile.close();
//vec[2][3] = 10;
  // Otherwise, list some basic information about the file.
  cout << "Your CSV file contains " << data.size() << " records.\n";
int i,j;
printf("most down%d", mostDownloaded);
printf("#apps down%d", numberApps);
getchar();
//printf("%d", matrix[i][j]);
int cont1 = 0;
  for (i=0; i<5;i++) {
		 for (j=0; j<tamPopulation;j++) {
			 printf("[%d] ", mat[i].at(j)); 
			 if (mat[i].at(j) ==1) cont1++;
		}
		cout << "\n" <<cont1; cont1=0;
		getchar();
		 
  }
  
  
		 for (i=0; i<5;i++) {
		 for (j=0; j<tamPopulation;j++) {
			 if (mat[i][j]==1) printf("[%d]-> [%d] \n", i,j); 
			 
		}
		//cout << "\n" <<cont1; cont1=0;
		//getchar();
		 
  }
  
  
  unsigned max_record_size = 0;
  for (unsigned n = 0; n < data.size(); n++)
    if (max_record_size < data[ n ].size())
      max_record_size = data[ n ].size();
  cout << "The largest record has " << max_record_size << " fields.\n";

  cout << "The second field in the fourth record contains the value " << data[2][1] << ".\n";
cout << "The second field in the fourth record contains the value " << data[ 2 ][ 2 ] << ".\n";
cout << "The second field in the fourth record contains the value " << data[ 2 ][ 3 ] << ".\n";
  cout << "Good bye!\n";
  return 0;
  }
