void PreencherMatrizes(int[,] matriz, int linhas, int colunas){
    for(int i = 0; i<3; i++){
        string[] temp = Console.ReadLine().Split(" ");
        for(int j = 0; j<3; j++){
            matriz[i,j] = int.Parse(temp[j]);
        }
    }
}
int[,] A = new int[3,3], B = new int[3,3];
Console.WriteLine("Digite os elementos da matriz A, sendo os elementos separados por um espaço e as linhas separadas por linhas");
PreencherMatrizes(A, 3, 3);
Console.WriteLine("Digite os elementos da matriz B, sendo os elementos separados por um espaço e as linhas separadas por linhas");
PreencherMatrizes(B, 3, 3);
int[,] C = new int[3,3];
Console.WriteLine("A matriz resultante é:");
for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        for(int z = 0; z<3; z++){
            C[i,j] += A[z,j] * B[i,z];
        }
        Console.Write($"{C[i,j]} ");
    }
    Console.WriteLine();
}