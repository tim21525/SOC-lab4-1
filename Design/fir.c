#include "fir.h"

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
   for(int k=0;k<N;k++){ 
      outputsignal[k] = 0;
   }
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
   
   initfir();
   for(int i=0;i<N;i++){
      for(int j=0;j<=i;j++){
         outputsignal[i] = outputsignal[i] + inputsignal[i-j] * taps[j];
      }
   }
   
   //outputsignal[0] = inputsignal[0]*taps[0];
   
	//write down your fir
	return outputsignal;
}