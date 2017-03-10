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

typedef struct appsDiferentesstruct{
	int id;
	int cont;
	int categoria;
	string nome;
}  tipoAppsDiferentes;

tipoAppsDiferentes appsDiferentes[900];
//vector <vector<int> > vec(200000, vector<int>(200000));
//int **matrix;
int numAppsDiferentes=0;
matrix mat;
int attempt=0;
int c[50];
int totalDownloads=0;
int contLinha=0;
int index_appID, index_Downloads, index_Category, index_Name;


string categoriasDiferentes[500];
int numCategoriasDiferentes=0;
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
contLinha++;
  // now we'll use a stringstream to separate the fields out of the line
  stringstream ss( line );
  string field;
  int contField=0; int i; 
  while (getline( ss, field, ',' ))
  {
	contField++;
	//cout << "cont" <<contLinha;
	//categoriasDiferentes[contField] = field.c_str();
	//cout << categoriasDiferentes[contField]; getchar();
	//Leitura da primeira linha, com os rotulos de cada campo
	if (contLinha==1) {
	cout << field.c_str();
		if (strcmp(field.c_str(), "App ID")==0) index_appID = contField;
		else if (strcmp(field.c_str(), "Value")==0) index_Downloads = contField;
		else if (strcmp(field.c_str(), "App Name")==0) index_Name = contField;
		else if (strcmp(field.c_str(), "App Category")==0) index_Category = contField;
		/*if (field.c_str() == "App ID")
		if (field.c_str() == "App ID")
		if (field.c_str() == "App ID")*/
	cout << index_appID;
	cout << index_Downloads;
	cout << index_Name;
	cout << index_Category;
	getchar();
	}
	
	//Leitura dos campos com os dados
	else {
	//cout << index_appID;
	//cout << index_Downloads;
	//cout << index_Name;
	//cout << index_Category;
	
		bool nova; int appID;   //id, cont 
		int appIndex;
		//Field appID: App ID
		if (contField == index_appID){
			appID =  atoi(field.c_str());
			nova = true;
			for (i=0; i<=numAppsDiferentes; i++) {
				if (appID == appsDiferentes[i].id) {
					nova=false;
					//appsDiferentes[i].cont++;
					appIndex = i;
					break;
				}
			}
			if (nova) {
				numAppsDiferentes++;
				appsDiferentes[numAppsDiferentes].id = appID;
				//appsDiferentes[numAppsDiferentes].cont++;
				appIndex = numAppsDiferentes;
			}
			 
		} //if (nova) ???????????????????????
		//Field numberDownloads: Value
		if (contField == index_Downloads){
			//cout << "\ncampo:" << field;
			numberDownloads = atoi(field.c_str()); //saving in this variable the number of downloads of one app
			numberDownloads = numberDownloads;
			//cout << "\nnum down:" << numberDownloads; 
			if (mostDownloaded ==0) {
					mostDownloaded = atoi(field.c_str()); 
					mostDownloaded = mostDownloaded;
					//matrix = (int**) malloc (sizeof(int*) * mostDownloaded); 
			}//saving the number of downloads of the most downloaded app	
			appsDiferentes[appIndex].cont+= numberDownloads;		
		}
		//Field Nome do App: App Name
		if (contField == index_Name){
		char nome; int size;
		//nome = field(1);
		//nome = field.c_str();
			appsDiferentes[appIndex].nome = (field.c_str());
			//size = field.length();
			//  cout <<  field.c_str(); 
			//cout << "char:" <<field[1]; //== "a") cout << "EITA"<<field.c_str();
			//if (nome== "o") cout << "he";
			//cout << "indexname" <<index_Name; getchar();
		}
		
		stringstream fs( field ); int categoria;
		
		//Field categoria: App Category
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
					numCategoriasDiferentes++;
					categoriasDiferentes[numCategoriasDiferentes] = field;
					//appsDiferentes[numAppsDiferentes].cont++;
					categoria = numAppsDiferentes;
					cout << categoriasDiferentes[numCategoriasDiferentes];
					cout << contLinha;			getchar();
				}
			/*if (field!="") {/*cout << "\ncategoria:" << field;*/ /*getchar();*}//*
			if (field == "") categoria=0;
			if (field == "\"Arcade & Action\"") categoria=1;
			if (field == "\"Game Casual\"") categoria=2;
			if ((field == "\"Sports Games\"") || (field == "Game Sports" ) ) categoria=3;
			if (field == "\"Music & Audio\"") categoria=4;
			if (field == "\"Game Puzzle\"") categoria=5;
			if (field == "\"Casual\"") categoria=6;
			if (field == "\"Brain & Puzzle\"") categoria=7;
			if (field == "\"Social\"") categoria=8;
			if (field == "\"Casual\"") categoria=9;
			if (field == "\"Game Role Playing\"") categoria=10;
			if (field == "\"Education\"") categoria=11;
			if (field == "\"Medical\"") categoria=12;
			if (field == "\"Game Arcade\"")categoria=13;
			if (field == "\"Game Action\"") categoria=14;
			if (field == "\"Books & Reference\"") categoria=15;
			else categoria=16;*/
			c[categoria]+=numberDownloads;
			appsDiferentes[appIndex].categoria = categoria;
			totalDownloads += numberDownloads;
		}
		
		double f = 0.0;  // (default value is 0.0)
		fs >> f;

		// add the newly-converted field to the end of the record
		record.push_back( f );
		
		//int i;
		
		//cout << "\ni" << i;
		numberApps++;
		
	  // Now we have read a single line, converted into a list of fields, converted the fields
	  // from strings to doubles, and stored the results in the argument record, so
	  // we just return the argument stream as required for this kind of input overload function.
		
	}
	}
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
//const int peruserInt = floor(peruser);
int idBaixadosPerUser[100];
//printf("#per user %3.3lf\n", peruser);

//getchar();
//printf("%d", matrix[i][j]);
int cont1 = 0;
cout << "categorias\n";
for (i=0; i<numCategoriasDiferentes; i++) {
					cout << (categoriasDiferentes[i]);
				
}
getchar();
 for (j=0; j<16;j++) {
			//printf("[%d] ", mat[i].at(j)); 
//			 cout <<"\nC:"<< (c[j]);
		}
//getchar();
int prob=0;
int baixado;
int categoriaAcabou =0;
int atualCategoria=0;
srand((unsigned)time(NULL));
int index; int k=0;
printf("num diferentes: %d\n", numAppsDiferentes); getchar();
int contVet[20]; int auxVet;
for (k=0;k<numAppsDiferentes; k++){
	cout << " "  <<appsDiferentes[k].nome;
	auxVet = appsDiferentes[k].categoria;
	contVet[auxVet]++;
	cout << "catego "  <<appsDiferentes[k].categoria << "\n";
	cout << appsDiferentes[k].cont << "\n";
	//getchar();
}
getchar();
for (k=0;k<17; k++){
cout << "contvet: "  <<contVet[k] << "\n";
}
cout << " Contlinha"  <<contLinha;
getchar();

 for (i=0; i<mostDownloaded;i++) { //mostDownloaded = number of USers
			//printf("[%d] ", mat[i].at(j)); 
			 cout << "\n user: " <<i+1; 
			 cout << " [" << 0 << "]"; c[0]--; //sempre baixa o da categoria mais baixada
			 
			 //procurar um app da categoria que foi baixada
			 for (index=0; index<numAppsDiferentes; index++) {
				if ((appsDiferentes[index].categoria == 0) && (appsDiferentes[index].cont > 0) ){
					cout << " [" << appsDiferentes[index].nome  << "]";
					idBaixadosPerUser[0] = appsDiferentes[index].id;
					appsDiferentes[index].cont--;
					break;
				}
			 }			 
			 
			  //CADA USUARIO BAIXA perUser APPS
			  for (j=2; j<peruser;j++) {
			  	printf("J:%d",j); getchar();
				//cout << "travei1? "; 
					//if ((c[0] == c[1] == c[2]== c[3]== c[4]== c[5]== c[6]== c[7]== c[8]== c[9]== c[10]== c[11]== c[12]== c[13]== c[14]== c[15]== c[16]== 0)) break;
					prob = rand() % (10);
					if (prob>=4){ 			
					//baixa da mesma categoria com 60%. 4 5 6 7 8 9
					//cout << "travei2? "; 
					  if (c[atualCategoria]>0) {
					  //cout << "travei3? "; 
						 cout << " [" << atualCategoria << "]"; 
						 c[atualCategoria]--;
					  }
					  else categoriaAcabou =1;
					  //cout << "travei4? "; 
					}
					
					else if ((prob<=3) || (categoriaAcabou==1))
					{ 		//0 1 2 3 ou acabou  a CategoriaAtual		
						baixado = rand() %(16);//cout << "travei? "; 
						while ((c[baixado] ==0) || (baixado == atualCategoria)) 
						{
							baixado  = rand() %(17);
							 //printf("[%d: %d] ", baixado, c[baixado]);//cout << "travei? "; 
						}				
						cout << " [" << baixado << "]";
						
						atualCategoria = baixado;
						c[baixado]--;
					}
					//printf("j%d ", j);//cout << "travei5? "; 
					bool aindaNaoBaixou; int l; int contAppDiferente =0;
					//aindaNaoBaixou = true; 
				
					for (index=0; index<numAppsDiferentes; index++) {
						if ((appsDiferentes[index].categoria == atualCategoria) && (appsDiferentes[index].cont > 0) ){
							//appsDiferentes[index] foi o escolhido pra ser baixado 
							
							for (l=2; l<j;l++) {
								if (idBaixadosPerUser[l]!= appsDiferentes[index].id) {
									contAppDiferente++;
									printf("[l:%d ,%d, %d]\n",l,idBaixadosPerUser[l],appsDiferentes[index].id);
									
								}	
							}
							printf("qts apps dif:%d , j-2:%d\n",contAppDiferente,j-2);
							getchar();
							contAppDiferente =0;
							if (contAppDiferente == j-2){ //ainda nao baixou esse app se for diferente de todos da lista q baixou
								cout << " [" << appsDiferentes[index].nome  << "]";
								appsDiferentes[index].cont--;
								idBaixadosPerUser[j] = appsDiferentes[index].id;
								break;
							}
							idBaixadosPerUser[j] = appsDiferentes[index].id;
							contAppDiferente =0;
						}
					}
						
					
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
  unsigned max_record_size = 0;
  for (unsigned n = 0; n < data.size(); n++)
    if (max_record_size < data[ n ].size())
      max_record_size = data[ n ].size();

	  //cout<< "HEYYOU\n" << data[ 4][14]<<data[ 4][15]<<data[ 4][16]<<data[ 4][17]<<data[ 4][18];
	 //cout<< "HEYYOU\n" << data[ 1][1]; getchar();

  
  return 0;
  }
