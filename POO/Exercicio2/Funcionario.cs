namespace Exercicio2
{
    class Funcionario
    {
        public string Nome { get; set; }
        public double SalarioBruto { get; set; }
        private double SalarioLiquido;
        public void MostrarDados()
        {
            Console.WriteLine($"Nome: {Nome}\nSalário líquido: {SalarioLiquido}");
        }
        private double CalcularSalarioLiquido(double salarioBruto)
        {
            if (salarioBruto < 2000)
                return 0.9 * salarioBruto;
            if (salarioBruto < 3000)
                return 0.85 * salarioBruto;
            return 0.8 * salarioBruto;
        }

        public void AumentarSalario(double porcentagemDecimal)
        {
            SalarioBruto *= 1 + porcentagemDecimal;
            SalarioLiquido = CalcularSalarioLiquido(SalarioBruto);
        }
        public Funcionario(string nome, double salarioBruto)
        {
            Nome = nome;
            SalarioBruto = salarioBruto;
            SalarioLiquido = CalcularSalarioLiquido(salarioBruto);
        }
    }
}