#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
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
string nome;
bool aleatoria=true; int contAux=0;
int tamPopulation = 2264;
unsigned aux;
int mostDownloaded =0; //226415
int numberApps =0; //900
int numberDownloads =0;
int contLinha=0;
int size;
//char teste[290100][290100];
typedef vector <double> record_t;
typedef vector <record_t> data_t;

typedef vector <unsigned int> tMatrix;
typedef vector <tMatrix> matrix;
int categoria=0;
typedef struct appsDiferentesstruct{
	string id;
	int cont;
	int categoria; //indice da categoria
	string nome;
	int downloaded;
}  tipoAppsDiferentes;

tipoAppsDiferentes appsDiferentes[902];
//vector <vector<int> > vec(200000, vector<int>(200000));
//int **matrix;
int numAppsDiferentes=0;
matrix mat;
int attempt=0;
int c[50];
int totalDownloads=0;
int index_appID, index_Downloads, index_Name, index_Rank, index_Category;

string categoriasDiferentes[500];
int numCategoriasDiferentes=0;

//-----------------------------------------------------------------------------
// Let's overload the stream input operator to read a list of CSV fields (which a CSV record).
// Remember, a record is a list of doubles separated by commas ','.
istream& operator >> ( istream& ins, record_t& record )
  {
  // make sure that the returned record contains only the stuff we read now
  record.clear();

 
  string line; // read the entire line into a string (a CSV record is terminated by a newline)
  getline( ins, line );
  contLinha++;
  stringstream ss( line );  // now we'll use a stringstream to separate the fields out of the line
  string field;
  int contField=0; int i;
  while (getline( ss, field, ',' ))
    {
	
	contField++;
	if (contLinha==1) {
	
		if (strcmp(field.c_str(), "Rank")==0) index_Rank = contField;
		else if (strcmp(field.c_str(), "Value")==0) index_Downloads = contField;
		else if (strcmp(field.c_str(), "App Name")==0) index_Name = contField;
		else if (strcmp(field.c_str(), "App Category")==0) index_Category = contField;
		else if (strcmp(field.c_str(), "App Name (Unified)")==0) {index_appID = contField; /*cout << field.c_str();*/ }
		
	}
	
	else 
		if (contLinha<=901)  //this condition is for avoiding printing unnecessary info after the file.
	{ 						 // remove this condition in case your file is bigger than that
		//getchar();
		//cout <<index_appID;
			
		/*
		*  Ignoring commas inside a field
		*/
		if (field.find_first_of('"') ==0){ //found the first "
			size = field.size();
			//read until the next comma, and check if the value right before the last value is a ", which means that the field is over
			while ((field.c_str()[size-1] != '"') ){ 
				stringstream fs( field );
				getline( ss, field, ',' );
				size = field.size();
			}
		}
		
		/*
		*------------------------------------------------------[ APP ID ]------------------------------
		*/
		
		bool nova; string appID;   //id, cont 
		int appIndex=0;
		if (contField == index_appID){
			appID =  (field.c_str());
			//cout << appID;
			nova = true;
			for (i=0; i<numAppsDiferentes; i++) {
				if (appID == appsDiferentes[i].id) {
					nova=false;
					//appsDiferentes[i].cont++;
					appIndex = i;
					//cout<< "repeti "<< appID <<appsDiferentes[i].id;
					break;
				}
			}
			if (nova) {
				
				appsDiferentes[numAppsDiferentes].id = appID;
				//appsDiferentes[numAppsDiferentes].cont++;
				appIndex = numAppsDiferentes;
				numAppsDiferentes++;
			}
			
			//appsDiferentes[appIndex].nome = (field.c_str()); 
			appsDiferentes[appIndex].cont+= numberDownloads;
			appsDiferentes[appIndex].nome = nome;
			appsDiferentes[appIndex].categoria = categoria;
			/*if (categoria == 3){
			cout<< "nome "<< nome; 
			cout<< "cont "<< numberDownloads; 
			cout << "numappsdif "<< numAppsDiferentes;
			cout <<" appindex:" << appsDiferentes[i].id;
			cout << "\n" <<appsDiferentes[appIndex].categoria; getchar();}*/
		}
		
		/*
		*-----------------------------------------------------[ Number of Downloads ]-----------
		*/
		if (contField == index_Downloads){
			//cout << "\ncampo:" << field;
			numberDownloads = atoi(field.c_str()); //saving in this variable the number of downloads of one app
			//numberDownloads = numberDownloads;
			//cout << "\nnum down:" << numberDownloads; 
			if (mostDownloaded ==0) {
					mostDownloaded = atoi(field.c_str()); 
					mostDownloaded = mostDownloaded;
					//matrix = (int**) malloc (sizeof(int*) * mostDownloaded); 
			}//saving the number of downloads of the most downloaded app	
			//appsDiferentes[appIndex].cont+= numberDownloads;		
		}
		
		/*
		* ------------------------------------------[Name of App ]----------------                                        
		*/
		if (contField ==index_Name){
			//appsDiferentes[appIndex].nome = (field.c_str());
			nome = (field.c_str());
			
		}
		
		/*
		* ------------------------------------------[Category of App ]----------------                                        
		*/
		stringstream fs( field ); 
		if (contField == index_Category){
		
			
			//cout << field; getchar();
			nova = true;
				for (i=0; i<numCategoriasDiferentes; i++) {
					if (field == categoriasDiferentes[i]) {
						nova=false;
						//appsDiferentes[i].cont++;
						categoria = i;
						break;
					}
				}
				if (nova) {
					
					categoriasDiferentes[numCategoriasDiferentes] = field;
					//appsDiferentes[numAppsDiferentes].cont++;
					categoria = numCategoriasDiferentes;
					//cout << categoriasDiferentes[numCategoriasDiferentes];
					//cout << contLinha;			//getchar();
					numCategoriasDiferentes++;
				}
			
			c[categoria]+=numberDownloads;
			//appsDiferentes[appIndex].categoria = categoria; //atribuindo o indice a categoria ao app desta linha
			totalDownloads += numberDownloads;
			
			/*if (field!="") {/*cout << "\ncategoria:" << field;*/ /*getchar();}*/
			/*if (field == "") categoria=0;
			else if ((field == "Game Action") || (field == "Game Adventure")) categoria=1;
			else if ((field == "\"Casual\"") || (field == "\"Game Casual\"")) categoria=2; 
			else if ((field == "\"Sports Games\"") || (field == "Game Sports" ) ) categoria=3;
			else if (field == "\"Music & Audio\"") categoria=4;
			else if (field == "\"Game Puzzle\"") categoria=5;
			else if (field == "\"Game Simulation\"")  categoria=6;
			else if ((field == "\"Brain & Puzzle\"") || (field == "\"Game Puzzle\"")) categoria=7;
			else if (field == "\"Social\"") categoria=8;
			else if ((field == "\"Racing\"") || (field == "\"Game Word\"")) categoria=9;
			else if ((field == "\"Game Role Playing\"") || (field == "\"Game Card\"") ) categoria=10;
			else if ((field == "\"Education\"") ||(field == "\"Game Educational\"")) categoria=11;
			else if (field == "\"Medical\"") categoria=12;
			else if ((field == "\"Game Arcade\"") || (field == "Game Arcade") || (field == "Game Casino")) categoria=13;
			else if ((field == "\"Game Action\"") || (field == "Game Action")) categoria=14;
			else if (field == "\"Books & Reference\"") categoria=15;
			else categoria=16;
			c[categoria]+=numberDownloads;
			appsDiferentes[appIndex].categoria = categoria;
			
			totalDownloads += numberDownloads;*/
	}
		
		double f = 0.0;  // (default value is 0.0)
		fs >> f;

		// add the newly-converted field to the end of the record
		record.push_back( f );
	}
		//int i;
		
		//cout << "\ni" << i;
		numberApps++;
	}
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

 //for (j=0; j<numCategoriasDiferentes;j++) {
			//printf("[%d] ", mat[i].at(j)); 
		 //if (j ==3)	{ cout <<"\nCatego:"<< (categoriasDiferentes[j]); getchar();}
	//	}
//getchar();
int prob=0;
int baixado;
int categoriaAcabou =0;
int atualCategoria=0;
srand((unsigned)time(NULL));
int index;
int k;
//cout << "\n appsdif: "<< numAppsDiferentes;// getchar(); 
//cout << "\n number of Users: "<< mostDownloaded; 
//cout << "\n peruser "<< peruser; getchar(); 
for (k=0;k<numAppsDiferentes; k++){
	//cout << " "  <<appsDiferentes[k].nome;
	//auxVet = appsDiferentes[k].categoria;

	/*if (appsDiferentes[k].categoria==3) {cout << "catego3 "  <<appsDiferentes[k].categoria << "\n";
	cout << "down3" << appsDiferentes[k].cont << "\n";
	getchar(); getchar(); getchar();}*/
}

 for (i=0; i<mostDownloaded;i++) { //mostDownloaded = number of USers
			//printf("[%d] ", mat[i].at(j)); 
			//getchar();
			 //cout << "\n User: " <<i+1; 
			 //cout << "\n [" << 0 << "]"; c[0]--; //sempre baixa o da categoria mais baixada
			 //procurar um app da categoria que foi baixada
			 for (index=0; index<numAppsDiferentes; index++) {
				if (appsDiferentes[index].categoria == 0 /*&& (appsDiferentes[index].cont > 0)*/){
					//cout << " [" << appsDiferentes[index].id  << "]\n";
					//cout << " [" << appsDiferentes[index].nome  << "]\n";
					appsDiferentes[index].cont--;
					appsDiferentes[index].downloaded++;
					atualCategoria = 0;
					break;
				}
			 }			 
			 
			  //CADA USUARIO BAIXA perUser APPS
			  for (j=2; j<peruser;j++) {
			  //cout << "travei1? "; 
					//if ((c[0] == c[1] == c[2]== c[3]== c[4]== c[5]== c[6]== c[7]== c[8]== c[9]== c[10]== c[11]== c[12]== c[13]== c[14]== c[15]== c[16]== 0)) break;
					prob = rand() % (100);
					if (prob>55){ 			//de 0 a 54: 55% de chance de baixar da mesma categoria
					//baixa da mesma categoria com 60%. 4 5 6 7 8 9
					//cout << "travei2? "; 
					  //if (c[atualCategoria]>0) {
					  //cout << "travei3? "; 
						// cout << " [" << atualCategoria << "]"; 
						 c[atualCategoria]--;
					  //}
					  //else categoriaAcabou =1;
					  //cout << "travei4? "; 
					}
					
					else //if ((prob<=3) || (categoriaAcabou==1))
					{ 		//0 1 2 3 ou acabou  a CategoriaAtual		
						baixado = rand() %(numCategoriasDiferentes); //existem numCAtegoriasDiferentes-1 categorias
																	
						while (/*(c[baixado] ==0) || */(baixado == atualCategoria)) 
						{
							baixado  = rand() %(17);
							 //printf("[%d: %d] ", baixado, c[baixado]);//cout << "travei? "; 
						}				
						//cout << " [" << baixado << "]";
						
						atualCategoria = baixado;
						c[baixado]--;
					}
					//printf("j%d ", j);//cout << "travei5? "; 
					int appsDessaCategoria[100]; int a; int aleatorio;
					a=0; 
					for (index=0; index<numAppsDiferentes; index++) {
						if ((appsDiferentes[index].categoria == atualCategoria) /*&& (appsDiferentes[index].cont > 0)*/){
							//if (appsDiferentes[index].nome == "Pou") index=numAppsDiferentes;
							//else 
							appsDessaCategoria[a] = index; 
							a++;
							//cout << " [" << appsDiferentes[index].nome  << "]";
							//appsDiferentes[index].cont--;
							//break;
							//cout << "dessacateg [" << appsDessaCategoria[a]    << "]\n"; getchar();
						}
						
					}	
					aleatorio = rand() % (a); //sorteando um app Unico da categoria que foi baixada
					//cout << appsDiferentes[appsDessaCategoria[aleatorio]].id << " : ";
					//cout << " [" << appsDiferentes[appsDessaCategoria[aleatorio]].nome  << "]\n";
					appsDiferentes[appsDessaCategoria[aleatorio]].downloaded++;
					
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
  

	  //cout<< "HEYYOU\n" << data[ 4][14]<<data[ 4][15]<<data[ 4][16]<<data[ 4][17]<<data[ 4][18];
	 //cout<< "HEYYOU\n" << data[ 1][1]; getchar();

	 for (k=0;k<numAppsDiferentes; k++){
	cout << appsDiferentes[k].downloaded;
	cout << ", "  << k+1 << "\n"; //appsDiferentes[k].nome << "\n";
	//auxVet = appsDiferentes[k].categoria;

	
	}
  
  return 0;
  }
