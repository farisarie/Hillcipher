#include<iostream>
#include<math.h>
using namespace std;
float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];
void getKeyMatrix() { //berfungsi untuk mendapatkan kunci dan pesan dari user
   int i, j;
   char mes[3];
   cout<<"Masukkan matrix 3x3 untuk key (harus memiliki inverse):\n";
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) {
      cin>>a[i][j];
      m[i][j] = a[i][j];
   }
   cout<<"\nMasukkan string 3 huruf(gunakan A sampai Z): ";
   cin>>mes;
   for(i = 0; i < 3; i++)
   msg[i][0] = mes[i] - 65;
}
void encrypt() { //berfungsi untuk mengenkripsi kalimat 
   int i, j, k;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   en[i][j] = en[i][j] + a[i][k] * msg[k][j];
   cout<<"\nEnkripsi string : ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(en[i][0], 26) + 65); //modulo 26 diambil untuk setiap elemen matriks yang diperoleh dengan perkalian
}
void inversematrix() { //menemukan inverse kunci matriks 
   int i, j, k;
   float p, q;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) {
      if(i == j)
         b[i][j]=1;
      else
         b[i][j]=0;
   }
   for(k = 0; k < 3; k++) {
      for(i = 0; i < 3; i++) {
         p = m[i][k];
         q = m[k][k];
         for(j = 0; j < 3; j++) {
            if(i != k) {
               m[i][j] = m[i][j]*q - p*m[k][j];
               b[i][j] = b[i][j]*q - p*b[k][j];
            }
         }
      }
   }
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++)
   b[i][j] = b[i][j] / m[i][i];
   cout<<"\n\nInverse Matrix :\n";
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++)
      cout<<b[i][j]<<" ";
      cout<<"\n";
   }
}
void decrypt() { //berfungsi untuk mendeskripsi kalimat 
   int i, j, k;
   inversematrix();
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   de[i][j] = de[i][j] + b[i][k] * en[k][j];
   cout<<"\nDecrypted string : ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(de[i][0], 26) + 65); //modulo 26 diambil untuk mendapatkan kalimat atau pesan yang asli
   cout<<"\n";
}
int main() {
   getKeyMatrix();
   encrypt();
   decrypt();
}