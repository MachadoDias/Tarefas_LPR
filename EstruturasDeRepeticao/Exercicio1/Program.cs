Console.WriteLine("Digite o número de elementos de uma sequência e em seguida digite a sequência, separados por espaço");
int []numbers;
try{
    numbers = Array.ConvertAll<string, int>(Console.ReadLine().Split(" "), int.Parse);
}
catch{
    Console.WriteLine("Entrada inválida");
    return;
}
if(numbers.Length != numbers[0] + 1){
    Console.WriteLine("O primeiro número da sequência não corresponde à quantidade de números");
    return;
}
int i = 1, numElementosPares = 0;
float media = 0;
while(i<=numbers[0]){
    if(numbers[i]%2 == 0) {
        media+=numbers[i];
        numElementosPares++;
    }
    i++;
}
if(numElementosPares == 0){
    Console.WriteLine("Não existem elementos pares");
    return;
}
media/=numElementosPares;
Console.WriteLine(media);
