namespace Exercicio1
{
    class Retangulo(double altura, double largura)
    {
        public double Altura { get; init; } = altura;
        public double Largura { get; init; } = largura;
        public double calcArea()
        {
            return Altura*Largura;
        }
        public double calcPerimetro()
        {
            return 2*(Altura + Largura);
        }
    }
}