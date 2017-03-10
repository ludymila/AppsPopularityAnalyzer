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
bool aleatoria=true; int contAux=0;
int tamPopulation = 2264;
unsigned aux;
int mostDownloaded =0; //226415
int numberApps =0; //900
int numberDownloads =0;
//char teste[290100][290100];
typedef vector <double> record_t;
typedef vector <record_t> data_t;

typedef vector <unsigned int> tMatrix;
typedef vector <tMatrix> matrix;

//vector <vector<int> > vec(200000, vector<int>(200000));
//int **matrix;
matrix mat;
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
	if (contField == 12){
		//cout << "\ncampo:" << field;
		numberDownloads = atoi(field.c_str()); //saving in this variable the number of downloads of one app
		numberDownloads = numberDownloads;
		//cout << "\nnum down:" << numberDownloads; 
		if (mostDownloaded ==0) {
				mostDownloaded = atoi(field.c_str()); 
				mostDownloaded = mostDownloaded;
				//matrix = (int**) malloc (sizeof(int*) * mostDownloaded); 
		}//saving the number of downloads of the most downloaded app		
	}
	
	
    stringstream fs( field );
	if (contField == 18){
		if (field!="") {/*cout << "\ncategoria:" << field;*/ /*getchar();*/}
		if (field == "") c[0]+=numberDownloads;
		if (field == "\"Arcade & Action\"") c[1]+=numberDownloads;
		if (field == "\"Game Casual\"") c[2]+=numberDownloads;
		if ((field == "\"Sports Games\"") || (field == "Game Sports" ) ) c[3]+=numberDownloads;
		if (field == "\"Music & Audio\"") c[4]+=numberDownloads;
		if (field == "\"Game Puzzle\"") c[5]+=numberDownloads;
		if (field == "\"Casual\"") c[6]+=numberDownloads;
		if (field == "\"Brain & Puzzle\"") c[7]+=numberDownloads;
		if (field == "\"Social\"") c[8]+=numberDownloads;
		if (field == "\"Casual\"") c[9]+=numberDownloads;
		if (field == "\"Game Role Playing\"") c[10]+=numberDownloads;
		if (field == "\"Education\"") c[11]+=numberDownloads;
		if (field == "\"Medical\"") c[12]+=numberDownloads;
		if (field == "\"Game Arcade\"") c[13]+=numberDownloads;
		if (field == "\"Game Action\"") c[14]+=numberDownloads;
		if (field == "\"Books & Reference\"") c[15]+=numberDownloads;
		else (c[16]+=numberDownloads);
		totalDownloads += numberDownloads;
	}
	
    double f = 0.0;  // (default value is 0.0)
    fs >> f;

    // add the newly-converted field to the end of the record
    record.push_back( f );
    }
	int i;
	
	//cout << "\ni" << i;
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
int main(int argc, char **argv)
  {
  int users[15000];
  // Here is the data we want.
  data_t data;
  mat.resize(901); //srand48(time(NULL));
	srand((unsigned)time(NULL));
  // Here is the file containing the data. Read it into data.
  //ifstream infile( "App_Annie_Intelligence_Top_Unified_Apps_Charts_google-play_Argentina_Overall_2013-10-06-2013-10-12.csv" );
  ifstream infile( argv[1] );
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
  //cout << "Your CSV file contains " << data.size() << " records.\n";
int i,j;
//printf("most down%d\n", mostDownloaded);
//printf("#apps down%d\n", numberApps);
//printf("#total downloads%d\n", totalDownloads);
float peruser = (totalDownloads/mostDownloaded);
//printf("#per user %3.3lf\n", peruser);

//getchar();
//printf("%d", matrix[i][j]);
int cont1 = 0;

 for (j=0; j<16;j++) {
			//printf("[%d] ", mat[i].at(j)); 
//			 cout <<"\nC:"<< (c[j]);
		}
//getchar();
int prob=0; ;
int baixado;
int categoriaAcabou =0;
int atualCategoria=0;
srand((unsigned)time(NULL));
 for (i=0; i<mostDownloaded;i++) { //mostDownloaded = number of USers
			//printf("[%d] ", mat[i].at(j)); 
			 cout << "\n user: " <<i+1; 
			 cout << " [" << 0 << "]"; c[0]--; //sempre baixa o da categoria mais baixada
			  //CADA USUARIO BAIXA perUser APPS
			  for (j=2; j<peruser;j++) {
			  //cout << "travei1? "; 
					//if ((c[0] == c[1] == c[2]== c[3]== c[4]== c[5]== c[6]== c[7]== c[8]== c[9]== c[10]== c[11]== c[12]== c[13]== c[14]== c[15]== c[16]== 0)) break;
					prob = rand() % (10);
					if (prob>=4)
					{ 			
					//baixa da mesma categoria com 60%. 4 5 6 7 8 9
					//cout << "travei2? "; 
					 // if (c[atualCategoria]>0) {
					  //cout << "travei3? "; 
						 cout << " [" << atualCategoria << "]"; 
						 c[atualCategoria]--;
					  ///
					  
					  
					  //cout << "travei4? "; 
					}else categoriaAcabou =1;
					
					if ((prob<=3) || (categoriaAcabou==1))
					{ 		//0 1 2 3 ou acabou  a CategoriaAtual		
						baixado = rand() %(16);//cout << "travei? "; 
						while (baixado == atualCategoria) //sorteia outro sem ser a mesma categoria
						{
							baixado  = rand() %(17);
							 //printf("[%d: %d] ", baixado, c[baixado]);//cout << "travei? "; 
						}				
						cout << " [" << baixado << "]";
						
						atualCategoria = baixado;
						//c[baixado]--;
					}
					//printf("j%d ", j);//cout << "travei5? "; 
				}
			// getchar();cout << "travei? "; 
	}
		
/*
  for (i=0; i<901;i++) {
		 for (j=0; j<tamPopulation;j++) {
			//printf("[%d] ", mat[i].at(j)); 
			 if (mat[i].at(j) ==1) cont1++;
		}
		cout << "\n" <<cont1; cont1=0;
		//getchar();
		 
  }
  
		  cout << "Aplicativo -> usuario que baixou \n";
		 for (i=0; i<901;i++) {
		 for (j=0; j<tamPopulation;j++) {
			 if (mat[i][j]==1) printf("[%d]-> [%d] \n", i,j); 
			 
		}
		 cout << "usuario -> apps que ele baixou \n";
		//getchar();
		 for (j=0; j<tamPopulation;j++) {
			printf("[usuario] %d: [", j);
			for (i=0; i<901;i++) {
			 if (mat[i][j]==1) printf("%d, ", i); 
			 }
			 printf("\n"); 
		}
		//cout << "\n" <<cont1; cont1=0;
		//getchar();
		 
  }
  
  */
  //cout << "travei? "; 
  unsigned n;
  unsigned max_record_size = 0;
  //for (unsigned n = 0; n < data.size(); n++)
    //if (max_record_size < data[ n ].size())
      //max_record_size = data[ n ].size();

	  //cout<< "HEYYOU\n" << data[ 4][14]<<data[ 4][15]<<data[ 4][16]<<data[ 4][17]<<data[ 4][18];
	 //cout<< "HEYYOU\n" << data[ 1][1]; getchar();

  
  return 0;
  }
