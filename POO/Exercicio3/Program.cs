namespace Exercicio3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Aluno aluno = new Aluno();
            Console.Write("Digite o nome do aluno: ");
            aluno.Nome = Console.ReadLine();
            Console.Write("Digite a matricula: ");
            aluno.Matricula = Console.ReadLine();
            Console.Write("Digite a nota da primeira prova: ");
            aluno.NotaProva1 = Convert.ToSingle(Console.ReadLine());
            Console.Write("Digite a nota da segunda prova: ");
            aluno.NotaProva2 = Convert.ToSingle(Console.ReadLine());
            Console.Write("Digite a nota do trabalho: ");
            aluno.NotaTrabalho = Convert.ToSingle(Console.ReadLine());
            Console.WriteLine($"Media: {aluno.Media()}");
            Console.WriteLine($"Final: {aluno.Final()}");
        }
    }
}