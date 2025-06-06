using System.Globalization;

string[] cidades = {"Vitória", "Belo Horizonte", "Rio de Janeiro", "São Paulo"};
int[,] distancias = new int[4,4];
for(int i = 0; i<4; i++){
    for(int j = i+1; j<4; j++){
        Console.Write($"Qual a distância entre {cidades[i]} e {cidades[j]}? ");
        UInt16 d = Convert.ToUInt16(Console.ReadLine());
        distancias[i,j] = d;
        distancias[j,i] = d;
    }
}
while(true){
    Console.WriteLine("Digite as cidades:");
    string c1 = Console.ReadLine();
    string c2 = Console.ReadLine();
    byte linha = 5, coluna = 5;
    for(byte i = 0; i < 4; i++){
        if(c1 == cidades[i]) linha = i;
        if(c2 == cidades[i]) coluna = i;
    }
    if(linha == 5 || coluna == 5) Console.WriteLine("Cidade inválida");
    else if(linha == coluna) break;
    else Console.WriteLine($"A distância entre {cidades[linha]} e {cidades[coluna]} é {distancias[linha,coluna]}");
}