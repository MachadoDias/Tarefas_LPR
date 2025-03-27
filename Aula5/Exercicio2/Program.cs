Console.WriteLine("Tente adivinhar um número de 1 a 100");
Random random = new Random();
int answer = random.Next(1,100), guess, attempts = 0;
do{
    int.TryParse(Console.ReadLine(), out guess);
    if(guess == answer) Console.WriteLine("acertou");
    else if(guess>answer) Console.WriteLine("chutou alto");
    else Console.WriteLine("chutou baixo");
    attempts++;
}while(guess != answer);
Console.WriteLine($"numero de tentativas: {attempts}");