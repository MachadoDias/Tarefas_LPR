namespace Exercicio1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double altura, largura;
            Console.WriteLine("Informe as dimensões do retângulo");
            Console.Write("Altura: ");
            altura = double.Parse(Console.ReadLine());
            Console.Write("Largura: ");
            largura = double.Parse(Console.ReadLine());
            Retangulo retangulo = new Retangulo(altura, largura);
            Console.WriteLine($"Área: {retangulo.calcArea().ToString("F2")}");
            Console.WriteLine($"Perímetro: {retangulo.calcPerimetro().ToString("F2")}");
        }
    }
}