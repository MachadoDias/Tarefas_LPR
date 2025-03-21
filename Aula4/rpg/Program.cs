Console.WriteLine("Escolha a classe da sua personagem e digite o nome:\nGuerreira\nMago\nArqueira");
string escolha = Console.ReadLine().ToUpper();
Console.Write("Habilidades: ");
switch(escolha){
    case "GUERREIRA":
        Console.WriteLine("Ataque Pesado, Defesa Total");
        break;
    case "MAGO":
        Console.WriteLine("Bola de Fogo, Escudo de Gelo");
        break;
    case "ARQUEIRA":
        Console.WriteLine("Flecha Precisa, Disparo Triplo");
        break;
    default:
        Console.WriteLine("\nErro: Classe inválida");
        break;
}
