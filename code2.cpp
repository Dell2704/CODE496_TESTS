#include <iostream> //cout
#include <cmath> //use pow&sqrt
#include <fstream>
using namespace std;


//global variable
int i, j;
int i_c,j_c;
const int nx = 31;
const int ny = 31;
const int dx = 1;
const int dy = 1;

double phi[nx][ny];

ofstream myfileO;
ifstream myfileI;

void initialize(){ // void = not return variable
  for(int i=0 ; i<=nx-1;i++){
    for(int j = 0; j<=ny-1;j++){
      phi[i][j]=0.0;
    }
  }
}

void visualize(){
  for(int i=0 ; i<=nx-1;i++){
    for(int j = 0; j<=ny-1;j++){
      cout<<phi[i][j]<<" ";
    }
    cout << "\n";
  }
  
}

void set_phi(){
  double radius = 10.;
  i_c=(nx-1)/2;
  j_c=(ny-1)/2;
  for(int i = 0 ; i<=nx-1;i++){
    for(int j = 0; j<=ny-1;j++){

      if(sqrt(pow(dx*(i-i_c),2)+pow(dy*(j-j_c),2))<radius){
	phi[i][j] = 1.;
      }
      else{
	phi[i][j] = 0.;
      }
    }
  }

}

void save_restartfile(){
  myfileO.open("file.dat");
  for(int i = 0 ; i<=nx-1;i++){
    for(int j = 0; j<=ny-1;j++){
      myfileO << phi[i][j] << " " ;
    }
    myfileO << "\n";
  }
  myfileO.close();
  
}
void read_restartfile(){
  myfileI.open("file.dat");
  for(int i = 0 ; i<=nx-1;i++){
    for(int j = 0; j<=ny-1;j++){
      myfileI >> phi[i][j] ;
    }
  }
  myfileI.close();
  
}

int main(){
   initialize();
  // set_phi();
   visualize();
  // save_restartfile();
  read_restartfile();
  visualize();
}

