public struct Heroi
{
    public string Nome;
    public string Poder;
    public int Pontuacao;
}
public struct Lista
{
    public Heroi[] herois = new Heroi[5];
    public Heroi[] equipe = new Heroi[3];
    public Lista(){}
}
public class Program
{
    static void menuPrincipal(Lista lista)
    {
        while (true)
        {
            Console.WriteLine("Menu\n1 - Cadastrar herois\n2 - Formar equipe\n3 - Exibir equipe\n4 - Sair");
            int escolha = Convert.ToInt16(Console.ReadLine());
            switch (escolha)
            {
                case 1:
                    for (byte i = 0; i < 5; i++)
                    {
                        cadastrarHeroi(lista, i);
                    }
                    break;
                case 2:
                    selecionarEquipe(lista);
                    break;
                case 3:
                    exibirEquipe(lista);
                    break;
                case 4:
                    return;
                default:
                    Console.WriteLine("Escolha Inválida");
                    break;
            }
        }
    }
    static void cadastrarHeroi(Lista lista, byte index)
    {
        Console.Write("Digite o nome do herói: ");
        string nome = Console.ReadLine();
        Console.Write("Digite o poder do heroí: ");
        string poder = Console.ReadLine();
        byte pontuacao;
        for (;;)
        {
            Console.Write("Digite a pontuação do heroí, de 1 a 100: ");
            if (byte.TryParse(Console.ReadLine(), out pontuacao) && pontuacao >= 1 && pontuacao <= 100) break;
            Console.WriteLine("Valor invalído");
        }
        Heroi h = new Heroi { Nome = nome, Poder = poder, Pontuacao = pontuacao };
        lista.herois[index] = h;
    }
    static void selecionarEquipe(Lista lista)
    {
        Console.WriteLine($"Escolha 3 heroís por número\n1 - {lista.herois[0].Nome}\n2 - {lista.herois[1].Nome}\n3 - {lista.herois[2].Nome}\n4 - {lista.herois[3].Nome}\n5 - {lista.herois[4].Nome}");
        byte e1 = 0, e2 = 0, e3 = 0;
        while (e1 == e2 || e1 == e3 || e2 == e3)
        {
            if (e1 > 0) Console.WriteLine("Escolha 3 heróis diferentes");
            e1 = Convert.ToByte(Console.ReadLine());
            e2 = Convert.ToByte(Console.ReadLine());
            e3 = Convert.ToByte(Console.ReadLine());
        }
        lista.equipe[0] = lista.herois[e1 - 1];
        lista.equipe[1] = lista.herois[e2 - 1];
        lista.equipe[2] = lista.herois[e3 - 1];
    }
    static void exibirEquipe(Lista lista)
    {
        for (int i = 0; i < 3; i++) Console.WriteLine($"{i} - {lista.equipe[i].Nome} Poder: {lista.equipe[i].Poder}");
        Console.WriteLine($"Pontuação da equipe: {calcularPontuacaoTotal(lista)}");
    }
    static int calcularPontuacaoTotal(Lista lista)
    {
        int p = 0;
        foreach (Heroi h in lista.equipe) p += h.Pontuacao;
        return p;
    }
    public static void Main()
    {
        Lista lista = new Lista();
        menuPrincipal(lista);
    }
}