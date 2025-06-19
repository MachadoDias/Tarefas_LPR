public struct Produto
{
    public string Nome;
    public string Codigo;
    public float Preco;
    public uint Quantidade;
}public class Program
{
    public static void Main()
    {
        Produto[] produtos = new Produto[3];
        for (int i = 0; i < 3; i++)
        {
            Console.Write($"Digite o nome do produto {i + 1}: ");
            produtos[i].Nome = Console.ReadLine();
            Console.Write($"Digite o código do produto {i + 1}: ");
            produtos[i].Codigo = Console.ReadLine();
            Console.Write($"Digite o preço do produto {i + 1}: ");
            produtos[i].Preco = Convert.ToSingle(Console.ReadLine());
            Console.Write($"Digite a quantidade do produto {i + 1}: ");
            produtos[i].Quantidade = Convert.ToUInt32(Console.ReadLine());
        }
        double valorTotal = 0;
        foreach (Produto produto in produtos)
        {
            valorTotal += produto.Quantidade * produto.Preco;
        }
        Console.WriteLine($"Valor total em estoque: {valorTotal:F2}");
    }
}