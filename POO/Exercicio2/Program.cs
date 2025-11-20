namespace Exercicio2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Digite o nome do funcionario: ");
            string nome = Console.ReadLine();
            Console.Write("Digite o salário do funcionário: ");
            double salario = Double.Parse(Console.ReadLine());
            Funcionario funcionario = new Funcionario(nome, salario);
            funcionario.MostrarDados();
        }
    }
}
