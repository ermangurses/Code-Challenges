// Implement C = A * B where A is a MxK matrix, B is a KxN matrix

int * C matMult (int * A[][K], int * B[][N] , int M, int K, int N ){

    int temp = 0;

    for (int k = 0; k < N; k++ ){
      
       for (int i = 0; i < M; i++ ){
     
           for (int j = 0; j < K; j++ ){
                 
              temp += A[i][j] * B[j][k]
           }  
       }
       C[i][k] = temp;
       temp = 0;
   }
   return C;
}
