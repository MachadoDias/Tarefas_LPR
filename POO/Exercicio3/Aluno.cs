namespace Exercicio3
{
    class Aluno
    {
        public string Nome { get; set; }
        public string Matricula { get; set; }
        public float NotaProva1 { get; set; }
        public float NotaProva2 { get; set; }
        public float NotaTrabalho { get; set; }
        public float Media()
        {
            return ((NotaProva1 + NotaProva2) * 2.5f + NotaTrabalho * 2) / 7;
        }
        public float Final()
        {
            float media = Media();
            return media < 60 ? 60 - media : 0;
        }
        public Aluno() { }
        public Aluno(string nome, string matricula, float notaProva1, float notaProva2, float notaTrabalho)
        {
            Nome = nome;
            Matricula = matricula;
            NotaProva1 = notaProva1;
            NotaProva2 = notaProva2;
            NotaTrabalho = notaTrabalho;
        }
    }
}